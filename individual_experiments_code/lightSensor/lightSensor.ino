void setup() {
  // Execute log board
  Serial.begin(9600);
}

void loop() {
  // Read the sensor input
  int digitalValue = digitalRead(4);

  // Log in the read value of the sensor (only in 0 and 1)
  Serial.print("Digital Read = ");
  Serial.print(digitalValue);

  // If the value is 1, display dim results
  if (digitalValue == 1){
    Serial.println("- Dim/Dark");
  } else {
    // Otherwise, the light is detected
    Serial.println("- Light");
  }
  // Add a .5 second delay
  delay(500);
}
