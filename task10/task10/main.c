/*
 * task10.c
 *
 * Created: 2019-11-21 11:14:21 AM
 * Author : Manmo
 */ 

#include <avr/io.h>


uint8_t lowbyte;
uint8_t highbyte;

//1011101101

ADCSRA |= (1<<ADSC);  //starts data collection

while(! ADCSRA & (1<<ADIF)); // loop until ADC completes


//ADMUX chooses input channel

//ADCSRA 

lowbyte =ADCL; // 00000000 11101101
highbyte = ADCH; // 00000000 00000010

unit16_t finalvalue;

finalvalue= (highbyte << 8) | lowbyte;


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

