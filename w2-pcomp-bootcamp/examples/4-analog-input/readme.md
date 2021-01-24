
# Analog inputs

Analog inputs allow us to sense the physical world using a wide range of analog sensors, electronic components that vary in resistance based on different physical properties.

These include:
- potentiometers (think of these as interaction sensors)
- light sensors
- humidity sensors
- basic microphone (loudness sensors)
- pressure sensors
and many many more.

Our Adafruit Feather boards are capable of sensing this variabibility in resistance, and thus incoming voltage between 0 or our reference voltage (typically 3 or 5 volts, 3 in our case) and map those to a value range. This allows for more fine grained control compared to digital reads that are either on or off (unless, of course, you're using a digital sensor).

The great thing about working with analog sensors, as you'll see in this example, is that you can keep the same code and protoype many different kinds of interactions using a range of analog sensors.

### The circuit - potentiometer

We'll begin by reading a continuous range of values from a potentiometer, treating it as a sensor and using that value to control the blinking rate of an LED.

![pot circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/4-analog-input/WIN_20210123_11_54_25_Pro.jpg?raw=true)

You can follow this circuit schematic
![pot schematic](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/4-analog-input/analog%20circuit.png?raw=true)

**Notice the GPIO numbers when connecting inputs and outputs**

### The code
Open this folder in the Arduino IDE to upload the sketch to your board.
Turn the dial on your potentiometer and notice the flashing rate of the LED.

**questions**
1. We're using a `delay()` call to control the timing of our loop, which halts all execution. This is fine for simple sketches but makes multitasking a challenge, can you think of another way to accomplish this task?

### The circuit - photoresistor

As mentioned, using analog sensors and an analog read makes it very easy to swap sensors, let's change up the circuit to use a photoresistor (light sensor):
![photo circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/4-analog-input/WIN_20210123_12_33_11_Pro.jpg?raw=true)

You can follow this circuit diagram
![photo schematic](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/4-analog-input/analog%20sensor%20circuit.png)

Notice that in addition to swapping the sensor, we are adding another resistor that goes to ground, this kind of circuit is called a "resistance divider", why?

The analog GPIO pins are capable of reading voltage variation that is the result of changing resistance on our sensors, but different sensors have different resistance ranges and the board can't automatically guess them all. Potentiometers make this process easy because they typically go all the way from no resistance, or very little, to a lot, but other sensors will have variable ranges.

By connecting the GPIO pin in the middle of the "resistance divider" circuit, the voltage detected will not rely on "absolute resistance" but on the ratio between the first and second resistor. Since photo resistors operate in the range of 1M ohm in darkness to 10k ohm in daylight (10 lumen) and less than 1k ohm in bright daylight, matching the midrange with a 10k ohm resistor will give us a usable range.

### Further reading
- [Arduino Analog input](https://www.arduino.cc/en/pmwiki.php?n=Tutorial/AnalogInput)
- [Arduino analogRead()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)
- [Arduino map()](https://www.arduino.cc/reference/en/language/functions/math/map/)
