#pragma once

#include <Arduino.h>
#include "VS1053.h"
#include "rtmidistart_plg.h"

namespace Bank
{

    // The standard banks are 0x79 and 0x78, but some MIDI songs seem to use bank number 0x7f for drums. The default bank depends on the channel number. Channel 10 defaults to percussion/drum bank, the other channels default to melodic.

    // So, if you send Bank Select (HI) with:
    // - 0 gives you the default bank depending on the channel. (0x78 for Channel 10, 0x79 for other channels.)
    // - 0x7f is mapped to 0x78.
    // - 0x78 and 0x79 give drum or melodic, respectively.
    // - other values are ignored.

    // Any channel can be melodic or drum bank. A lot of MIDI songs use two drum channels.

    // Changing the bank of a channel does not affect notes that are already playing on the channel, so if you switch between melodic and drum bank, a single channel can have both playing at the same time.

    enum MIDI_BANK
    {
        DEFAULT_BANK = 0,
        DRUMS_1 = 0x78,
        DRUMS_2 = 0x7F,
        MELODIC = 0x79,
    };
} // namespace Bank

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
    void write(uint8_t a, uint8_t b, uint8_t c)
    {
        buffer[1] = a;
        buffer[3] = b;
        buffer[5] = c;
        player.playChunk(buffer, sizeof(buffer));
    }

    void write(uint8_t a, uint8_t b)
    {
        buffer[1] = a;
        buffer[3] = b;
        player.playChunk(buffer, 4);
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
        write(0xE0 | channel, low, high);
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

    void setSustainLevel(uint8_t channel, uint8_t value)
    {
        write(0xB0 | channel, 0x40, value);
    }
};
