
// LED Brightness Control using PWM

#define led 2           // LED connected to GPIO2
#define channel 0       // PWM channel (0–15)
#define frequency 5000  // PWM frequency in Hz
#define resolution 8    // 8-bit resolution (0–255)

void setup() {
  ledcAttachChannel(led, frequency, resolution, channel);  // Attach PWM channel with given pin, frequency, resolution and channel
}

void loop() {
   // Fade LED brightness up
  for (short i = 0; i <= 255; i++) {
    ledcWriteChannel(channel, i); // Set brightness level
    delay(30);
  }
  // Fade LED brightness down
  for (short i = 255; i >= 0; i--) {
    ledcWriteChannel(channel, i);
    delay(30);
  }
}
