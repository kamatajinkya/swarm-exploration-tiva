/*
 * irc.c
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */




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
