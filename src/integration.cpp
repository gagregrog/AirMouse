#include "am/integration.h"

void logReading(float yaw, float pitch, float mov_h, float mov_v);

void readAndMove(void) {
  mpu_reading_t reading;
  mpuRead(&reading);

  float mov_h = reading.yaw * -MOUSE_MULTIPLIER_H;
  float mov_v = reading.pitch * MOUSE_MULTIPLIER_V;

  if (abs(reading.yaw) > 0 || abs(reading.pitch) > 0) {
    logReading(reading.yaw, reading.pitch, mov_h, mov_v);
  }

  bleMove(mov_h, mov_v);
}

void logReading(float yaw, float pitch, float mov_h, float mov_v) {
  Serial.print("yaw: ");
  Serial.print(yaw);
  Serial.print(" -> ");
  Serial.print(mov_h);
  Serial.print("  --  pitch: ");
  Serial.print(pitch);
  Serial.print(" -> ");
  Serial.println(mov_v);
}
