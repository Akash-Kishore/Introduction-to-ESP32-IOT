//***************************************************************
//  ESP32 IoT Project: Read Latest Temperature & Humidity from ThingSpeak
//***************************************************************
//  This program connects the ESP32 to Wi-Fi and reads the latest
//  temperature and humidity data uploaded to a ThingSpeak channel.
//  The data is requested in JSON format and parsed using Arduino_JSON.
//***************************************************************

#include <WiFi.h>          // Wi-Fi functions
#include <HTTPClient.h>    // HTTP client for web requests
#include <Arduino_JSON.h>  // Library to parse JSON data

// ---------------- Wi-Fi Credentials ----------------
const char* ssid = "YOUR SSID";     // Replace with your Wi-Fi SSID
const char* password = "YOUR PASSWORD";  // Replace with your Wi-Fi password

// ---------------- ThingSpeak Channel Info ----------------
String channelID = "YOUR CHANNEL ID";                           // Your ThingSpeak Channel ID
String readAPIKey = "YOUR READ API";                 // ThingSpeak Read API Key
String server = "http://api.thingspeak.com/channels/";  // Base URL

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  Serial.print("Connecting to WiFi...");
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
  // Only proceed if Wi-Fi is connected
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Construct full URL to read the latest data in JSON format
    String url = server + channelID + "/feeds/last.json?api_key=" + readAPIKey;

    http.begin(url);            // Initialize HTTP connection
    int httpCode = http.GET();  // Send GET request

    if (httpCode > 0) {
      // Successfully received response
      String payload = http.getString();  // Get response as string
      Serial.println("Received Data: " + payload);

      // Parse JSON response
      JSONVar data = JSON.parse(payload);

      // Check if parsing succeeded
      if (JSON.typeof(data) == "undefined") {
        Serial.println("Parsing failed!");
        return;
      }

      // Extract data fields (from ThingSpeak fields)
      String temperature = (const char*)data["field1"];
      String humidity = (const char*)data["field2"];

      // Print the values
      Serial.println("Latest Temperature: " + temperature + " °C");
      Serial.println("Latest Humidity: " + humidity + " %");
    } else {
      Serial.println("Error in HTTP request!");
    }

    http.end();  // Close HTTP connection
  } else {
    Serial.println("WiFi Disconnected!");
  }

  // ThingSpeak updates every 15 seconds, so read every 15s
  delay(15000);
}
