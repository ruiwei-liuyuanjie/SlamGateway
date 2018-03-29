/*
 * Slam.h
 *
 *  Created on: 2018年3月29日
 *      Author: xd
 */

#ifndef SLAM_H_
#define SLAM_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <string>
#include <vector>
#include <cstdint>
#include "rpos/rpos.h"
#include "rpos/robot_platforms/slamware_core_platform.h"
#include "rpos/features/location_provider/map.h"
#include "config.h"
#include "utils.h"
#include "mqtt_wrap.h"
#include "String.h"
#include "cJSON.h"
using namespace std;
using namespace rpos::core;
using namespace rpos::robot_platforms;
using namespace rpos::features;
using namespace rpos::features::location_provider;

class Slam {
	SlamwareCorePlatform mSdp;
	String mIp;
	uint16_t mPort;
	int mIndex;
	bool mSlamConnect = false;
	bool mAlive = false;
public:
	Slam(int index, String ip, uint16_t port);
	void nbConnect(int timeout);	//非阻塞链接
	bool isConnect();
};

#endif /* SLAM_H_ */
