#include <SoftwareSerial.h>

SoftwareSerial SIM900A(10, 11);

int flameSensor = 2;
int flameDetected = 0;
int relayPin = 7;

String phoneNo = "+919361450307";

bool callOngoing = false; 

void setup() {
  Serial.begin(9600);
  SIM900A.begin(9600);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); 
  delay(1000);
  Serial.println("SIM900A is ready");
  Serial.println("Fire alert system ready");
}

void loop() {
  flameDetected = digitalRead(flameSensor);

  if (flameDetected == LOW) {
    Serial.println("Flame detected");

    digitalWrite(relayPin, LOW);

    callOngoing = true; 

    call(); // initiate call

  } else {
    if (callOngoing == false) { 
      digitalWrite(relayPin, HIGH); 
    }
  }
}

void call() {
  Serial.println("Calling...");

  SIM900A.println("ATD" + phoneNo + ";");
  delay(5000); 
  SIM900A.println("ATH");

  callOngoing = false;

  Serial.println("Call ended");
}
