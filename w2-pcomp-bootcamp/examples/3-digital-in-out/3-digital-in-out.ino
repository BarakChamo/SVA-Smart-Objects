/*
  Digital inputs and outputs
  Button and LED toggle

  In this example we'll learn how to configure GPIO pins 
  for digital input and output, and how to interface with them in our sketch.
*/

// first, let's define pins for our inputs and outputs
// these will match the configuration on our circuit or breadboard
const int buttonPin = 33;      // the number of the pushbutton pin
const int ledAPin =  12;      // the number of the first LED pin
const int ledBPin =  27;      // the number of the second LED pin

// then, we'll define a variable that will hold our button state
int buttonState = 0;

void setup() {
  // initialize both LED pins as an digital output:
  pinMode(ledAPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  Serial.begin(115200);
  // initialize the button pin as an digital input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the current state of the button and store it in a variable
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the button is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    digitalWrite(ledAPin, HIGH);
    digitalWrite(ledBPin, LOW);
  } else {
    digitalWrite(ledAPin, LOW);
    digitalWrite(ledBPin, HIGH);
  }
}
