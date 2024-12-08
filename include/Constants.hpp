#ifndef CONSTANTS
#define CONSTANTS
#include "main.h"
extern int ui_id;
extern int gameMode;
extern int auton;
// extern lv_obj_t *gamescr;
// extern lv_obj_t *matchscr;
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
# 1: [X] MOTOR_PORT_LEFT_A
# 2: [X] MOTOR_PORT_LEFT_B
# 3: [X] MOTOR_PORT_LEFT_C
# 4: [X] SENSOR_PORT_IMU
# 5: [X] ADI_EXPANDER_PNEUMATICS
  6: [ ]
  7: [ ]
  8: [ ]
  9: [ ] 
 10: [ ] 
#11: [X] MOTOR_PORT_RIGHT_A
#12: [X] MOTOR_PORT_RIGHT_B
#13: [X] MOTOR_PORT_RIGHT_C
#14: [X] MOTOR_PORT_FISHMECH
#15: [X] MOTOR_PORT_INTAKE
!16: [-] ADIEXPANDER_LEDSTRIP_PORT // Future Use
!17: [-] MOTOR_PORT_UNUSED // Reserved to use in place of actual motors in the auton selector
 18: [ ] 
 19: [ ]
 20: [ ]
#21: [X] GEN_PORT_VEXNET_MAIN

? BUILTIN ADI PORTS
 22A: [ ]
 22B: [ ]
 22C: [ ]
 22D: [ ]
 22E: [ ]
 22F: [ ]
 22G: [ ]
 22H: [ ]
*/

// ! MOTORS
// * DRIVETRAIN
    // ? LEFT
#define MOTOR_PORT_LEFT_A               -1
#define MOTOR_PORT_LEFT_B               2
#define MOTOR_PORT_LEFT_C               3

    // ? RIGHT
#define MOTOR_PORT_RIGHT_A              -11
#define MOTOR_PORT_RIGHT_B              12
#define MOTOR_PORT_RIGHT_C              13

// * INTAKE
#define MOTOR_PORT_INTAKE               -15

// * Fish Mech
#define MOTOR_PORT_FISHMECH             -14

// Legacy Motors Redefinition to please auton selector (to avoid scope creep for the auton selector)
#define MOTOR_PORT_UNUSED               17
#define MOTOR_PORT_LEFT_LIFT            MOTOR_PORT_UNUSED
#define MOTOR_PORT_RIGHT_LIFT           MOTOR_PORT_UNUSED
#define MOTOR_PORT_INTAKE2              MOTOR_PORT_UNUSED
          


// ! SENSORS
#define SENSOR_PORT_IMU                 4
#define SENSOR_PORT_MOGO_LIMIT_SWITCH   'c'
#define SENSOR_PORT_OPTICAL_COLOR       17//15

// ! PNEUMATICS
#define PNEUMATIC_SMARTPORT_MOBILE_GOAL  5
#define PNEUMATIC_ADIPORT_MOBILE_GOAL    'a'

#define PNEUMATIC_SMARTPORT_SWEEPER      6
#define PNEUMATIC_ADIPORT_SWEEPER        2

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



#define CONTROL_BUTTON_INTAKE_IN        E_CONTROLLER_DIGITAL_R1
#define CONTROL_BUTTON_INTAKE_OUT       E_CONTROLLER_DIGITAL_R2

#define CONTROL_AXIS_LEFT_DRIVE         E_CONTROLLER_ANALOG_LEFT_Y
#define CONTROL_AXIS_RIGHT_DRIVE        E_CONTROLLER_ANALOG_RIGHT_Y

#define CONTROL_BUTTON_MOGO_TOGGLE      E_CONTROLLER_DIGITAL_L1
#define CONTROL_BUTTON_MOGO_RELEASE     E_CONTROLLER_DIGITAL_RIGHT
#define CONTROL_BUTTON_MOGO_GRAB        E_CONTROLLER_DIGITAL_LEFT

#define CONTROL_BUTTON_FISHMECH_UP      E_CONTROLLER_DIGITAL_UP
#define CONTROL_BUTTON_FISHMECH_DOWN    E_CONTROLLER_DIGITAL_DOWN

#define CONTROL_BUTTON_SWEEPER_TOGGLE   E_CONTROLLER_DIGITAL_L1
#define CONTROL_BUTTON_SWEEPER_OUT      E_CONTROLLER_DIGITAL_L1
#define CONTROL_BUTTON_SWEEPER_IN       E_CONTROLLER_DIGITAL_L2



#define USE_LIFT_PRESETS               0

#endif

