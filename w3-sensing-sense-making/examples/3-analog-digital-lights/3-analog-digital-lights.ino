#include <analogWrite.h>

#define PI 3.1415926535897932384626433832795
#define TWO_PI 6.283185307179586476925286766559

// define two arrays to hold analog and digital pins
int analogLedPins[] = {A0, A1};
int digitalLedPins[] = {12, 27};
int potPin = A3;

float speed = 100.0;
float elapsed = 0;

void setup() {
  // set analog outputs
  pinMode(analogLedPins[0], OUTPUT);
  pinMode(analogLedPins[1], OUTPUT);

  // set digital outputs
  pinMode(digitalLedPins[0], OUTPUT);
  pinMode(digitalLedPins[1], OUTPUT);

  pinMode(potPin, INPUT);

  Serial.begin(115200);

//  pinMode(analogPins[0], OUTPUT);
}

void loop() {
  // increment elapsed frame time by potentiometer value
  speed = analogRead(A3) / 8190.0; // map the range to 0 to 0.5
  elapsed += speed;
  
  for(int i = 0; i < 2; i++) {
    // calculate a moving sine wave, 
    // offset a little for each LED by their position in the array
    float offset = elapsed + i * PI;
    float currentSine = (sin(offset) + 1.0) / 2.0; // map the sine wave from -1 to 1 to 0 to 1 range

    // write to digital pin (must be 0 or 1, HIGH or LOW)
    digitalWrite(digitalLedPins[i], currentSine > 0.5);
  
    // write to analog pin (continuous number between 0 and 255)
    analogWrite(analogLedPins[i], currentSine * 255);

    Serial.println(speed);
  }
}
