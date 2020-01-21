/*
  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/
#include <Wire.h>

//めも
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/*
相手はとりあえず[slave_receiver]で動作確認
*/
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//自作変数
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//キャンディごとに指定するデバイスナンバー
const int mydevice_number = 8;
//工場出荷時に絵文字を登録するところ
const String EMOJI[8] = {
  ":triumph:",":rage:",":angry:",":face_with_symbols_on_mouth:",":smiling_imp:",
  ":imp:",":skull:",":skull_and_crossbones:"
};
String hoge = "fuga";

//左右トグルで絵文字を選択するときの操作変数
int pos_cnt = 5000;
//操作変数を絵文字配列に対応させるために5で割る
int pos_emoji = pos_cnt%5;
////キャンディのactive(絵文字選択状態)がtrue
//boolean candy_act = false;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

// These constants won't change. They're used to give names to the pins used:
const int analogInPin_X = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin_Y = A1;  // Analog input pin that the potentiometer is attached to

int sensorValue_X = 0;        // value read from the pot
int outputValue_X = 0;        // value output to the PWM (analog out)
int sensorValue_Y = 0;        // value read from the pot
int outputValue_Y = 0;        // value output to the PWM (analog out)



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  // 読み取り
  // read the analog in value:
  sensorValue_X = analogRead(analogInPin_X);
  // map it to the range of the analog out:
  outputValue_X = map(sensorValue_X, 0, 1023, 0, 255);
  sensorValue_Y = analogRead(analogInPin_Y);
  outputValue_Y = map(sensorValue_Y, 0, 1023, 0, 255);

  // 選択画面時のみカウントが動く
  if (outputValue_Y < 20){
    if (outputValue_X > 70){
      pos_cnt = pos_cnt+1;
    };
    if (outputValue_X < 20){
      pos_cnt = pos_cnt-1;
    };
    pos_emoji = pos_cnt%5;
  }

  // print the results to the Serial Monitor:
  // 選択画面の場合
  if (outputValue_Y < 20){
    // シリアルモニタに表示
    Serial.print("I am ");
    Serial.print(mydevice_number);
    Serial.print("\n");
//    Serial.print("output_X = ");
//    Serial.print(outputValue_X);
    Serial.print("emoji_X = ");
    Serial.println(pos_emoji);
  //  Serial.print("\t output_Y = ");
  //  Serial.println(outputValue_Y);
  };
  // 確定送信の場合
  if (outputValue_Y > 80){
    // シリアルモニタに表示
    Serial.print("\n");
    Serial.print("I am ");
    Serial.print(mydevice_number);
    Serial.print("\n");
    Serial.print("NOW emoji is ...");
    Serial.println(EMOJI[pos_emoji]);
    // i2cで送信
    Wire.beginTransmission(8); // transmit to device #8
//    Wire.write("emoji");        // sends five bytes
    Wire.print(EMOJI[pos_emoji]);
    Wire.write(pos_emoji);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  };


  // 絵文字選択速度はここで調整
  delay(300);
}
