// Servo Motor Control using PWM (ESP32)

#include <ESP32Servo.h>  // Include servo library for ESP32
#define servoPin 2  // Servo control pin connected to GPIO2

byte pos = 0;   // Variable to store servo position (0–180 degrees)
Servo myservo;  // Create servo object

void setup() {
  // Allocate a timer for PWM (required by ESP32Servo library)
  ESP32PWM::allocateTimer(0);
  // Set PWM frequency to 50 Hz (standard for servos)
  myservo.setPeriodHertz(50);
  // Attach servo to pin with pulse width range (500–2400 µs)
  // These limits define the 0° and 180° positions for most servos
  myservo.attach(servoPin, 500, 2400);
}

void loop() {
  // Sweep servo from 0° to 180°
  for (pos = 0; pos <= 180; pos++) {
    myservo.write(pos);  // Move servo to current angle
    delay(15);           // Small delay for smooth motion
  }
  // Sweep servo back from 180° to 0°
  for (pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(15);
  }
}
