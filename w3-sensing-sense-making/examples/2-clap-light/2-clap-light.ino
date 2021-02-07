/*
  Analog Input 
*/

int ledPin = 12;
int sensorPin = A0;    // select the input pin for the sensor
int sensorValue = 0;  // variable to store the value coming from the sensor

// clap light paramaters
int triggerThreashold = 200; // minimum analog value to count as trigger
int triggerDuration = 200; // how long between values to count as a trigger
int triggerInterval = 500; // how long between triggers to toggle lights
int lastTrigger = 0; // keep track of the last time the previous trigger was detected

bool lastLight = false;

void toggleLight(bool turnOn) {
  // keep track of latest light state
  lastLight = turnOn;
  
  if(turnOn)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}

void setup() {
  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
  // begin serial connection
  Serial.begin(115200);

  // initialize our light (off)
  toggleLight(false);
}

void loop() {
  // read the value from the sensor:
  int currentValue = analogRead(sensorPin);
  int now = millis(); // get current runtime in miliseconds
  
  // check if this is a trigger (upward spike)
  bool isTrigger = (currentValue > sensorValue) && (currentValue > triggerThreashold) && ((now - lastTrigger)> triggerDuration);
    
  if(isTrigger && ((now - lastTrigger)< triggerInterval)) {
    Serial.println("trigger");
    toggleLight(!lastLight);
  }

  if(isTrigger) {
    lastTrigger = now;
  }

  // keep track of latest sensor value
  sensorValue = currentValue;

  // print current value
//  Serial.println(sensorValue);

}
