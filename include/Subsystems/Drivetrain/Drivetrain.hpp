#pragma once
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h"

#include "Subsystems/Intake.hpp"
#include "Subsystems/MobileGoalGrabber.hpp"
#include "Constants.hpp"

// pros::MotorGroup left_drive({1, 2, 3}, pros::MotorGears::blue);
// pros::MotorGroup right_drive({4, 5, 6}, pros::MotorGears::blue);

// lemlib::Drivetrain bot(&left_drive, &right_drive, 10,
//                        lemlib::Omniwheel::NEW_275, 360, 2);

namespace LCHS {
    // Drivetrain class for managing drivetrain during driver control LemLib handles the drivetrain during autonomous
    class Drivetrain {
        private:
            pros::MotorGroup leftDrive;
            pros::MotorGroup rightDrive;
            LCHS::Intake intake;
            LCHS::MobileGoalGrabber mogoGrabber;
        
        public:

        Drivetrain (std::initializer_list<std::int8_t> leftDrivePorts, std::initializer_list<std::int8_t> rightDrivePorts) : leftDrive(leftDrivePorts), rightDrive(rightDrivePorts), intake({MOTOR_PORT_INTAKE}, {MOTOR_PORT_LEFT_LIFT, MOTOR_PORT_RIGHT_LIFT}, PNEUMATIC_PORT_PTO_LEFT, PNEUMATIC_PORT_PTO_RIGHT, SENSOR_PORT_LIFT), mogoGrabber(PNEUMATIC_PORT_MOBILE_GOAL, SENSOR_PORT_MOGO_LIMIT_SWITCH) {
            leftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            rightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            
        }

        void move(int leftSpeed, int rightSpeed);
        void brake();

        /*
        If the drivetrain motors get above a certain threshold for torque for a certain amount of time, the drivetrain will take the lift ptos. 

        TODO talk to Nick and Evan about wether they want that to be a feature. Personally, I feel that it'd be better to make it manually triggered.
        */




            
    };
};