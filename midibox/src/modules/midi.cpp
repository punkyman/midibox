#include "midi.h"
#include <Arduino.h>

void Midi::Init()
{
    Serial1.begin(31250);
}