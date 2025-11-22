#include "am/mpu.h"

#ifdef USE_MPU6050
bool sleepMPU = true;
Adafruit_MPU6050 mpu;

void mpuInit(void) {
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050");
    while (1) {
      delay(10);
    }
  }

  Serial.println("Found MPU6050");

  // Sleep MPU until bluetooth is connected
  mpu.enableSleep(sleepMPU);
}

void mpuAwake(void) {
  if (sleepMPU) {
    Serial.println("Waking MPU6050...");
    delay(3000);
    sleepMPU = false;
    mpu.enableSleep(false);
    delay(500);
  }
}

void mpuRead(mpu_reading_t *reading) {
    mpuAwake();

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    float yaw = g.gyro.z + MPU_CALIBRATION_OFFSET_YAW;
    float pitch = g.gyro.x + MPU_CALIBRATION_OFFSET_PITCH;

    reading->pitch = pitch;
    reading->yaw = yaw;
};

#endif
