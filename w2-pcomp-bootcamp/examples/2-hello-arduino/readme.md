
# Hello Arduino!

Let's upload our first sketch to our boards!

Since we're using an Arduino-compatible board (AdaFruit's Feather Huzzah32), we can write sketches in C++, use Arduino libraries and upload them to our board using the Arduino IDE.

Writing our own microcontroller programs, or sketches, gives us complete control over the behaviour of our board, how it interfaces with physical inputs and physical outputs. For now though, let's begin with a simple sketch that introduces communication over a serial connection.

### Setting up our board

Most Arduino boards, our Feather included, can be powered from USB as well as directly from power and ground pins.

Note the `3v`, `USB` and  `GND` pins on the board:
![feather schematic](https://s3.amazonaws.com/learn-production/guides/images/000/001/641/medium800/thumb.jpg?1494450119)

The Adafruit Feather has a built is power regulator and can convert 5V coming in from the USB port or `USB` pin to its 3.3v operating voltage, you can also power it will 3.3v directly from the `3v` pin, with `GND` connected to common ground.

Being able to power the board from the GPIO pins makes it possible to power our circuits without USB connections, having a standalone prototype that doesn't require a computer and can even be powred from a battery pack.

Here is an example schematic on how to set up your board with power connections on a breadboard:
![power schematic](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/2-hello-arduino/power%20microcontroller.png)

### Uploading sketches
While we can power the board from USB and GPIO, we can only flash sketches when the board is connected to our computer, you can find instructions on how to set up the Arduino IDE with your Adafruit Feather Huzzah 32 boards.

### Basic sketch - serial interface
Open this folder with the Arduino IDE to review, edit and upload the first sketch.

This example shows the basic parts of an Arduino sketch, the `setup()` and `loop()` functions and how to interface with the serial monitor.

With the sketch open and the board connected, press the Upload button and when done, open the serial monitor.
Try typing `Hello!` into the serial monitor's input field!

### Further reference
- [Arduino's `setup()` function](https://www.arduino.cc/reference/en/language/structure/sketch/setup/)
- [Arduino's `loop()` function](https://www.arduino.cc/reference/en/language/structure/sketch/loop/)
- [Arduino's Serial library](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
