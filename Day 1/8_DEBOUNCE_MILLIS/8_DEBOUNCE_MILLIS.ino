// Multi-State Button LED Control (with debounce using delay)
// -----------------------------------------------------------
// 1st press  → LED ON
// 2nd press  → LED blinks every 1000ms
// 3rd press  → LED blinks every 100ms
// 4th press  → LED OFF
// Then repeats in the same order

#define led 2
#define button 4

int ledState = LOW;            // Current LED output state (HIGH = ON, LOW = OFF)
int mode = 0;                  // 0=OFF, 1=ON, 2=blink 1000ms, 3=blink 100ms
unsigned long prevMillis = 0;  // Stores last time LED was toggled
int interval = 0;              // Time delay for blinking (in milliseconds)

void setup() {
  pinMode(led, OUTPUT);            // LED pin as output
  pinMode(button, INPUT);   // Button input with internal pull-up resistor

  Serial.begin(9600);
  Serial.println("Press button to change LED mode");
}

void loop() {
  // -------------------------------
  // Button handling with debounce
  // -------------------------------
  if (digitalRead(button) == LOW) {   // Button pressed (LOW because of pull-up)
    delay(200);                       // Simple debounce delay (filters noise)

    while (digitalRead(button) == LOW); // Wait until button is released
    // This ensures one full press is counted only once

    mode++;                 // Move to next mode each press
    if (mode > 3) mode = 0; // After 3, wrap back to 0 (repeat cycle)
  }

  // -------------------------------
  // LED behavior based on mode
  // -------------------------------
  unsigned long currentMillis = millis(); // Current time in milliseconds

  switch (mode) {
    case 0: // LED OFF
      digitalWrite(led, LOW);
      break;

    case 1: // LED ON
      digitalWrite(led, HIGH);
      break;

    case 2: // LED BLINK every 1000ms
      interval = 1000; // Set blink speed
      if (currentMillis - prevMillis >= interval) {
        prevMillis = currentMillis;   // Save current time
        ledState = !ledState;         // Toggle LED state
        digitalWrite(led, ledState);  // Apply LED state
      }
      break;

    case 3: // LED BLINK every 100ms
      interval = 100;  // Set faster blink speed
      if (currentMillis - prevMillis >= interval) {
        prevMillis = currentMillis;   // Save current time
        ledState = !ledState;         // Toggle LED state
        digitalWrite(led, ledState);  // Apply LED state
      }
      break;
  }
}
