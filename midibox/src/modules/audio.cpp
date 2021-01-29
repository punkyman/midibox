#include "audio.h"
#include "hardware.h"
#include <SPI.h>

VS1053 vs1053(PIN_AUDIO_XCS, PIN_AUDIO_XDCS, PIN_AUDIO_DREQ, PIN_AUDIO_XRESET);
VS1053::RtMidi midi(vs1053);

uint8_t volume = 0x7f;

void Audio::Init()
{
    pinMode(PIN_AUDIO_SDCARD_CS,OUTPUT);
    digitalWrite(PIN_AUDIO_SDCARD_CS,HIGH);

    SPI.begin();
    vs1053.begin();
    midi.begin();
}

void Audio::SetVolume(uint8_t volume)
{
    vs1053.setVolume(volume);
}

void Audio::MidiDrumMode()
{
    midi.selectDrums(0);
}

void Audio::MidiNoteOn(uint8_t channel, uint8_t note)
{
    midi.noteOn(channel, note, volume);
}

void Audio::MidiNoteOff(uint8_t channel, uint8_t note)
{
    midi.noteOff(channel, note);
}
