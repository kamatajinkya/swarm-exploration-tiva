/*
 * wheelOdom.c
 *
 *  Created on: May 27, 2019
 *      Author: Ajinkya Kamat
 */

#include <math.h>
#include <modules/odom/naiveWheelOdom.h>
#include "hardware/robot.h"

#define NAIVEWHEELODOM_NUM_PREVIOUS_READINGS_TO_CONSIDER 10

static struct{
    synchronisedEncoders_readings enoderReadings[NAIVEWHEELODOM_NUM_PREVIOUS_READINGS_TO_CONSIDER];
    SensorDriverInterface driver;
    Pose2D lastKnownPose;
}module;

Pose2D naiveWheelOdom_Update()
{
    size_t numReadings = module.driver.peek(NAIVEWHEELODOM_NUM_PREVIOUS_READINGS_TO_CONSIDER,
                                            (sensorBufferAddress)&module.enoderReadings);

    size_t i;
    for(i = 0; i < numReadings; i++)
    {
        Pose2D updatedPose;
        float deltaTime;

        updatedPose.timestamp = module.enoderReadings[i].timestamp;
        deltaTime = (updatedPose.timestamp - module.lastKnownPose.timestamp)*10000000.0;

        float linearVelocity = 0.5*(module.enoderReadings[i].speedList[EncoderWheelID_right]
                               + module.enoderReadings[i].speedList[EncoderWheelID_left]);
        float angularVelocity = (module.enoderReadings[i].speedList[EncoderWheelID_right]
                               + module.enoderReadings[i].speedList[EncoderWheelID_left])/robot.wheel_to_wheel_distance;

        updatedPose.x = module.lastKnownPose.x + deltaTime*linearVelocity*cos(module.lastKnownPose.alpha);
        updatedPose.y = module.lastKnownPose.y + deltaTime*linearVelocity*sin(module.lastKnownPose.alpha);
        updatedPose.alpha = module.lastKnownPose.alpha + angularVelocity*deltaTime;

        module.lastKnownPose = updatedPose;
    }

    return module.lastKnownPose;
}
