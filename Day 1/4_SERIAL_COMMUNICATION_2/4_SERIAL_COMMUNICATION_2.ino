// Serial Communication Example: Read a number and print its square
// This program asks the user to enter a number via the Serial Monitor,
// reads the input, and then prints the square of that number.

int num = 0;  // Declare a variable to store the incoming number

void setup() {
  Serial.begin(9600);                 // Initialize serial communication at 9600 bits per second
  Serial.println("Enter a number:");  // Send an initial message to the user
}

void loop() {

  // Check if any data is available to read from Serial Monitor
  if (Serial.available()) {
    // Read the number entered by the user
    num = Serial.parseInt();  // Reads an integer from serial input
    int square = num * num;   // Calculate and print the square

    // Print the result to Serial Monitor
    Serial.print("Square of ");
    Serial.print(num);
    Serial.print(" is: ");
    Serial.println(square);

    // Ask for next input
    Serial.println("Enter another number:");

    // Make sure your serial monitor is set to "No Line Ending"
  }
}
