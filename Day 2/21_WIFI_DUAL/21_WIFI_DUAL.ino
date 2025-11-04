// Wi-Fi Dual Mode: Access Point + Station (ESP32)
// ESP32 connects to an existing Wi-Fi network (STA)
// and also creates its own Access Point (AP)

#include <WiFi.h>

const char* ssid = "YOUR_SSID";          // Your Wi-Fi network name
const char* password = "YOUR_PASSWORD";  // Your Wi-Fi password

void setup() {
  Serial.begin(115200);  // Start Serial Monitor

  // Enable both Station and Access Point modes
  WiFi.mode(WIFI_AP_STA);

  // Connect to existing Wi-Fi (Station mode)
  WiFi.begin(ssid, password);

  // Create a Wi-Fi Access Point (AP mode)
  WiFi.softAP("ESP32_AP", "12345678");

  Serial.println("Station + Access Point running");

  // Wait until connected to Wi-Fi network
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Once connected, print both IP addresses
  Serial.println("\nWiFi connected!");
  Serial.print("Station (STA) IP: ");
  Serial.println(WiFi.localIP());

  Serial.print("Access Point (AP) IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Nothing in loop for now
}
