#include "ESPControl.h"

int senderNo = 0;
String path = "nothing";

int buttonPin[4] = {D1,D2, D3,D4};
int ledPin[4] = {D5, D6, D7, D8};
String message;

void setup() {
  Serial.begin(9600);
  start("KJACT Smartbro", "bd8e4d538dfa993960152da646");
  for(int a = 0; a < 4; a++){
    pinMode(buttonPin[a], INPUT_PULLUP);
    pinMode(ledPin[a], OUTPUT);
  }
}

void loop()
{
  if (CheckNewReq() == 1)
  {
    path = getPath();
    path.remove(0, 1);   //Remove slash /
    message = "SOS/<NodeMCU" + path + ">";
    Serial.println(message);
    senderNo = path.toInt();
    digitalWrite(ledPin[senderNo - 1], HIGH);
  }
  for(int b = 0; b < 4; b++){
    if(digitalRead(buttonPin[b]) == 0){
      digitalWrite(ledPin[b], LOW);
    }
  }
}
