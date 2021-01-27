# Basic analog circuits

## Lighting up an LED
Let's begin with a simple circuit, lighting up an LED.
This is a simple 5V DC circuit, review the following schematic:
![basic analog circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/1-basic-analog/basic%20analog%20circuit.jpg)

**What we'll need for this circuit:**
- Breadboard
- Breadboard power supply
- An LED (any color)
- A 220 Ohm resistor
- bridge jumpers

You can also review this schematic to build the circuit:
![](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/1-basic-analog/basic%20potentiometer%20circuit.png?raw=true)

This is a series DC circuit, meaning that all components are connected in series, one after another, and electricity flows in a single path from power to ground, lighting up the LED along the way.

**questions**
- Why are we using a 220Ohm resistor in series with the LED?
- What would be the effect of different resistors on the LED's brightness?


## Adding a button

Let's now add a button so we can turn our LEDs on and off, the circuit still runs in series, but a button is added to break the circuit.

This is the new circuit with the added button:
![button circuit photo](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/1-basic-analog/WIN_20210122_22_52_22_Pro.jpg)

These buttons are available in your kits, notice that they have 4 legs that fit over the bridge, each two are connected and the connection is bridged when the button is pressed - this makes it possible to use the button over the breadboard bridge.

You can refer to the updated schematic:
![button circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/1-basic-analog/basic%20button%20circuit.png)

## Adding a potentiometer
Finally, let's swap our button for a potentiometer to have variable control over the LED's brightness.

![potentiometer circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/1-basic-analog/WIN_20210122_22_58_18_Pro.jpg)

A potentiometer is a variable resistor, as you turn the dial, the connceted surface of the resistive material grows and resistance increases. Resistors come in different shapes and sizes are are rated by their maximum resistance.

![potentiometer](https://components101.com/sites/default/files/component_pin/potentiometer-pinout.png)
With the two fixed pins connected to power and ground, the middle variable pin will provide variable resistance.

You can refer to the udpated schematic:
![potentiometer schematic](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w2-pcomp-bootcamp/examples/1-basic-analog/basic%20potentiometer%20circuit.png)

**questions**
- Why are we using a 220Ohm resistor as well as a potentiometer in series with the LED?



