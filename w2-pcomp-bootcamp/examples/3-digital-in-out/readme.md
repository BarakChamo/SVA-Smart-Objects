# Digital ins and outs

The magic of microcontrollers such as the Adafruit Feather and Arduino boards, is the simplicity with which they allow us to "get out of the box" and interface with the physical world! Turn things on and off, use sensors, move motors, all by leveraging the power of GPIO - General Purpose Inputs and Outputs


### Digital interfaces

Most Arduino board GPIO, the feather included, have two modes of operation: `Digital` and `Analog`.
- `Analog` - analog interfaces work by reading or modulating a pin's voltage and give a continuous range of values, think of how a potentiomter allows us to change resistance, and hence voltage potential, on a continuous scale. Analog inputs and outputs are great for interfacing with analog components such as potentiometers, lights, motors and other components that we can control or read values from based on voltage levels in an analog circuit.
- `Digital` - digital interfaces use the voltage level as a reference, modulating values between `GND` and `REF` (typically 3 or 5 volts) to send data at certain speeds - this is how all computers and other digital electronics work. Digital interfaces are usually used to control more complex electronics, where a simple analog value is not enough and more data needs to be sent to received.

In this example however, we're going to use the digital interface as a simple `On/Off` gate, reading values as 0 or 1 and using them to turn LEDs on and off.

### The circuit

As you can see, this circuit features both the microcontroller and other analog components, connected and controlled by GPIO. It uses one pin to read the status of a button, and two pins to turn LEDs on and off.

![digital circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/3-digital-in-out/WIN_20210123_02_26_20_Pro.jpg)

Included components:
- breadboard
- Adafruit Feather 32
- Bridge jumpers
- Button
- 2X Leds (any color)
- 3X 220 Ohm resistors

You can follow this circuit diagram to complete the circuit, start with one LED and then add the other.
![button circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/3-digital-in-out/digital%20circuit.png?raw=true)
**Make sure you connect all components to the correct GPIO pins**

### The code
Open this folder in the Arduino IDE to see the sketch for this example, notice the setup of each pin, and how they correspond to our circuit configuration.

### Questions
- why are we using a resistor in series with the button?
- can you implement a different button function? a toggle press instead of a momentary press?
