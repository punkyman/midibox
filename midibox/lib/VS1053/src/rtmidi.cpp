#include "rtmidi.h"

const char* RtMidi::BankName(uint8_t number)
{
    if(number > 127)
        return PSTR("UNKNOWN BANK");

    return BANKNAMES[number];
}
