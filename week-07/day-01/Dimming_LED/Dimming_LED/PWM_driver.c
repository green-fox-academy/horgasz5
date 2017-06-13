/*
 * PWM_driver.c
 *
 * Created: 2017. 06. 12. 11:04:54
 *  Author: HP
 */ 
#include "PWM_driver.h"
#include <avr/io.h>
#include <stdint.h>
//#include <util/delay.h>

void PWM_init()
{
	// initialize TCCRB0 as per requirement, say as follows
	TCCR0A |= (1 << WGM00) | (1 << COM0A1) | (1 << WGM01);
	
	TCCR0B |= (1 << CS00);
	
	// make sure to make OCR0A pin (pin PD6 for atmega168PB) as output pin
	DDRD |= (1 << DDRD6);
}
