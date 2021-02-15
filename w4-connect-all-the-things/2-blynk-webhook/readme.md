# Blynk webhooks example

In this example, we'll use webhook in the other direction, triggering changes on our Feather board using Blynk, by listening for actions on other services using IFTTT.

## Board

Our circuit is very simple, just a single LED connected to analog output A1 with a 220 ohm resistor.

![circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Untitled%20Sketch%202_bb.png)

## IFTTT

Create a new IFTTT recipe using Google Assistant (or any other service) as an "If this..." condition.

If you're using Google Assistant, use the following settings:
![GA](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Capture.2.PNG)

Then, connect a "then that!" condition to use a webhook, we'll be pointing the webhook action at the Blynk HTTP API, setting a virtual pin 
that will be automatically updated on our boards (and without using the app dashboard)

![webhook](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w4-connect-all-the-things/Capture.PNG)

The API format is as follows:
`http://blynk-cloud.com/{YOUR_AUTH_TOKEN}/update/{PIN}?value={VALUE}`

In our example, we're using virtual pin 32, and write the IFTTT ingredient value to {VALUE}

[You can find more documentation of the Blynk HTTP API here.](https://blynkapi.docs.apiary.io/#)

## Sketch

The sketch is provided in this folder, make sure you replace the relevant wifi credentials and Blynk authentication token.
