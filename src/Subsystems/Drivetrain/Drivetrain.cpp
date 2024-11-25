#include "Constants.hpp"
#include "main.h"  // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/motors.h"

#include <atomic>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "Subsystems/Drivetrain/Drivetrain.hpp"  // IWYU pragma: keep
static bool reset = false;
LCHS::Drivetrain::Drivetrain(
    std::initializer_list<std::int8_t> leftDrivePorts,
    std::initializer_list<std::int8_t> rightDrivePorts) :
    leftDrive(leftDrivePorts),
    rightDrive(rightDrivePorts),
    intake({MOTOR_PORT_INTAKE}),
    mogoGrabber(PNEUMATIC_PORT_MOBILE_GOAL, SENSOR_PORT_MOGO_LIMIT_SWITCH) {

    }

void LCHS::Drivetrain::move(std::int32_t voltageLeft,
                            std::int32_t voltageRight) {
                              std::cout << to_string(voltageLeft) << " " << to_string(voltageRight) << std::endl;
  leftDrive.move_voltage(voltageLeft);
  rightDrive.move_voltage(voltageRight);
  std::cout << leftDrive.get_target_velocity() << " " << rightDrive.get_target_velocity() << std::endl;
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

  // Get the voltage from the controller
  std::int32_t leftVoltage = -master.get_analog(CONTROL_AXIS_LEFT_DRIVE);
  std::int32_t rightVoltage = master.get_analog(CONTROL_AXIS_RIGHT_DRIVE);

  // Set the voltage for the drivetrain
  //move(leftVoltage, rightVoltage);
  move_velocity(leftVoltage, rightVoltage);

  bool isLiftMoving = false;
}
