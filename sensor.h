/*
 * sensor.h
 *
 *  Created on: 25. mar. 2018
 *      Author: Gylfi
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "sensor.h"
#include <avr/io.h>

#define LEG_NUM 4
#define STANDING 0
#define SITTING 1
#define LIYING 3
#define SAMPLE_SIZE 5


int distance_measure();
int distance_calc();


#endif /* SENSOR_H_ */
