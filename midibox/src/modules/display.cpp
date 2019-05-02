#include "display.h"
#include "hardware.h"

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(ADDR_I2C_LCD,16,2); 

void Display::Init()
{
    lcd.init();
    lcd.backlight();
    lcd.write("prout");
}
