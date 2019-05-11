#pragma once
#include <Arduino.h>

namespace Storage
{
    void Init();

    uint8_t PopulateFilesFromDirectory(const char* directory);
    uint8_t GetFilesNumber();
    const String& GetFileName(uint8_t fileNumber);
}