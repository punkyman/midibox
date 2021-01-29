#include <Arduino.h>
#include "console.h"

int myPutc(char c, FILE *t)
{
  Serial.write(c);
}

void Console::Init()
{
  delay(1000); // let time for the serial of pio to connect
  Serial.begin(9600);
  fdevopen(&myPutc, 0); // support for printf style output
}
