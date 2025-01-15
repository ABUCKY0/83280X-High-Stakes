#ifndef AUTONOMI_HPP
#define AUTONOMI_HPP
#include "Subsystems/Drivetrain/Drivetrain.hpp"
#include "lemlib/api.hpp"  // IWYU pragma: keep

void redLeft(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs);
void redRight(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs);
void blueLeft(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs);
void blueRight(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs);
void skillsPrimary(lemlib::Drivetrain& drivetrain, LCHS::Drivetrain& robotsubs);
void skillsSecondary(lemlib::Drivetrain& drivetrain,
                     LCHS::Drivetrain& robotsubs);
void noSkills();
void noMatch();

#endif