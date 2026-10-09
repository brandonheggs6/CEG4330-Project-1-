#include <Arduino.h>
#define LED_PIN 2
#define BUTTON_PIN 0

long microSecOn;
long lastFlip = 0;
bool currState = false;
void setup()
{
  // Open up serial communication to display debug info
  Serial.begin(9600); // Baud rate is 9600 to communicate via COM on Windows

  // Set the onboard LED pin to be an output
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  microSecOn = micros();
  // Write to the serial monitor the status of the LED and turn the LED on  (active low)
  if (digitalRead(BUTTON_PIN)){//while button is held down
    if (currState){
      if (microSecOn > (lastFlip + 1000) )
      {
        digitalWrite(LED_PIN, LOW);
        lastFlip = micros();//update last state
        currState = false;//reset current state
        //Serial.write("case 1");
      }
    }
    else {
      if (microSecOn > (lastFlip + 3000) )
      {
        digitalWrite(LED_PIN, HIGH);
        lastFlip = micros();//update last state
        currState = true;//reset current state
        //Serial.write("case 2");
      }
    }
  }
  else{
    if (currState){
      if (microSecOn > (lastFlip + 3000) )
      {
        digitalWrite(LED_PIN, LOW);
        lastFlip = micros();//update last state
        currState = false;//reset current state
        //Serial.write("case 3");
      }
    }
    else {
      if (microSecOn > (lastFlip + 1000) )
      {
        digitalWrite(LED_PIN, HIGH);
        lastFlip = micros();//update last state
        currState = true;//reset current state
        //Serial.write("case 4");
      }
    }
  }
}