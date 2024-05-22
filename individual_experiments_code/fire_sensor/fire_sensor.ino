void setup()  {
// initialize serial communication @ 9600 baud:
Serial.begin(9600);  
}

void loop() {
// read the sensor on digitalPin 2:
int sensorReading  = digitalRead(2);

// range value:
if (sensorReading){
  // If there is any read, then display in the log
  Serial.println("** No  Fire **");
} else {
  // Otherwise, display another result
  Serial.println("** There is Fire **");
}
delay(1000);  // delay between reads
}