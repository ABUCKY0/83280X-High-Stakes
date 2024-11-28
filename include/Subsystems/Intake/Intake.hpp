#ifndef SUBSYSTEM_INTAKE_HPP
#define SUBSYSTEM_INTAKE_HPP
// //#include "Drivetrain/Drivetrain.hpp"
#include <atomic>
// // #include "lemlib/pid.hpp"
#include "Subsystems/Intake/IntakePID.hpp"
#include "main.h"  // IWYU pragma: keep


namespace LCHS {
enum class IntakeSpeedPresets { IN, OUT, SLOW_IN, SLOW_OUT, STOP };

/**
 * @brief Intake subsystem
 *
 * This class is responsible for controlling the intake and lift subsystems. It
 * is responsible for controlling the intake motors, lift motors, and the PTOs.
 */
class Intake {
 public:
  pros::MotorGroup intakeMotors;

 public:
  /**
   * @brief Default constructor, deleted to prevent usage
   */
  Intake() = delete;

  /**
   * @brief Intake subsystem
   *
   * Creates a new instance of the intake subsystem.
   * @param motors The ports of the intake motors, named motors to prevent
   * collision with the actual MotorGroup, liftMotors
   * @param rotationPort The port of the rotation sensor
   * @see pros::MotorGroup
   */
  Intake(std::initializer_list<std::int8_t> motors);

  /**
   * @brief Set the Intake Speed object
   * 
   * @param speed The speed to set the intake motors to
   */
  void setIntakeSpeed(int speed);

  /**
   * @brief Sets the Intake speed to a given preset
   * 
   * @param preset The preset to set the intake speed to
   */
  void setIntakeSpeedPreset(LCHS::IntakeSpeedPresets preset);

  /**
   * @brief Get the Intake Speed object
   * 
   * @return double The speed of the intake motors
   */
  double getIntakeSpeed();

  /**
   * @brief Get the Lift Position object
   * 
   * @return double The position of the lift
   */
  // LCHS::PTOState getPTOState();

  /**
   * @brief Update the intake subsystem 
   * 
   */
  void update();

};
};  // namespace LCHS
#endif