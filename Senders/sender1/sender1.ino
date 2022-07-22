#include "ESP_MICRO.h"

// Preparations for hold button
unsigned long currentMillis;
int prevState = LOW;
unsigned long currTime;
bool longPressed = false;
const int intervalReading = 50;
unsigned long prevTime;
unsigned long totalDuration;

bool sendSOS = false; // Sends SOS to the base
const int senderNo = 1;

// Digital I/O pins
const int buttonPin = D1, led1 = D2, led2 = D3; // EDIT

void longPress(int buttonPin, unsigned long durationPeriod){
  
  if(currentMillis - prevTime > intervalReading){
    int buttonState = digitalRead(buttonPin);
    
    if(buttonState == HIGH && prevState == LOW && !longPressed){ // Button pressed
      currTime = currentMillis;
      prevState = HIGH;
      digitalWrite(LED_BUILTIN, LOW);
    }
    
    totalDuration = currentMillis - currTime;
    if(buttonState == HIGH && !longPressed && totalDuration >= durationPeriod){ // Long pressing button
      longPressed = true;  
      digitalWrite(LED_BUILTIN, HIGH);
      sendSOS = true;
    }

    if(buttonState == LOW && prevState == HIGH){ // Button is released after long press
      prevState = LOW;
      longPressed = false;
      digitalWrite(LED_BUILTIN, HIGH);
    }
    prevTime = currentMillis;
  }
}
  

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  start("KJACT Smartbro", "bd8e4d538dfa993960152da646"); //EDIT
}

void loop() {
  currentMillis = millis();
  longPress(buttonPin, 3000);
  if(sendSOS){
    waitUntilNewReq();
    returnThisInt(senderNo);
    sendSOS = false;
    Serial.println("SOS has been sent to local server!");
    
    for(int a = 0; a < 5; a++){ // Blinks the led alternately
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      delay(500);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(500);
    }
  }
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}
