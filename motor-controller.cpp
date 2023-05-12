#include <Arduino.h>
#include "Servo.h"

class motorController {
  private:
    int potValue;  // value from the analog pin
    Servo ESC;     // create servo object to control the ESC
    unsigned long lastTime = 0;
    unsigned long currentTime = 0;

  public:
    void setupESC() {
    ESC.attach(D4,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
    }

    void updateSpeed() {
        potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
        potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
        ESC.write(potValue);
        Serial.println(potValue);
    }

    void writeMicroseconds(int value) {
      currentTime = micros();
      unsigned long loopTime = currentTime - lastTime;

      if (loopTime > 20000) { //only update if at rate of 50Hz (not to slow down whole code)
        lastTime = currentTime;
        ESC.writeMicroseconds(value);
      }
    }
};
