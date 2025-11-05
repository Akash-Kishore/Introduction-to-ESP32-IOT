//***************************************************************
//  ESP32 Web Server to Display DHT11 Temperature and Humidity
//***************************************************************
//  This program connects the ESP32 to Wi-Fi and starts a web server.
//  When you open the ESP32's IP address in a browser, it displays
//  real-time temperature and humidity data from the DHT11 sensor.
//***************************************************************

#include <WiFi.h>        // Wi-Fi library
#include <WebServer.h>   // Web server library
#include "DHT.h"         // DHT sensor library

#define DHTPIN 4         // DHT11 data pin connected to GPIO4
#define DHTTYPE DHT11    // Using DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);     // Create DHT object
WebServer server(80);         // Create web server on port 80

// Replace with your Wi-Fi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

//-------------------------
// Handle the root webpage
//-------------------------
void handleRoot() {
  float temp = dht.readTemperature();   // Read temperature (°C)
  float hum  = dht.readHumidity();      // Read humidity (%)

  // Build HTML page
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";  // Auto-refresh every 5 sec
  html += "<title>DHT11 Data</title></head>";
  html += "<body style='text-align:center; font-size:30px; margin-top:20%;'>";
  html += "Temperature: " + String(temp) + " &deg;C<br>";
  html += "Humidity: " + String(hum) + " %";
  html += "</body></html>";

  // Send HTML response to client
  server.send(200, "text/html", html);
}

//-------------------------
// Setup function
//-------------------------
void setup() {
  Serial.begin(115200);
  dht.begin();                       // Initialize DHT sensor

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print assigned IP address
  Serial.println("\nConnected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Define web server route
  server.on("/", handleRoot);
  server.begin();                    // Start the server
  Serial.println("Web server started!");
}

//-------------------------
// Main loop
//-------------------------
void loop() {
  server.handleClient();             // Handle client requests
}
