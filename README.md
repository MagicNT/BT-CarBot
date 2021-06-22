# Bluetooth GUI Remote Controlled Arduino-Based 4-Wheels Car Bot

## Objective
The purpose behind this project is to implement a 4-wheels car bot that is Arduino-based and that is remote controlled via Bluetooth through a Processing Graphical User Interface (GUI) that we developed specifically for this project.

## Background
Arduino is an open-source hardware and software company, project and user community that designs and manufactures single-board microcontrollers and microcontroller kits for building digital devices and interactive objects that can sense and control objects in the physical and digital world. Its products are licensed under the GNU Lesser General Public License (LGPL) or the GNU General Public License (GPL), permitting the manufacture of Arduino boards and software distribution by anyone. Below is a picture of the Arduino bard used in this project, it is an Arduino Uno SMD board:

![1](https://user-images.githubusercontent.com/86275885/122963297-8498f200-d35c-11eb-978b-c83c0f9318a4.jpg)


The Arduino Uno, the successor to the Arduino Duemilanove, is a microcontroller board based on a surface-mounted (SMD) ATmega328 AVR microcontroller. It has 20 digital input/output pins (of which 6 can be used as PWM outputs and 6 can be used as analog inputs), a 16 MHz resonator, a USB connection, a power jack, an in-circuit system programming (ICSP) header, and a reset button. The Arduino has an extensive support community, which makes it a large surface for library development with embedded electronics.


## Design Components

### Hardware:
- Arduino Uno SMD microcontroller
- Metal chassis to hold all components and wheels
- 4 plastic wheels
- 4 carbon brush 130 DC high speed small motor high torque
- 6V external battery source (made up of 4 internal AA batteries each 1.5V)
- L298N Dual H-Bridge Motor Controller
- Small half-size breadboard
- Female-Male-Mixed jump wires
- HC-06 Low Energy Bluetooth Module (up to 10m of connectivity)
- Computer with 2 USB ports + Bluetooth Remote Port Built-in
- USB-to-Arduino 3.0 cable cord


### Software:
- Computer running Microsoft Windows OS
- Arduino IDE 
- Processing 3
- Bluetooth Virtual Stack Serial Communicator from Toshiba
- Arduino IDE Serial Terminal for debugging


## Hardware Overview

- L298N Dual H-Bridge Motor Controller:

![2](https://user-images.githubusercontent.com/86275885/122963723-ec4f3d00-d35c-11eb-9f38-20cbd0d5d6d3.jpg)

- 4 Carbon brush 130 DC high speed small motor high torque:

![3](https://user-images.githubusercontent.com/86275885/122963740-ef4a2d80-d35c-11eb-84a3-ebe3a45398c2.jpg)

These motors can be controlled to rotate in both clockwise and anti-clockwise directions simply by varying the polarity of the voltage applied to their terminals.

- 6V external battery source (made up of 4 internal AA batteries each 1.5V):

![4](https://user-images.githubusercontent.com/86275885/122963876-130d7380-d35d-11eb-9ff2-1abf1513ee61.jpg)

- HC-06 Low Energy Bluetooth Module (up to 10m of connectivity):

![5](https://user-images.githubusercontent.com/86275885/122963921-1dc80880-d35d-11eb-994b-c964d9a7396b.png)

## Hardware Layout

- Motor and L98N motor controller setup:

![6](https://user-images.githubusercontent.com/86275885/122964027-3c2e0400-d35d-11eb-81a5-9d6fb5c1be0f.png)


- Arduino Uno, motors, power supply and L98N motor controller pin setup:

![7](https://user-images.githubusercontent.com/86275885/122964060-43551200-d35d-11eb-821b-c148351e9194.png)


- Arduino Uno and HC-06 Bluetooth Module pin setup:

![8](https://user-images.githubusercontent.com/86275885/122964095-4bad4d00-d35d-11eb-8723-7c5ff9dc755b.png)


## Software Overview

### Arduino IDE:

The Arduino integrated development environment (IDE) is a cross-platform application (for Windows, macOS, Linux) that is written in the programming language Java. It is used to write and upload programs to Arduino board.

The Arduino IDE supports the languages C and C++ using special rules of code structuring. The Arduino IDE supplies a software library from the Wiring project, which provides many common input and output procedures. User-written code only requires two basic functions, for starting the sketch and the main program loop, that are compiled and linked with a program stub main() into an executable cyclic executive program with the GNU toolchain, also included with the IDE distribution. The Arduino IDE employs the program avrdude to convert the executable code into a text file in hexadecimal encoding that is loaded into the Arduino board by a loader program in the board's firmware. A screenshot of the interface is shown below:

![ide](https://user-images.githubusercontent.com/86275885/122964391-99c25080-d35d-11eb-9993-91ffc51a0e41.png)


### Processing 3:

Processing is an open-source graphical library and integrated development environment (IDE) / playground built for the electronic arts, new media art, and visual design communities with the purpose of teaching non-programmers the fundamentals of computer programming in a visual context.

Processing uses the Java language, with additional simplifications such as additional classes and aliased mathematical functions and operations. As well as this, it also has a graphical user interface for simplifying the compilation and execution stage.

The Processing language and IDE were the precursor to numerous other projects, notably Arduino, Wiring and P5.js. a screenshot of the software is show below:


![p31](https://user-images.githubusercontent.com/86275885/122964840-0c333080-d35e-11eb-9443-3b5ded1b7bab.png)



### Arduino IDE Serial Terminal Overview:


![p32](https://user-images.githubusercontent.com/86275885/122964866-11907b00-d35e-11eb-9464-e7c8eed3ab43.png)


### Processing 3 GUI to control the bot:

![p33](https://user-images.githubusercontent.com/86275885/122964978-3127a380-d35e-11eb-9503-484419d01d7c.png)


## Design Comments
- The bot wires were neatly extended an collated to the downside of the bot in order to make the appearance as aesthetic as possible.
- Jump wires were organized and decreased in number as much as possible and all components were fixated on the metal chassis in order for them not to fall apart or get disconnect during bot’s range of action.
- The 6V battery supply was used to power the bot when disconnect from the computer whereas the later one was used when the bot is connected.
- In order to download the Arduino IDE program unto the Arduino Uno SMD micro-controller board a straight-though USB connection has to be made to the computer and through the corresponding port in Windows to the IDE (in this case COM5).
- While the Arduino IDE program is being downloaded we must disconnect the TX/RX connections of the HC-06 BLE Bluetooth module so that the IDE can find the right relative built-in TX/RX of the chip itself and use them for the download/upload operation.
- Once the download process is over we can reconnect the TX/RX pins of the Bluetooth module to their corresponding Arduino Uno SMD pin numbers. And by this time, the IDE will detect a new open port which is COM3 or COM4 used for the computer to connect to the Arduino and serially send commands over. We must note that for this operation to be successful the HC-06 module was paired with the computer after setting up a virtual Bluetooth stack (Bluetooth Stack from Toshiba) and securing the connection with the module’s default unchangeable password “1234”.
- After that this was setup, we could know connect back to the Arduino board using the built-in serial terminal which we chose to open up on port COM3 or COM4 and then send commands over as shown before in the Arduino IDE serial terminal screenshot.  The board will respond with connect back signals we have written in the code for example “-- Command: Go Front”...
- After that we made sure that the connection is up and running, we went to Processing3 and wrote a custom Interface to control the board without the use of a manual command typing interface. The GUI consists of 4 buttons: Front, Back, Right, and Left. Each sends the corresponding signal to the Arduino board which based on the now-saved in ROM code that we uploaded, will execute its instructions to go frontward or backward or…
- The serial connection is at 9600 baud rate.
- The software written in Processing3 can connect to the Bluetooth port based on a small set of instructions which dynamically allocates the port channels available and lets the user choose the port they want to use. In this case, on the computer the port was always COM3 which has an array index of 0.
- Each button press is accompanied by a routine to send over specific signals to the BLE module. 
- The dynamics of the bot motion is based on first connection the wires of each 2 aligned motors and treating them as one then connect these wires to the L98N motor controller as shown in picture before in the Hardware Overview section of this report.
- To make the car go back or frontward, we make the four motors/wheels rotate in exactly same direction.   To make the car bot shift right, we make the right side wheels rotate backwards where the left side wheels rotate frontward making the bot go in the right way. And vice versa for the left direction mode. 
- Arduino IDE was used to write the program to control the Arduino and the hardware while Processing 3 was used to interface with that car bot and control its movement remotely over Bluetooth by creating a simple aesthetic GUI.

## Pictures
![1](https://user-images.githubusercontent.com/86275885/122965458-94b1d100-d35e-11eb-8ade-95ad07519a97.jpg)
![2](https://user-images.githubusercontent.com/86275885/122965460-954a6780-d35e-11eb-8939-9cf8227d9494.jpg)
![3](https://user-images.githubusercontent.com/86275885/122965464-97142b00-d35e-11eb-8dd2-c13a3da73732.jpg)
![4](https://user-images.githubusercontent.com/86275885/122965467-98455800-d35e-11eb-896b-802596dbeffc.jpg)

## Conclusion
This project has been a well-rounded mixture of knowledge gainer as it allowed us to get hands-on Arduino and Processing3 which offer outstanding hardware and software concepts. We learned to control hardware in a synchronized way to simulate precise movements on the ground of a 4-wheels car and we also used Object Oriented Programming to develop an interface which connect to the hardware we build through Bluetooth module by turn to an Arduino Uno SMD board. This project also required knowledge of electronics to implement the circuit and manage the wiring of all components together thus allowing us to realize the goal we want. Without hardware and electronics this project could not have been made and of course creativity and aesthetic taste to make the whole result look fashionable and user-friendly.


