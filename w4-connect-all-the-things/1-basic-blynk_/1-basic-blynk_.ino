/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLllqKdIoF"
#define BLYNK_DEVICE_NAME "Simple Template"
#define BLYNK_AUTH_TOKEN "YOUR AUTH TOKEN"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#define LED_ANALOG 25
#define LED_DIGITAL 26

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <analogWrite.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YOUR WIFI SSID";
char pass[] = "YOUR WIFI PASS";


// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.println(value);
  digitalWrite(LED_DIGITAL, value);
  
  // Update state
  Blynk.virtualWrite(V1, value);
}

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V1)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.println(value);

  analogWrite(LED_ANALOG, value);

}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(LED_DIGITAL, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
