/*
 * synchronisedEncoders.h
 *
 *  Created on: May 26, 2019
 *      Author: kamat
 */

#ifndef HARDWARE_SENSOR_ENCODER_SYNCHRONISEDENCODERS_H_
#define HARDWARE_SENSOR_ENCODER_SYNCHRONISEDENCODERS_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "module/device/timer.h"

#include "encoder.h"

#define SYNCHRONISEDENCODERS_MAX_NUM_ENCODERS 2

typedef struct{
    Microseconds timestamp;
    encoder_Speed speedList[SYNCHRONISEDENCODERS_MAX_NUM_ENCODERS];
    size_t numEncoders;
}synchronisedEncoders_readings;


void synchronisedEncoders_init();

void synchronisedEncoders_isr();

#endif /* HARDWARE_SENSOR_ENCODER_SYNCHRONISEDENCODERS_H_ */
