#include <SoftwareSerial.h>

SoftwareSerial SIM900A(10, 11);  

int flameSensor = 2;  
int flameDetected = 0;
String phoneNo = "+919361450307";  
void setup() {
  Serial.begin(9600);
  SIM900A.begin(9600);
  delay(1000);
  Serial.println("SIM900A is ready");
  Serial.println("Fire alert system ready");
}

void loop() {
  flameDetected = digitalRead(flameSensor); 
  if (flameDetected == LOW) {
    Serial.println("Flame detected");
    delay(1000);  
    call();
  }
}

void call() {
  delay(1000);
  SIM900A.println("ATD" + phoneNo + ";");  
  delay(50000);  
  SIM900A.println("ATH");   
  Serial.println("Call ended");
}
