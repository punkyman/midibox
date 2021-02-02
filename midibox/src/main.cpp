#include <Arduino.h>
#include <MemoryFree.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"
#include "modules/console.h"

#include "midimode.h"

void setup()
{
  Console::Init();
  Display::Init();
  Midi::Init();
  Input::Init();
  //  Storage::Init();

  Audio::Init();

  MidiSetup();
}

void loop()
{
  MidiLoop();
}
