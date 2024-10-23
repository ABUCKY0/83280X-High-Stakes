#include "Constants.hpp"
#include "main.h"  // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/motors.h"

#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "Subsystems/Drivetrain/Drivetrain.hpp"  // IWYU pragma: keep

LCHS::Drivetrain::Drivetrain(
    std::initializer_list<std::int8_t> leftDrivePorts,
    std::initializer_list<std::int8_t> rightDrivePorts) :
    leftDrive(leftDrivePorts),
    rightDrive(rightDrivePorts),
    intake({MOTOR_PORT_INTAKE}, {MOTOR_PORT_LEFT_LIFT, MOTOR_PORT_RIGHT_LIFT},
           PNEUMATIC_PORT_PTO_LEFT, PNEUMATIC_PORT_PTO_RIGHT, SENSOR_PORT_LIFT),
    mogoGrabber(PNEUMATIC_PORT_MOBILE_GOAL, SENSOR_PORT_MOGO_LIMIT_SWITCH) {}

void LCHS::Drivetrain::move(std::int32_t voltageLeft,
                            std::int32_t voltageRight) {
  leftDrive.move_voltage(voltageLeft);
  rightDrive.move_voltage(voltageRight);
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

void LCHS::Drivetrain::takeLiftMotors() {
  this->intake.pto_take();
}

void LCHS::Drivetrain::releaseLiftMotors() {
  this->intake.pto_release();
}

void LCHS::Drivetrain::brake() {
  leftDrive.brake();
  rightDrive.brake();
}

void LCHS::Drivetrain::driverControl() {
  // Get the voltage from the controller
  std::int32_t leftVoltage = master.get_analog(CONTROL_AXIS_LEFT_DRIVE);
  std::int32_t rightVoltage = master.get_analog(CONTROL_AXIS_RIGHT_DRIVE);

  // Set the voltage for the drivetrain
  move(leftVoltage, rightVoltage);

  bool isLiftMoving = false;
  // If the driver presses the L1 button, lift moves up.
  if (this->master.get_digital(CONTROL_BUTTON_LIFT_UP)) {
    isLiftMoving = true;
    if (this->intake.getPTOState() == LCHS::PTOState::DRIVETRAIN) {
      takeLiftMotors();
    }

    if (!this->intake.isLiftAtTop()) {
      this->intake.moveLift(127);
    } else {
      this->intake.moveLift(0);
    }
  } else if (this->master.get_digital(CONTROL_BUTTON_LIFT_DOWN)) {
    isLiftMoving = true;
    if (this->intake.getPTOState() == LCHS::PTOState::DRIVETRAIN) {
      takeLiftMotors();
    }

    if (!this->intake.isLiftAtBottom()) {
      this->intake.moveLift(-127);
    } else {
      this->intake.moveLift(0);
    }
  } else {
    this->intake.moveLift(0);
  }

  if (this->master.get_digital(CONTROL_BUTTON_INTAKE_IN)) {
    this->intake.setIntakeSpeed(127);
  } else if (master.get_digital(CONTROL_BUTTON_INTAKE_OUT)) {
    this->intake.setIntakeSpeed(-127);
  } else {
    this->intake.setIntakeSpeed(0);
  }
}
