#pragma once

namespace MidiMessage
{
    namespace MessageType
    {
        enum MIDI_MESSAGE_TYPES
        {
            NOTE_OFF = 0b1000,
            NOTE_ON = 0b1001,
            POLY_AFTERTOUCH = 0b1010,
            CONTROL_CHANGE = 0b1011, // also called Channel mode
            PROGRAM_CHANGE = 0b1100,
            CHANNEL_AFTERTOUCH = 0b1101,
            PITCH_BEND = 0b1110,
            SYSTEM = 0b1111
        };
    }

    // byte accessors have to be declared in reverse order here (!)
    union MessageInfo
    {
        unsigned char data;
        struct
        {
            unsigned char channel : 4;
            unsigned char id : 4;
        } infos;
    };

    union MessageData
    {
        unsigned char data;
        struct
        {
            unsigned char value : 7;
            unsigned char padding : 1;
        } infos;
    };

    struct Message
    {
        MessageInfo info;
        MessageData data1;
        MessageData data2;
    };

    void Print(Message msg);
    int MessageLength(int message_type);
} // namespace Midi
