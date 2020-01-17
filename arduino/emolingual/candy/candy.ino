// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

//自作変数
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//工場出荷時に絵文字を登録するところ
const String EMOJI[5] = {"lya","lya","lyu","lya","lyo"};
//左右トグルで絵文字を選択するときの操作変数
int pos_cnt = 0;
//操作変数を絵文字配列に対応させるために5で割る
int pos_emoji = pos_cnt%5;
//キャンディのactive(絵文字選択状態)がtrue
boolean candy_act = false;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//アナログスティック 0:x, 1:y
int stick[2];

int FlickDirection() {
  int d;
   stick[0] = analogRead(A1);
  stick[1] = analogRead(A0);

  if(stick[1] >= 700){
    d = 2;
  } else if(stick[1] <= 300){
    d = 4;
  }else if(stick[0] <= 300){
    d = 1;
  }else if(stick[0] >= 700){
    d = 3;
  }else{
    d = 0;
  }
  return d;
}


void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
}
