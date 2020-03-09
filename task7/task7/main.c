/*
 * task7.c
 *
 * Created: 2019-11-07 12:16:43 PM
 * Author : Manmo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//LED on and off at the comparion value for time

uint8_t keep_going = 1;

//manual way of setting up interrupts

ISR(TIMER0_OVF_vect) 

{

	PORTD^= (1 << PD1);

}



ISR(TIMER0_COMPA_vect)

{

	PORTD^= (1 << PD1);

}




void setup()

{

	DDRB |= (1<<PD3); // Set as output pin
	
	//	TCCR0A= |= (1<<COM0A0) | (1<<COM0A1);
	PORTD &= ~(1<<PD3);  // Start pin as 0

	TCCR0B = 0x01; // Chooses normal mode with no clock prescaling
	TIMSK0 = 1;  // Enables timer 0 overflow interrupt

	OCR0A = 200; //Number that compares at that time

	sei();

}


int main()
{
	setup();
	while(1) loop();
}


















