#pragma once

#include <Arduino.h>

namespace Input
{
    void Init();
    void Read(int8_t* scrolls, bool* click);
}
