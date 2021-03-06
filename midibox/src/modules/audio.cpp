#include "audio.h"
#include "pins.h"
#include <SPI.h>
#include <VS1053.h>
#include <rtmidi.h>

VS1053 vs1053(PIN_AUDIO_XCS, PIN_AUDIO_XDCS, PIN_AUDIO_DREQ, PIN_AUDIO_XRESET);
RtMidi midi(vs1053);

uint8_t volume = 0x7f;

void Audio::Init()
{
    pinMode(PIN_AUDIO_SDCARD_CS,OUTPUT);
    digitalWrite(PIN_AUDIO_SDCARD_CS,HIGH);

    SPI.begin();
}

void Audio::MidiMode()
{
    vs1053.begin();
    midi.begin();
}

void Audio::DataMode()
{
    vs1053.begin();
}

void Audio::SetVolume(uint8_t volume)
{
    vs1053.setVolume(volume);
}

void Audio::MidiSetInstrument(uint8_t channel, uint8_t instrument)
{
    midi.selectInstrument(channel, instrument);
}


int Audio::MidiProcess(MidiMessage::Message msg)
{
    uint8_t control;

    switch(msg.info.infos.id)
    {
        case MidiMessage::MessageType::NOTE_ON:
            midi.noteOn(msg.info.infos.channel, msg.data1.infos.value, volume);
            return 0;
        case MidiMessage::MessageType::NOTE_OFF:
            midi.noteOff(msg.info.infos.channel, msg.data1.infos.value);
            return 0;
        case MidiMessage::MessageType::PITCH_BEND:
            midi.pitchBend(msg.info.infos.channel, msg.data1.infos.value, msg.data2.infos.value);
            return 0;
        case MidiMessage::MessageType::CONTROL_CHANGE:
            control = msg.data1.infos.value;
            if(control == 1) // mod wheel
            {
                midi.setReverbLevel(msg.info.infos.channel, msg.data2.infos.value);
                return 0;
            }
            else if(control == 64) // sustain pedal
            {
                midi.setSustainLevel(msg.info.infos.channel, msg.data2.infos.value);
                return 0;
            }
            else
                return -1;
        default:
            return -1;
    }
}
