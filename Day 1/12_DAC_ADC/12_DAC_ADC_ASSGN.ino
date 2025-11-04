// DAC to ADC Conversion on ESP32
// --------------------------------------------------------
// This program generates analog voltages using the DAC pin (GPIO26)
// and reads them back using an ADC pin (GPIO34).
// It then prints the ADC value and its equivalent voltage (in Volts).

#define dac 26   // DAC output pin (Only GPIO25 or GPIO26)
#define adc 34   // ADC input pin (use ADC-capable pins: 32–39)

void setup() {
  Serial.begin(9600);     // Initialize Serial Monitor
  pinMode(adc, INPUT);    // Set ADC pin as input
}

void loop() {
  // -------------------------
  // Increase DAC output (0 → 255)
  // -------------------------
  for (int i = 0; i <= 255; i++) {
    dacWrite(dac, i);                // Generate analog voltage (0–3.3V)
    delay(10);                       // Small delay for stabilization

    int adcValue = analogRead(adc);  // Read back the voltage
    float voltage = (adcValue / 4095.0) * 3.3; // Convert ADC value to voltage

    // Display results on Serial Monitor
    Serial.print("ADC Value: ");
    Serial.print(adcValue);
    Serial.print(" Voltage: ");
    Serial.print(voltage, 2);
    Serial.println(" V");

    delay(100);
  }

  // -------------------------
  // Decrease DAC output (255 → 0)
  // -------------------------
  for (int i = 255; i >= 0; i--) {
    dacWrite(dac, i);                // Generate analog voltage
    delay(10);                       // Allow voltage to settle

    int adcValue = analogRead(adc);  // Read the voltage back
    float voltage = (adcValue / 4095.0) * 3.3;

    Serial.print("ADC Value: ");
    Serial.print(adcValue);
    Serial.print(" Voltage: ");
    Serial.print(voltage, 2);
    Serial.println(" V");

    delay(100);
  }
}
