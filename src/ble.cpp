#include "am/ble.h"

BLEHidAdafruit blehid;   // HID device (mouse, keyboard, media keys)

void bleInit(void) {
  Bluefruit.begin();
  
  // BLE General
  Bluefruit.setName("XiaoMouse");
  Bluefruit.setTxPower(4);   // optional, stronger signal

  // Configure HID
  blehid.begin();

  // Advertising
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_MOUSE);
  Bluefruit.Advertising.addService(blehid);

  Bluefruit.Advertising.start(0); // forever
  Serial.println("BLE HID Mouse ready!");
}

void blePressLeft(void) {
  if (Bluefruit.connected()) {
    blehid.mouseButtonPress(MOUSE_BUTTON_LEFT);
  }
}

void bleReleaseLeft(void) {
  if (Bluefruit.connected()) {
    blehid.mouseButtonRelease(MOUSE_BUTTON_LEFT);
  }
}

void blePressRight(void) {
  if (Bluefruit.connected()) {
    blehid.mouseButtonPress(MOUSE_BUTTON_RIGHT);
  }
}

void bleReleaseRight(void) {
  if (Bluefruit.connected()) {
    blehid.mouseButtonRelease(MOUSE_BUTTON_RIGHT);
  }
}

void bleMove(float mov_h, float mov_v) {
  if (Bluefruit.connected()) {
    blehid.mouseMove(mov_h, mov_v);
  }
}
