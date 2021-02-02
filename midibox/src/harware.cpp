#include "hardware.h"

#include "modules/audio.h"
#include "modules/display.h"
#include "modules/midi.h"
#include "modules/input.h"
#include "modules/storage.h"
#include "modules/console.h"

void HardwareInit()
{
  Console::Init();
  Display::Init();
  Midi::Init();
  Input::Init();
  //  Storage::Init();

  Audio::Init();
}