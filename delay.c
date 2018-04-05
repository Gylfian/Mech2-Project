/*
 * delay.c
 *
 *  Created on: 7. feb. 2018
 *      Author: Gylfi
 */

void delay_ms (unsigned int uimS )
{
	unsigned volatile long ulMax , ulCount ;
	ulMax = 380 * uimS ;
	ulCount =0;
	while ( ulCount != ulMax ) {
		ulCount++;
	}
}

void delay_s (unsigned int uiS )
{
	unsigned volatile long ulMax , ulCount ;
	ulMax = 380000 * uiS ;
	ulCount =0;
	while ( ulCount != ulMax ) {
		ulCount++;
	}
}

void delay_us (unsigned int uiuS )
{
	unsigned volatile long ulMax , ulCount ;
	ulMax = 38 * uiuS ;
	ulCount =0;
	while ( ulCount != ulMax ) {
		ulCount++;
	}
}
