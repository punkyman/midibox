#pragma once

#include <VS1053.h>

namespace Audio
{
    void Init();

    void SetVolume(uint8_t volume);

    void MidiDrumMode();
    void MidiNoteOn(uint8_t channel, uint8_t note);
    void MidiNoteOff(uint8_t channel, uint8_t note);
}
