#pragma once
#include "midimessage.h"

namespace Midi
{
    void Init();
    bool Available();
    Message Read();

    void PrintMessage(Message msg);
} // namespace Midi
