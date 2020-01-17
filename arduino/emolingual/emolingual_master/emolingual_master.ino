// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <string.h>
#include <stdio.h>

const int buttonPin01 = 7;     // the number of the pushbutton pin
const int buttonPin02 = 8;     // the number of the pushbutton pin

void setup() {
  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
//  HIGHのときだけよみとる
  while (digitalRead(buttonPin01) == HIGH){
  Wire.requestFrom(8, 4);    // request 4 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  
  delay(500);
  }

//  HIGHのときだけよみとる
  while (digitalRead(buttonPin02) == HIGH){
  Wire.requestFrom(2, 4);    // request 4 bytes from slave device #2

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  
  delay(500);
  }

}
