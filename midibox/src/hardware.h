#pragma once
#include <Arduino.h>

// midi interface https://www.arduino.cc/en/tutorial/midi
// uses serial component, no special pins required

// input component https://www.aliexpress.com/item/Five-Direction-Navigation-Button-Module-Diy-Electronic-PCB-Board-MCU-AVR-Game-5D-Rocker-Joystick-Independent/32879111530.html
const uint8_t PIN_INPUT_UP = 4;
const uint8_t PIN_INPUT_DOWN = 5;
const uint8_t PIN_INPUT_LEFT = 6;
const uint8_t PIN_INPUT_RIGHT = 7;
const uint8_t PIN_INPUT_MIDDLE = 8;
const uint8_t PIN_INPUT_SET = 9;

// display component http://wiki.sunfounder.cc/index.php?title=I%C2%B2C_LCD1602
const uint8_t ADDR_I2C_LCD = 0x27;

// audio component http://www.geeetech.com/wiki/index.php/VS1053_MP3_breakout_board_with_SD_card
const uint8_t PIN_AUDIO_CS = 10; // for VS1053 / sd selection
const uint8_t PIN_AUDIO_XCS = 18;
const uint8_t PIN_AUDIO_XRESET = 19;
const uint8_t PIN_AUDIO_XDCS = 20;
const uint8_t PIN_AUDIO_DREQ = 21;
