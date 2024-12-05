#include <Ultrasonic.h>

Ultrasonic ultrassom(7, 6);
const int buzzer = 3;
const int ledGreen = 13;
const int ledYellow = 11;
const int ledRed = 9;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void yellow(){
  tone(buzzer, 400, 400);
  delay(1000);
  tone(buzzer, 400, 600);
  delay(1000);
}

void red(){
  tone(buzzer, 400, 700);
  delay(100);
  tone(buzzer, 400, 900);
  delay(100);
}

void loop() {
  int distance_cm;

  distance_cm = ultrassom.distanceRead();

  if (distance_cm > 41) {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
  } else if (distance_cm <= 10 && distance_cm > 5) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
  } else if (distance_cm <= 5 && distance_cm > 4) {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    yellow(); 
  } else if (distance_cm <= 3) {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    red();
  }

  delay(100);
}
