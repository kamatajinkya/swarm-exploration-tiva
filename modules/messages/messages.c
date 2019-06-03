/*
 * messages.c
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */

#include "messages.h"
#include "modules/logging/logging.h"

Msg_MessegeTypeHelpers messageTypeHelpers[MSG_NUM_MESSAGETYPES] =
{

};

long message_serialize(const void* msg, Msg_MessageType type, long maxStrLen, char* str)
{
    long strLen;
    message_serializeStatus status = messageTypeHelpers[type].serialize(msg, maxStrLen, str, &maxStrLen);

    if(status == message_serializeStatusNotEnoughSpace)
    {
        return -1;
    }

    return strlen;
}

Msg_MessageType message_deserialize(const char* str, long strlen, void* msg)
{
    Msg_MessageType type;
    type = messageTypeHelpers[type].deserialize(str, strlen, maxMsgSize, msg);

    if(status == message_deserializeMalformedString)
    {
        return 0;
    }

    return type;
}
