
# Smart Objects Week 2 - Physical Computing Bootcamp

## Contents
- [what is physical computing?](#what-is-physical-computing)
- [Electronics fundamentals](#electronics-fundamentals)
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



#### Voltage
[A brief explaination of volatage on YouTube](https://www.youtube.com/watch?v=w82aSjLuD_8)

#### Current
[A brief explaination of current on YouTube](https://www.youtube.com/watch?v=kcL2_D33k3o)

#### Resistance and Ohm's Law
[A brief explaination of Ohm's law](https://www.youtube.com/watch?v=HsLLq6Rm5tU)
[Ohm's law calculator](https://theengineeringmindset.com/ohms-law-calculator/)

##### Why do I need to know this?!

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
