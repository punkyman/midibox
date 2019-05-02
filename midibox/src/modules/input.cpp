#include "input.h"
#include <Arduino.h>
#include "hardware.h"

void Input::Init()
{
    pinMode(PIN_INPUT_UP    , INPUT_PULLUP);
    pinMode(PIN_INPUT_DOWN  , INPUT_PULLUP);
    pinMode(PIN_INPUT_LEFT  , INPUT_PULLUP);
    pinMode(PIN_INPUT_RIGHT , INPUT_PULLUP);
    pinMode(PIN_INPUT_MIDDLE, INPUT_PULLUP);
    pinMode(PIN_INPUT_SET   , INPUT_PULLUP);
}
