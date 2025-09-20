#include<LiquidCrystal.h>
LiquidCrystal LCD(11,10,9,2,3,4,5);

#define trigPin 13 // Trigger pin
#define echoPin 12 // Echo pin

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Target Distance:");
}

void loop() {
  long duration;
  float distance;

  // Trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to cm
  distance = (duration * 0.0343) / 2;

  LCD.setCursor(0,1);
  LCD.print("                "); // clear row
  LCD.setCursor(0,1);

  if (distance >= 2 && distance <= 400) {
    LCD.print(distance);
    LCD.print(" cm");
  } else {
    LCD.print("Out of range");
  }

  delay(250);
}
