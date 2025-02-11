#include "autonomi.hpp"
#include "Subsystems/Intake/Intake.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"  // IWYU pragma: keep
#include "pros/motors.h"

ASSET(grab_mogo_txt);
ASSET(grabFirstRing_txt);
ASSET(grabSecondRing_txt);
ASSET(contactBar_txt);
ASSET(blueLeftEnd_txt);

/**
 * @brief Red Left autonomous code
 * @author @ABUCKY0
 */
void redLeft(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Red right autonomous code here
  std::cout << pros::millis() << " - DEBUG: Red Right Auton\n";
  drivetrain.mogoGrabber.release();
  chassis.setPose(-64, 24, 270);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  chassis.moveToPose(-24, 24, 270, 2000, {.forwards = false});
  chassis.waitUntilDone();
  drivetrain.mogoGrabber.grab();
  drivetrain.intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::IN);
  chassis.moveToPoint(-24, 50, 3000);
  chassis.turnToHeading(180, 2000);
  chassis.moveToPose(-24, 16, 180, 3000);
}

/**
 * @brief Red Right autonomous code
 * 
 */
void redRight(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Red right autonomous code here
  std::cout << pros::millis() << " - DEBUG: Red Right Auton\n";
  drivetrain.mogoGrabber.release();
  chassis.setPose(-64, -24, 270);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  chassis.moveToPose(-24, -24, 270, 2000, {.forwards = false});
  chassis.waitUntilDone();
  drivetrain.mogoGrabber.grab();
  drivetrain.intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::IN);
  chassis.moveToPoint(-24, -50, 3000);
  chassis.turnToHeading(0, 2000);
  chassis.moveToPoint(-24, -16, 3000);
  // chassis.moveToPoint(-11, -11, 3000);
  // chassis.follow(blueLeftEnd_txt, 4, 2000);
}

/**
 * @brief Blue Left autonomous code
 * 
 */
void blueLeft(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Blue left autonomous code here
  std::cout << pros::millis() << " - DEBUG: Blue Left Auton\n";
  drivetrain.mogoGrabber.release();
  chassis.setPose(64, -24, 90);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  chassis.moveToPose(24, -24, 90, 2000, {.forwards = false});
  chassis.waitUntilDone();
  drivetrain.mogoGrabber.grab();
  drivetrain.intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::IN);
  chassis.moveToPoint(24, -50, 3000);
  chassis.turnToHeading(0, 2000);
  chassis.moveToPoint(24, -16, 3000);
}

/**
 * @brief Blue Right autonomous code
 * 
 */
void blueRight(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Blue right autonomous code here
  std::cout << pros::millis() << " - DEBUG: Blue Right Auton\n";
  drivetrain.mogoGrabber.release();
  chassis.setPose(64, 24, 90);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  chassis.moveToPose(24, 24, 90, 2000, {.forwards = false});
  chassis.waitUntilDone();
  drivetrain.mogoGrabber.grab();
  drivetrain.intake.setIntakeSpeedPreset(LCHS::IntakeSpeedPresets::IN);
  chassis.moveToPoint(24, 50, 3000);
  chassis.turnToHeading(180, 2000);
  chassis.moveToPoint(24, 16, 3000);
  // chassis.turnToHeading(300, 1000);
}

/**
 * @brief Primary Skills Auton
 * 
 */
void skillsPrimary(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Skills autonomous code here
  std::cout << pros::millis() << " - DEBUG: Skills Primary Auton\n";
  chassis.setPose(-64, -24, 270);
  chassis.moveToPose(-47, -24, 270, 2000, {.forwards = false});
  //clamp
  drivetrain.mogoGrabber.grab();

  chassis.turnToHeading(90, 1000);
  chassis.moveToPoint(-24, -24, 5000);
  chassis.turnToHeading(180, 1000);
  chassis.moveToPoint(-24, -47, 5000);
  chassis.turnToHeading(90, 1000);
  chassis.swingToPoint(0, -59, lemlib::DriveSide::RIGHT, 2500);
  chassis.turnToHeading(270, 1000);
  chassis.moveToPoint(-47, -59, 1000);
  chassis.turnToHeading(0, 1000);
  chassis.moveToPoint(-47, -47, 1000);
  chassis.turnToHeading(270, 1000);
  chassis.moveToPoint(-60, -47, 1000);
  chassis.turnToHeading(26.6, 1000);
  chassis.moveToPoint(-60, -60, 1000, {.forwards = false});
  chassis.moveToPoint(-48, 0, 5000);
}

/**
 * @brief Secondary Skills Auton
 * 
 */
void skillsSecondary(lemlib::Drivetrain& drivetrain,
                     LCHS::Drivetrain& robotsubs) {
  // Skills autonomous code here
  std::cout << pros::millis() << " - DEBUG: Skills Secondary Auton\n";
}

/**
 * @brief NoRun Skills Auton (Meant to control LED strips)
 * @note Does nothing, Selecting this option will not run any autonomous code
 * 
 */
void noSkills(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Does Nothing, meant to control LED strips (to be setup at a later time)
  std::cout << pros::millis() << " - DEBUG: No Skills Auton\n";
}

void noMatch(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain) {
  // Does Nothing, meant to control LED strips (to be setup at a later time)
  std::cout << pros::millis() << " - DEBUG: No Match Auton\n";
}
