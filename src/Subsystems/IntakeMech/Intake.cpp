
#include "Subsystems/Intake/Intake.hpp"
//#include "lemlib/pid.hpp"
#include "Subsystems/Intake/IntakePID.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.h"

static float kp_up = 6.0f;
static float ki_up = 0.0f;
static float kd_up = 0.0f;
static float kp_down = 2.0f;
static float ki_down = 0.0f;
static float kd_down = 0.0f;

/**
 * @brief Intake subsystem
 *
 * This class is responsible for controlling the intake and lift subsystems. It
 * is responsible for controlling the intake motors, lift motors, and the PTOs.
 */
LCHS::Intake::Intake(std::initializer_list<std::int8_t> motors): intakeMotors(motors, pros::v5::MotorGears::blue) {
  std::cout << "Intake Init" << std::endl;
}

/**
 * @brief Move the intake motors at a given speed
 * 
 * @param speed [-127, 127] The speed to set the intake motors to
 * @note Uses -127 to 127, i.e. what is outputted by the controller analog sticks
 */
void LCHS::Intake::setIntakeSpeed(int speed) {
  intakeMotors.move(speed);
}

/**
 * @brief Set the Intake to a preset speed
 * 
 * @param preset Preset to use
 */
void LCHS::Intake::setIntakeSpeedPreset(LCHS::IntakeSpeedPresets preset) {
  switch (preset) {
  case IntakeSpeedPresets::IN:
    intakeMotors.move(-127);
    break;
  case IntakeSpeedPresets::OUT:
    intakeMotors.move(127);
    break;
  case IntakeSpeedPresets::SLOW_IN:
    intakeMotors.move(-60);
    break;
  case IntakeSpeedPresets::SLOW_OUT:
    intakeMotors.move_velocity(60);
    break;
  case IntakeSpeedPresets::STOP:
    intakeMotors.move_velocity(0);
    intakeMotors.brake();
    break;
  default:
    break;
  }
}

/**
 * @brief UNUSED
 * 
 */
void LCHS::Intake::update() {}