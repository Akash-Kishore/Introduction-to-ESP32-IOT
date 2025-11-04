// Bluetooth-based Temperature & Humidity Monitor using ESP32 and DHT11

#include "BluetoothSerial.h"  // Library for Bluetooth Classic (Serial over Bluetooth)
#include "DHT.h"              // Library for DHT temperature/humidity sensor

BluetoothSerial SerialBT;  // Create Bluetooth Serial object

#define DHTPIN 4           // DHT11 data pin connected to GPIO4
#define DHTTYPE DHT11      // DHT sensor type
DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

void setup() {
  Serial.begin(115200);            // Start Serial Monitor (for debugging)
  SerialBT.begin("ESP32_Sensor");  // Bluetooth device name
  dht.begin();                     // Initialize DHT sensor

  Serial.println("Bluetooth Started! Connect to 'ESP32_Sensor'");
}

void loop() {
  // Read temperature and humidity
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Check for read errors
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print data to Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("°C  Hum: ");
  Serial.print(hum);
  Serial.println("%");

  // Send data to Bluetooth device
  SerialBT.print("Temperature: ");
  SerialBT.print(temp);
  SerialBT.print(" °C, Humidity: ");
  SerialBT.print(hum);
  SerialBT.println(" %");

  delay(2000);  // Update every 2 seconds
}
