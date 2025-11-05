//***************************************************************
//  ESP32 IoT Project: Send DHT11 Temperature & Humidity to ThingSpeak
//***************************************************************
//  This program reads temperature and humidity from a DHT11 sensor,
//  connects ESP32 to Wi-Fi, and uploads the data to ThingSpeak cloud
//  every 15 seconds.
//***************************************************************

#include <WiFi.h>        // Wi-Fi functions
#include "DHT.h"         // DHT sensor library
#include "HTTPClient.h"  // HTTP requests library

// ---------------- WiFi Credentials ----------------
const char* ssid = "YOUR_SSID";          // Replace with your Wi-Fi SSID
const char* password = "YOUR_PASSWORD";  // Replace with your Wi-Fi password

// ---------------- ThingSpeak Settings ----------------
String apiKey = "YOUR_API_KEY";                           // Write API key from your ThingSpeak channel
const char* server = "http://api.thingspeak.com/update";  // ThingSpeak update URL

// ---------------- DHT Sensor Configuration ----------------
#define DHTPIN 4           // DHT11 connected to GPIO 4
#define DHTTYPE DHT11      // Sensor type (DHT11 or DHT22)
DHT dht(DHTPIN, DHTTYPE);  // Create DHT object

void setup() {
  Serial.begin(115200);
  dht.begin();  // Initialize DHT sensor

  // Connect to Wi-Fi network
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Read data from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();  // Temperature in °C

  // Check for valid readings
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display data on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Send data to ThingSpeak if connected to Wi-Fi
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Create full URL with fields and API key
    String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(temperature) + "&field2=" + String(humidity);

    http.begin(url);            // Start HTTP connection
    int httpCode = http.GET();  // Send GET request

    // Check HTTP response
    if (httpCode > 0) {
      Serial.println("Data uploaded to ThingSpeak successfully!");
    } else {
      Serial.println("Error uploading data to ThingSpeak!");
    }

    http.end();  // Close connection
  }

  // ThingSpeak allows updates every 15 seconds minimum
  delay(15000);
}
