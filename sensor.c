/*
 * sensor.c
 *
 *  Created on: 25. mar. 2018
 *      Author: Gylfi
 */

#include "sensor.h"

int distance_measure()
{
	int dist = 0;
	int limit = 0;

	TCNT1=0;
	PORTC|=1<<PINC0;
	while(TCNT1<100);
	PORTC&=~(1<<PINC0);

	TCNT1=0;
	while ( !(PINC & (1 << PINC1)) && (TCNT1 < 30000));  // checking if echo has become high  and not exceeding the time for max range i.e 5 m
	limit = TCNT1;

	if(limit < 300000)
	{
		TCNT1=0;
		while(PINC&(1<<PINC1));    // waiting until the echo become low again
		dist =TCNT1/58;
	}
	delay_ms(20);
	return dist;

}

int distance_calc()
{
	int sum = 0;
	int dist = 0;
	for (int i = 0; i < SAMPLE_SIZE; i++)
	{
		dist = distance_measure();
		if(sum < dist)
		{
			sum = dist;
		}
	}

	return sum;
}

