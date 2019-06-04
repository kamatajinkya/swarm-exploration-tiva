/*
 * message.h
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */

#ifndef MODULES_MESSAGE_MESSAGE_H_
#define MODULES_MESSAGE_MESSAGE_H_

#include "messageType.h"

long message_serialize(const void* msg, Msg_MessageType type, long maxStrLen, char* str);

Msg_MessageType message_deserialize(const char* str, long strlen, long maxMsgSize, void* msg);


#endif /* MODULES_MESSAGE_MESSAGE_H_ */
