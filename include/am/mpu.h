#pragma once

#ifndef AirMouseMpu_h
#define AirMouseMpu_h

#include "am/core.h"
#include "am/config.h"

// Shared interface - same for all sensor implementations
struct mpu_reading_t {
  float pitch;
  float yaw;
};

void mpuInit(void);
void mpuRead(mpu_reading_t *reading);

// Sensor-specific includes (for implementation files only)
#ifdef USE_MPU6050
    #include <Adafruit_MPU6050.h>
#endif

#ifdef USE_LSM6DS3
    #include "LSM6DS3.h"
#endif

#endif
