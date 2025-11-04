// Reading Potentiometer Value

#define pot 34   // Potentiometer connected to analog pin 34 (input only)

void setup() {
  Serial.begin(9600);   // Start serial communication at 9600 baud
  pinMode(pot, INPUT);  // Set potentiometer pin as input
}

void loop() {
  // Read analog value from potentiometer
  int potValue = analogRead(pot);  // ESP32 ADC range: 0 - 4095 (12-bit resolution)

  // Print the value to Serial Monitor
  Serial.println(potValue);

  delay(200);  // Small delay for readability (prints ~5 times per second)
}
