
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// This is the Gui to control over the arduino bot


import controlP5.*;          //import ControlP5 library to build UI
import processing.serial.*; // import processing serial library for the bluetooth serial communication


Serial port;    // create  global serial object
ControlP5 cp5;  //create ControlP5 object
PFont font;     // create a font variable for the display


////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {  //setup routine to do all initilization for GUI and hardware

  size(600, 400);                          //window size, (width, height)
  printArray(Serial.list());               //prints all available serial ports
  port = new Serial(this, "COM3", 9600);   //i have connected arduino to com3, it would be different in linux and mac os

  cp5 = new ControlP5(this);                      // create new controlP5 instnce
  font = createFont("calibri light bold", 20);    // custom fonts for buttons and title

  cp5.addButton("Front")       //"Front" is the name of button
    .setPosition(250, 50)      //x and y coordinates of upper left corner of button
    .setSize(120, 70)          //(width, height)
    .setFont(font)             //specify font to be used in button text
    .setColorActive(150)       // set color when button is selected over
    .setColorBackground(150)   // set bckground color for the main front button
    ;

  cp5.addButton("Back")     //"Back" is the name of button
    .setPosition(250, 250)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)       //(width, height)
    .setFont(font)
    ;

  cp5.addButton("Left")     //"Left" is the name of button
    .setPosition(100, 150)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)       //(width, height)
    .setFont(font)
    ;

  cp5.addButton("Right")     //"Right" is the name of button
    .setPosition(400, 150)   //x and y coordinates of upper left corner of button
    .setSize(120, 70)        //(width, height)
    .setFont(font)
    ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////


void draw() {               //routine responsible of building the layout
  background(50, 50, 50);   // background color of window (r, g, b) or (0 to 255)
} 


////////////////////////////////////////////////////////////////////////////////////////////////////


//lets add some functions to our buttons
//so whe you press any button, it sends perticular char over serial port

void Front() { // when front button pressed execute the following method
  port.write('f'); // send appropriate command over bluetooth port
}

void Back() { // when Back button pressed execute the following method
  port.write('b'); // serial command are determined by our arduino program
}

void Right() { // when right button pressed execute the following method
  port.write('r');
}

void Left() { // when left button pressed execute the following method
  port.write('l');
}


////////////////////////////////////////////////////////////////////////////////////////////////////
