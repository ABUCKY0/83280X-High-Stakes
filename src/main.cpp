#include "main.h"
#include <algorithm>
#include <iostream>
#include "./Constants/constants.h"
#include "./AutonomousSelector/BuildInfo/build_info.h"
#include "./AutonomousSelector/Selector.hpp"
pros::adi::AnalogOut wings('A');


// Controller master(E_CONTROLLER_MASTER);
// Motor left_frt_mtr(MOTOR_PORT_LEFT_FRONT);
// Motor left_mid_mtr(MOTOR_PORT_LEFT_MIDDLE);
// Motor left_bck_mtr(MOTOR_PORT_LEFT_BACK);
// // group motors
// Motor_Group left_dt({left_frt_mtr, left_mid_mtr, left_bck_mtr});

// Motor right_frt_mtr(MOTOR_PORT_RIGHT_FRONT);
// Motor right_mid_mtr(MOTOR_PORT_RIGHT_MIDDLE);
// Motor right_bck_mtr(MOTOR_PORT_RIGHT_BACK);

// // group motors
// Motor_Group right_dt({right_frt_mtr, right_mid_mtr, right_bck_mtr});

// Motor intake1 = Motor(MOTOR_PORT_INTAKE);
// Motor intake2 = Motor(MOTOR_PORT_INTAKE_2);
// // Reverse
// MotorGroup intake({intake1, intake2});

// Motor flywheel = Motor(MOTOR_PORT_FLYWHEEL);

void actuateWings(bool state)
{
  // Actuate the wings
  estpsi = estpsi - 5;
  if (state)
  {
    wings.set_value(1);
  }
  else
  {
    wings.set_value(0);
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
//   intake2.set_reversed(true);
//   // set gearset
//   left_frt_mtr.set_gearing(MOTOR_GEARSET_18);
//   left_mid_mtr.set_gearing(MOTOR_GEARSET_18);
//   left_bck_mtr.set_gearing(MOTOR_GEARSET_18);
//   right_frt_mtr.set_gearing(MOTOR_GEARSET_18);
//   right_mid_mtr.set_gearing(MOTOR_GEARSET_18);
//   right_bck_mtr.set_gearing(MOTOR_GEARSET_18);
//   flywheel.set_gearing(MOTOR_GEARSET_06);

//   left_dt.set_gearing(MOTOR_GEARSET_18);
//   right_dt.set_gearing(MOTOR_GEARSET_18);
#if USE_UI == 1
  cout << "[MAIN] (INFO): [UI_INIT] Marble UI\n";
  cout << "Running Marble UI\n";
  init_marble_ui();
  create_tasks();

#else
  cout << "[MAIN] (INFO): [NOUI_INIT] No UI Initalized\n";
#endif
  std::cout << "Build Date: " << std::string(build_date) << std::endl;
  std::cout << "Git Branch: " << std::string(git_branch) << std::endl;
  std::cout << "Git Commit: " << std::string(git_commit) << std::endl;
  std::cout << "Compiler Version: " << std::string(compiler_version) << std::endl;
  std::cout << "Build Environment: " << std::string(build_environment) << std::endl;
  std::cout << "Build Number: " << build_number << std::endl;
  std::cout << "Developer Name: " << std::string(developer_name) << std::endl;
  std::cout << "Application Environment: " << std::string(application_environment) << std::endl;
  std::cout << "Codebase Version: " << std::string(codebase_version) << std::endl;

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { cout << "Disabled"; }

void runMatchAuton(char auton)
{
  // Run the selected match auton
  switch (auton)
  {
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
void runSkillsAuton(char auton)
{
  // Run the selected skills auton
  switch (auton)
  {
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
void competition_initialize()
{
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
void autonomous()
{
  cout << "[MAIN] (INFO): [AUTON] Running Autonomous\n";
  // Run the selected auton
  if (gameMode == 0 || gameMode == NULL)
  {
    runMatchAuton(auton);
  }
  else
  {
    runSkillsAuton(auton);
  }
}

uint32_t RGBToUint32(uint8_t red, uint8_t green, uint8_t blue)
{
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
void opcontrol()
{
  while (true)
  {
    pros::delay(20);
  }
}
