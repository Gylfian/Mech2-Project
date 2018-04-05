#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"

#define LEG_NUM 4
#define STANDING 0
#define SITTING 1
#define LIYING 3
#define SAMPLE_SIZE 5

int walker = 0;
int state = 0;
int trained = 0;
int best_sequence[4] = {1,2,3,0};

ISR (TIMER0_OVF_vect)
{
	switch(walker)
	{
	case 0:
		PORTB = 0b100000;
		break;
	case 1:
		PORTB = 0b010000;
		break;
	case 2:
		PORTB = 0b001000;
		break;
	case 3:
		PORTB = 0b000100;
		break;
	}
}

ISR (TIMER0_COMPA_vect)
{
	PORTB = 0x00;
}

ISR(PCINT0_vect)
{
	trained = 1;
	best_sequence[0] = 1;
	best_sequence[1] = 2;
	best_sequence[2] = 3;
	best_sequence[3] = 0;
}

/*
 * This is not an ANN!!!
 * The function just returns an array of all permutations of a 4-digit number
 * each digit goes from 0-3
 */
void ANN(int *walker_num[])
{
    int i,j,k,l;
    int counter = 0;
    for(i = 0; i < LEG_NUM; i++)
    {
        for(j = 0; j < LEG_NUM; j++)
        {
            for(k = 0; k < LEG_NUM; k++)
            {
                for(l = 0; l < LEG_NUM; l ++)
                {
                    if(!(i==j || i==k || i==l || j==k || j==l || k==l))
                    {
                        walker_num[counter] = i;
                        walker_num[counter+1] = j;
                        walker_num[counter+2] = k;
                        walker_num[counter+3] = l;
                        counter += 4;
                    }
                }
            }
        }
    }
}

int main()
{
	 DDRB = 0x3E; //set pins for servos
	 DDRC|=1<<PINC0; // set pins for sensor
	 TCCR1B|=1<<CS10;

	 //interrupt initialisation
	 OCR0A = 0; // range 6-48
	 TCCR0A = 0;
	 TCCR0B = 0x05;
	 TIMSK0 = 0x03;
	 TIFR0 = 0x03;
	 PCICR=0x1;
	 PCMSK0=0x1;
	 asm("sei");

	 int first_measurement = 0;
	 int second_measurement = 0;
	 int distance = 0;
	 int best_run = 0;
	 int run = 0;
	 int round = 0;
	 int walk_index = 0;
	 int walker_num[96];
	 ANN(&walker_num);

	 while(1)
	 {
		if(!trained)
		{
			if(round%4 == 0)
			{
				first_measurement = distance_measure();
			}

			walker = walker_num[round];
			walk();

			if(round%4 == 0)
			{
				second_measurement = distance_measure();
				run = second_measurement - first_measurement;
				if (run > best_run)
				{
					best_run = run;
					best_sequence[0] = walker_num[round-3];
					best_sequence[1] = walker_num[round-2];
					best_sequence[2] = walker_num[round-1];
					best_sequence[3] = walker_num[round];
				}
			}

			round++;
			if (round >= 96)
			{
				sit();
				delay_ms(5000);
				stand_up();
				trained = 1;
			}
		}
		else
		{
			walker = best_sequence[walk_index];
			walk();
			walk_index++;
			if(walk_index > 4) walk_index = 0;
			distance = distance_calc();
			if (distance <= 150)
			{
				distance = distance_calc();
				if (distance < 80)
				{
					hump();
				}
				else
				{
					sit();
					delay_ms(4000);
					stand_up();
				}

			}
		}
	 }

	 return 0;
}
