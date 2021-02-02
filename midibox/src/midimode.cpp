#include "midimode.h"
#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include <instrumentname.h>

int8_t scrolls = 0;
bool click = false;

int8_t instrument = 0;


void MidiSetup()
{
    Audio::MidiMode();
}

void MidiLoop()
{
  while (Midi::Available())
  {
    MidiMessage::Message msg = Midi::Read();
    MidiMessage::Print(msg);

    Audio::MidiProcess(msg);
  }

  Input::Read(&scrolls, &click);
  if (scrolls != 0)
  {
    instrument += scrolls;
    if (instrument < 0)
      instrument += 128;
    instrument %= 128;

    Display::Clear();
    Display::PrintLn_P(InstrumentName(instrument));
    Audio::MidiSetInstrument(0, instrument);
  }
}