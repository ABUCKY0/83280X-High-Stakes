
#include "Subsystems/Intake.hpp"


/**
 * @brief Intake subsystem
 *
 * This class is responsible for controlling the intake and lift subsystems. It
 * is responsible for controlling the intake motors, lift motors, and the PTOs.
 */

LCHS::Intake::Intake(std::initializer_list<std::int8_t> motors,
                     std::initializer_list<std::int8_t> liftmotors,
                     std::uint8_t pneumaticLeft, std::uint8_t pneumaticRight,
                     const std::int8_t rotationPort)
    : intakeMotors(motors), liftMotors(liftmotors),
      ptoLeft(pneumaticLeft, true), ptoRight(pneumaticRight, true),
      liftPosition(rotationPort), ptoState(PTOState::LIFT) {
  intakeMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  ptoLeft.retract();
  ptoRight.retract();
}

/**
 * @brief Takes the PTOs from the drivetrain and sets the brake mode to hold
 *
 * Takes the extra 11w motor power from the drivetrain, applies it to the lift,
 * and sets the brake mode to hold
 *
 */
void LCHS::Intake::pto_take() {
  // take the PTOs from the drivetrain
  ptoState = PTOState::LIFT;
  ptoLeft.retract();
  ptoRight.retract();
  ptoLock = false;
  liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  liftMotors.move(0); // Ensure that the lift motors are not moving to prevent
                      // the lift from having a mind of it's own
  liftMotors.brake();
}

void LCHS::Intake::pto_release() {
  ptoState = PTOState::DRIVETRAIN;

  ptoLeft.extend();
  ptoRight.extend();
  ptoLock = true;
  liftMotors.move(0); // Ensure that the lift motors are not moving, as this
                      // could negatively affect the drivetrain. Although the
                      // motors being limp is not ideal, it is better than the
                      // drivetrain fighting against the motors.
  /*
   When connecting to the Drivetrain, we want the motors to coast so that the
   Drivetrain can move freely. For now, I'm going to leave setting the
   motorspeed for the controller in the Drivetrain subsystem.
   */
  liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}


void LCHS::Intake::moveLift( std::int32_t speed) {
  // liftMotors.move(speed);

  if (ptoState == PTOState::DRIVETRAIN) {
    pto_take();
  }
  pros::delay(15);
  liftMotors.move(speed);
}

bool LCHS::Intake::isLiftAtBottom() {
  if (liftPosition.get_angle() < 15) {
    return true;
  }
  return false;
}

bool LCHS::Intake::isLiftAtTop() {
  if (liftPosition.get_angle() > 135) { // 135 degrees is the top of the lift
    return true;
  }
  return false;
}

LCHS::PTOState LCHS::Intake::getPTOState() { return ptoState; }


void LCHS::Intake::setIntakeSpeed(int speed) {
  intakeMotors.move(speed);
}

void LCHS::Intake::setIntakeSpeedPreset(LCHS::IntakeSpeedPresets preset) {
  switch (preset) {
  case IntakeSpeedPresets::IN:
    intakeMotors.move_velocity(200);
    break;
  case IntakeSpeedPresets::OUT:
    intakeMotors.move_velocity(-200);
    break;
  case IntakeSpeedPresets::SLOW_IN:
    intakeMotors.move_velocity(100);
    break;
  case IntakeSpeedPresets::SLOW_OUT:
    intakeMotors.move_velocity(-100);
    break;
  case IntakeSpeedPresets::STOP:
    intakeMotors.move_velocity(0);
    break;
  }
}