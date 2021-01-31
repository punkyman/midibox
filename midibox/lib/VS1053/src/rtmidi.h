#pragma once

#include <Arduino.h>
#include "VS1053.h"
#include "rtmidistart_plg.h"

namespace Bank
{
    enum MIDI_BANK
    {
        DEFAULT_BANK = 0,
        DRUMS_1 = 0x78,
        DRUMS_2 = 0x7F,
        MELODIC = 0x79,
    };
}

/**
   * Play real-time MIDI.  Useful for using the VS1053 to make an
   * instrument.  Note that this implementation uses the SDI for
   * rtmidi commands.
   */
class RtMidi
{
private:
    VS1053 &player;
    uint8_t buffer[6];

protected:
    /**
     * Write a single MIDI command out via SDI
     *
     * @param a First value (command byte)
     * @param b Second value (operand byte)
     * @param c Third value (optional 2nd operand)
     */
    void write(uint8_t a, uint8_t b, uint8_t c = 0)
    {
        buffer[1] = a;
        buffer[3] = b;
        buffer[5] = c;
        player.playChunk(buffer, sizeof(buffer));
    }

public:

    /**
     * Construct from a VS1053 player
     *
     * @param _player Player which will play the MIDI notes
     */
    RtMidi(VS1053 &_player) : player(_player)
    {
        memset(buffer, 0, 6);
    }
    /**
     * Enable the real-time MIDI mode.  Only call this when you now want
     * to send rtmidi, not raw music data
     */
    void begin(void)
    {
        player.loadUserCode(rtmidi_plugin, RTMIDI_PLUGIN_SIZE);
    }
    /**
     * Begin playing a note
     *
     * @param channel Which channel to play on
     * @param note Which note to play
     * @param volume How loud
     */
    void noteOn(uint8_t channel, uint8_t note, uint8_t volume)
    {
        write(channel | 0x90, note, volume);
    }
    /**
     * Stop playing a note
     *
     * @param channel Which channel to afffect 
     * @param note Which note to stop
     */
    void noteOff(uint8_t channel, uint8_t note)
    {
        write(channel | 0x80, note, 0x45);
    }

    /**
     * Stop playing a note
     *
     * @param channel Which channel to afffect 
     * @param note Which note to stop
     */
    void pitchBend(uint8_t channel, uint8_t low, uint8_t high)
    {
        write(channel | 0xE0, low, high);
    }

    void selectInstrument(uint8_t channel, uint8_t instrument)
    {
        write(0xC0 | channel, instrument);
    }

    void selectBank(uint8_t channel, uint8_t bank)
    {
        write(0xB0 | channel, 0, bank);
    }

    void setGlobalReverbDecay(uint8_t value)
    {
        write(0xB0, 0x0C, value);
    }

    void setReverbLevel(uint8_t channel, uint8_t value)
    {
        write(0xB0 | channel, 0x5B, value);
    }
};
