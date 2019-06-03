/*
 * messages.h
 *
 *  Created on: May 25, 2019
 *      Author: kamat
 */

#ifndef MODULES_MESSAGE_MESSAGETYPE_H_
#define MODULES_MESSAGE_MESSAGETYPE_H_

typedef enum {
    MSG_MESSAGETYPE_NULL = 0,
    MSG_MESSAGETYPE_TIMESTAMP,
    //Add new msg types as you create them
    MSG_NUM_MESSAGETYPES
}Msg_MessageType;

Msg_MessageType Msg_getMsgTypeFromString(const char* data);

typedef enum{
    message_serializeStatusSuccess = 0,
    message_serializeStatusNotEnoughSpace = -1
}message_serializeStatus;

typedef enum{
    message_deserializeStatusSuccess = 0,
    message_deserializeStatusNotEnoughSpace = -1,
    message_deserializeMalformedString = -2
}message_deserializeStatus;

typedef struct {
    Msg_MessageType (*getMsgType)();
    message_serializeStatus (*serialize) (const void*, long, char*, long*);
    message_deserializeStatus (*deserialize)(const char*, long, long, void*);
}Msg_MessegeTypeHelpers;

#endif /* MODULES_MESSAGE_MESSAGETYPE_H_ */
