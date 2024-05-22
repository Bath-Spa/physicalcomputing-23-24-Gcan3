// Placing the right locations of the components
const int led = 8;
const int pir = 2;
int motion;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the sensor output
  motion = digitalRead(pir);
  if(motion) {
    // Light up the LED once there is detection and log it
    digitalWrite(led, HIGH);
    Serial.println("Detected");
  } else {
    // Otherwise, dim the LED and log it
    digitalWrite(led, LOW);
    Serial.println("Nothing detected... Waiting");
  }
}
