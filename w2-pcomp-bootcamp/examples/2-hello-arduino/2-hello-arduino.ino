// This is a bare bones Arduino sketch.
// Like all new sketches, it contains a setup() and a loop() function.
// - the setup() function gets called once when your sketch first loads.
// - the loop() function gets called repeatedly as long as your board is powered.

// global variables are accesible by both the setup and loop function.

String name = "Barak";
String message;

void setup() {
  // this is the setup function, this is where we'll performn
  // all sketch preparation that only needs to happen once.
  // This includes initializing variables, activating libraries, etc.

  // To print to the serial monitor, we must call Serail.begin with a specified 
  // baud rate that will be used for reading values
  Serial.begin(115200);

  // Let's print a welcome message once when the device loads
  Serial.println("Welcome to Arduino, " + name + "!");
}

void loop() {
  // this is the loop function, it runs continuously, one run after another
  // this programming model is called a loop-based pattern and is common to microcontrolelrs and games
  // here you'll write the bulk of your application code that runs as long as the device is active. 

  // Let's print a message letting us know how long the device has been on
  Serial.print("Sketch running for "); // notice we're calling print and not println, this won't break a line
  Serial.print(millis() / 1000); // let's get the current time in milliseconds and divide to get runtime in seconds
  Serial.println("seconds."); // finally, call println to break a line

  // Check if any serial input is available
  if(Serial.available()) {
    // read the incoming message into the string variable
    message = Serial.readString();

    // print out the message to the serial monitor
    Serial.println(message);
  }
  
  // delay execution by a second to not hammer the serial monitor too much
  // (these loops are fast)
  delay(1000);
}
