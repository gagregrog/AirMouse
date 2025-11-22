#include "am/mpu.h"

#ifdef USE_LSM6DS3
LSM6DS3 imu(I2C_MODE, 0x6A); // I2C device address 0x6A

void mpuInit(void) {
  if (imu.begin() != 0) {
    Serial.println("Failed to find LSM6DS3");
    while (1) {
      delay(10);
    }
  }

  Serial.println("Found LSM6DS3");
}

void mpuRead(mpu_reading_t *reading) {
    float yaw = imu.readFloatGyroZ() + MPU_CALIBRATION_OFFSET_YAW;
    float pitch = imu.readFloatGyroX() + MPU_CALIBRATION_OFFSET_PITCH;

    reading->pitch = pitch;
    reading->yaw = yaw;
};

#endif
