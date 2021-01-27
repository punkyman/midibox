#include <Arduino.h>
#include <MemoryFree.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"

void setup()
{
  Serial.begin(9600);

  //  Audio::Init();
  //  Display::Init();
  Midi::Init();
  //  Input::Init();
  //  Storage::Init();

  //  Serial.println("prout");
}

void loop()
{
  while (Midi::Available())
  {
    Midi::Message msg = Midi::Read();
    Midi::PrintMessage(msg);
  }
}
