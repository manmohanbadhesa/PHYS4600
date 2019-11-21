/*
 * task9.c
 *
 * Created: 2019-11-14 11:41:03 AM
 * Author : Manmo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect)
{
	PORTD ^= (1<<PD3);
}

ISR(TIMER0_COMPA_vect)
{
	PORTD ^= (1<<PD3);
}

void loop()
{

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