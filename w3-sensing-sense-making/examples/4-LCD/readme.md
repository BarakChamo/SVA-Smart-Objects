
# Using an LCD breakout

This example will show you how to use the 1602A 16x2 LCD screens that are bundled with your electronics kits.

Notice the pins in the sketch and follow the diagram, the sketch is the original Arduino example with modified pins.

Note: the operating voltage of the Feather board is 3.3v which is enough to power the LCD but not for a super clear image.

### Schematic
![schematic](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w3-sensing-sense-making/examples/4-LCD/LCD%20circuit.png)

### Circuit
![circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w3-sensing-sense-making/examples/4-LCD/circuit.jpg)


### Pins

LCD Pin | Feather pin
------------ | -------------
VSS | GND
VDD | 3.3V
V0 | GND
RS | 14
RW | GND
E | 32
D4 | 15
D5 | 33
D6 | 27
D7 | 12
A | 3.3v
K | GND

### Code
[The sketch is available here](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w3-sensing-sense-making/examples/4-LCD/4-LCD.ino)
