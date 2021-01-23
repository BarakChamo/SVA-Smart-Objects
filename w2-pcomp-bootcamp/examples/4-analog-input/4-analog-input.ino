/*
  Analog Input 
*/

int sensorPin = A1;    // select the input pin for the potentiometer
int ledPin = 12;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

// expected value range from analog input
int valueMin = 0;
int valueMax = 4095;

// desired LED delay range
int durationMin = 100;
int durationMax = 400;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  // begin serial connection
  Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  // write out the current value (try viewing it with the serial plotter)
  Serial.println(sensorValue);

  // map the value from sensor input range to desired application range
  sensorValue = map(sensorValue, valueMin, valueMax, durationMin, durationMax);
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
