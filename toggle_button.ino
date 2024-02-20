const int buttonPin = 25;      // Pin connected to the button
int buttonState = HIGH;       // Current state of the button
int lastButtonState = HIGH;   // Previous state of the button
int buttonToggle = 0;         // Variable to toggle between 0 and 1

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as INPUT_PULLUP
  Serial.begin(115200);                // Initialize Serial communication
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    // Check if the button is pressed (LOW state)
    if (buttonState == LOW) {
      buttonToggle = 1 - buttonToggle; // Toggle the buttonToggle variable between 0 and 1
      Serial.println(buttonToggle);    // Print the current state to Serial monitor
    }
    delay(50); // Debounce delay to avoid multiple toggles for a single button press
  }

  lastButtonState = buttonState; // Update the last button state

}
