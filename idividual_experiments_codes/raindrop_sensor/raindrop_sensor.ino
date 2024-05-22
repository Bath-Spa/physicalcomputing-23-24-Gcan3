// Sensor variable
int sensorRead = 0;

void setup() {
	Serial.begin(9600);
	pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // Get the read
	int sensorRead= analogRead(A0);
  // Log in the number value
	Serial.println(sensorRead);
  // Less than 1000 means that the water is detected
  if(sensorRead < 1000) {
    // Light up the LED once the water is detected
    digitalWrite(13, HIGH);
    delay(200); // Add a .2 second delay
  } else {
    // Else, set the LED dim
    digitalWrite(13, LOW); 
    delay(200); // Add a .2 second delay
  }
}