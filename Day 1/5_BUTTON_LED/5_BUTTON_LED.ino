// Controlling LED through Button
// This program turns an LED ON when the button is pressed,
// and turns it OFF when the button is released.

#define led 2  // LED connected to digital pin 2
#define btn 4  // Push button connected to digital pin 4

void setup() {
  Serial.begin(9600);    // Initialize serial communication at 9600 baud rate
  pinMode(led, OUTPUT);  // Set LED pin as output
  pinMode(btn, INPUT);   // Set button pin as input
}

void loop() {

  byte btnState = digitalRead(btn);                // Read the current state of the button (HIGH or LOW)
  Serial.printf("Button State = %d\n", btnState);  // Print the button state to Serial Monitor

  // Check if button is pressed (active LOW configuration)
  if (btnState == LOW) {
    digitalWrite(led, HIGH);  // Turn LED ON
    Serial.println("LED ON");
  } else {
    digitalWrite(led, LOW);  // Turn LED OFF
    Serial.println("LED OFF");
  }
}
