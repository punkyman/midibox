#include "display.h"
#include "pins.h"

#include <LiquidCrystal_I2C.h>

#define LCD_NUM_COLS 16
#define LCD_NUM_ROWS 2

char ScreenBuffer[(LCD_NUM_COLS * LCD_NUM_ROWS) + 1];

LiquidCrystal_I2C lcd(ADDR_I2C_LCD, LCD_NUM_COLS, LCD_NUM_ROWS);

void Display::Init()
{
    lcd.init();
    lcd.backlight();
    lcd.leftToRight();
}

void Display::Clear()
{
    lcd.clear();
}

void Display::PrintLn(const char *str)
{
    size_t length = strlen_P(str);

    lcd.setCursor(0, 0);
    lcd.print(str);

    if (length > LCD_NUM_COLS)
    {
        lcd.setCursor(0, 1);
        lcd.print(str[LCD_NUM_COLS]);
    }
}

void Display::PrintLn_P(const char *str)
{
    size_t length = strlen_P(str);

    lcd.setCursor(0, 0);
    lcd.print((const __FlashStringHelper *)str);

    if (length > LCD_NUM_COLS)
    {
        lcd.setCursor(0, 1);
        lcd.print((const __FlashStringHelper *)&str[LCD_NUM_COLS]);
    }
}
