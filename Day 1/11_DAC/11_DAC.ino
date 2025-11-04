// LED Brightness Control using ESP32 DAC (GPIO26)

#define dacPin 26  // Only GPIO25 or GPIO26 can be used as DAC pins

void setup() {
  // No setup needed for DAC; it’s ready to use automatically
}

void loop() {
  // Fade LED brightness UP (0 → 255)
  for (int i = 0; i <= 255; i++) {
    dacWrite(dacPin, i);  // Increase output voltage (LED gets brighter)
    delay(10);
  }

  // Fade LED brightness DOWN (255 → 0)
  for (int i = 255; i >= 0; i--) {
    dacWrite(dacPin, i);  // Decrease output voltage (LED dims)
    delay(10);
  }
}
