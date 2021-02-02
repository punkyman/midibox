#pragma once
#include <Arduino.h>

// midi interface https://www.arduino.cc/en/tutorial/midi
// uses serial component, no special pins required

const uint8_t PIN_INPUT_CLK = 7;
const uint8_t PIN_INPUT_DATA = 8;
const uint8_t PIN_INPUT_SW = 9;

// display component http://wiki.sunfounder.cc/index.php?title=I%C2%B2C_LCD1602
const uint8_t ADDR_I2C_LCD = 0x27;

// audio component http://www.geeetech.com/wiki/index.php/VS1053_MP3_breakout_board_with_SD_card
const uint8_t PIN_AUDIO_SDCARD_CS = 10; // for VS1053 / sd selection
const uint8_t PIN_AUDIO_XCS = 18;
const uint8_t PIN_AUDIO_XRESET = 19;
const uint8_t PIN_AUDIO_XDCS = 20;
const uint8_t PIN_AUDIO_DREQ = 21;