// Night Lamp using LDR and LED
// -----------------------------------------------------
// LED turns ON in darkness and OFF in light.
// Works on ESP32 using an LDR sensor connected to an ADC pin.

#define led 2     // LED pin (output)
#define ldr 34    // LDR connected to ADC pin

void setup() {
  Serial.begin(9600);     // Start serial communication
  pinMode(led, OUTPUT);   // Set LED pin as output
  pinMode(ldr, INPUT);    // LDR pin as analog input
}

void loop() {
  // Read the LDR sensor value
  short ldrData = analogRead(ldr);  // ESP32 ADC range: 0 - 4095

  // Print LDR reading to Serial Monitor
  Serial.printf("LDR Data = %d\n", ldrData);

  // If LDR value is low → dark, high → bright (depends on circuit)
  // You can adjust the threshold (e.g., 2000) depending on your LDR.
  if (ldrData > 2500) {   // Dark condition (less light)
    digitalWrite(led, HIGH);  // Turn LED ON
  } else {                // Bright condition (more light)
    digitalWrite(led, LOW);   // Turn LED OFF
  }

  delay(500);  // Wait half a second before next reading
}
