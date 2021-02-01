#include <Arduino.h>
#include <MemoryFree.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"
#include "modules/console.h"

#include <instrumentname.h>

int8_t scrolls = 0;
bool click = false;

int8_t instrument = 0;

void setup()
{
  Console::Init();
  Audio::Init();
  //  Display::Init();
  Midi::Init();
  Input::Init();
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

  Input::Read(&scrolls, &click);
  if(scrolls != 0)
  {
    instrument += scrolls;
    if(instrument < 0)
      instrument += 128;
    instrument %= 128;

    printf_P(InstrumentName(instrument));
    Serial.println();
    Audio::SetInstrument(0, instrument);
  }
}
