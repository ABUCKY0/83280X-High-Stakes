// C++ Includes
#include <algorithm> // IWYU pragma: keep
#include <cstddef>   // IWYU pragma: keep
#include <iostream>
#include <optional> // IWYU pragma: keep

// PROS
#include "main.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"

// Constants
#include "Constants.hpp"

// Subsystems
#include "AutonomousSelector/Selector.hpp"
#include "Subsystems/MobileGoalGrabber.hpp"
#include "Subsystems/Intake.hpp"
#include "Subsystems/Drivetrain/Drivetrain.hpp"
#include "Vex/things.h"

// pros::Controller master(CONTROLLER_MASTER);
// pros::MotorGroup leftdt({MOTOR_PORT_LEFT_A, MOTOR_PORT_LEFT_B});
// pros::MotorGroup rightdt({MOTOR_PORT_RIGHT_A, MOTOR_PORT_RIGHT_B});
LCHS::Drivetrain drivetrain({MOTOR_PORT_LEFT_A, MOTOR_PORT_LEFT_B},
                            {MOTOR_PORT_RIGHT_A, MOTOR_PORT_RIGHT_B});

// #include "Subsystems/Drivetrain/LemLibDrivetrain.cpp"

#include "Constants.hpp"
#include "lemlib/api.hpp"
#include "main.h"  // IWYU pragma: keep
#include "pros/motor_group.hpp"

pros::MotorGroup lemleft_drive({MOTOR_PORT_LEFT_A, MOTOR_PORT_LEFT_B},
                               pros::MotorGears::green);
pros::MotorGroup lemright_drive({MOTOR_PORT_RIGHT_A, MOTOR_PORT_RIGHT_B},
                                pros::MotorGears::green);

// drivetrain settings
lemlib::Drivetrain lemlib_drivetrain(
    &lemleft_drive,              // left motor group
    &lemright_drive,             // right motor group
    10,                          // 10 inch track width
    lemlib::Omniwheel::NEW_275,  // using new 4" omnis
    360,                         // drivetrain rpm is 360
    2                            // horizontal drift is 2 (for now)
);

pros::Imu inertial(SENSOR_PORT_IMU);
pros::adi::Encoder front_back(ODOM_POD_LONGITUDINAL_INPUT,
                              ODOM_POD_LONGITUDINAL_OUTPUT);
pros::adi::Encoder left_right(ODOM_POD_LATERAL_INPUT, ODOM_POD_LATERAL_OUTPUT);

//https://lemlib.readthedocs.io/en/stable/tutorials/2_configuration.html#vertical-tracking-wheel
lemlib::TrackingWheel front_back_wheel(&front_back, 2.75, -3.25);
lemlib::TrackingWheel left_right_wheel(&left_right, 2.75, -3.25);
lemlib::OdomSensors sensors(&front_back_wheel, nullptr, &left_right_wheel,
                            nullptr, &inertial);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(
    10,   // proportional gain (kP)
    0,    // integral gain (kI)
    3,    // derivative gain (kD)
    3,    // anti windup
    1,    // small error range, in inches
    100,  // small error range timeout, in milliseconds
    3,    // large error range, in inches
    500,  // large error range timeout, in milliseconds
    20    // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(
    2,    // proportional gain (kP)
    0,    // integral gain (kI)
    10,   // derivative gain (kD)
    3,    // anti windup
    1,    // small error range, in degrees
    100,  // small error range timeout, in milliseconds
    3,    // large error range, in degrees
    500,  // large error range timeout, in milliseconds
    0     // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(lemlib_drivetrain,   // drivetrain settings
                        lateral_controller,  // lateral PID settings
                        angular_controller,  // angular PID settings
                        sensors              // odometry sensors
);
// static LCHS::MobileGoalGrabber mogoGrabber(PNEUMATIC_PORT_MOBILE_GOAL, SENSOR_PORT_MOGO_LIMIT_SWITCH);
// static LCHS::Intake intake({MOTOR_PORT_INTAKE}, {MOTOR_PORT_LEFT_LIFT, MOTOR_PORT_RIGHT_LIFT}, PNEUMATIC_PORT_PTO_LEFT, PNEUMATIC_PORT_PTO_RIGHT, SENSOR_PORT_LIFT);

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
  /*
  Build Information
  */
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


  //vex things
  std::cout << "Is Comp Switch??: " << to_string(pros::competition::is_competition_switch()) << std::endl;
  std::cout << "IS Field Control??: " << to_string(pros::competition::is_field_control())  << std::endl;

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { cout << "[MAIN] (INFO): [STATUS] Disabled"; }

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
    drivetrain.driverControl(); // Drivetrain.cpp/Drivetrain.hpp
    pros::delay(20);
  }
}
