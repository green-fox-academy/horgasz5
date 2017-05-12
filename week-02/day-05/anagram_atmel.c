#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function
#include <string.h>

void UART_Init() {
	// Write this function
	// See the datasheet on page 246 for hints and table 25-9.

	//TODO:
	// At first set the baud rate to 9600
	// The CPU clock frequency is 16MHz
	uint16_t ubbr = 103;
	UBRR0H = ubbr >> 8;
	UBRR0L = ubbr;

	//TODO:
	// Set the following frame format: 8N1
	// It is set to 8N1 by default

	//TODO:
	// Enable TX
	UCSR0B |= 1 << TXEN0;

	//TODO:
	// Enable RX
	UCSR0B |= 1 << RXEN0;
}

void UART_SendCharacter(char character) {
	// Write this function, which can send a character through UART will polling method
	// See page 247 of the datasheet for hints, be aware that the code in the datasheet has a problem :)

	//TODO:
	// Wait for empty buffer
	while ( !( UCSR0A & (1<<UDRE0)) );

	//TODO:
	// Put data to buffer
	UDR0 = character;
}

char UART_GetCharacter() {
	// Write this function, which waits for a character and returns when one is received
	// See page 249 of the datasheet for hints, be aware that the code in the datasheet has a problem :)

	//TODO:
	// Wait for data received
	while ( !(UCSR0A & (1<<RXC0)) );

	//TODO:
	// Put data to buffer
	return UDR0;
}

int main(void) {
	
	//Don't forget to call the init function :)
	UART_Init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	//TODO:
	// Try printf
	printf("Startup...\r\n");

	// Loop that runs forever
	char first[50];
	char second[50];
	uint8_t boo = 1;

	printf("First word:\r\n");
	gets(first);
	puts(first);
	printf("Second word:\r\n");
	gets(second);
	puts(second);
	uint8_t f_len = strlen(first);
	uint8_t s_len = strlen(second);

	if (f_len != s_len){
		printf("\r\nOne of the word is longer than the other!\r\n");
		boo = 0;
	}

	for(uint8_t i = 0; i < f_len; i++){
		for(uint8_t j = 0; j < s_len; j++){
			if(first[i] == second[j]){
				second[j] = '0';
			}
		}
	}

	for(uint8_t i = 0; i < s_len; i++){
		if(second[i] != '0'){
			boo = 0;
		}
	}

	if(boo == 1){
		printf("\r\nThe two words are anagrams!\r\n", first, second);
		}else{
		printf("\r\nNOT anagrams!\r\n");
	}

	return 0;
	
	
}