#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function

static volatile char flag = 0;

ISR(PCINT0_vect)
{
	// Toggle the LED
	if (flag == 0)
	{
		flag = 1;
	}else if (flag == 1)
	{
		flag = 0;
	}
}

// This is an init function, which initializes the MCU for the rest of the program.
// It is common in embedded C programs to set port direction (input/output), pull-ups and pull-downs,
// and everything that is needed at the start of your program. It is like the "on start" block in a micro:bit,
// or like the "setup" in arduino.

void init()
{
	// The button is connected to PB7 pin, which is the PCINT7 pin (PinChangeINTerrupt7 pin)
	PORTB &= ~(1 << PORTB7);
	// If we anable this interupt on every pin state changes the interrupt handler will be fired.
	// So when the button is pressed OR released the inturrupt handler will run.

	// Set the PCINT7 bit of PCMSK0 register. This will enable the interrupts from the button (PB7=PCINT7)
	PCMSK0 |= 1 << PCINT7;

	// Enable pin interrupt on change 0 interrupts. This will enable PCINT0, PCINT1, PCINT2 ... PCINT7 interrupts.
	PCICR |= 1 << PCIE0;

	// Finally, enable the interrupts globally
	sei();

	// Set PB5 as output, this is the LED pin
	DDRB |= 1 << PORTB1;
	DDRB |= 1 << PORTB3;
	DDRB |= 1 << PORTB4;
	DDRB |= 1 << PORTB5;

}

int main(void)
{
	// Never forget to cal the init function if you have it :)
	init();

	while (1)
	{
		if (flag == 1)
		{
			PORTB |= 1 << PORTB1;
			PORTB |= 1 << PORTB3;
			PORTB |= 1 << PORTB4;
			PORTB |= 1 << PORTB5;
		}else{
		PORTB |= 1 << PORTB1;
		PORTB &= ~(1<< PORTB3);
		PORTB &= ~(1<< PORTB4);
		PORTB &= ~(1<< PORTB5);
		_delay_ms(200);
		PORTB |= 1 << PORTB3;
		PORTB |= 1 << PORTB4;
		PORTB |= 1 << PORTB5;
		PORTB &= ~(1<< PORTB1);
		_delay_ms(200);
		}
	}
}