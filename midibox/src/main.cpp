#include <Arduino.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"

void setup()
{
  Audio::Init();
  Display::Init();
  Midi::Init();
  Input::Init();
}

void loop()
{
}