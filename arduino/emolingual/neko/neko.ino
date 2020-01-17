// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

#include "Keyboard.h"
const int rowNum = 2;
const int colNum = 2;
const int rowPin[rowNum] = { 3, 4 };
const int colPin[colNum] = { 5, 6 };
const byte keyMap[rowNum][colNum] = {
 { 0x61, 0x62 },
 { 0x63, 0x64 }
};
bool currentState[rowNum][colNum];
bool beforeState[rowNum][colNum];
int i,j;
byte hoge;


void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event

  for( i = 0; i < rowNum; i++){
  pinMode(rowPin[i],OUTPUT);
  }
  for( i = 0; i < colNum; i++){
  pinMode(colPin[i],INPUT);
  }
  for( i = 0; i < rowNum; i++){
  for( j = 0; j < colNum; j++){
  currentState[i][j] = LOW;
  beforeState[i][j] = LOW;
  }
  digitalWrite(rowPin[i],LOW);
  }
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for( i = 0; i < rowNum; i++){
  digitalWrite( rowPin[i], HIGH );
  for( j = 0; j < colNum; j++){
  currentState[i][j] = digitalRead(colPin[j]);
  if ( currentState[i][j] != beforeState[i][j] ){
  Serial.print("key(");
  Serial.print(i);
  Serial.print(",");
  Serial.print(j);
  Serial.print(")");
  if ( currentState[i][j] == HIGH){
  Serial.println(" Push!");
//  Keyboard.press( keyMap[i][j] );
  hoge = keyMap[i][j];
  } else {
  Serial.println(" Release!");
//  Keyboard.release( keyMap[i][j] );
  hoge = keyMap[i][j];
  }
  beforeState[i][j] = currentState[i][j];
  }
  }
  digitalWrite( rowPin[i], LOW );
  }

  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(hoge); // respond with message of 6 bytes
}
