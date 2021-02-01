#pragma once

#include <Arduino.h>
#include "midimessage.h"

namespace Audio
{
    void Init();

    void SetVolume(uint8_t volume);
    void SetInstrument(uint8_t channel, uint8_t instrument);

    int Process(Midi::Message msg);
}
