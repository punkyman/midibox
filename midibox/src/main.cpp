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

    if(msg.info.infos.id == Midi::MessageType::NOTE_ON)
      Audio::MidiNoteOn(0, msg.data1.infos.value);
    else if(msg.info.infos.id == Midi::MessageType::NOTE_OFF)
      Audio::MidiNoteOff(0, msg.data1.infos.value);
  }
}
