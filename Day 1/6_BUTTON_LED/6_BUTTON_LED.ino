// Control Two LEDs Using Two Buttons
// Button 1 → LED 1 blinks every 1000ms
// Button 2 → LED 2 blinks every 100ms

#define led1 15  // LED 1 connected to pin 15
#define led2 2   // LED 2 connected to pin 2
#define btn1 4   // Button 1 connected to pin 4
#define btn2 5   // Button 2 connected to pin 5

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  // Read button states (LOW means pressed because of INPUT_PULLUP)
  bool b1 = digitalRead(btn1);
  bool b2 = digitalRead(btn2);

  if (b1 == LOW && b2 == HIGH) {
    // When Button 1 pressed LED 1 blinks every 1000ms
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  } else if (b1 == HIGH && b2 == LOW) {
    // When Button 1 pressed LED 2 blinks every 100ms
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
  }
}
