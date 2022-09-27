#include <Arduino.h>

/*
  "StAuth10184: I Jesse Em, 000295218 certify that this material is my original work. 
  No other person's work has been used without due acknowledgement. 
  I have not made my work available to anyone else."
*/

static bool isOn = false;

void setup() {

  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 

  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // set default PWM range 
  analogWriteRange(1023); 
}

void loop() {

  //store the input variables
  int iVal = analogRead(A0);
  int iButton = digitalRead(D5);   

  //if the button is pressed, and the state is set to OFF
  if (iButton == LOW && isOn == false) {
    isOn = true;
  } 
  //if the button is pressed, and the state is set to ON
  else if (iButton == LOW && isOn == true) {
    isOn = false;
  }

  //if the state is OFF, ensure the LED is off
  if (!isOn) {
    digitalWrite(D4, HIGH);
  } 
  //if the state is ON, turn on the LED according to the variable resistor
  else {
    analogWrite(D4, iVal); 
  }

delay(1);
}