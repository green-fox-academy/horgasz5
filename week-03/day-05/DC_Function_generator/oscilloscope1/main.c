#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ADC_driver.h"
#include "UART_driver.h"
#include "MCP4821_driver.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define MAX_VOLTAGE		4.096
#define MIN_VOLTAGE		0

void SystemInit(){

	//Init previously projects
	
	MCP4821_Init();
	ADC_Init();
    UART_Init();
	sei();
}



int main(void)
{
	SystemInit();
	char voltage_string[25];
	float voltage;
	uint16_t adc_data;
	uint16_t data_to_DAC;
	    
	MCP4821_Data_t DAC_data;
	DAC_data.start_zero = 0;
	DAC_data.dont_care = 0;
	DAC_data.gain = 0;
	DAC_data.shutdown = 1;
	DAC_data.data = 0x000;
		
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	
	printf("Startup...\r\n");
		
	while(1){
		puts("Give me a voltage between 0 and 4.096");
		
		gets(voltage_string);
		voltage = atof(voltage_string);
		if (voltage < 0)
		{
			voltage = 0;
		}else if (voltage >= 4.096)
		{
			voltage = 4.095;
		}
		
		DAC_data.data = (uint16_t)(voltage * 1000);
		
		// Send data to DAC
		MCP4821_SendData(&DAC_data);
	
		_delay_ms(20);
			
		//printf("%d\r\n", adc_data);
		//UART_SendCharacter(adc_data >> 2);
}
}