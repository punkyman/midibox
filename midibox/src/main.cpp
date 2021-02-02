#include <Arduino.h>
#include <MemoryFree.h>

#include "hardware.h"
#include "midimode.h"

void setup()
{
  HardwareInit();
  MidiSetup();
}

void loop()
{
  MidiLoop();
}
