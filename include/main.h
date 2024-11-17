/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h" // IWYU pragma: keep

/**
 * You should add more #includes here
 */
// #include "okapi/api.hpp"
// #include "pros/api_legacy.h"
#include "pros/apix.h" // IWYU pragma: keep
/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
using namespace pros::literals;
// using namespace okapi;
using namespace pros;
using namespace std;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
#include "packages/lemlib/api.hpp" // IWYU pragma: keep
#include <iostream>                // IWYU pragma: keep
#include <random>                  // IWYU pragma: keep
#include <string>                  // IWYU pragma: keep
#include <vector>                  // IWYU pragma: keep


#endif

LV_IMG_DECLARE(arrow_down);
LV_IMG_DECLARE(arrow_up);
LV_IMG_DECLARE(Confirm_NotReady);
LV_IMG_DECLARE(Match_Selections);
LV_IMG_DECLARE(Skills_Selections);
LV_IMG_DECLARE(Field_Regular);
LV_IMG_DECLARE(Field_Skills);
LV_IMG_DECLARE(Match_Button);
LV_IMG_DECLARE(Match_Button_Selected);
LV_IMG_DECLARE(Skills_Button);
LV_IMG_DECLARE(Skills_Button_Selected);
LV_IMG_DECLARE(Confirm_Ready);
LV_IMG_DECLARE(Auton_Disabled);
LV_IMG_DECLARE(Preload_Only_Auton);
LV_IMG_DECLARE(MatchLoad_Auton);
LV_IMG_DECLARE(Goal_Auton);
LV_IMG_DECLARE(Driver_Control);
LV_IMG_DECLARE(Over_Barrier_Auton);
LV_IMG_DECLARE(Under_Sidebar_Auton);
LV_IMG_DECLARE(Launch_Only_Auton);
LV_IMG_DECLARE(Lobo_Cube);
LV_IMG_DECLARE(Robotics_Logo_Big);
LV_IMG_DECLARE(Robotics_Logo_Huge);
LV_IMG_DECLARE(Team_Name);
LV_IMG_DECLARE(Auton_Selection);
LV_IMG_DECLARE(Brain_Statistics);
LV_IMG_DECLARE(Field_And_Auton_Selector);
LV_IMG_DECLARE(Red_Cube);
LV_IMG_DECLARE(Green_Cube);
LV_IMG_DECLARE(Gray_Cube);
LV_IMG_DECLARE(Yellow_Cube);
LV_IMG_DECLARE(Battery_Charge_Box);
LV_IMG_DECLARE(Empty_Long_Box);
LV_IMG_DECLARE(Selector);
LV_IMG_DECLARE(chicken_sandwich);
LV_IMG_DECLARE(chicken_sandwich_nobg);
LV_IMG_DECLARE(fire);
LV_IMG_DECLARE(MiniChickenSandwich);
LV_IMG_DECLARE(hellokittyicon);
LV_IMG_DECLARE(transparent);


LV_IMG_DECLARE(marblebg);
LV_IMG_DECLARE(hellokitty_bg);
LV_IMG_DECLARE(ChristmasStockings);
LV_IMG_DECLARE(OGBackground);

LV_FONT_DECLARE(blackopsone_4);
LV_FONT_DECLARE(blackopsone_6);
LV_FONT_DECLARE(blackopsone_8);
LV_FONT_DECLARE(blackopsone_10);
LV_FONT_DECLARE(blackopsone_12);
LV_FONT_DECLARE(blackopsone_14);
LV_FONT_DECLARE(blackopsone_16);
LV_FONT_DECLARE(blackopsone_18);
LV_FONT_DECLARE(blackopsone_20);
LV_FONT_DECLARE(blackopsone_25);
LV_FONT_DECLARE(blackopsone_30);
LV_FONT_DECLARE(blackopsone_40);
LV_FONT_DECLARE(blackopsone_50);

LV_IMG_DECLARE(ogButton);
LV_IMG_DECLARE(helloKittyButton);
LV_IMG_DECLARE(batmanButton);
LV_IMG_DECLARE(redMarbleButton);
LV_IMG_DECLARE(ThanksgivingButton);
LV_IMG_DECLARE(ChristmasButton);

LV_IMG_DECLARE(lobo);
LV_IMG_DECLARE(mini_lobo);
#endif // _PROS_MAIN_H_
