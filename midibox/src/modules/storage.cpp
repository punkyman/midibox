#include "storage.h"
#include <SD.h>
#include <SPI.h>
#include "pins.h"

String* files = nullptr;
uint8_t filesNumber = 0;
String emptyFile;

uint8_t countFiles(const char* directory)
{
  File root = SD.open(directory);
  uint8_t count = 0;
  File entry;

  while(entry = root.openNextFile())
  {
    if(!entry.isDirectory())
      ++count;
    entry.close();
  }

  root.close();
  return count;
}

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

void Storage::Init()
{
  SD.begin(SPI_CLOCK_DIV16 /* 1MHZ */ , PIN_AUDIO_SDCARD_CS);
}

uint8_t Storage::GetFilesNumber()
{
  return filesNumber;
}

const String& Storage::GetFileName(uint8_t fileNumber)
{
  if(fileNumber > filesNumber)
    return emptyFile;

  return files[fileNumber];
}

uint8_t Storage::PopulateFilesFromDirectory(const char* directory)
{
  if(files != nullptr)
  {
    delete[] files;
    filesNumber = 0;
  }
  
  uint8_t count = countFiles(directory);
  if(count == 0)
    return 0;

  files = new String[count];

  File root = SD.open(directory);
  File entry;

  while(entry = root.openNextFile())
  {
    if(!entry.isDirectory())
    {
      files[filesNumber] = entry.name();
      ++filesNumber;
    }  
    entry.close();
  }
//  assert( filesNumber == count );

  return filesNumber;
}
