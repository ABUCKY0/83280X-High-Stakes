#ifndef CONSTANTS
#define CONSTANTS
#include "main.h"
extern int ui_id;
extern int gameMode;
extern int auton;
extern lv_obj_t *gamescr;
extern lv_obj_t *matchscr;
extern lv_obj_t *skillsscr;


#define MOTOR_PORT_LEFT_FRONT 1
#define MOTOR_PORT_LEFT_MIDDLE 2
#define MOTOR_PORT_LEFT_BACK 3
#define MOTOR_PORT_RIGHT_FRONT 11
#define MOTOR_PORT_RIGHT_MIDDLE 12
#define MOTOR_PORT_RIGHT_BACK 13
#define MOTOR_PORT_INTAKE 10
#define MOTOR_PORT_INTAKE_2 20
#define MOTOR_PORT_FLYWHEEL 5

#endif

/*
 * Defines what version of the UI to use (depricated)
 * 1 - Marble UI
 */
#define USE_UI 1