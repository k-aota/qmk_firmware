// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

const int buttonPin = 7;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(buttonPin, INPUT);

  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  if (buttonState == HIGH) {
  Wire.write("b!"); // respond with message of 6 bytes
  // as expected by master
  }else{
  Wire.write("c!"); // respond with message of 6 bytes    
  }
}
