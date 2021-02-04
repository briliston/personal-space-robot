#include "SR04.h"
#include "LedControl.h"
#define TRIG_PIN 7
#define ECHO_PIN 6
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;
LedControl lc=LedControl(12,10,11,1);

void setup() {
  Serial.begin(9600);
  delay(1000);
  lc.shutdown(0,false);
  //Set the brightness to a medium values
  lc.setIntensity(0,8);
  //and clear the display
  lc.clearDisplay(0);
}

void happy(){

  byte happy[8]={B00000000,B01100110,B01100110,B00000000,B01000010,B01000010,B00111100,B00000000};
  
  lc.setRow(0,0,happy[0]);
  lc.setRow(0,1,happy[1]);
  lc.setRow(0,2,happy[2]);
  lc.setRow(0,3,happy[3]);
  lc.setRow(0,4,happy[4]);
  lc.setRow(0,5,happy[5]);
  lc.setRow(0,6,happy[6]);
  lc.setRow(0,7,happy[7]);
}

void sad(){

  byte sad[8]={B00000000,B01100110,B01100110,B00000000,B00111100,B01000010,B01000010,B00000000};
  
  lc.setRow(0,0,sad[0]);
  lc.setRow(0,1,sad[1]);
  lc.setRow(0,2,sad[2]);
  lc.setRow(0,3,sad[3]);
  lc.setRow(0,4,sad[4]);
  lc.setRow(0,5,sad[5]);
  lc.setRow(0,6,sad[6]);
  lc.setRow(0,7,sad[7]);
}

void loop() {
  distance = sr04.Distance();
   Serial.print(distance);
   Serial.println("cm");
  if(distance < 100){
    sad();
    delay(1000);
  }
  else{
    happy();
    delay(1000);
  }
}
