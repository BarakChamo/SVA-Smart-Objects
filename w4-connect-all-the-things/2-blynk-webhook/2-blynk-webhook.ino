#define BLYNK_TEMPLATE_ID "TMPLllqKdIoF"
#define BLYNK_DEVICE_NAME "Simple Template"
#define BLYNK_AUTH_TOKEN "YOUR AUTH TOKEN"

#include <analogWrite.h>

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int ledPin = A1;
int ledValue;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "BLYNK_AUTH";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WIFI_SSID";
char pass[] = "WIFI_PASS";


// called when the device is connected to the Blynk server
BLYNK_CONNECTED() {
  // Your code here
}

// called when an app is connected to the Blynk project
BLYNK_APP_CONNECTED() {
  // Your code goes here
}

// called when an app is disconnceted from the Blynk project
BLYNK_APP_DISCONNECTED(){
}

// Listen for changes of virtual pin 4
// BLYNK_WRITE are special functions that can be defined multiple times with different pin arguments
BLYNK_WRITE(V32) {
  ledValue = param.asInt();
  analogWrite(ledPin, ledValue);
}

// for more Blynk firmware handlers visit http://docs.blynk.cc/#blynk-firmware

void setup() {
  // Debug console
  Serial.begin(9600);

  // start the Blink service over WiFi
  Blynk.begin(auth, ssid, pass);

  // setup input pins
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // update Blynk connection and automatic values
  Blynk.run();

  // do anything else you want ion your sketch
  // but, DO NOT WRITE TO BLYNK HERE CONTINUOUSLY, ONLY IN TIMEOUT HANDLER!
}
