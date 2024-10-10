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
1   O---front----O  11
    |------------|
    |------------|
2   O--top-down--O  12
    |------------|
    |------------|
3   O----back----O  13


M1  |⎺⎻⎼⎽
    |    ⎺⎻⎼⎽
    |        ⎺⎻⎼⎽
    |            ⎺⎻⎼⎽
    |________________⎺⎻⎼⎽

*/

#define MOTOR_PORT_LEFT_FRONT           1
#define MOTOR_PORT_LEFT_MIDDLE          2
#define MOTOR_PORT_LEFT_BACK            3
#define MOTOR_PORT_RIGHT_FRONT          11
#define MOTOR_PORT_RIGHT_MIDDLE         12
#define MOTOR_PORT_RIGHT_BACK           13
#define MOTOR_PORT_LEFT_LIFT            20
#define MOTOR_PORT_RIGHT_LIFT           10
#define MOTOR_PORT_INTAKE               15

#define SENSOR_PORT_IMU                 21
#define SENSOR_PORT_LIFT                19
#define SENSOR_PORT_INTAKE_LIMIT_SWITCH 18
#define SENSOR_PORT_MOGO_LIMIT_SWITCH   17

#define PNEUMATIC_PORT_MOBILE_GOAL      1
#define PNEUMATIC_PORT_PTO_LEFT         2
#define PNEUMATIC_PORT_PTO_RIGHT        3

#define LEDSTRIP_PORT_UNDERGLOW 

#endif

/*
 * Defines what version of the UI to use (depricated)
 * 1 - Marble UI
 */
#define USE_UI 1