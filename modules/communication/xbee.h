/*
 * xbee.h
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */

#ifndef MODULES_COMMUNICATION_XBEE_H_
#define MODULES_COMMUNICATION_XBEE_H_

typedef enum{
    xbee_initStatusSuccess = 0,
    xbee_initStatusFailed = -1
}xbee_initStatus;

typedef struct{
    //TOSO: Add config as needed
}xbee_initConfig;
xbee_initStatus xbee_init(xbee_initConfig config);


typedef enum{
    xbee_enqueueTransmitStatusSuccess = 0,
    xbee_enqueueTransmitStatusBufferOverflow = -1,
}xbee_enqueueTransmitStatus;
xbee_enqueueTransmitStatus xbee_enqueueTransmit(const char* str, long strlen, long deviceID);

typedef enum{
    xbee_dequeueRecievedStatusSuccess = 0,
    xbee_dequeueRecievedStatusNoDataAvailable = 1,
    xbee_dequeueRecievedStatusFailed = -1
}xbee_dequeueRecievedStatus;
xbee_dequeueRecievedStatus xbee_dequeueRecieved(long strlen, )

void xbee_isr();

#endif /* MODULES_COMMUNICATION_XBEE_H_ */
