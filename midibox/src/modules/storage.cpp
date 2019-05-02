#include "storage.h"
#include <SD.h>
#include <SPI.h>
#include "hardware.h"

void Storage::Init()
{
    SD.begin(SPI_CLOCK_DIV16 /* 1MHZ */ , PIN_AUDIO_CS);
}
