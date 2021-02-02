#pragma once

#include <Arduino.h>
#include <midimessage.h>

namespace Audio
{
    void Init();

    void MidiMode();
    void DataMode();

    void SetVolume(uint8_t volume);

    void MidiSetInstrument(uint8_t channel, uint8_t instrument);
    int MidiProcess(MidiMessage::Message msg);
}
