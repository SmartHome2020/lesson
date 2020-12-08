#include <Ultrasonic.h>
#define Trig 31
#define Echo 33
#include <Servo.h>
int led_pir = 24;
Servo servo;
void setup() {
  Serial.begin(9600);
  servo.attach(13);
  pinMode(led_pir, OUTPUT);
}

void loop() {
  servo.write(30);
  distance = ultrasonic.distanceRead();
  if (distance <= 10) {
    delay(2000);
    digitalWrite(led_pir, HIGH);
    tone(piezoPin, 1000);
    delay(500);
    tone(piezoPin, 500, 500);
    tone(piezoPin, 1000);
    delay(500);
  }
  else {
    noTone(piezoPin);
    digitalWrite(led_pir, LOW);
  }
}
