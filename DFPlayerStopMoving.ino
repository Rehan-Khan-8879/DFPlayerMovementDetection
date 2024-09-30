#include "Arduino.h"                                             //libarary
#include "DFRobotDFPlayerMini.h"                                 //libarary
#include <SoftwareSerial.h>                                       //libarary

#define sensor 12           // connecting sensor to pin 12 of arduino 

int sensor_value = 0;       //creating variable to store value of sensor

SoftwareSerial mySerial(2,3);        //Creating my own TX and RX pin in this case RX is 2 and TX is 3
DFRobotDFPlayerMini myPlayer;        //Creating the player 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           //Begin the serial communication for Serial monitor
  mySerial.begin(9600);          //Begin the Serial communication for DFPlaye mini
  myPlayer.begin(mySerial);          // Connecting audio player to mySerial

  pinMode(sensor,INPUT);             //Defining the pinMode of pin which sensor is connected

  myPlayer.volume(30);               // setting the volume for 
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
