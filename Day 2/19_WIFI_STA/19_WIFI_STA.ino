// Wi-Fi Station Mode Example (ESP32)
// Connects ESP32 to an existing Wi-Fi network

#include <WiFi.h>  // Include Wi-Fi library for ESP32

#define led 2  // LED connected to GPIO2 (onboard LED)

const char* ssid = "YOUR_SSID";          // Replace with your Wi-Fi name
const char* password = "YOUR_PASSWORD";  // Replace with your Wi-Fi password

void setup() {
  Serial.begin(115200);  // Start Serial Monitor
  pinMode(led, OUTPUT);  // Set LED pin as output

  WiFi.mode(WIFI_STA);         // Set ESP32 as a Wi-Fi station (client)
  WiFi.begin(ssid, password);  // Start connecting to Wi-Fi

  Serial.print("Connecting");
  // Wait until connected to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(led, LOW);  // LED OFF while connecting
  }

  // When connected
  Serial.println("\nConnected!");
  digitalWrite(led, HIGH);  // Turn LED ON after successful connection
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print assigned IP
}

void loop() {
  // Nothing in loop for this example
}
