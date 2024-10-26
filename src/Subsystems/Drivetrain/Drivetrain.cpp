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
    intake({MOTOR_PORT_INTAKE, MOTOR_PORT_INTAKE2}, {MOTOR_PORT_LEFT_LIFT, MOTOR_PORT_RIGHT_LIFT},
           PNEUMATIC_PORT_PTO_LEFT, PNEUMATIC_PORT_PTO_RIGHT, SENSOR_PORT_LIFT),
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
  if (!reset) {
    reset = true;
    this->intake.liftPosition.set_position(0);
  }
  // Get the voltage from the controller
  std::int32_t leftVoltage = -master.get_analog(CONTROL_AXIS_LEFT_DRIVE);
  std::int32_t rightVoltage = master.get_analog(CONTROL_AXIS_RIGHT_DRIVE);

  // Set the voltage for the drivetrain
  //move(leftVoltage, rightVoltage);
  move_velocity(leftVoltage, rightVoltage);
  // std::cout << "LiftPos: " << this->intake.liftPosition.get_position()
  //            << std::endl;

  bool isLiftMoving = false;
  // If the driver presses the L1 button, lift moves up.
  if (this->master.get_digital(CONTROL_BUTTON_LIFT_UP)) {
    isLiftMoving = true;
    if (this->intake.getPTOState() == LCHS::PTOState::DRIVETRAIN) {
      takeLiftMotors();
    }

    if (!this->intake.isLiftAtTop()) {
      this->intake.moveLift(-50);
      std::cout << "moving up,0";
    } else {
      this->intake.moveLift(0);
      this->intake.brakeLift();
    }
  } else if (this->master.get_digital(CONTROL_BUTTON_LIFT_DOWN)) {
    isLiftMoving = true;
    if (this->intake.getPTOState() == LCHS::PTOState::DRIVETRAIN) {
      takeLiftMotors();
    }

    if (!this->intake.isLiftAtBottom()) {
      this->intake.moveLift(120);
    } else {
      this->intake.moveLift(0);
      this->intake.brakeLift();
    }
  } else {
    this->intake.moveLift(0);
    this->intake.brakeLift();
  }
  // if (this->master.get_digital_new_press(CONTROL_BUTTON_LIFT_DOWN)) {
  //   switch (this->intake.liftPositionPreset) {
  //     // enum class LIFTPositionPresets { MAX, WALL, ALLIANCE, MIN, E_STOP };
  //     case LCHS::LIFTPositionPresets::MAX:
  //       this->intake.moveLiftPreset(LCHS::LIFTPositionPresets::WALL);
  //       break;
  //     case LCHS::LIFTPositionPresets::WALL:
  //       this->intake.moveLiftPreset(LCHS::LIFTPositionPresets::ALLIANCE);
  //       break;
  //     case LCHS::LIFTPositionPresets::ALLIANCE:
  //       this->intake.moveLiftPreset(LCHS::LIFTPositionPresets::MIN);
  //       break;
  //     case LCHS::LIFTPositionPresets::MIN:
  //       // Do nothing
  //       break;
  //     default:
  //       break; 
  //   }

  // }
  // else if (this->master.get_digital_new_press(CONTROL_BUTTON_LIFT_UP)) {
  //   switch (this->intake.liftPositionPreset) {
  //     case LCHS::LIFTPositionPresets::MIN:
  //       this->intake.moveLiftPreset(LCHS::LIFTPositionPresets::ALLIANCE);
  //       break;
  //     case LCHS::LIFTPositionPresets::ALLIANCE:
  //       this->intake.moveLiftPreset(LCHS::LIFTPositionPresets::WALL);
  //       break;
  //     case LCHS::LIFTPositionPresets::WALL:
  //       this->intake.moveLiftPreset(LCHS::LIFTPositionPresets::MAX);
  //       break;
  //     case LCHS::LIFTPositionPresets::MAX:
  //       // Do nothing
  //       break;
  //     default:
  //       break; 
  //   }
  // }
  //   this->intake.update();

  if (this->master.get_digital(CONTROL_BUTTON_INTAKE_OUT)) {
    this->intake.setIntakeSpeed(127);
  } else if (master.get_digital(CONTROL_BUTTON_INTAKE_IN)) {
    this->intake.setIntakeSpeed(-127);
  } else {
    this->intake.setIntakeSpeed(0);
  }


  std::atomic_bool mogoGrabbed = false;
  if (this->master.get_digital_new_press(CONTROL_BUTTON_MOGO_TOGGLE)) {
    if (mogoGrabbed) {
      this->mogoGrabber.release();
      mogoGrabbed = false;
    } else {
      this->mogoGrabber.grab();
      mogoGrabbed = true;
    }
  }
}
