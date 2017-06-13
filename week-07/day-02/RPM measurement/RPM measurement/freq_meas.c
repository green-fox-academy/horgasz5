#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

uint8_t tick_count = 0;
uint8_t tick_counted = 0;
uint16_t tick_prev = 0;
uint16_t tick_now = 0;

// TODO:
// Write the interrupt handlers
ISR(TIMER1_OVF_vect)
{
	tick_count++;
}

ISR(TIMER1_CAPT_vect)
{
	tick_counted = tick_count;
	tick_count = 0;
	tick_prev = tick_now;
	tick_now = TCNT1;
}

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
	
	//Set prescale to 1024
	TCCR1B |= 0b101;
	
	//Enable Overflow Interrupt - TIFR1 / TOV1 bit is the flag
	TIMSK1 |= 1 << TOIE1;
	
	//Enable Capture Interrupt - TIFR1 / ICF1 bit is the flag
	TIMSK1 |= 1 << ICIE1;
	
	//Enable both interrupts
	//TIMSK1 = 0b100001;
}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
	// 0.000064 is: prescale / Fcpu. Now its: 1024 / 16.000.000
	float freq = ( 1 / ( 0.000064 * (65535 * tick_counted - tick_prev + tick_now)));
	
	return freq;
}