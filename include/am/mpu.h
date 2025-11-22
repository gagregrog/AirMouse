#include "am/core.h"
#include "am/config.h"
#include <Adafruit_MPU6050.h>

#pragma once

#ifndef AirMouseMpu_h
#define AirMouseMpu_h

struct mpu_reading_t {
  float pitch;
  float yaw;
};

void mpuInit(void);
void mpuRead(mpu_reading_t *reading);

#endif
