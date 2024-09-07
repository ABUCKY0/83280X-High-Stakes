#include "main.h"
#include "./AutonomousSelector/Selector.hpp"
#include "./Constants/constants.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include <algorithm> // IWYU pragma: keep
#include <cstddef>   // IWYU pragma: keep
#include <iostream>
#include <optional> // IWYU pragma: keep


ROBOTLOG::LOGGER logger();

pros::Controller master(CONTROLLER_MASTER);
pros::MotorGroup leftdt({1, 2, 3});
pros::MotorGroup rightdt({11, 12, 13});

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
#if USE_UI == 1
  cout << "[MAIN] (INFO): [UI_INIT] Marble UI\n";
  cout << "Running Marble UI\n";
  init_marble_ui();
  create_tasks();

#else
  cout << "[MAIN] (INFO): [NOUI_INIT] No UI Initalized\n";
#endif
  std::cout << "Build Date: " << BUILD_DATE << std::endl;
  std::cout << "Git Branch: " << GIT_BRANCH << std::endl;
  std::cout << "Git Commit: " << GIT_COMMIT << std::endl;
  std::cout << "Compiler Version: " << COMPILER_VERSION << std::endl;
  std::cout << "Build Environment: " << BUILD_ENVIRONMENT << std::endl;
  std::cout << "Build Number: " << BUILD_NUMBER << std::endl;
  std::cout << "Developer Name: " << DEVELOPER_NAME << std::endl;
  std::cout << "Application Environment: " << APPLICATION_ENVIRONMENT
            << std::endl;
  std::cout << "Codebase Version: " << CODEBASE_VERSION << std::endl;
  std::cout << "Build Environment: " << BUILD_ENVIRONMENT << std::endl;
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { cout << "Disabled"; }

void runMatchAuton(char auton) {
  // Run the selected match auton
  switch (auton) {
  case 0:
    cout << "[MAIN] (INFO): [AUTONRUN] Preload Only Autonomous (ID:0)\n";
    // Preload Only Auton
    break;
  case 1:
    cout << "[MAIN] (INFO): [AUTONRUN] Load Side Autonomous (ID:1)\n";

    // Load Side Auton
    break;
  case 2:
    cout << "[MAIN] (INFO): [AUTONRUN] Goal Side Autonomous (ID:2)\n";
    // Goal Side Auton
    break;
  case 3:
    cout << "[MAIN] (INFO): [AUTONRUN] No Autonomous (ID:3)\n";
    // No Autonomous
    break;
  default:
    cout << "[MAIN] (INFO): [AUTONRUN] Preload Only Autonomous [Default State] "
            "(ID:0 [-1])\n";
    // run 0
    break;
  }
}
void runSkillsAuton(char auton) {
  // Run the selected skills auton
  switch (auton) {
  case 0:
    cout << "[MAIN] (INFO): [SKILLSRUN] Over Barrier Autonomous (ID:0)\n";
    // Over Barrier Auton
    break;
  case 1:
    cout << "[MAIN] (INFO): [SKILLSRUN] Under Sidebar Autonomous (ID:1)\n";
    // Under Side Bar Auton
    break;
  case 2:
    cout << "[MAIN] (INFO): [SKILLSRUN] Launch Only Autonomous (ID:2)\n";
    // Launch-Only Auton
    break;
  case 3:
    cout << "[MAIN] (INFO): [SKILLSRUN] No Autonomous (ID:3)\n";
    // No Autonomous
    break;
  default:
    cout << "[MAIN] (INFO): [AUTONRUN] Over Barrier Autonomous [Default State] "
            "(ID:0 [-1])\n";
    // run 0
    break;
  }
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  cout << "[MAIN] (INFO): [INIT] Competition Initalize\n";
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  cout << "[MAIN] (INFO): [AUTON] Running Autonomous\n";
  // Run the selected auton
  if (gameMode == 1) {
    runSkillsAuton(auton);
  } else {
    runMatchAuton(auton);
  }
}

uint32_t RGBToUint32(uint8_t red, uint8_t green, uint8_t blue) {
  // Pack the RGB components into a 32-bit unsigned integer
  return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  while (true) {
    leftdt.move(master.get_analog(ANALOG_LEFT_Y));
    rightdt.move(master.get_analog(ANALOG_RIGHT_Y));
    pros::delay(20);
  }
}
