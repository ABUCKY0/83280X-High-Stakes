#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

// !PROS
#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h"

// !LC SUBSYSTEMS
#include "Constants.hpp"
#include "Subsystems/Intake/Intake.hpp"
#include "Subsystems/MogoMech/MobileGoalGrabber.hpp"
#include "Subsystems/SweeperMech/Sweeper.hpp"
#include "Subsystems/FishMech/FishMech.hpp"

// !LIBRARIES
#include "VexboxController/VexboxController.hpp"

// pros::MotorGroup left_drive({1, 2, 3}, pros::MotorGears::blue);
// pros::MotorGroup right_drive({4, 5, 6}, pros::MotorGears::blue);

// lemlib::Drivetrain bot(&left_drive, &right_drive, 10,
//                        lemlib::Omniwheel::NEW_275, 360, 2);

namespace LCHS {
// Drivetrain class for managing drivetrain during driver control LemLib handles
// the drivetrain during autonomous
class Drivetrain {
 private:
  // Motors
  pros::MotorGroup leftDrive;
  pros::MotorGroup rightDrive;
  
  // Subsystems
  LCHS::Intake intake;
  LCHS::MobileGoalGrabber mogoGrabber;
  LCHS::SweeperMech sweeperMech;
  LCHS::FishMech fishMech;

  // Controller
  pros::Controller master{E_CONTROLLER_MASTER};
  //VexboxController master{E_CONTROLLER_MASTER};

  std::function<void()> mogoAct;
  std::function<void()> sweeperAct;

 public:
  [[deprecated(
      "Use Drivetrain(std::initializer_list<std::int8_t> leftDrivePorts, "
      "std::initializer_list<std::int8_t> rightDrivePorts) instead")]]
  Drivetrain() = delete;

  /**
   * @brief Construct a new Drivetrain object
   * ----------------------------------------------------------------------
   * @param leftDrivePorts - The ports for the left side of the drivetrain
   * @param rightDrivePorts - The ports for the right side of the drivetrain
   */
  Drivetrain(std::initializer_list<std::int8_t> leftDrivePorts,
             std::initializer_list<std::int8_t> rightDrivePorts, std::function<void()> mogoAct, std::function<void()> sweeperAct);
  /**
   * @brief Sets the voltage for the drivetrain from -127 to 127.
   *
   * @param voltageLeft New voltage for the left side of the drivetrain [-127, 127]
   * @param voltageRight New voltage for the right side of the drivetrain
   * [-127, 127]
   */
  void move(std::int32_t voltageLeft, std::int32_t voltageRight);

  /**
   * @brief Sets the voltage for the drivetrain from -127 to 127.
   *
   * @param positionLeft New voltage for the left side of the drivetrain [-127, 127]
   * @param positionRight New voltage for the right side of the drivetrain [-127, 127]
   * @param velocityLeft
   * @param velocityRight
   */
  void move_absolute(const double positionLeft, const double positionRight,
                     const double velocityLeft, const double velocityRight);
  void move_relative(const double positionLeft, const double positionRight,
                     const double velocityLeft, const double velocityRight);
  void move_velocity(const double velocityLeft, const double velocityRight);
  void brake();

  void takeLiftMotors();
  void releaseLiftMotors();

  pros::MotorGroup getLeftDrive();
  pros::MotorGroup getRightDrive();
  pros::Controller getMaster();
  /*
  If the drivetrain motors get above a certain threshold for torque for a
  certain amount of time, the drivetrain will take the lift ptos.

  *[X] talk to Nick and Evan about wether they want that to be a feature.
  * Seems nick and evan both agree that it should be a feature.
  Personally, I feel that it'd be better to make it manually triggered.
  */
  static void TaskDetectMotorStress();
  static void TaskDetectMotorStressEntry(void* thisPtr);

  void driverControl();
};
};  // namespace LCHS
#endif