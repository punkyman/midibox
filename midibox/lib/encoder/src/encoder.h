#pragma once
#include <Arduino.h>

#define INC_CW 0
#define INC_CCW 1

#define USE_CLICK_ENCODER
#define HARDWARE_STEPS 4
#define HARDWARE_INC INC_CCW

extern volatile int8_t encoder_scrolls;
extern bool encoder_switch;

void encoder_init(uint8_t clock_pin, uint8_t data_pin, uint8_t switch_pin);
void encoder_clear_readings();
void encoder_read_values();
