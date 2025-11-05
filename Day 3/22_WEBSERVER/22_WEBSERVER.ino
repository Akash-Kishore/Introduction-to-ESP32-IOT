//***************************************************************
//  ESP32 Basic Web Server
//***************************************************************
//  This program connects the ESP32 to your Wi-Fi network (Station Mode)
//  and starts a simple web server that displays a message when
//  you open the ESP32's IP address in a web browser.
//
//  Example: http://192.168.x.x  → shows "Hi everyone" in the browser.
//***************************************************************

#include <WiFi.h>          // Wi-Fi library for ESP32
#include <WebServer.h>     // HTTP server library

// Replace with your Wi-Fi credentials
const char* ssid = "YOUR_SSID";         
const char* password = "YOUR_PASSWORD"; 

// Create a web server object on port 80 (default HTTP port)
WebServer server(80);

// Function to handle requests to the root URL "/"
void handleRoot() {
  // Send a 200 OK response with HTML content
  server.send(200, "text/html",
              "<html>"
              "<body style='text-align:center; font-size:30px; margin-top:20%;'>"
              "Hi everyone"
              "</body></html>");
}

void setup() {
  Serial.begin(115200);             // Start serial monitor
  WiFi.begin(ssid, password);       // Connect ESP32 to your Wi-Fi network

  Serial.print("Connecting to Wi-Fi");
  // Wait until connected to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Once connected, print the IP address
  Serial.println("\nConnected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Define server route: what to do when "/" is accessed
  server.on("/", handleRoot);

  // Start the web server
  server.begin();
  Serial.println("Web server started! Open the IP above in a browser.");
}

void loop() {
  // Continuously handle client requests (web browser connections)
  server.handleClient();
}
