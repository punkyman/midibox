#include <Arduino.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"

void setup()
{
  Audio::Init();
  Display::Init();
  Midi::Init();
  Input::Init();
  Storage::Init();
}

void loop()
{
}