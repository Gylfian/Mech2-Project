/*
 * movement.c
 *
 *  Created on: 1. apr. 2018
 *      Author: Gylfi
 */

#include "movement.h"

void walk()
{
	if (walker == 0 || walker == 2)
	{
		OCR0A = 22;
		delay_ms(100);
		OCR0A = 30;
		delay_ms(100);
	}
	else
	{
		OCR0A = 30;
		delay_ms(100);
		OCR0A = 22;
		delay_ms(100);
	}
}

void sit() //
{
	 walker = 2;
	 OCR0A = 16;
	 delay_ms(300);
	 walker = 3;
	 OCR0A = 40;
	 delay_ms(300);
	 state = SITTING;
}

void stand_up()
{
	 walker = 0;
	 OCR0A = 14;
	 delay_ms(500);
	 walker = 1;
	 OCR0A = 46;
	 delay_ms(500);
	 walker = 2;
	 OCR0A = 30;
	 delay_ms(500);
	 walker = 3;
	 OCR0A = 22;
	 delay_ms(500);
	 walker = 0;
	 OCR0A = 30;
	 delay_ms(500);
	 walker = 1;
	 OCR0A = 22;
	 delay_ms(500);
	 state = STANDING;

}

void lie_down()
{
	 walker = 2;
	 OCR0A = 48;
	 delay_ms(500);
	 walker = 3;
	 OCR0A =14;
	 delay_ms(500);

	 walker = 1;
	 OCR0A = 48;
	 delay_ms(500);
	 walker = 0;
	 OCR0A =14;
	 delay_ms(500);
}

void hump()
{
	 lie_down();
	 for(unsigned int i = 0; i < 30; i++)
	 {
		walker = 2;
		OCR0A = 44;
		delay_ms(200);
		OCR0A = 48;
		delay_ms(200);
		walker = 3;
		OCR0A =18;
		delay_ms(200);
		OCR0A = 14;
		delay_ms(200);
	 }
	 stand_up();
}

