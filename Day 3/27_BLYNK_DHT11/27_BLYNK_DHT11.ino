//***************************************************************
//  ESP32 + DHT11 + Blynk IoT Cloud
//***************************************************************
//  This code reads temperature and humidity from the DHT11 sensor
//  and uploads the data to the Blynk IoT cloud using virtual pins.
//  You can view the values live on the Blynk mobile app or web dashboard.
//***************************************************************

#define BLYNK_TEMPLATE_ID "YourTemplateID"  // From Blynk Web Dashboard
#define BLYNK_DEVICE_NAME "YourDeviceName"  // Device name in Blynk
#define BLYNK_AUTH_TOKEN "YourAuthToken"    // Unique token for your device

#include <WiFi.h>              // Wi-Fi functions for ESP32
#include <WiFiClient.h>        // Handles Wi-Fi connections
#include <BlynkSimpleEsp32.h>  // Blynk library for ESP32
#include "DHT.h"               // DHT sensor library

// Blynk and Wi-Fi credentials (update with your info)
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";      // Wi-Fi SSID
char pass[] = "YourWiFiPassword";  // Wi-Fi Password

// DHT Sensor setup
#define DHTPIN 4       // DHT11 data pin connected to GPIO4
#define DHTTYPE DHT11  // Sensor type
DHT dht(DHTPIN, DHTTYPE);

// Timer object to schedule periodic tasks
BlynkTimer timer;

//---------------------------------------------------------------
// Function: Reads DHT11 sensor and sends data to Blynk Cloud
//---------------------------------------------------------------
void sendSensor() {
  float temp = dht.readTemperature();  // Read temperature in °C
  float hum = dht.readHumidity();      // Read humidity in %

  // Validate sensor readings
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send values to Blynk virtual pins
  Blynk.virtualWrite(V1, temp);  // Virtual Pin V1 → Temperature widget
  Blynk.virtualWrite(V2, hum);   // Virtual Pin V2 → Humidity widget

  // Print values to Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C  |  Hum: ");
  Serial.print(hum);
  Serial.println(" %");
}

//---------------------------------------------------------------
// Setup Function
//---------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  dht.begin();                    // Initialize DHT sensor
  Blynk.begin(auth, ssid, pass);  // Connect to Wi-Fi and Blynk Cloud

  // Run sendSensor() every 2 seconds (2000 milliseconds)
  timer.setInterval(2000L, sendSensor);
}

//---------------------------------------------------------------
// Main Loop
//---------------------------------------------------------------
void loop() {
  Blynk.run();  // Keeps Blynk connected and processes events
  timer.run();  // Runs the periodic tasks (sensor reading)
}
