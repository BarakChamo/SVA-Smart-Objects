
# Smart Objects Week 2 - Physical Computing Bootcamp

## Contents
- [what is physical computing?](#what-is-physical-computing)
- [Electronics fundamentals](#electronics-fundamentals)
  - [Voltage](#voltage)
  - [Current](#current)
  - [Resistance and Ohm's law](#resistance-and-ohms-law)
  - [DC Circuits](#dc-circuits)
- [Component Glossary](#component-glossary)
- [Tools of the Trade](tools-of-the-trade)
- [Hello Arduino](#hello-arduino)
- [Introduction to the ESP32](#introduction-to-the-esp32)
- [Alternative IoT Platforms](#alternative-iot-platforms)

### What is Physical Computing?
Physical computing is the creation of computer systems that interact with the physical world and physical body.
It provides tools that bridge the analog and digital worlds. From
the inputs of sensors to environment to outputting light, sound, and/or motion,
interaction becomes possible, and through coding, endlessly customizable. 

Using microcontrollers, sensors, and actuators we will study the principles
of tangible systems, embodied HCI and protoypes new forms of interactive systems.

Physical computing skills will serve you well as you venture off to prototype, design and build
smart objects, interactive installations, robots or any product with a computer in it.

### Electronics fundamentals

All physical computing project are, essentially, small computers that interact with
custom circuits, be it as simple as an Arduino detecting button clicks and lighting up
an LED or a WiFi-enabled controller that senses temperature and moisture levels and 
alerts you to water your basil in time. Before we get to the computing part (by programmming microcontrollers) it's important
to get a good grasp on the physical, or electrical side of things.

Electronics is a broad topic and can be discussed and understood at many levels, from atoms to circuits to appliances.
For the purpose of this introduction, we will acknowledge electric current as the flow of electrons, used to power
electronic devices and electrical circuits, and focus our attention to the control, direction and manipulation of
that current to drive our own circuits and components that require certain amounts of electricity over time.

It is often useful to understand the basic mechanics of electrical flow through the water metaphor, thinking
of the flow of electrons along an electrical circuit as water flowing through a pipe system. While this metaphor
is not 100% physically accurate, it is sufficient for understanding basic principles of electrical potential and charge,
how these translate to voltage and current, and how they can be manipulated.


#### Voltage
[A brief explaination of volatage on YouTube](https://www.youtube.com/watch?v=w82aSjLuD_8)
[More info about the physics behind voltage and electrical potential](https://www.youtube.com/watch?v=z8qfhFXjsrw&feature=emb_title)

We define voltage as the amount of potential energy between two points on a circuit. One point has more charge than another. This difference in charge between the two points is called voltage. It is measured in volts, which, technically, is the potential energy difference between two points that will impart one joule of energy per coulomb of charge that passes through it (don't panic if this makes no sense, all will be explained). The unit "volt" is named after the Italian physicist Alessandro Volta who invented what is considered the first chemical battery. Voltage is represented in equations and schematics by the letter "V".

When describing voltage, current, and resistance, a common analogy is a water tank. In this analogy, charge is represented by the water amount, voltage is represented by the water pressure, and current is represented by the water flow. So for this analogy, remember:

- Water = Charge
- Pressure = Voltage
- Flow = Current

Consider a water tank at a certain height above the ground. At the bottom of this tank there is a hose.

![voltage as water pressure](https://cdn.sparkfun.com/assets/e/8/8/4/8/5113d1c3ce395fc87d000000.png)

The pressure at the end of the hose can represent voltage. The water in the tank represents charge. The more water in the tank, the higher the charge, the more pressure is measured at the end of the hose.

We can think of this tank as a battery, a place where we store a certain amount of energy and then release it. If we drain our tank a certain amount, the pressure created at the end of the hose goes down. We can think of this as decreasing voltage, like when a flashlight gets dimmer as the batteries run down. There is also a decrease in the amount of water that will flow through the hose. Less pressure means less water is flowing, which brings us to current.

#### Current
[A brief explaination of current on YouTube](https://www.youtube.com/watch?v=kcL2_D33k3o)
[Another great review of electrical current](https://www.youtube.com/watch?v=kYwNj9uauJ4&feature=emb_title) 

We can think of the amount of water flowing through the hose from the tank as current. The higher the pressure, the higher the flow, and vice-versa. With water, we would measure the volume of the water flowing through the hose over a certain period of time. With electricity, we measure the amount of charge flowing through the circuit over a period of time. Current is measured in Amperes (usually just referred to as "Amps"). An ampere is defined as 6.241*10^18 electrons (1 Coulomb) per second passing through a point in a circuit. Amps are represented in equations by the letter "I".

Let's say now that we have two tanks, each with a hose coming from the bottom. Each tank has the exact same amount of water, but the hose on one tank is narrower than the hose on the other.

![Current as water flow](https://cdn.sparkfun.com/assets/6/f/b/5/3/5113d1c3ce395fcc7d000000.png)

We measure the same amount of pressure at the end of either hose, but when the water begins to flow, the flow rate of the water in the tank with the narrower hose will be less than the flow rate of the water in the tank with the wider hose. In electrical terms, the current through the narrower hose is less than the current through the wider hose. If we want the flow to be the same through both hoses, we have to increase the amount of water (charge) in the tank with the narrower hose.

![Amperage as water pressure](https://cdn.sparkfun.com/assets/7/6/4/b/6/5113dc8fce395fe201000001.png)

This increases the pressure (voltage) at the end of the narrower hose, pushing more water through the tank. This is analogous to an increase in voltage that causes an increase in current.

Now we're starting to see the relationship between voltage and current. But there is a third factor to be considered here: the width of the hose. In this analogy, the width of the hose is the resistance. This means we need to add another term to our model:

- Water = Charge (measured in Coulombs)
- Pressure = Voltage (measured in Volts)
- Flow = Current (measured in Amperes, or "Amps" for short)
- **Hose Width = Resistance**

#### Resistance and Ohm's Law
[A brief explaination of Ohm's law](https://www.youtube.com/watch?v=HsLLq6Rm5tU)
[Another great visual demonstration of Ohm's law](https://www.youtube.com/watch?v=8jB6hDUqN0Y&feature=emb_title)
[Ohm's law calculator](https://theengineeringmindset.com/ohms-law-calculator/)

Consider again our two water tanks, one with a narrow pipe and one with a wide pipe.

![Amperage as pressure equalization](https://cdn.sparkfun.com/assets/6/f/b/5/3/5113d1c3ce395fcc7d000000.png)

It stands to reason that we can't fit as much volume through a narrow pipe than a wider one at the same pressure. This is resistance. The narrow pipe "resists" the flow of water through it even though the water is at the same pressure as the tank with the wider pipe.

![resistance as water pressure control](https://cdn.sparkfun.com/assets/d/8/e/8/b/5114247dce395f1e7e000008.png)

In electrical terms, this is represented by two circuits with equal voltages and different resistances. The circuit with the higher resistance will allow less charge to flow, meaning the circuit with higher resistance has less current flowing through it.

This brings us to Georg Ohm. Ohm defines the unit of resistance of "1 Ohm" as the resistance between two points in a conductor where the application of 1 volt will push 1 ampere, or 6.241×10^18 electrons. This value is usually represented in schematics with the greek letter "Ω", which is called omega, and pronounced "ohm".

##### Ohm's Law (or how to put all this to practice)


Combining the elements of voltage, current, and resistance, Ohm developed the formula:

alt text
Where

V = Voltage in volts
I = Current in amps
R = Resistance in ohms
This is called Ohm's law. Let's say, for example, that we have a circuit with the potential of 1 volt, a current of 1 amp, and resistance of 1 ohm. Using Ohm's Law we can say:

![A](https://cdn.sparkfun.com/assets/8/7/5/3/0/5112d060ce395f432a000000.gif)
Let's say this represents our tank with a wide hose. The amount of water in the tank is defined as 1 volt and the "narrowness" (resistance to flow) of the hose is defined as 1 ohm. Using Ohms Law, this gives us a flow (current) of 1 amp.

Using this analogy, let's now look at the tank with the narrow hose. Because the hose is narrower, its resistance to flow is higher. Let's define this resistance as 2 ohms. The amount of water in the tank is the same as the other tank, so, using Ohm's Law, our equation for the tank with the narrow hose is

![B](https://cdn.sparkfun.com/assets/6/c/a/b/5/5112d060ce395f1c27000001.gif)
But what is the current? Because the resistance is greater, and the voltage is the same, this gives us a current value of 0.5 amps:

![C](https://cdn.sparkfun.com/assets/a/f/6/e/7/5112d060ce395fb227000001.gif)

![measurements](https://cdn.sparkfun.com/assets/3/a/c/7/6/5113d1c3ce395fec01000000.png)

#### DC Circuits
[An introduction to DC circuits in series](https://www.youtube.com/watch?v=VV6tZ3Aqfuc)
[An introduction to DC circuits in parallel](https://www.youtube.com/watch?v=5uyJezQNSHw)

### Component Glossary

#### Capacitors
[A brief exaplaination of capacitors](https://www.youtube.com/watch?v=X4EUwTwZ110)

#### Diodes
[A brief exaplaination of diodes](https://www.youtube.com/watch?v=Fwj_d3uO5g8)


### Tools of the Trade

### Hello Arduino
Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards are able to read inputs - light on a sensor, a finger on a button, or a Twitter message - and turn it into an output.

Arduino simplifies the process of working with microcontrollers by offering a unified environment for a a range of boards, sensors, and compatible hardware - that means that you don't have to dig through long data sheets, run command line compilers, etc. The Arduino community is both vibrant and helpful and many projects, from controlling programmable LEDs to a plethora of sensors, are available and well documented.

To use Arduino install the [Arduino Development Enviroment](https://www.arduino.cc/en/software) for your operating system and follow this [AdaFruit guide to set up your Feather board in the Arduino board manager](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/using-with-arduino-ide).

### Elements of Microcontrollers

### Introduction to the ESP32 and AdaFruit Feather 
The microcontroller you received from IxD is an [Adafruit Feather Huzzah 32](https://www.adafruit.com/product/3405). It's a small board that packs a serious punch, based on the [Espressif ESP32](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/esp32-faq), a dual-core microcontroller that features built-in WiFi, Bluetooth, battery power and flash memory.

The ESP32 is compatible with the Arduino runtime, meaning that you can program it using the [Arduino language and the Arduino IDE](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/using-with-arduino-ide
), but still [benefit from the power of the ESP32 board](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather
).

We chose the Adafruit board for you because Adafruit provides a wealth of educational information and the board is compatible with the [Adafruit Feather Wing modular extension system.](https://learn.adafruit.com/adafruit-feather)

#### Moving forward with ESP32 based boards and microcontrollers

The great this about the ESP32 platform, especially when coupled with Arduino-based development, is that you can easily move your project to another board with more features or a different layout, with minimal changes to your code.

For example, if you want to connect your ESP32 project to a screen and read data from an SD card, you could swap the Adafruit Feather for a [Lolin D32 Pro 2.0](https://www.wemos.cc/en/latest/d32/d32_pro.html) that has built in SD card and TFT screen interfaces. Or, if you're looking for a more polished controller, with built in screen and buttons, you could opt for the ESP32 based [M5 Stack modular platform](https://m5stack.com/).

### Alternative IoT Platforms
