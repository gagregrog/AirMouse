#include "am/buttons.h"

EasierButton leftClick(LEFT_BUTTON_PIN);
EasierButton rightClick(RIGHT_BUTTON_PIN);

void buttonsInit(void) {
  leftClick.setOnPressed(blePressLeft);
  leftClick.setOnReleased(bleReleaseLeft);
  rightClick.setOnPressed(blePressRight);
  rightClick.setOnReleased(bleReleaseRight);

  leftClick.begin();
  rightClick.begin();
}

void buttonsLoop(void) {
  leftClick.update();
  rightClick.update();
}
