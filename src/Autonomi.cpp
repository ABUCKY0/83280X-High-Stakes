#include "autonomi.hpp"
#include "main.h"  // IWYU pragma: keep

ASSET(grab_mogo_txt);

/**
 * @brief Red Left autonomous code
 * @author @ABUCKY0
 */
void redLeft(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs) {
  // Red left autonomous code here
  std::cout << pros::millis() << " - DEBUG: Red Left Auton\n";
}

/**
 * @brief Red Right autonomous code
 * 
 */
void redRight(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs) {
  // Red right autonomous code here
  std::cout << pros::millis() << " - DEBUG: Red Right Auton\n";
}

/**
 * @brief Blue Left autonomous code
 * 
 */
void blueLeft(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs) {
  // Blue left autonomous code here
  std::cout << pros::millis() << " - DEBUG: Blue Left Auton\n";
}

/**
 * @brief Blue Right autonomous code
 * 
 */
void blueRight(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs) {
  // Blue right autonomous code here
  std::cout << pros::millis() << " - DEBUG: Blue Right Auton\n";
}

/**
 * @brief Primary Skills Auton
 * 
 */
void skillsPrimary(lemlib::Drivetrain& drivetrain,
                   LCHS::Drivetrain& robotsubs) {
  // Skills autonomous code here
  std::cout << pros::millis() << " - DEBUG: Skills Primary Auton\n";
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
void noSkills(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs) {
  // Does Nothing, meant to control LED strips (to be setup at a later time)
  std::cout << pros::millis() << " - DEBUG: No Skills Auton\n";
}

void noMatch(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs) {
  // Does Nothing, meant to control LED strips (to be setup at a later time)
  std::cout << pros::millis() << " - DEBUG: No Match Auton\n";
}