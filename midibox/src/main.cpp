#include <Arduino.h>

#include "modules/audio.h"
#include "modules/display.h"

void setup()
{
  Audio::Init();
  Display::Init();
}

void loop()
{
}