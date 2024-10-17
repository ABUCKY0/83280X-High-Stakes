#ifndef SUBSYSTEM_INTAKE_HPP
#define SUBSYSTEM_INTAKE_HPP
// //#include "Drivetrain/Drivetrain.hpp"
#include "lemlib/pid.hpp"
#include "main.h" // IWYU pragma: keep
#include <atomic>

namespace LCHS {
enum class PTOState { DRIVETRAIN, LIFT };
enum class LIFTPositionPresets { MAX, MIN, WALL, ALLIANCE, E_STOP };
enum class IntakeSpeedPresets { IN, OUT, SLOW_IN, SLOW_OUT, STOP };

/**
 * @brief Intake subsystem
 *
 * This class is responsible for controlling the intake and lift subsystems. It
 * is responsible for controlling the intake motors, lift motors, and the PTOs.
 */
class Intake {
private:
  pros::MotorGroup intakeMotors;
  pros::MotorGroup liftMotors;
  pros::adi::Pneumatics ptoLeft;
  pros::adi::Pneumatics ptoRight;
  pros::Rotation liftPosition;
  // LCHS::PTOState ptoState = LCHS::PTOState::LIFT;
  std::atomic<LCHS::PTOState> ptoState =  LCHS::PTOState::LIFT;
  std::atomic<LCHS::LIFTPositionPresets> liftPositionPreset = LCHS::LIFTPositionPresets::MIN;
  std::atomic_bool ptoLock = false;

  //lemlib::PID liftPID;

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
   * @param liftmotors The ports of the lift motors
   * @param pneumaticLeft The port of the left PTO
   * @param pneumaticRight The port of the right PTO
   * @param rotationPort The port of the rotation sensor
   * @see pros::MotorGroup
   */
  Intake(std::initializer_list<std::int8_t> motors,
         std::initializer_list<std::int8_t> liftmotors,
         std::uint8_t pneumaticLeft, std::uint8_t pneumaticRight,
         const std::int8_t rotationPort);

  /**
   * @brief Release the PTOs and set the lift motors to coast
   * Sets the PTOs to the extended position and sets the lift motors to coast
   */
  void pto_take();

  /**
   * @brief Retract the PTOs and set the lift motors to hold
   * Sets the PTOs to the retracted position and sets the lift motors to hold
   */
  void pto_release();

  /**
   * @brief Moves lift motors at a given speed
   *
   * @param speed Speed to move the lift motors at (127 to -127)
   * @note This function does not verify bounds of the lift. This should be done by the caller.
   */
  void moveLift(int32_t speed);

  /**
   * @brief Move the lift to a preset position
   *
   * @param preset The preset to move the lift to
   */
  void moveLiftPreset(LCHS::LIFTPositionPresets preset);

  /**
   * @brief Is the lift at the top?
   * 
   * @return true If the lift is at the top
   * @return false If the lift is not at the top
   */
  bool isLiftAtTop();

  /**
   * @brief Is the lift at the bottom?
   * 
   * @return true If the lift is at the bottom
   * @return false If the lift is not at the bottom
   */
  bool isLiftAtBottom();

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
  LCHS::PTOState getPTOState();
};
}; // namespace LCHS
#endif