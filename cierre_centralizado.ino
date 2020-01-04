/*
 * Arduino Central Locking
 * 
 * created 2019
 * by Adrian Novegil <adrian.novegil@gmail.com>
 * 
 * This is Open Source software released under the Apache 2.0 license
 * 
 */

#include "constants.h"

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
boolean centralLockState = false;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(BUTTON_3_PIN, INPUT);
  pinMode(BUTTON_4_PIN, INPUT);
  
  // initialize the pin to control the motors  
  pinMode(ACTUATOR_IN_1, OUTPUT);
  pinMode(ACTUATOR_IN_2, OUTPUT);
  pinMode(ACTUATOR_IN_3, OUTPUT);
  pinMode(ACTUATOR_IN_4, OUTPUT);
  pinMode(ACTUATOR_IN_5, OUTPUT);
  pinMode(ACTUATOR_IN_6, OUTPUT);
  pinMode(ACTUATOR_IN_7, OUTPUT);
  pinMode(ACTUATOR_IN_8, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton value:
  // Check if the pushbutton is pressed.
  if (digitalRead(BUTTON_1_PIN) == HIGH) {
    // delay to debounce switch
    delay(100);
    centralLockState = !centralLockState;
   // Change the door state
   if(centralLockState) {
     moveForward(FRONT_DOORS);
     moveForward(BACK_DOORS);
     moveForward(CAR_TRUNK_DOOR);
     delay(WAIT_TIME); 
     fullStop(FRONT_DOORS);
     fullStop(BACK_DOORS);
     fullStop(CAR_TRUNK_DOOR);
   } else {
     moveBackward(FRONT_DOORS);
     moveBackward(BACK_DOORS);
     moveBackward(CAR_TRUNK_DOOR);
     delay(WAIT_TIME); 
     fullStop(FRONT_DOORS);
     fullStop(BACK_DOORS);
     fullStop(CAR_TRUNK_DOOR);
   }
    
  }
  delay(100); 
}

void openFrontDoors () {}

void closeFrontDoors () {}

void openBackDoors () {}

void closeBackDoors () {}

void openTrunkDoor () {}

void closeTrunkDoor () {}

void openAllDoor () {}

void closeAllDoors () {}

void openAllDoorsAndTrunkDoor () {}

void closeAllDoorsAndTrunkDoor () {}

/**
 * Function to open the doors  
 */
void moveForward(const int pinMotor[2]) {
  digitalWrite(pinMotor[0], HIGH);
  digitalWrite(pinMotor[1], LOW);
}

/**
 * Function to close the doors  
 */
void moveBackward(const int pinMotor[2]) {
  digitalWrite(pinMotor[0], LOW);
  digitalWrite(pinMotor[1], HIGH);
}

/**
 * Function that stops the motor voltage
 *
 */
void fullStop(const int pinMotor[2]) {
  digitalWrite(pinMotor[0], LOW);
  digitalWrite(pinMotor[1], LOW);
}
