// LED Control via Bluetooth using ESP32

#include "BluetoothSerial.h"  // Include Bluetooth library

#define LED_PIN 2  // LED connected to GPIO2

BluetoothSerial SerialBT;  // Create Bluetooth Serial object

void setup() {
  Serial.begin(9600);        // Start Serial Monitor for debugging
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output

  // Start Bluetooth communication with device name "ESP32_LED"
  SerialBT.begin("ESP32_LED");
  Serial.println("Bluetooth Started! Connect to 'ESP32_LED'");
}

void loop() {
  // Check if Bluetooth has received any data
  if (SerialBT.available()) {
    char data = SerialBT.read();  // Read one character from Bluetooth
    Serial.println(data);         // Print received data to Serial Monitor

    // Turn LED ON if '1' is received
    if (data == '1') {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    }
    // Turn LED OFF if '0' is received
    else if (data == '0') {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    }
  }
}
