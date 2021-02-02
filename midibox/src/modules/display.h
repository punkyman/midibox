#pragma once
#include <Arduino.h>

namespace Display
{
    void Init();

    void Clear();

    void PrintLn(const char* str);

    void PrintLn(const __FlashStringHelper * str);
}