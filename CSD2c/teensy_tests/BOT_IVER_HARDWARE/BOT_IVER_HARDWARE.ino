#include <Math.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

int prevState = LOW;


void setup() {
    Serial.begin(9600);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
}

void loop() {
  // update potmeters
    float pot1 = analogRead(A0) / 1023.;
    float pot2 = analogRead(A1) / 1023.;
    // update toggles
    int currState = digitalRead(2);
    if(currState != prevState){
      // A transition occurred (from pressed to released or from released to pressed)
      Serial.print("HOERTJE");
    }
    prevState = currState;
    Serial.print("POT1 = ");
    Serial.println(pot1);
    Serial.print("POT2 = ");
    Serial.println(pot2);
    delay(50);
}
