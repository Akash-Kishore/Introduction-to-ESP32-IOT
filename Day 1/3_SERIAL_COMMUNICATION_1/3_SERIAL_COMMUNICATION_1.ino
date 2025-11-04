
// Serial Communication Example
// This program demonstrates basic serial communication between ESP32 and a computer via the Serial Monitor.

byte num = 100;  // Declare a byte variable and assign it a value

void setup() {
  Serial.begin(9600);  // Initialize serial communication at a baud rate of 9600 bits per second

  // Send text messages to the Serial Monitor
  Serial.print("Hi Everyone 1");     // Prints text without moving to the next line
  Serial.println(" Hi Everyone 2");  // Prints text and moves to a new line
  Serial.println("Hi Everyone 3");

  // Print a formatted string (like printf in C)
  Serial.printf("Number = %d\n", num);  // Displays: Number = 100
}

void loop() {
  // Check if data is available to read from the Serial Monitor
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');  // Read the incoming data as a string until a newline character ('\n')
    Serial.println(data);                        // Echo the received data back to the Serial Monitor
  }
}
