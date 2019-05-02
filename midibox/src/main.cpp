#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <VS1053.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print("prout");
}

void loop() {
  // put your main code here, to run repeatedly:
}