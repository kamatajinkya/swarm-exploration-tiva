/*
 * irc.h
 *
 *  Created on: May 25, 2019
 *      Author: kamat
 *
 *  This module deals with the interrobot communication. It stores the messages to
 *  be sent to other robots and publishs them when ever the bus is free.
 *  This module is agnostic to the under lying hardware
 *
 */

#ifndef MODULES_COMMUNICATION_IRC_H_
#define MODULES_COMMUNICATION_IRC_H_

#include <stdint.h>
#include <stdlib.h>

#include "hardware/comms/serialDriver.h"
#include "modules/messages/message.h"
#include "modules/messages/messageTimestamp.h"

typedef unsigned int IRC_RobotID;

#define IRC_MAX_ROBOTS 8

typedef enum{
    IRC_initStatusSuccessful = 0,
    IRC_initStatusFailed = -1,
}IRC_initStatus;

typedef struct{
}IRC_initConfig;

IRC_initStatus IRC_init(IRC_initConfig config);

typedef enum{
    IRC_publishStatusSuccessful = 0,
    IRC_publishStatusFailed = -1,
    IRC_publishStatusBufferOverflow = -4,
    IRC_publishStatusPreviousMsgPending = -6,
    IRC_publishStatusRobotIDInvalid = -7
}IRC_publishStatus;
IRC_publishStatus IRC_publishCurrentTime(IRC_RobotID robotID, msg_Timestamp timestamp);

//Todo: Implement similar functions for other new types

typedef enum{
    IRC_recieveStatusNoDataAvailable = 1,
    IRC_recieveStatusSuccessful = 0,
    IRC_recieveStatusFailed = -1,
    IRC_recieveStatusRobotIDInvalid = -2
}IRC_recieveStatus;
IRC_recieveStatus IRC_getLastRecievedTime(IRC_RobotID robotID, msg_Timestamp* timestamp);

void IRC_publisherRun();
void IRC_recieverRun();

#endif /* MODULES_COMMUNICATION_IRC_H_ */
