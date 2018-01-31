/*
 * main.c
 *
 *  Created on: 12. jan. 2018
 *      Author: Gylfi
 */

#include <avr/io.h>
#include <util/delay.h>
#include <print.h>

int main ( )
{
	DDRB=0x20 ;
	USARTInit();
	char c = 85;
	while ( 1 )
	{

		uart_putchar(c);
		/*
		PORTB=0x20 ;
		_delay_ms(1000);
		PORTB=0;
		_delay_ms(1000);
		int check = TCNT0;
		printf(check);
		printf(" test\n");
		*/
		//TCCR1B |= 1<<CS10;

	}
	return 0 ;
}
