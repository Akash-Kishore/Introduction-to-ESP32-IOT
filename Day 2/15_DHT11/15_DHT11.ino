// Temperature and Humidity Measurement using DHT11 Sensor

#include "DHT.h"         // Include DHT sensor library

#define DHTPIN 2         // DHT11 data pin connected to GPIO2
#define DHTTYPE DHT11    // Define sensor type (DHT11 or DHT22)

DHT dht(DHTPIN, DHTTYPE); // Create DHT object with pin and type

void setup() {
  Serial.begin(9600);    // Start serial communication
  dht.begin();           // Initialize the DHT sensor
}

void loop() {
  delay(2000);           // DHT11 needs ~2 seconds between readings

  // Read humidity and temperature values
  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Default is °C

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;  // Skip this loop if failed
  }

  // Print results to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("°C");
}
