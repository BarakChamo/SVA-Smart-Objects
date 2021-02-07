# Example 2 - building a clap light!

This example will show you how to read and process an incoming analog signal from a small microphone sensor to turn an LED on and off after two quick claps are detected.

### In class
Try to follow the circuit schematics and implement the code for clap detection on your own.
The code follows a simple principle of threashold detection on the incoming signal, as depicted here:
![threashold](https://www.researchgate.net/publication/307823015/figure/fig10/AS:404546577813514@1473462828593/Detection-of-sonar-signals-and-measurement-threshold-for-the-two-way-travel-time-time-of.png)

Begin with detecting a single clap, and then incorporate additional timing to only toggle the lights when claps are detected in quick succesion.

DON'T GO STRAIGHT FOR THE CODE SAMPLE! THAT'S NO FUN!

### Circuit
![circuit](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w3-sensing-sense-making/examples/2-clap-light/WIN_20210129_23_18_05_Pro.jpg)

### Schematic
![schematic](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w3-sensing-sense-making/examples/2-clap-light/clap%20light.png)

### Code
[Code is available here](https://github.com/BarakChamo/SVA-Smart-Objects/blob/main/w3-sensing-sense-making/examples/2-clap-light/2-clap-light.ino)
