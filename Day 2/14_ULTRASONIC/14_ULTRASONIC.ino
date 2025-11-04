// Distance Measurement using Ultrasonic Sensor (HC-SR04)

#define trig 18   // Trigger pin connected to GPIO18
#define echo 19   // Echo pin connected to GPIO19

void setup() {
  Serial.begin(9600);       // Start serial communication
  pinMode(trig, OUTPUT);    // Trig pin as output
  pinMode(echo, INPUT);     // Echo pin as input
  digitalWrite(trig, LOW);  // Ensure trigger is LOW at start
}

void loop() {
  // Send a 10µs pulse to trigger the ultrasonic burst
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure how long the echo pin stays HIGH (in microseconds)
  unsigned long duration = pulseIn(echo, HIGH);

  // Calculate distance in cm (speed of sound = 0.0343 cm/µs)
  float distance = 0.0343 * duration / 2;

  // Print result to Serial Monitor
  Serial.printf("Distance: %.2f cm\n", distance);

  delay(300);  // Wait a bit before next measurement
}
