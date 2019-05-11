#include <Arduino.h>
#include <MemoryFree.h>

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"

void setup()
{
  Serial.begin(9600);

//  Audio::Init();
  Display::Init();
  Midi::Init();
  Input::Init();
  Storage::Init();
}

void loop()
{
  Serial.println("prout");
  Storage::PopulateFilesFromDirectory("/");
  for(uint8_t i = 0; i < Storage::GetFilesNumber(); ++i)
  {
    Serial.println(Storage::GetFileName(i));
  }
  Serial.println(freeMemory());
}
