#pragma once

#include <Arduino.h>
#include "midimessage.h"

namespace Audio
{
    void Init();

    void SetVolume(uint8_t volume);

    void MidiDrumMode();
    int Process(Midi::Message msg);
}
