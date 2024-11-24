
#include "Subsystems/Intake/Intake.hpp"
//#include "lemlib/pid.hpp"
#include "Subsystems/Intake/IntakePID.hpp"

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
LCHS::Intake::Intake(std::initializer_list<std::int8_t> motors,
                     std::uint8_t pneumaticLeft, std::uint8_t pneumaticRight,
                     const std::int8_t rotationPort)
    : intakeMotors(motors), 
      ptoLeft(pneumaticLeft, true), ptoRight(pneumaticRight, true),
       ptoState(PTOState::LIFT) {
  intakeMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //liftMotors.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
  ptoLeft.retract();
  ptoRight.retract();
  // liftPosition.reset_position();
}

/**
 * @brief Takes the PTOs from the drivetrain and sets the brake mode to hold
 *
 * Takes the extra 11w motor power from the drivetrain, applies it to the lift,
 * and sets the brake mode to hold
 *
 */
// void LCHS::Intake::pto_take() {
//   // take the PTOs from the drivetrain
//   ptoState = PTOState::LIFT;
//   ptoLeft.retract();
//   ptoRight.retract();
//   ptoLock = false;
//   liftMotors.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
//   liftMotors.move(0); // Ensure that the lift motors are not moving to prevent
//                       // the lift from having a mind of it's own
//   liftMotors.brake();
// }

// void LCHS::Intake::pto_release() {
//   ptoState = PTOState::DRIVETRAIN;

//   ptoLeft.extend();
//   ptoRight.extend();
//   ptoLock = true;
//   liftMotors.move(0); // Ensure that the lift motors are not moving, as this
//                       // could negatively affect the drivetrain. Although the
//                       // motors being limp is not ideal, it is better than the
//                       // drivetrain fighting against the motors.
//   /*
//    When connecting to the Drivetrain, we want the motors to coast so that the
//    Drivetrain can move freely. For now, I'm going to leave setting the
//    motorspeed for the controller in the Drivetrain subsystem.
//    */
//   liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
// }


// void LCHS::Intake::moveLift( std::int32_t speed) {
//   // liftMotors.move(speed);

//   if (ptoState == PTOState::DRIVETRAIN) {
//     pto_take();
//   }
//   pros::delay(15);
//   liftMotors.move_velocity(speed);
// }



// bool LCHS::Intake::isLiftAtBottom() {
//   if (liftPosition.get_position()/100 < 2) {
//     return true;
//   }
//   return false;
// }

// bool LCHS::Intake::isLiftAtTop() {
//   if (liftPosition.get_position()/100 > 90) { // 135 degrees is the top of the lift
//     return true;
//   }
//   return false;
// }

// LCHS::PTOState LCHS::Intake::getPTOState() { return ptoState; }

// void LCHS::Intake::brakeLift() {
//   liftMotors.move_velocity(0);
//   liftMotors.brake();
// }

void LCHS::Intake::setIntakeSpeed(int speed) {
  intakeMotors.move(speed);
}

void LCHS::Intake::setIntakeSpeedPreset(LCHS::IntakeSpeedPresets preset) {
  switch (preset) {
  case IntakeSpeedPresets::IN:
    intakeMotors.move_velocity(-200);
    break;
  case IntakeSpeedPresets::OUT:
    intakeMotors.move_velocity(200);
    break;
  case IntakeSpeedPresets::SLOW_IN:
    intakeMotors.move_velocity(-100);
    break;
  case IntakeSpeedPresets::SLOW_OUT:
    intakeMotors.move_velocity(100);
    break;
  case IntakeSpeedPresets::STOP:
    intakeMotors.move_velocity(0);
    break;
  }
}


// void LCHS::Intake::moveLiftPreset(LCHS::LIFTPositionPresets preset) {
//   this->liftPositionPreset = preset;
// }

// void LCHS::Intake::resetPID() {
//   liftPID.reset();
// }

void LCHS::Intake::update() {
  // // Update the lift position
  // LCHS::LIFTPositionPresets current = liftPositionPreset;
  // int target_pos;
  // switch (current) {
  //   case LCHS::LIFTPositionPresets::MAX:
  //     target_pos = 135; // Max position
  //     break;
  //   case LCHS::LIFTPositionPresets::MIN:
  //     target_pos = 0; // Mid position
  //     break;
  //   case LCHS::LIFTPositionPresets::WALL:
  //     target_pos = 60; // Wall position
  //     break;
  //   case LCHS::LIFTPositionPresets::ALLIANCE:
  //     target_pos = 90; // Alliance position
  //     break;
  //   case LCHS::LIFTPositionPresets::E_STOP:
  //     target_pos = liftPosition.get_position(); // Stop at current position
  //     break;
  // }
  // // Update the lift position based on the current preset
  // std::cout << "\033[2J";
  // int target = target_pos - (this->liftPosition.get_position() / 100);
  // int PIDOutput = liftPID.update(target);
  // std::cout << "PID Output: " << PIDOutput << std::endl;
  // std::cout << "Current Position: " << this->liftPosition.get_position() << std::endl;
  // std::cout << "Get Error: " << target << std::endl;
  // switch (current) {
  //   case LCHS::LIFTPositionPresets::MAX:
  //     std::cout << "Requested State: MAX" << std::endl;
  //     break;
  //   case LCHS::LIFTPositionPresets::MIN:
  //     std::cout << "Requested State: MIN" << std::endl;
  //     break;
  //   case LCHS::LIFTPositionPresets::WALL:
  //     std::cout << "Requested State: WALL" << std::endl;
  //     break;
  //   case LCHS::LIFTPositionPresets::ALLIANCE:
  //     std::cout << "Requested State: ALLIANCE" << std::endl;
  //     break;
  //   case LCHS::LIFTPositionPresets::E_STOP:
  //     std::cout << "Requested State: E_STOP" << std::endl;
  //     break;
  // }

  // // Move the lift motors based on the PID output
  // //this->liftMotors.move_voltage(-PIDOutput);


  // //this->liftMotors.move(-PIDOutput);
  // //PIDOutput = std::clamp(PIDOutput, -100, 100);
  // this->liftMotors.move(-PIDOutput);
}
