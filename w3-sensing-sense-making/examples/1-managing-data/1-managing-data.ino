/*
  Analog Input 
*/

int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor
int maxValue = 0;
int minValue = 9999;

void setup() {
  // begin serial connection
  Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  // keep track of maximum value
  maxValue = max(sensorValue, maxValue);

  // keep track of min value
  minValue = min(sensorValue, minValue);

  
  // write out the current value (try viewing it with the serial plotter)
  Serial.print(sensorValue); // current value
  Serial.print(" ");
  Serial.print(minValue);    // minimum value
  Serial.print(" ");
  Serial.println(maxValue);  // maximum value


}
