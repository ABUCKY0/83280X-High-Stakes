#ifndef CONSTANTS
#define CONSTANTS
#include "main.h"
extern int ui_id;
extern int gameMode;
extern int auton;
extern lv_obj_t *gamescr;
extern lv_obj_t *matchscr;
extern lv_obj_t *skillsscr;

/*
    L            R
    O---front----O  
    |------------|
    |------------|
    O--top-down--O  
    |------------|
    |------------|
    O----back----O  


    |⎺⎻⎼⎽
    |    ⎺⎻⎼⎽
    |        ⎺⎻⎼⎽
    |            ⎺⎻⎼⎽
    |________________⎺⎻⎼⎽

*/

/*
*1: [X] MOTOR_PORT_LEFT_A
*2: [X] MOTOR_PORT_LEFT_B
*3: [X] MOTOR_PORT_LEFT_LIFT
!4: [ ]
!5: [ ]
!6: [ ]
!7: [ ]
!8: [ ]
*9: [ ] MOTOR_PORT_INTAKE
*10: [X] MOTOR_PORT_RIGHT_LIFT
*11: [X] MOTOR_PORT_RIGHT_A
*12: [X] MOTOR_PORT_RIGHT_B
!13: [ ]
*14: [X] SENSOR_PORT_IMU
*15: [X] SENSOR_PORT_OPTICAL_COLOR
todo 16: [-] ADIEXPANDER_LEDSTRIP_PORT // Future Use
*17: [X] SENSOR_PORT_MOGO_LIMIT_SWITCH
*18: [X] SENSOR_PORT_INTAKE_LIMIT_SWITCH
*19: [X] SENSOR_PORT_LIFT
*20: [X] GEN_PORT_VEXNET_BACKUP
*21: [X] GEN_PORT_VEXNET_PRIMARY

? BUILTIN ADI PORTS
*22A: [X] PNEUMATIC_PORT_MOBILE_GOAL
*22B: [X] PNEUMATIC_PORT_PTO_LEFT
*22C: [X] PNEUMATIC_PORT_PTO_RIGHT
!22D: [ ]
*22E: [X] ODOM_POD_LONGITUDINAL_INPUT
*22F: [X] ODOM_POD_LONGITUDINAL_OUTPUT
*22G: [X] ODOM_POD_LATERAL_INPUT
*22H: [X] ODOM_POD_LATERAL_OUTPUT
*/

//! MOTORS
// * DRIVETRAIN
    // ? LEFT
#define MOTOR_PORT_LEFT_A               11
#define MOTOR_PORT_LEFT_B               12
#define MOTOR_PORT_LEFT_C               -13

    // ? RIGHT
#define MOTOR_PORT_RIGHT_A              1
#define MOTOR_PORT_RIGHT_B              2
#define MOTOR_PORT_RIGHT_C              -3

// * LIFT
// #define MOTOR_PORT_LEFT_LIFT            -13
// #define MOTOR_PORT_RIGHT_LIFT           3

// * INTAKE
#define MOTOR_PORT_INTAKE               4
#define MOTOR_PORT_THINGY               17

// ! SENSORS
#define SENSOR_PORT_IMU                  5
#define SENSOR_PORT_LIFT                18
#define SENSOR_PORT_INTAKE_LIMIT_SWITCH 
#define SENSOR_PORT_MOGO_LIMIT_SWITCH   17
#define SENSOR_PORT_OPTICAL_COLOR       15

// ! PNEUMATICS
#define PNEUMATIC_PORT_MOBILE_GOAL      1 
#define PNEUMATIC_PORT_PTO_LEFT         2
#define PNEUMATIC_PORT_PTO_RIGHT        3

// ! VEXNET
#define GEN_PORT_VEXNET_PRIMARY         21
#define GEN_PORT_VEXNET_BACKUP          20

// ! ODOM-PODS
// ? LONGITUDINAL AXIS (FRONT TO BACK) - E F
// ? LATERAL AXIS (LEFT TO RIGHT) - G H

#define ODOM_POD_LONGITUDINAL_INPUT     5
#define ODOM_POD_LONGITUDINAL_OUTPUT    6

#define ODOM_POD_LATERAL_INPUT          7
#define ODOM_POD_LATERAL_OUTPUT         8

// ! ADI EXPANDERS (LEDS)
#define ADIEXPANDER_LEDSTRIP_PORT        16 // Future Use

/** 
 * Defines what version of the UI to use (depricated)
 * 1 - Marble UI
 */
#define USE_UI 1



#define CONTROL_BUTTON_LIFT_UP          E_CONTROLLER_DIGITAL_L1
#define CONTROL_BUTTON_LIFT_DOWN        E_CONTROLLER_DIGITAL_L2
#define CONTROL_BUTTON_INTAKE_IN        E_CONTROLLER_DIGITAL_R1
#define CONTROL_BUTTON_INTAKE_OUT       E_CONTROLLER_DIGITAL_R2

#define CONTROL_AXIS_LEFT_DRIVE         E_CONTROLLER_ANALOG_LEFT_Y
#define CONTROL_AXIS_RIGHT_DRIVE        E_CONTROLLER_ANALOG_RIGHT_Y

#define CONTROL_BUTTON_MOGO_TOGGLE      E_CONTROLLER_DIGITAL_Y

#define USE_LIFT_PRESETS               0

#endif

