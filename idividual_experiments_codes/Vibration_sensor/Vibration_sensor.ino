// Store pin locations
int vibPin = 2;
int sensorState = 1;
int led = 13;

void setup() {
  pinMode(vibPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Get the state of the sensor
  Serial.print("Vibration status: ");
  sensorState = digitalRead(vibPin); // Display value is only indicated through two interchanging variables

  if(sensorState == 1) {
    // If there is vibration (indicated through the '1' signal), then log the output and light up the LED
    digitalWrite(led, HIGH);
    Serial.println("Vibrating");
  } else {
    // Otherwise, dim the LED and log the result
    digitalWrite(led, LOW);
    Serial.println("No vibration");
  }
  delay(50); // 0.05 sec delay per loop
}
