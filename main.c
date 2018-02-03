/*
 * main.c
 *
 *  Created on: 12. jan. 2018
 *      Author: Gylfi
 */

#include <avr/io.h>
#include <util/delay.h>
#include "print.h"

int main ( )
{
	DDRD |= 0xFF;
	TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0;
	TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10;
	ICR1 = 50000;
	OCR1A = ICR1 - 8000; //18000

	while (1)
	{

	}
	/*
	USARTInit();
	stdout = &mystdout ;

	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12;
	TIMSK1 |= 1<<OCIE1A; //If using atmega324, this regester is TIMSK1
	OCR1A = 15624;
	while(1)
	{
		printf("%d \n", TCNT1);
	}
	*/
	/*
	DDRB=0x20;
	USARTInit();
	stdout = &mystdout ;

	while ( 1 )
	{
		PORTB=0x20 ;
		_delay_ms(100);
		PORTB=0;
		_delay_ms(100);
		int check = TCNT0;
		printf("%d \n", check);
		TCNT0++;
	}
	*/
	return 0 ;
}
