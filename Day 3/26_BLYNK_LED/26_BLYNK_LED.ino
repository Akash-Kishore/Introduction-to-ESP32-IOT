//***************************************************************
//  ESP32 + Blynk IoT Basic Connection Example
//***************************************************************
//  This code connects the ESP32 to the Blynk IoT cloud via Wi-Fi.
//  Once connected, you can control or monitor sensors/actuators
//  using the Blynk mobile app or web dashboard.
//***************************************************************

#define BLYNK_TEMPLATE_ID "YourTemplateID"  // From Blynk Web Dashboard
#define BLYNK_DEVICE_NAME "YourDeviceName"  // Device name in Blynk
#define BLYNK_AUTH_TOKEN "YourAuthToken"    // Unique token for your device

#include <WiFi.h>              // ESP32 Wi-Fi library
#include <WiFiClient.h>        // Handles Wi-Fi client functions
#include <BlynkSimpleEsp32.h>  // Blynk library for ESP32

// Authentication and Wi-Fi credentials
char auth[] = BLYNK_AUTH_TOKEN;    // Blynk Auth Token
char ssid[] = "YourWiFiSSID";      // Wi-Fi SSID
char pass[] = "YourWiFiPassword";  // Wi-Fi Password

void setup() {
  Serial.begin(115200);  // Start serial monitor for debugging

  // Connect to Wi-Fi and Blynk cloud
  Blynk.begin(auth, ssid, pass);

  // Once connected, you can check your Blynk app/dashboard
  Serial.println("Connected to Blynk Cloud!");
}

void loop() {
  // Keeps the Blynk connection active and processes incoming commands
  Blynk.run();
}
