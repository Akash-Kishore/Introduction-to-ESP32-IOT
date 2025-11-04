
// Blink LED for every 1 second

// Define the pin number where the LED is connected
#define led 2  // 'led' is now a constant representing digital pin 2

void setup() {
  pinMode(led, OUTPUT);  // Configure the LED pin as an OUTPUT so we can control it (turn ON or OFF)
}

void loop() {

  digitalWrite(led, HIGH);  // Turn the LED ON by setting the voltage on the pin to HIGH (3.3V)
  delay(1000);              // Wait for 1000 milliseconds (1 second)
  digitalWrite(led, LOW);   // Turn the LED OFF by setting the voltage on the pin to LOW (0V)
  delay(1000);              // Wait for another 1000 milliseconds (1 second)
}
