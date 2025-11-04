// Wi-Fi Access Point Mode (ESP32)
// ESP32 creates its own Wi-Fi network (Hotspot)

#include <WiFi.h>

void setup() {
  Serial.begin(115200);  // Start serial communication

  // Start ESP32 as a Wi-Fi Access Point
  // Parameters: (SSID, Password)
  WiFi.softAP("ESP32_AP", "12345678");
  Serial.print("Access Point started!\nIP Address: ");
  Serial.println(WiFi.softAPIP());  // Print AP IP (usually 192.168.4.1)
}

void loop() {
  static int lastCount = 0;

  // Get number of devices currently connected to the AP
  int count = WiFi.softAPgetStationNum();

  // Only print when number of devices changes
  if (count != lastCount) {
    Serial.print("Connected devices: ");
    Serial.println(count);
    lastCount = count;
  }

  delay(1000);  // Check every 1 second
}
