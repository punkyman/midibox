#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <VS1053.h>
#include "hardware.h"

LiquidCrystal_I2C lcd(ADDR_I2C_LCD,16,2); 
VS1053 vs1053(PIN_AUDIO_XCS, PIN_AUDIO_XDCS, PIN_AUDIO_DREQ, PIN_AUDIO_XRESET);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print("prout");
}

void loop() {
  // put your main code here, to run repeatedly:
}