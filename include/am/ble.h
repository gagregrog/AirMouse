#include "am/core.h"
#include <bluefruit.h>

#pragma once

#ifndef AirMouseBLE_h
#define AirMouseBLE_h

void bleInit(void);
void blePressLeft(void);
void bleReleaseLeft(void);
void blePressRight(void);
void bleReleaseRight(void);
void bleMove(float mov_h, float mov_v);

#endif
