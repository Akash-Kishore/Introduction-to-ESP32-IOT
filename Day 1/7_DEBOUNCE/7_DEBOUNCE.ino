// Turn ON and OFF LED with the same button using debounce delay
// This program toggles the LED state (ON/OFF) each time the button is pressed.
// A simple 200ms delay is used to prevent false triggers caused by button bounce.

#define led 2     // LED connected to digital pin 2
#define button 4  // Push button connected to digital pin 4

byte ledState = 0;  // Variable to store current LED state (0 = OFF, 1 = ON)
byte buttonState;   // Variable to store current reading from the button

void setup() {
  // Configure pin modes
  pinMode(led, OUTPUT);    // LED as output
  pinMode(button, INPUT);  // Button as input with internal pull-up resistor
}

void loop() {
  buttonState = digitalRead(button);  // Read the current state of the button

  // Check for a button press event (state changed from HIGH → LOW)
  if (buttonState == 0) {
    delay(200);  // Debounce delay: ignore small fluctuations from mechanical bounce

    // Toggle LED state
    ledState = !ledState;         // If LED was ON, turn it OFF; if OFF, turn it ON
    digitalWrite(led, ledState);  // Update the LED output
  }
}
