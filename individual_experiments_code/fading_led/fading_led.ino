// Set brightness level
int brightness = 0;

void setup{
  pinMode(9, OUTPUT);
}

void loop {
  // Increase the brightness level everytime it is low by 5
  for (brightness = 0; brightness <= 255; brightness += 5){
    analogWrite(9, brightness);
    // Short delay on each iteration
    delay(30);
  }
  // Decrease the brightness level by 5 when its max brightness
  for (brightness = 255; brightness >= 0; brightness -= 5){
    analogWrite(9, brightness);
    // Short delay on each iteration
    delay(30);
  }
}