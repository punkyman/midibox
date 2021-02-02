#pragma once
#include <midimessage.h>

namespace Midi
{
    void Init();
    bool Available();
    MidiMessage::Message Read();
} // namespace Midi
