/*
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"
#include <Wire.h>


void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  delay(100);  
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    Keyboard.print(c);
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
//  Keyboard.print(' ');
  Keyboard.print("\0");   // 終端記号「\0」を送信
}
