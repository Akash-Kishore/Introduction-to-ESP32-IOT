//***************************************************************
//  ESP32 + Blynk IoT + LDR + PWM LED
//  Auto = LDR-based (V1=1), Manual = Slider-based (V0: 0–100%)
//  Uses analogWrite() API compatible with ESP32 core 3.x
//***************************************************************

#define BLYNK_TEMPLATE_ID   "TMPL3Bj3FU76t"
#define BLYNK_TEMPLATE_NAME "Automatic LED"
#define BLYNK_AUTH_TOKEN    "V-cWmEeLQBUnc1UoQfId5KUIv0xHompw"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Nothing Phone 2a";
char pass[] = "133555567";

// Pins
const int LED_PIN = 2;    // PWM-able
const int LDR_PIN = 34;   // ADC (32..39)

// PWM prefs (for analogWrite on ESP32 core 3.x)
const int PWM_RES_BITS = 8;     // 0..255
const int PWM_FREQ_HZ  = 5000;  // 5 kHz

// Blynk controls
// V1: 1 = Auto (LDR), 0 = Manual (Slider)
// V0: Slider 0..100 (%)
int modeAuto  = 1;
int sliderPct = 0;

BLYNK_WRITE(V1) {               // Mode
  modeAuto = param.asInt();
}

BLYNK_WRITE(V0) {               // Slider 0..100
  sliderPct = param.asInt();
  if (sliderPct < 0)   sliderPct = 0;
  if (sliderPct > 100) sliderPct = 100;
}

void setup() {
  Blynk.begin(auth, ssid, pass);
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);

  // ESP32 core 3.x analogWrite setup
  analogWriteResolution(LED_PIN, PWM_RES_BITS);   // (pin, bits)
  analogWriteFrequency(LED_PIN, PWM_FREQ_HZ);     // (pin, Hz)
  analogWrite(LED_PIN, 0);                        // start off
}

void loop() {
  Blynk.run();

  int brightness; // 0..255

  if (modeAuto == 1) {
    int ldr = analogRead(LDR_PIN);               // 0..4095
    brightness = map(ldr, 3600, 4095, 0, 255);      // invert: dark -> bright
    Serial.println(ldr);
  } else {
    // MANUAL: 0–100% -> 0–255 PWM
    brightness = map(sliderPct, 0, 100, 0, 255);
  }

  analogWrite(LED_PIN, brightness);
}
