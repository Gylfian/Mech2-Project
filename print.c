/*
 * print.c
 *
 *  Created on: 31. jan. 2018
 *      Author: Gylfi
 */

#include<print.h>
#include <avr/io.h>
#include <stdio.h>


void USARTInit ( )
{
	UBRR0 = 103; // s e t baudrate ( here 9600 f o r arduino uno R3) 1/9600 = 104 microsec
	UCSR0C|=(1<<UCSZ00) |(1<<UCSZ01) ; //No parity , 8 b i t s , 1 stop b i t
	UCSR0B|=(1<<RXEN0) |(1<<TXEN0) ; // Enable The r e c e i v e r and t r a n s m i t t e r
}

int uart_putchar (char c, FILE * stream)
{
	while ( ! ( UCSR0A & (1<<UDRE0) ) )
		; // wait f o r ready
	UDR0 = c ; // send the char
	return 0 ;
}

