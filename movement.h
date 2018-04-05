/*
 * movement.h
 *
 *  Created on: 1. apr. 2018
 *      Author: Gylfi
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include <avr/io.h>

extern int walker;
extern int state;

#define LEG_NUM 4
#define STANDING 0
#define SITTING 1
#define LIYING 3
#define SAMPLE_SIZE 5

void sit();
void lie_down();
void stand_up();
void hump();
void walk();

#endif /* MOVEMENT_H_ */
