/*
 * Constants definition
 *
 * created 2019
 * by Adrian Novegil <adrian.novegil@gmail.com>
 *
 */
 
// Control buttons pin configuration
const int BUTTON_1_PIN = 2;  // General lock
const int BUTTON_2_PIN = 3;  // Back lock
const int BUTTON_3_PIN = 4;  // Car trunk
const int BUTTON_4_PIN = 5;  // Children control

// Actuators configuration pin configuration
// Front doors
const int ACTUATOR_IN_1 = 6;  
const int ACTUATOR_IN_2 = 7;
// Back doors
const int ACTUATOR_IN_3 = 8;  
const int ACTUATOR_IN_4 = 9;
// Trunk door
const int ACTUATOR_IN_5 = 10; 
const int ACTUATOR_IN_6 = 11;
// Children locking actuators
const int ACTUATOR_IN_7 = 12;
const int ACTUATOR_IN_8 = 13;

// Door arrays definitio
const int FRONT_DOORS[2] = {ACTUATOR_IN_1, ACTUATOR_IN_2};
const int BACK_DOORS [2] = {ACTUATOR_IN_3, ACTUATOR_IN_4};
const int CAR_TRUNK_DOOR[2] = {ACTUATOR_IN_5, ACTUATOR_IN_6};
const int CHILDREN_LOCKING[2] = {ACTUATOR_IN_7, ACTUATOR_IN_8};

// Wait time between actuator phases
const int WAIT_TIME = 500;
const int LOOP_TIME = 100;

