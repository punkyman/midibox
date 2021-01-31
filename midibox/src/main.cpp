#include <Arduino.h>
#include <MemoryFree.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"
#include "modules/console.h"

void setup()
{
  Console::Init();
  Audio::Init();
  //  Display::Init();
  Midi::Init();
  //  Input::Init();
  //  Storage::Init();
}

void loop()
{
  while (Midi::Available())
  {
    Midi::Message msg = Midi::Read();
    Midi::PrintMessage(msg);

    Audio::Process(msg);
  }
}
