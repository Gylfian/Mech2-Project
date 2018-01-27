/*
 * main.c
 *
 *  Created on: 12. jan. 2018
 *      Author: Gylfi
 */

#include <avr/io.h>
#include <util/delay.h>

void move_servo_ccw(int servo)
{
	DDRB = servo;
	for(int i = 0; i < 500; i++ )
	{
		PORTB = servo;
		my_delay (i);
		PORTB=0;
		my_delay(1000-i);
	}
}

void move_servo_cw()
{
	int iDutyCycle = 50;
	DDRB=0x04 ;
	for(int i = 0; i < 1000; i++ )
	{
		PORTB = 0x00 ;
		my_delay ( iDutyCycle ) ;
		PORTB=04;
		my_delay(100-iDutyCycle);
	}
}

void my_delay ( int i )
{
	int j ;
	for ( j =0; j<i ; j++)
		asm( "nop" ) ;
}

int main ()
{

	DDRB = 0x20;
	while ( 1 )
	{
		move_servo_ccw(0x04);
	}

	return 0 ;
}
