#include <Arduino.h>

#define LEDPIN 11

void setup() {
  pinMode(LEDPIN,OUTPUT);
}

void loop() {
  uint8_t value = 0;
  
  while(value < 256)
  {
    analogWrite(LEDPIN,value);
    value ++;
    delay(10);
  }
  digitalWrite(LEDPIN,LOW);
  delay(1000);
}