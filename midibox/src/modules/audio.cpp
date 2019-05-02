#include "audio.h"
#include "hardware.h"
#include <VS1053.h>

VS1053 vs1053(PIN_AUDIO_XCS, PIN_AUDIO_XDCS, PIN_AUDIO_DREQ, PIN_AUDIO_XRESET);

void Audio::Init()
{
    vs1053.begin();
}
