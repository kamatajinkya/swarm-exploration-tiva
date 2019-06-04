/*
 * irc.c
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */
#include "irc.h"
#include "modules/common/circularbuffer.h"

#define IRC_HEARTBEAT_BUFFER_SIZE 1

static struct{
    msg_Heartbeat heartBeatTransmitBuffer[IRC_HEARTBEAT_BUFFER_SIZE];
    long heartBeatTransmitRobotIDBuffer[IRC_HEARTBEAT_BUFFER_SIZE];
    CircularBufferPtr heartBeatTransmitBufferPtr;

}module;

IRC_initStatus IRC_init(IRC_initConfig config)
{
    //Todo: Initialize all the data types
    return IRC_initStatusSuccessful;
}

/// This is a generic implementation of the send msg. Use this function to actually send the msg.
static IRC_sendStatus IRC_enqueueSend(IRC_RobotID robotID, const char* msg, size_t size)
{
    //TODO: Implement everything to notify zigbee that it is supposed to send the msg
    return IRC_sendStatusSuccessful;
}


static IRC_recieveStatus IRC_dequeueRecieve(IRC_RobotID robotID, IRC_ChannelID channelID, char* msg, size_t* size)
{
    //Todo: implement this
    return IRC_recieveStatusSuccessful;
}

IRC_publishStatus IRC_publishHeartBeat(IRC_RobotID robotID, msg_Heartbeat heartbeat)
{
    if(robotID > IRC_MAX_ROBOTS)
        return IRC_publishStatusRobotIDInvalid;

    long bufferLocation = circularBuffer_Push(&module.heartBeatTransmitBufferPtr);

    if(bufferLocation < -1)
        return IRC_publishStatusBufferOverflow;

    module.heartBeatTransmitBuffer[bufferLocation] = heartbeat;
    module.heartBeatTransmitRobotIDBuffer[bufferLocation] = robotID;

    return IRC_publishStatusSuccessful;
}

void IRC_publisherRun()
{
    //Todo: Check all the transmit buffer and convert the contents to xbee and start sending
}
void IRC_recieverRun()
{

}
