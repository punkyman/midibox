#include "rtmidi.h"

const char* RtMidi::InstrumentName(uint8_t number)
{
    if(number > 127)
        return PSTR("UNKNOWN BANK");

    return INSTRUMENT_NAMES[number];
}
