#include "input.h"
#include <Arduino.h>
#include "pins.h"
#include <encoder.h>

void Input::Init()
{
    encoder_init(PIN_INPUT_CLK, PIN_INPUT_DATA, PIN_INPUT_SW);
}

void Input::Read(int8_t* scrolls, bool* click)
{
    encoder_read_values();
    *scrolls = encoder_scrolls;
    *click = encoder_switch;
    encoder_clear_readings();
}