// Blink LED and Buzzer Alternately Every 1 Second
// This program turns ON the LED while the buzzer is OFF,
// then swaps states every second — creating an alternating blink-beep effect.

// Define pin numbers
#define led 2     // LED connected to digital pin 2
#define buzzer 4  // Buzzer connected to digital pin 4

void setup() {
  pinMode(led, OUTPUT);     // Set LED pin as output
  pinMode(buzzer, OUTPUT);  // Set Buzzer pin as output
}

void loop() {
  // Turn ON LED and OFF buzzer
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, LOW);
  delay(1000);  // Wait 1 second

  // Turn OFF LED and ON buzzer
  digitalWrite(led, LOW);
  digitalWrite(buzzer, HIGH);
  delay(1000);  // Wait 1 second
}
