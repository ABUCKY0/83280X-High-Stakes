#include "Constants.hpp"
#include "main.h"  // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/ext_adi.h"
#include "pros/motors.h"

#include <atomic>
#include <cerrno>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "Subsystems/Drivetrain/Drivetrain.hpp"  // IWYU pragma: keep
static bool reset = false;

static inline const pros::adi::ext_adi_port_pair_t sweeperport = {
    PNEUMATIC_SMARTPORT_SWEEPER, PNEUMATIC_ADIPORT_SWEEPER};
static inline const pros::adi::ext_adi_port_pair_t mogoport = {
    5, PNEUMATIC_ADIPORT_MOBILE_GOAL};

LCHS::Drivetrain::Drivetrain(std::initializer_list<std::int8_t> leftDrivePorts,
                             std::initializer_list<std::int8_t> rightDrivePorts,
                             std::function<void()> mogoAct,
                             std::function<void()> sweeperAct) :
    leftDrive(leftDrivePorts),
    rightDrive(rightDrivePorts),
    intake({MOTOR_PORT_INTAKE, MOTOR_PORT_INTAKE2}),
    mogoGrabber(PNEUMATIC_ADIPORT_MOBILE_GOAL, SENSOR_PORT_MOGO_DISTANCE),
    //fishMech({MOTOR_PORT_FISHMECH}),
    sweeperMech(PNEUMATIC_ADIPORT_SWEEPER),
    mogoAct(mogoAct),
    sweeperAct(sweeperAct) {
      std::cout << "drivtrain init";
    }

void LCHS::Drivetrain::move(std::int32_t voltageLeft,
                            std::int32_t voltageRight) {
  leftDrive.move(voltageLeft);
  rightDrive.move(voltageRight);
}

void LCHS::Drivetrain::move_absolute(const double positionLeft,
                                     const double positionRight,
                                     const double velocityLeft,
                                     const double velocityRight) {
  leftDrive.move_absolute(positionLeft, velocityLeft);
  rightDrive.move_absolute(positionRight, velocityRight);
}

void LCHS::Drivetrain::move_relative(const double positionLeft,
                                     const double positionRight,
                                     const double velocityLeft,
                                     const double velocityRight) {
  leftDrive.move_relative(positionLeft, velocityLeft);
  rightDrive.move_relative(positionRight, velocityRight);
}

void LCHS::Drivetrain::move_velocity(const double velocityLeft,
                                     const double velocityRight) {
  leftDrive.move_velocity(velocityLeft);
  rightDrive.move_velocity(velocityRight);
}

void LCHS::Drivetrain::brake() {
  leftDrive.brake();
  rightDrive.brake();
}

void LCHS::Drivetrain::driverControl() {
  // # Movement
  std::int32_t leftVoltage = master.get_analog(CONTROL_AXIS_LEFT_DRIVE);
  std::int32_t rightVoltage = master.get_analog(CONTROL_AXIS_RIGHT_DRIVE);

  // Deadzone between -5 and 5
  if (leftVoltage > -10 && leftVoltage < 10) {
    leftVoltage = 0;
  }
  if (rightVoltage > -10 && rightVoltage < 10) {
    rightVoltage = 0;
  }

  // Deadzone above 124 and below -124
  if (leftVoltage > 124) {
    leftVoltage = 127;
  }
  if (leftVoltage < -124) {
    leftVoltage = -127;
  }

  move(leftVoltage, rightVoltage);

  // # Intake
  if (master.get_digital(CONTROL_BUTTON_INTAKE_IN)) {
    intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::IN);
  } else if (master.get_digital(CONTROL_BUTTON_INTAKE_OUT)) {
    intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::OUT);
  } else {
    intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::STOP);
  }
  
  // # MOGO
  if (master.get_digital_new_press(CONTROL_BUTTON_MOGO_TOGGLE)) {
    std::cout << "Toggling mogo\n" << std::flush;
    mogoAct();
    mogoGrabber.toggle();
    // print state
    std::cout << "Mogo state: " << mogoGrabber.getState() << std::endl;
  } 

  // if (master.get_digital_new_press(CONTROL_BUTTON_MOGO_RELEASE)) {
  //   std::cout << "Toggling mogo\n" << std::flush;
  //   //std::cout << mogoGrabber.grab() << std::endl;
  //   // print state
  //   //std::cout << "Mogo state: " << mogoGrabber.getState() << std::endl;
  //   mogotwo.extend();
  //   std::cout << errno << std::endl;
  //   // pros::c::ext_adi_digital_write(5, 1, true);
  // } else if (master.get_digital_new_press(CONTROL_BUTTON_MOGO_GRAB)) {
  //   std::cout << "Toggling mogo\n" << std::flush;
  //   //std::cout << mogoGrabber.release() << std::endl;
  //   // print state
  //   //std::cout << "Mogo state: " << mogoGrabber.getState() << std::endl;
  //   mogotwo.retract();
  //   std::cout << errno  << std::endl;
  //   //pros::c::ext_adi_digital_write(5, 1, false);
  // }

  // # Sweeper
  if (master.get_digital(CONTROL_BUTTON_SWEEPER_OUT)) {
    sweeperMech.swingout();
  } else if (master.get_digital(CONTROL_BUTTON_SWEEPER_IN)) {
    sweeperMech.swingin();
  }
  if (master.get_digital_new_press(CONTROL_BUTTON_SWEEPER_TOGGLE)) {
    std::cout << "Toggling sweeper\n" << std::flush;
    sweeperAct();
    sweeperMech.toggle();
    // print state
    std::cout << "Sweeper state: " << int(sweeperMech.getState()) << std::endl;
  }

  // // # FishMech
  // if (master.get_digital(CONTROL_BUTTON_FISHMECH_UP) && !master.get_digital(CONTROL_BUTTON_FISHMECH_OVERRIDE)) {
  //   fishMech.spin(100);
  // } else if (master.get_digital(CONTROL_BUTTON_FISHMECH_DOWN) && !master.get_digital(CONTROL_BUTTON_FISHMECH_OVERRIDE)) {
  //   fishMech.spin(-100);
  // } 
  
  // else if (master.get_digital(CONTROL_BUTTON_FISHMECH_UP) &&  master.get_digital(CONTROL_BUTTON_FISHMECH_OVERRIDE)) {
  //   fishMech.overrideSpin(100);
  // } else if (master.get_digital(CONTROL_BUTTON_FISHMECH_DOWN) && master.get_digital(CONTROL_BUTTON_FISHMECH_OVERRIDE)) {
  //   fishMech.overrideSpin(-100);
  // }

  // else {
  //   fishMech.stop();
  // }

  // if (master.get_digital_new_press(CONTROL_BUTTON_FISHMECH_RESET) && master.get_digital_new_press(CONTROL_BUTTON_FISHMECH_OVERRIDE)) {
  //   fishMech.calibrate();
  // }
}
