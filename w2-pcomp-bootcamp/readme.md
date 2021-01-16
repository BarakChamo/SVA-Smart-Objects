
# Smart Objects Week 2 - Physical Computing Bootcamp

## Contents
- [what is physical computing?](#what-is-physical-computing)
- [Electronics fundamentals](#electronics-fundamentals)
  - [Voltage](#voltage)
  - [Current](#current)
  - [Resistance and Ohm's law](#resistance-and-ohms-law)
  - [DC Circuits](#dc-circuits)
- [Component Glossary](#component-glossary)
  - [Circuit notation](#circuit-notation)
- [Tools of the Trade](tools-of-the-trade)
  - [Multimeter](#multimeter)
  - [Breadboard](#breadboard)
- [Hello Arduino](#hello-arduino)
- [Introduction to the ESP32](#introduction-to-the-esp32)
- [Alternative IoT Platforms](#alternative-iot-platforms)

## Example projects
- [Basic circuits]()
- [Hello World]()
- [Serial read and write]()
- [First Blink and PWM]()
- [Working with analog inputs and outputs]()
- [Working with digital inputs and outputs]()
- [Timing and flow control]()

## Additional readings
- [Introduction to basic circuits](https://learn.sparkfun.com/tutorials/what-is-a-circuit/all)

-----

## What is Physical Computing?
Physical computing is the creation of computer systems that interact with the physical world and physical body.
It provides tools that bridge the analog and digital worlds. From
the inputs of sensors to environment to outputting light, sound, and/or motion,
interaction becomes possible, and through coding, endlessly customizable. 

Using microcontrollers, sensors, and actuators we will study the principles
of tangible systems, embodied HCI and protoypes new forms of interactive systems.

Physical computing skills will serve you well as you venture off to prototype, design and build
smart objects, interactive installations, robots or any product with a computer in it.

-----

## Electronics fundamentals

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


### Voltage
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

### Current
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

### Resistance and Ohm's Law
[A brief explaination of Ohm's law](https://www.youtube.com/watch?v=HsLLq6Rm5tU)

[Another great visual demonstration of Ohm's law](https://www.youtube.com/watch?v=8jB6hDUqN0Y&feature=emb_title)

[Ohm's law calculator](https://theengineeringmindset.com/ohms-law-calculator/)

Consider again our two water tanks, one with a narrow pipe and one with a wide pipe.

![Amperage as pressure equalization](https://cdn.sparkfun.com/assets/6/f/b/5/3/5113d1c3ce395fcc7d000000.png)

It stands to reason that we can't fit as much volume through a narrow pipe than a wider one at the same pressure. This is resistance. The narrow pipe "resists" the flow of water through it even though the water is at the same pressure as the tank with the wider pipe.

![resistance as water pressure control](https://cdn.sparkfun.com/assets/d/8/e/8/b/5114247dce395f1e7e000008.png)

In electrical terms, this is represented by two circuits with equal voltages and different resistances. The circuit with the higher resistance will allow less charge to flow, meaning the circuit with higher resistance has less current flowing through it.

This brings us to Georg Ohm. Ohm defines the unit of resistance of "1 Ohm" as the resistance between two points in a conductor where the application of 1 volt will push 1 ampere, or 6.241×10^18 electrons. This value is usually represented in schematics with the greek letter "Ω", which is called omega, and pronounced "ohm".

#### Ohm's Law (or how to put all this to practice)


Combining the elements of voltage, current, and resistance, Ohm developed the formula:

![_](https://cdn.sparkfun.com/assets/a/5/0/2/6/5113d140ce395f777e000000.gif)

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

### DC Circuits
[An introduction to DC circuits in series](https://www.youtube.com/watch?v=VV6tZ3Aqfuc)

[An introduction to DC circuits in parallel](https://www.youtube.com/watch?v=5uyJezQNSHw)

[In depth overview of DC circuits on Sparkfun](https://learn.sparkfun.com/tutorials/series-and-parallel-circuits)

-----

## Component Glossary

### Circuit notation
Each of the following components, and many others, have a marked notation that makes them easy to identify in circuit diagrams. 
Familiarize yourselves with the notations and use them to refer to shared circuits and document your own.

![component notation](http://s3-ap-southeast-1.amazonaws.com/subscriber.images/physics/2017/08/23084723/Electric-Circuit-Symbols.png)

These components are then organized in circuit diagrams such as this one:

![circuit diagram](https://electronarrative.files.wordpress.com/2015/02/7-basic-plots-7-rebirth.png)

Always identify and note the power source, which indicates the polarity and direction of the circuit - as a rule the large line is always the positive, and the thicker short line is negative.

![power notation](https://www.electronicsclub.info/symbols/cell.gif)

These may come in many variations but share the same principle and their polarity is clearly discernible.
![DC power supply](https://www.electronicsclub.info/symbols/dcsupply.gif)
![battery pack](https://www.electronicsclub.info/symbols/battery.gif)

[Refer to this list for a comprehensive review of circuit symbols.](https://www.electronicsclub.info/circuitsymbols.htm)

### Resistors

### Potentiometers

### Capacitors
[A brief exaplaination of capacitors](https://www.youtube.com/watch?v=X4EUwTwZ110)

### Diodes
[A brief exaplaination of diodes](https://www.youtube.com/watch?v=Fwj_d3uO5g8)

#### Light emitting diodes (LEDs)

#### Transistors

#### Switches

## Tools of the Trade

### Multimeter
[A very detailed overview of multimeters](https://learn.sparkfun.com/tutorials/how-to-use-a-multimeter)

A multimeter or a multitester, is an electronic measuring instrument that combines several measurement functions in one unit. 
A typical multimeter can measure voltage, current, and resistance as well as continuity, or if a circuit is open or closed.

Multimeters come in many shapes and sizes but generally feature a reading display and a dial for mode setting and sensitivity (calbirating the multimeter for voltage and current ranges).

![Multimeter example](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/1/01_Multimeter_Tutorial-01.jpg).

Multimeter probes are used to contact points in the circuit we wish to test.

![Multimeter used](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/1/01_Multimeter_Tutorial-19.jpg)


### Breadboard
[A very detailed overview of breadboards](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard)

![breadboard](https://cdn.sciencebuddies.org/Files/7304/6/breadboard-hole-leads.jpg)

A breadboard is a construction base for prototyping of electronics, also known as a solderless board or plugboard. Breadboards make it easy to prototype circuits by plugging
components into connected terminals without the need for soldering, making the process quick and the components reusable, it is an invaluable tool for quick physical computing iteration but understanding the topology of a breadboard is key to using it well.


To understand how power flows in a typical breadboard, let's look at it's bottom with the adhesive pad removed:
![breadboard back](https://static1.makeuseofimages.com/wp-content/uploads/2018/06/breadboard_back_peel_670.jpg?q=50&fit=crop&w=750&dpr=1.5)

As you can see, certain pins are connected by long metal strips, making them "essentially the same pin". this allows us to establish direct connection
between pins that are mounted on the same strip, and what make the "solderless contact".

So why are some pins connected and others not? and why are the orientations different?

Let's review the topology of a breadboard:
![breadboard topology](https://static1.makeuseofimages.com/wp-content/uploads/2018/06/breadboard_annotated_670-1.jpg?q=50&fit=crop&w=750&dpr=1.5)

Most larger breadboards wil have two long lines on either side noted as `+` or `-`, these are the power terminals that are meant to make power delivery
and circuit continuity easy across the breadboard. Note that the two sides are not connected, and you'll have to bridge them on your own if you want.

The rest of the pin grid is marked by row and column, with every half row connected before and after the middle divider:
![pin grid](https://cdn.sciencebuddies.org/Files/7326/6/breadboard-row-connections.png)

why the middle divider? to double the amount of usable space on a breadboard and to facilitate mounting microcontrollers.

Let's review a simple diagram circuit to understand how breadboards are used:
![breadboard diagram](https://cdn.tutsplus.com/mac/uploads/2013/10/completecircuit.png)

What's happening in this circuit:
- The power source (battery bank) is connected to the power terminals - notice the red, or positive charge is connected to the red terminal and the ground, or negative charge, is connected to the blue terminal - this is just a convention but one you should follow if you don't want to accidentally fry your Arduinos at 3AM.
- A power line is connecting the red power terminal to a button in row F6, this feeds power into the circuit - notice it is in the same row and half as the top pin of the button, so they are connected by the breadboard's internal bridges.
- The bottom pin of the button is connected to the top pin of an LED -again notice how components are placed vertically, so their pins are not conencted to one another, while connection line are placed horizontally to essentially connected the components without soldering - this is the magic of breadboards.
- In the final connection, a resistor is placed vertically, this is done to save in wires and connections, and conncets the bottom leg of the LED to the final connection.
- The last black connection is running back to the ground terminal, thus completing the circuit - when the button is pressed, the LED will light up!

-----

## Hello Arduino
Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards are able to read inputs - light on a sensor, a finger on a button, or a Twitter message - and turn it into an output.

Arduino simplifies the process of working with microcontrollers by offering a unified environment for a a range of boards, sensors, and compatible hardware - that means that you don't have to dig through long data sheets, run command line compilers, etc. The Arduino community is both vibrant and helpful and many projects, from controlling programmable LEDs to a plethora of sensors, are available and well documented.

To use Arduino install the [Arduino Development Enviroment](https://www.arduino.cc/en/software) for your operating system and follow this [AdaFruit guide to set up your Feather board in the Arduino board manager](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/using-with-arduino-ide).

### The Arduino IDE
As mentioned, Arduino proejcts are programmed in the Arduino IDE (Integrated Development Environment), Arduino's IDE features:
- Code editor - where you write your Arduino "sketches"
- Board manager - where you manage your various microcontrollers
- Library manager - where you can find and use a range of pre-written libraries
- Compiler - that will build and load your sketches to your board
- Serial monitor - that will show you a log of all serial communication and allow you to entre simple serial commands

![Arduino IDE](https://core-electronics.com.au/media/wysiwyg/tutorials/aidan/arduino-ide.png)

The IDE's serial monitor also features a nifty serial plotter that is incredibly useful in understanding input and output signals.
![Serial plotter](https://arduinogetstarted.com/images/tutorial/arduino-serial-plotter-single-graph.jpg)

### Anatomy of Arduino Sketches
[Arduino language reference](https://www.arduino.cc/reference/en/)

Arduino projects are writed in a slightly modified version of C++.

Every Arduino project starts with two predefined methods `setup()` and `loop()`, this is part of a loop-based programming model that would be familiar if you've used Processing or P5.js before.

The `setup()` method is called once, when your sketch begins execution on the microcontroller and is only called once. This is where you'll perform all dynamic initialization, like activating sensors, connecting to WiFi, preparing arrays and defining initial application state.

The `loop()` method is executed right after the `setup()` completes and repeats forever (or until your code explodes). The loop is the meat and potatoes of your Arduino sketch and is where you'll repeatedly read input data, perform calculations, modify application state and write to outputs.

An app-loop model implies several design considerations, 

More on that in the examples and in class.

### Elements of Microcontrollers

The two elements of physical computing projects are, well, the physical, and the computing. How does these relate to Arduino?

![Arduino GPIO pinout](https://tse3.mm.bing.net/th?id=OIP.J3GeuERadqLEq3hBtAhh-gHaGU&pid=Api)

Arduino's board architecture (or any microcontroller for that matter) is made of many different components but at a high level is made of two parts:
- MCU (or Microcontroller unit) - this is the black bar in the diagram, the brain of the Arduino that integrates the CPU, memory and other core components of the "on board computer"
- GPIO (general purpose inputs and outputs) - these are the pins on the sides of the board - they are the device's "senses" and provide an interface to digital and analog inputs and outputs.

Most of our work with microcontrollers is to sense the world around us using GPIO inputs, process that information and respond to it by sending outputs to output GPIO or communicating it with other devices.

The Arduino language and libraries make working with inputs and outpus extremely easy, and abstract most of the low level operations that are required to interface the MCU with the GPIO. This means we can code at a higher level of abstraction, concering mostly with the meaning and operation of inputs and outputs, and frees our minds to be more creative with physical computing.

-----

## Introduction to the ESP32 and AdaFruit Feather 
The microcontroller you received from IxD is an [Adafruit Feather Huzzah 32](https://www.adafruit.com/product/3405). It's a small board that packs a serious punch, based on the [Espressif ESP32](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/esp32-faq), a dual-core microcontroller that features built-in WiFi, Bluetooth, battery power and flash memory.

The ESP32 is compatible with the Arduino runtime, meaning that you can program it using the [Arduino language and the Arduino IDE](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/using-with-arduino-ide
), but still [benefit from the power of the ESP32 board](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather
).

We chose the Adafruit board for you because Adafruit provides a wealth of educational information and the board is compatible with the [Adafruit Feather Wing modular extension system.](https://learn.adafruit.com/adafruit-feather)

#### Moving forward with ESP32 based boards and microcontrollers

The great this about the ESP32 platform, especially when coupled with Arduino-based development, is that you can easily move your project to another board with more features or a different layout, with minimal changes to your code.

For example, if you want to connect your ESP32 project to a screen and read data from an SD card, you could swap the Adafruit Feather for a [Lolin D32 Pro 2.0](https://www.wemos.cc/en/latest/d32/d32_pro.html) that has built in SD card and TFT screen interfaces. Or, if you're looking for a more polished controller, with built in screen and buttons, you could opt for the ESP32 based [M5 Stack modular platform](https://m5stack.com/).

### Alternative IoT Platforms
