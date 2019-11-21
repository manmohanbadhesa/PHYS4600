/*
 * task7.c
 *
 * Created: 2019-11-07 12:16:43 PM
 * Author : Manmo
 */ 

#include <avr/io.h>

void loop(){}


int main(void)
{
    /* Replace with your application code */
    
    
		TCNT0 =0;
		TCCR0B = (1<< CS00) | (1<<CS02);
		
	while (1)
	{
		while((TIFR0 & 1) == 0) ;
		PORTD ^= (1<< PD1);
		
    }
}









