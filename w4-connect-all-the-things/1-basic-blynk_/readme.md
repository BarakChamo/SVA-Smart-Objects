# Example - Getting Started with Blynk

In this example we'll learn how to use Blynk, a simple and powerful IoT platform to connect our devices to the IoT cloud, 
interact with digital interfaces, report telemetry from physical sensors and connect to other online services.

This is a multi-part example that will cover several topis.

## Setting up Blynk and Arduino

Before we can get started, please download the [Blynk app](https://blynk.io/) to your phone and sign up for a free account.
Then, install the `Blynk` library from the Arduino IDE's Library Manager in `Sketch > Include Library > Manage Libraries`.

Open the example sketch, you'll notice several string field for you to complete:
```cpp
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YOUR_BLYNK_PROJECT_AUTH_TOKEN";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WIFI_SSID";
char pass[] = "WIFI_PASS";
```

In the Blynk app, create a project. You will then be emailed the auth token for your project, you can always find the auth token
in your project's configuration sceen. Replace `YOUR_BLYNK_PROJECT_AUTH_TOKEN` with your project's auth token.

![project settings](https://pressbooks.com/app/uploads/sites/52490/2016/07/blynk-auth-token-1.jpg)

Finally, replace `WIFI_SSID` and `WIFI_PASS` with your WiFi credentials.


## Part 1 - Blinking with Blynk

Let's begin with a basic example, turning an LED on and off, on our breadboards, from the Blynk project dashboard.

First, let's prep our breadboard with a single LED

### Circuit
![part1](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/part1.png)

### Blynk project
In your new Blynk project, add a button from the widget library:

<img src="https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Screenshot_2021-02-07-12-05-44-34_980d3cd05c70b8deb691e1a04aeb6aca_2.jpg" width="400">

Press the button widget to configure the button, set it to be a `SWITCH` button and set the pin to `DIGITAL` pin `12`.

<img src="https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Screenshot_2021-02-07-12-07-17-27_980d3cd05c70b8deb691e1a04aeb6aca_2.jpg" width="400">

Then, activate your sketch by pressing the `PLAY` button. You'll be able to then press that button to turn on your LED!
<img src="https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Screenshot_2021-02-07-12-05-55-30_980d3cd05c70b8deb691e1a04aeb6aca_2.jpg" width="400">

### Sketch
Upload the provided sketch, make sure to follow previous instruction to set the auth token and WiFi credentials.

To set up our connection to the Blynk project we have to do two things:

First, initialize the Blynk library with our project's token:
```cpp
void setup() {
  // start the Blink service over WiFi
  Blynk.begin(auth, ssid, pass);
}
```

Then, update the Blynk connection every time the loop runs:
```cpp
void loop() {
  // update Blynk connection and automatic values
  Blynk.run();
}
```

Notice we're never calling digitalWrite or pinMode for pin 14, everything is handled by Blynk's library when using digital pins!

You should now be able to turn the LED on GPIO12 on and off from the Blynk app.

## Part 2 - Adding a virtual pin, LED slider

Let's move on to a more complex example, using Blynk's virtual pins to send analog values and dim an LED.

We'll use the same sketch, but update our Blynk project and breadboard.

### Breadboard

Let's add an analog output connected to pin A1, remember only pins A0 and A1 can be used for analog output on the ESP32.

![part 2](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/part2.png)

### Blynk project

In your Blynk project, add a slider widget and configure it to address `VIRTUAL` pin `4`, this is a representation of a pin
that we can access from both the Blynk project and our Arduino code, and lets us easily share data between the physical and digital systems.

<img src="https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Screenshot_2021-02-07-12-47-31-58_980d3cd05c70b8deb691e1a04aeb6aca_2.jpg" width="400">

Set the slider's range to 0 to 255, to match the values we'll be writing to the LED using `analogWrite`.

<img src="https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Screenshot_2021-02-07-12-47-52-14_980d3cd05c70b8deb691e1a04aeb6aca_2.jpg" width="400">

### Code
We'll be using the same code, notice the two parts that receive data from the virtual pin and write it to the analog pin:

```cpp
// Listen for changes of virtual pin 4
// BLYNK_WRITE are special functions that can be defined multiple times with different pin arguments
BLYNK_WRITE(V4) {
  ledValue = param.asInt();
  analogWrite(ledPin, ledValue);
}
```

`BLINK_WRITE(VIRTUAL_PIN)` functions are similar to `setup()` and `loop()`, they are expected by the Blynk library and if defined, they'll
be called every time we write to a virtual pin in our Blynk apps, that's all we have to do to sync the app and our device using virtual pins!

Notice this particular function listens to virtual pin `V4`, you can define multiple virtual pin listeners using different arguments to listen
to other virtual pins.

In this case, we want to use the pin's value as an integer so we call `param.asInt()` but we can get floats, booleans, strings and more.
Refer to the virtual pins reference for more options. 

```cpp

```

