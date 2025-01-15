#ifndef AUTONOMI_HPP
#define AUTONOMI_HPP
#include "Subsystems/Drivetrain/Drivetrain.hpp"
#include "lemlib/api.hpp"  // IWYU pragma: keep

void redLeft(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain);
void redRight(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain);
void blueLeft(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain);
void blueRight(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain);
void skillsPrimary(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain);
void skillsSecondary(lemlib::Chassis& chassis, LCHS::Drivetrain& drivetrain);
void noSkills();
void noMatch();

#endif