# Example - Getting Started with Blynk

In this example we'll learn how to use Blynk, a simple and powerful IoT platform to connect our devices to the IoT cloud, 
interact with digital interfaces, report telemetry from physical sensors and connect to other online services.

This is a multi-part example that will cover several topis.

## Setting up Blynk, Arduino and IFTTT

### Blynk setup

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

### IFTTT setup

Later in this example we'll be connecting Blynk and IFTTT, the IoT trigger service to send Slack notifications using our devices.

To do that, please sign up for a free account with [IFTTT here](https://ifttt.com/home)

Once signed up, set up the Maker service that will allow you to use webhooks to trigger IFTTT actions.
Go to [IFTTT Maker Service](https://ifttt.com/maker_webhooks) and press the `documentation` button, record your unique key

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

## Part 3 - Triggering cloud updates

So far we've used the Blynk dashboard to turn LEDs on and off on our app, let's see how we can go in the other direction and read values from our board into the dashboard.

We'll do so with a potentiometer, but you can use any analog sensor you like.

### Circuit

![part 3](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/part3.png)

Note: when WiFi is used, only certain analog pins can be used for AnalogRead, these are limited to pins using ADC #1, refer to Adafruit's documentation to find which are correct for your board.

### Blynk project

Add a vertical Level widget, we'll use this level as an indicator for our potentiometer's resistance.

<img src="https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Screenshot_2021-02-07-13-13-33-22_980d3cd05c70b8deb691e1a04aeb6aca_2.jpg" width="400">

Configure the Level to listen to `VIRTUAL` pin `5`, with a range of 0 to 4095, to match our analog read resolution, and a reading rate of `PUSH`, this means the value will update whenever the Arduino code pushes new updates. 

### Sketch

We'll be using the same sketch.

An important thing to note is that we don't want to send values to Blynk every time our loop() is called, which will result in hundreds of calls per second and cause Blynk to block your project. Instead, we'll configure a timer to call a function every X seconds and send updates to Blynk on defined intervals.

To set up the timer, we create a Timer object and configure its interval:

```cpp
BlynkTimer timer;

void setup() {
  // start the Blink service over WiFi
  Blynk.begin(auth, ssid, pass);

  // configure the blynk timer to call onTimer() every second
  timer.setInterval(1000L, onTimer);
}
```

Notice the `onTimer` function passed to `timer.setInterval`, that is a function we write, a callback that the timer will call once per interval:
In this timer we call `Blynk.virtualWrite(PIN, VALUE)`, just like `digitalWrite` and `analogWrite`, and our dashboards will update automatically!

```cpp
// define a timer callback
// this is where we write to Blynk virtual pins
void onTimer() {
  // Write to virtual pins.
  // don't send more that 10 values per second.
  Blynk.virtualWrite(V5, potValue);
  Blynk.virtualWrite(V6, buttonValue);
  Blynk.virtualWrite(V7, buttonValue * 255); // write to virtual LED pin
}
```

Refer to class notes for more information about working with virtual pins.

## Part 4 - Triggering actions

Finally, let's see how to do more interesting things than updating the Blynk dashboard, interacting with real digital services and other online systems!

Let's do so by adding a button to our board, and use it to:
- show an indicator on the project dashboard
- send a push notification
- send us a message on Slack using IFTTT

### circuit

Add a button to your circuit and connect it to digital pin 14

![part 4](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/part4.png)

### Sketch
We'll be using the same sketch.

Notice the following parts of the code where virtual pins are updated:

Using our onTimer timer callback, we continuously update the state of the virtual pins used by the button and LED widgets.
Notice we're multiplying the digital value, 0 or 1, by 255, to turn the LED on our dashboard on and off - it expects an analog range and can be dimmed!
```cpp
void onTimer() {
  // Write to virtual pins.
  // don't send more that 10 values per second.
  Blynk.virtualWrite(V5, potValue);
  Blynk.virtualWrite(V6, buttonValue);
  Blynk.virtualWrite(V7, buttonValue * 255); // write to virtual LED pin
}
```

Using a simple function in our loop, we catch changes to our button's digital value to trigger actions only when it is first pressed, this is
to assure we don't constantly write to the virtual pins, but only once when the button is pressed:
```cpp
  // if button is pressed, send push notification to Blynk app
  if(tempButtonValue && !buttonValue) {
    // careful! notice we're only writing to Blynk in loop() under certain conditions
    Blynk.notify("Yaaay... button is pressed!");
    Blynk.virtualWrite(V8, "Hello from my Feather!"); // write to virtual webhook pin
  }
  
```

Here, we call `Blynk.notify` to trigger a notification using the Push Notification widget.
Writing to virtual pin 8 will trigger the webhook that we will connect to Slack using IFTTT, see how we can even write strings to virtual pins?!

### Blynk project

In our sketch we'll add a few diffrent components, an indicator, a webhook and a push notification

#### Button indicator
Add a Value Display and and LED widget, set the Value Display to read from virtual pin 6 and the LED to read from virtual pin 7.
Set both widgets to `PUSH` as reading mode.

#### push notification
Next, add a push notification widget, notice the push notification is generic and is not tied to a specific pin.

In our Arduino code we call `Blynk.notify(NOTIFICATION);`, you can use this call with any value to trigger a push notification on your connected mobile device.

#### webhook - IFTTT and Slack integration
Finally, add a Webhook widget.

##### What are webhooks
Webhooks are public URL addresses that allow different services to trigger actions, like APIS. 
We can use webhooks to accept incoming actions from 3d-party services, or use other services' webhooks to trigger actions from our own devices and code.
Using the webhook widget, we can call web APIs and Webhooks whenever a virtual pin is triggered, this is an incredibly powerful feature that you can use to connect
your smart devices and any public online service, from Gmail to Spotify - in this example we'll be using If This Than That -IFTTT.

##### Create IFTTT tigger event

1. Sign up to IFTTT and find your unique key using the instructions at the top of this page
2. Go to [IFTTT's Create wizard](https://ifttt.com/create)
3. In `If this`, choose `Webhooks` and then `receive a web request`
4. Name your event, for example `SEND_SLACK` and press `Create Trigger`
5. In `then than`, choose `Slack` and `Post to Channel`
6. You'll be prompted to authenticate Slack with IFTTT, allow it access to the SVA IxD Slack.
7. In `Post to Channel` settings, choose `Channels` and `#device-chat`
8. Specify the title and message body you'd want to send when your button is pressed, you can add `ingredients`, or dynamic values that we'll populate from Blynk!
9. Add at least one ingredient, using the predefined name `value1`
10. Press `Create`, `Continue` and `Finish`
11. Verify your trigger is set to `Connected`

##### Blynk webhook configuration
Open the Webhook widget's configuration and configure a connection to IFTTT's Maker webhooks.
Documenetation of the maker webhook is available by pressing `Documentation` [here](https://ifttt.com/maker_webhooks)

**OUTPUT**
We'll be using Virtual Pin 8 to trigger the webhook.

**URL**
IFTTT's Maker Service webhook URL is formatted as follows:
`https://maker.ifttt.com/trigger/{EVENT_NAME}/with/key/{USER_KEY}`

You should have your unique user key, the event name will match whatever you called it, in  this example it is `SEND_SLACK`.
Format your URL and enter it in Blynk's Webhook widget `URL` field.

**METHOD**
We want to send dynamic data to our webhook, incuding a customized message and values from our device, so set the METHOD to `PUT` to allow sending a JSON payload

**BODY**
This is the JSON that is sent to IFTTT's webhook and will replace trigger "ingredients" such as `value1`. Ingredients are matched by name from this JSON object to the content of our Slack triggers.

Blynk will dynamically replace any occurance of the string `/pin/` with the content sent with `virtualWrite()` from our Arduino code, the combination of this feature and IFTTT's ingredients allows us to easily send values from our Arduino code all the way to Slack messages with a single line of code.

Set the body to the following JSON string
`{"value":"/pin/"}`

Be careful when typing, malformed JSON strings will cause an error.

Upload the code to your boards, press play on Blynk, and press the  buttton!

