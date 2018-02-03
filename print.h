/*
 * print.h
 *
 *  Created on: 31. jan. 2018
 *      Author: Gylfi
 */

#ifndef PRINT_H_
#define PRINT_H_

#include <stdio.h>


void USARTInit ();
int uart_putchar(char c, FILE * stream);
FILE mystdout = FDEV_SETUP_STREAM( uart_putchar , NULL,_FDEV_SETUP_WRITE) ;

#endif /* PRINT_H_ */
