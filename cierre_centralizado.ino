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

// Variable for reading the pushbutton status
int buttonState = 0;
// Central locking state. Open or Close ;-)
boolean centralLockingState = false;
boolean childrenLockingState = false;

/**
 * System configuration
 */
void setup() {
  // Initialize the pushbutton pin as an input:
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(BUTTON_3_PIN, INPUT);
  pinMode(BUTTON_4_PIN, INPUT);
  
  // Initialize the pin to control the motors  
  pinMode(ACTUATOR_IN_1, OUTPUT);
  pinMode(ACTUATOR_IN_2, OUTPUT);
  pinMode(ACTUATOR_IN_3, OUTPUT);
  pinMode(ACTUATOR_IN_4, OUTPUT);
  pinMode(ACTUATOR_IN_5, OUTPUT);
  pinMode(ACTUATOR_IN_6, OUTPUT);
  pinMode(ACTUATOR_IN_7, OUTPUT);
  pinMode(ACTUATOR_IN_8, OUTPUT);
}

/**
 * System loop
 */
void loop() {
  // Read the state of the pushbutton value:
  // Normal mode
  if (digitalRead(BUTTON_1_PIN) == HIGH) {
    // Delay to debounce switch
    delay(100);
    // Change the door state
    if(centralLockingState) {
      openFrontDoors();
    } else {
      closeAllDoorsAndTrunkDoor();
    }
    centralLockingState = !centralLockingState;
  }
  // Open and close all :-P
  if (digitalRead(BUTTON_2_PIN) == HIGH) {
    // Delay to debounce switch
    delay(100);
    // Change the door state
    if(centralLockingState) {
      openAllDoorsAndTrunkDoor();
    } else {
      closeAllDoorsAndTrunkDoor();
    }
    centralLockingState = !centralLockingState;
  }
  // Trunk door button
  if (digitalRead(BUTTON_3_PIN) == HIGH) {
    // Delay to debounce switch
    delay(100);
    // Change the door state
    if(centralLockingState) {
      openTrunkDoor();
    } else {
      closeTrunkDoor();
    }
    centralLockingState = !centralLockingState;
  }
  // Children locking buttons
  if (digitalRead(BUTTON_4_PIN) == HIGH) {
    // Delay to debounce switch
    delay(100);
    // Change the door state
    if(childrenLockingState) {
      // Nothing for the moment
    } else {
      // Nothing for the moment
    }
    childrenLockingState = !childrenLockingState;
  }
  delay(LOOP_TIME); 
}

/**
 * Open front doors
 */
void openFrontDoors () {
  moveForward(FRONT_DOORS);
  delay(WAIT_TIME); 
  fullStop(FRONT_DOORS);
}

/**
 * Close front doors
 */
void closeFrontDoors () {
  moveBackward(FRONT_DOORS);
  delay(WAIT_TIME); 
  fullStop(FRONT_DOORS);
}

/**
 * Open back doors
 */
void openBackDoors () {
  moveForward(BACK_DOORS);
  delay(WAIT_TIME); 
  fullStop(BACK_DOORS);
}

/**
 * Close back doors
 */
void closeBackDoors () {
  moveBackward(BACK_DOORS);
  delay(WAIT_TIME); 
  fullStop(BACK_DOORS);
}

/**
 * Open trunk door
 */
void openTrunkDoor () {
  moveForward(CAR_TRUNK_DOOR);
  delay(WAIT_TIME); 
  fullStop(CAR_TRUNK_DOOR);
}

/**
 * Close trunk door
 */
void closeTrunkDoor () {
  moveBackward(CAR_TRUNK_DOOR);
  delay(WAIT_TIME); 
  fullStop(CAR_TRUNK_DOOR);
}

/**
 * Open all the doors
 */
void openAllDoor () {
  moveForward(FRONT_DOORS);
  moveForward(BACK_DOORS);
  delay(WAIT_TIME); 
  fullStop(FRONT_DOORS);
  fullStop(BACK_DOORS);
}

/**
 * Close all the doors
 */
void closeAllDoors () {
  moveBackward(FRONT_DOORS);
  moveBackward(BACK_DOORS);
  delay(WAIT_TIME); 
  fullStop(FRONT_DOORS);
  fullStop(BACK_DOORS);
}

/**
 * Open all the doors and the trunk door
 */
void openAllDoorsAndTrunkDoor () {
  moveForward(FRONT_DOORS);
  moveForward(BACK_DOORS);
  moveForward(CAR_TRUNK_DOOR);
  delay(WAIT_TIME); 
  fullStop(FRONT_DOORS);
  fullStop(BACK_DOORS);
  fullStop(CAR_TRUNK_DOOR);
}

/**
 * Close all the doors and the trunk door
 */
void closeAllDoorsAndTrunkDoor () {
  moveBackward(FRONT_DOORS);
  moveBackward(BACK_DOORS);
  moveBackward(CAR_TRUNK_DOOR);
  delay(WAIT_TIME); 
  fullStop(FRONT_DOORS);
  fullStop(BACK_DOORS);
  fullStop(CAR_TRUNK_DOOR);
}

// =============================================================================

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
