#include <Arduino.h>
#include "Adafruit_TinyUSB.h"
// Apparently if you don't include the Adafruit_TinyUSB.h header you don't get Serial
// and you won't be able to find the device as an upload port at /dev/tty.usbmodem1453xxxx
// If you find yourself in this situation, double tap the teeny tiny reset button on the board
// (to the right of the USB-C if it is facing you) to get the board to enter bootloader mode,
// then begin the upload and double tap reset _again_
