#pragma once
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h"

pros::MotorGroup left_drive({1, 2, 3}, pros::MotorGears::blue);
pros::MotorGroup right_drive({4, 5, 6}, pros::MotorGears::blue);

lemlib::Drivetrain bot(&left_drive, &right_drive, 10, lemlib::Omniwheel::NEW_275, 360, 2);