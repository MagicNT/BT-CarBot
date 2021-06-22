

//////////////////////////////////////////////////////////////////////////////////////
///////////////// This is the main arduino bot program to control hardware

#include <SoftwareSerial.h> // import the serial bluetooth library

SoftwareSerial BT(0, 1); // create the Bluetooth object to handle communications
// creates a "virtual" serial port/UART
// connect BT module TX to 0
// connect BT module RX to 1
// connect BT Vcc to 5V, GND to GND


// connect motor controller pins to Arduino digital pins
// motor A
int enA = 10; // motor A enable line with PWM speed control
int in1 = 9;  // motor A control line 1
int in2 = 8;  // motor A control line 2
// motor B
int in3 = 7;  // motor B control line 1
int in4 = 6;  // motor B control line 2
int enB = 5;  // motor B enable line with PWM speed control


//////////////////////////////////////////////////////////////////////////////////////


void setup() { // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  BT.begin(9600); // opens bluetooth serial port and sets data rate to 9600 bps
}


//////////////////////////////////////////////////////////////////////////////////////


void control_motor_A(int option) { // control motor A direction of rotation
  if (option == 0) { // set forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else if (option == 1) { set backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else if (option == 2) { // stop 
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}

void set_speed_motor_A(int sp) { // set motor A speed value 0-250
  analogWrite(enA, sp);
}

void control_motor_B(int option) { // control motor A direction of rotation
  if (option == 0) { // set forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (option == 1) { // set backware
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if (option == 2) { // stop
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

void set_speed_motor_B(int sp) { // set motor B speed value 0-250
  analogWrite(enB, sp);
}


//////////////////////////////////////////////////////////////////////////////////////


void go_front_back(int dir, int spd) { // make bot go front of back based on direction index and speed
  control_motor_A(dir);
  control_motor_B(dir);
  set_speed_motor_A(spd);
  set_speed_motor_B(spd);
}

void go_right(int spd) { // make bot go right with speed option
  control_motor_A(0);    // make motor A go backward
  control_motor_B(1);    // make motor B go backward
  set_speed_motor_A(spd);
  set_speed_motor_B(spd);
}

void go_left(int spd) { // make bot go left with speed option
  control_motor_A(1);   // make motor A go forward
  control_motor_B(0);   // make motor B go backwar
  set_speed_motor_A(spd);
  set_speed_motor_B(spd);
}


//////////////////////////////////////////////////////////////////////////////////////


void loop() { // main arduino routine to keep program running all time

  if (BT.available() > 0) {      // once serial command available take it
    char command = BT.read();    // read the incoming byte:
    BT.print("--==> Command: "); // print received command

    switch (command) { // do actions based on command sent over
      case 'f':
        BT.println("Go Front");
        go_front_back(1, 250);
        break;

      case 'b':
        BT.println("Go Back");
        go_front_back(0, 250);
        break;

      case 'r':
        BT.println("Go Right");
        go_right(250);
        break;

      case 'l':
        BT.println("Go Left");
        go_left(250);
        break;

      case 's':
        BT.println("Stop!");
        go_front_back(2, 250);
        break;

      default:
        BT.println("Nohing!");
        break;
    }
  }
}


//////////////////////////////////////////////////////////////////////////////////////
