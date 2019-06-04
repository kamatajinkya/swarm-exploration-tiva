/*
 * sensors.h
 *
 *  Created on: May 26, 2019
 *      Author: kamat
 */

#ifndef MODULE_SENSOR_SENSORDRIVER_H_
#define MODULE_SENSOR_SENSORDRIVER_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char* sensorBufferAddress;

typedef size_t (*sensorPopReadings) (size_t, sensorBufferAddress buffer);
typedef size_t (*sensorPeekReadings) (size_t, sensorBufferAddress buffer);

typedef struct{
    sensorPopReadings pop;
    sensorPeekReadings peek;
}SensorDriverInterface;

#endif /* MODULE_SENSOR_SENSORDRIVER_H_ */
