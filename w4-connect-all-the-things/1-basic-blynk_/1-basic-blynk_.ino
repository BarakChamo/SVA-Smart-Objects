/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <analogWrite.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int potPin = A4;
const int buttonPin = 14;
const int ledPin = A1;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YOUR_BLYNK_PROJECT_AUTH_TOKEN";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WIFI_SSID";
char pass[] = "WIFI_PASS";


BlynkTimer timer;

int potValue = 0;
int buttonValue = 0;
int ledValue = 0;

// define a timer callback
// this is where we write to Blynk virtual pins
//void onTimer() {
//  // Write to virtual pins.
//  // don't send more that 10 values per second.
//  Blynk.virtualWrite(V5, potValue);
//  Blynk.virtualWrite(V6, buttonValue);
//  Blynk.virtualWrite(V7, buttonValue * 255); // write to virtual LED pin
//}

// Listen for changes of virtual pin 4
// BLYNK_WRITE are special functions that can be defined multiple times with different pin arguments
//BLYNK_WRITE(V4) {
//  ledValue = param.asInt();
//  analogWrite(ledPin, ledValue);
//}

void setup() {
  // Debug console
  Serial.begin(9600);

  // start the Blink service over WiFi
  Blynk.begin(auth, ssid, pass);

  // configure the blynk timer to call onTimer() every second
//  timer.setInterval(1000L, onTimer);

  // setup input pins
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // update Blynk connection and automatic values
  Blynk.run();

  // update the Blynk timer
//  timer.run();
  
  // read physical pins
  potValue = analogRead(potPin);
  int tempButtonValue = digitalRead(buttonPin);

  // if button is pressed, send push notification to Blynk app
//  if(tempButtonValue && !buttonValue) {
//    // careful! notice we're only writing to Blynk in loop() under certain conditions
//    Blynk.notify("Yaaay... button is pressed!");
//    Blynk.virtualWrite(V8, "Hello from my Feather!"); // write to virtual webhook pin
//  }
  
  // keep track of latest button value
  buttonValue = tempButtonValue;

  // do anything else you want ion your sketch
  // but, DO NOT WRITE TO BLYNK HERE CONTINUOUSLY, ONLY IN TIMEOUT HANDLER!
}
