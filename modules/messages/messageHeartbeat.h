/*
 * messageTimestamp.h
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */

#ifndef MODULES_MESSAGES_MESSAGEHEARTBEAT_H_
#define MODULES_MESSAGES_MESSAGEHEARTBEAT_H_

#include "messageType.h"

typedef struct{
    unsigned long beatNumber;
}msg_Heartbeat;



#endif /* MODULES_MESSAGES_MESSAGEHEARTBEAT_H_ */
