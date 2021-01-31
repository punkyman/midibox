#pragma once

#include <Arduino.h>
#include "VS1053.h"
#include "rtmidistart_plg.h"

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
    static const char* const INSTRUMENT_NAMES[];

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

    /**
     * Choose the drums instrument
     *
     * @param channel Which channel to play the drums on
     */
    void selectDrums(uint8_t channel)
    {
        write(0xB0 | channel, 0, 0x78);
        write(0xC0 | channel, 30);
    }

    void selectInstrument(uint8_t channel, uint8_t instrument)
    {
        write(0xC0 | channel, instrument);
       
    }

    static const char* InstrumentName(uint8_t number);
};
