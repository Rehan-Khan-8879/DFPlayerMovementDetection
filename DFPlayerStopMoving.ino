#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

#define sensor 12

int sensor_value = 0;

SoftwareSerial mySerial(2,3);
DFRobotDFPlayerMini myPlayer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  myPlayer.begin(mySerial);

  pinMode(sensor,INPUT);

  myPlayer.volume(30);
  myPlayer.play(3);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor_value = digitalRead(sensor);
  Serial.println(sensor_value);
  if(sensor_value == 1){
    myPlayer.play(0002);
    delay(5000);
    
  } 
  else{}
  
}
