#include <Arduino.h>


#define REDLEDPIN 9
#define GREENLEDPIN 11
#define BLUELEDPIN 10

void setup() {
  pinMode(REDLEDPIN,OUTPUT);
  pinMode(GREENLEDPIN,OUTPUT);
  pinMode(BLUELEDPIN,OUTPUT);

}


void ShowColorWheelPos(byte WheelPos ) {
  uint8_t Red = 0;
  uint8_t Green = 0;
  uint8_t Blue = 0;

  if (WheelPos < 85) {
    Red = WheelPos*3;
    Green = (255-WheelPos*3);
    Blue = 0;    
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    Red = (255-WheelPos)*3;
    Green = 0;
    Blue = WheelPos *3;    
  } else {
    WheelPos -= 170;
    Red = 0;
    Green = WheelPos *3;
    Blue = (255-WheelPos*3);
  }

  analogWrite(REDLEDPIN,Red);
  analogWrite(GREENLEDPIN,Green);
  analogWrite(BLUELEDPIN,Blue);

}


void loop() {
   uint8_t value = 0;
  
  while(value < 256)
  {
    
    value ++;
    ShowColorWheelPos(value);
    delay(10);
  }
  digitalWrite(REDLEDPIN,LOW);
  delay(1000);
}



