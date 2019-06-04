/*
 * robot.h
 *
 *  Created on: May 26, 2019
 *      Author: kamat
 */

#ifndef MODULE_ROBOT_H_
#define MODULE_ROBOT_H_

typedef enum {
    EncoderWheelID_left = 0,
    EncoderWheelID_right = 1
}robot_EndcoderWheelID;

typedef struct{
    float wheel_to_wheel_distance;
}robot_Desctiption;

extern robot_Desctiption robot;

#endif /* MODULE_ROBOT_H_ */
