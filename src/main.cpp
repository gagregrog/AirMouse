#include "am/core.h"
#include "am/mpu.h"
#include "am/ble.h"
#include "am/buttons.h"
#include "am/integration.h"

void readAndMove(void);

void setup(void)
{
  Serial.begin(115200);
  bleInit();
  delay(1000);
  mpuInit();
  buttonsInit();
}

void loop(void)
{
  buttonsLoop();
  readAndMove();
}

