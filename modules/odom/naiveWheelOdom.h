/*
 * wheelOdom.h
 *
 *  Created on: May 26, 2019
 *      Author: kamat
 */

#ifndef MODULES_ODOM_NAIVEWHEELODOM_H_
#define MODULES_ODOM_NAIVEWHEELODOM_H_

#include "hardware/sensor/encoder/synchronisedEncoders.h"
#include "modules/Pose2D.h"

Pose2D naiveWheelOdom_Update();



#endif /* MODULES_ODOM_NAIVEWHEELODOM_H_ */
