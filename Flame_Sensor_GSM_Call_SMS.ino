#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4);

const int flamePin = 2;

void setup() {
  pinMode(flamePin, INPUT);
  mySerial.begin(9600);
}

void loop() {
  if (digitalRead(flamePin) == HIGH) {
    mySerial.println("Flame detected!");
    delay(1000); // wait for 1 second
    mySerial.println("Calling...");
    mySerial.println("ATD+9176955432;"); // replace with your phone number
    delay(1000); // wait for 1 second before hanging up
    mySerial.println("ATH"); // hang up the call
  }
  delay(1000); // wait for 1 second before detecting the flame again
}
