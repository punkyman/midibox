#include "midi.h"
#include <Arduino.h>

void Midi::Init()
{
    Serial.begin(31250);
}