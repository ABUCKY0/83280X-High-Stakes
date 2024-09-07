#ifndef SUBSYSTEM_INTAKE_H
#define SUBSYSTEM_INTAKE_H

#include "main.h"
#include <iostream>
#include "pros/apix.h"

enum class PTOState {
    DRIVETRAIN,
    LIFT
};



/**
 * @brief Intake subsystem
 * 
 * This class is responsible for controlling the intake and lift subsystems. It is responsible for controlling the intake motors, lift motors, and the PTOs.
 */
class Intake {
private:
    pros::MotorGroup intakeMotors;
    pros::MotorGroup liftMotors;
    pros::adi::Pneumatics ptoLeft;
    pros::adi::Pneumatics ptoRight;
    pros::Rotation liftPosition;
    PTOState ptoState = PTOState::LIFT;


public:
    Intake() = delete;
    Intake(std::initializer_list<std::int8_t> motors, std::initializer_list<std::int8_t> liftmotors, std::uint8_t pneumaticLeft, std::uint8_t pneumaticRight, const std::int8_t rotationPort) : intakeMotors(motors), liftMotors(liftmotors), ptoLeft(pneumaticLeft, true), ptoRight(pneumaticRight, true), liftPosition(rotationPort), ptoState(PTOState::LIFT) {
        intakeMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }

    /**
     * @brief Takes the PTOs from the drivetrain and sets the brake mode to hold
     * 
     * Takes the extra 11w motor power from the drivetrain, applies it to the lift, and sets the brake mode to hold
     * 
     */
    void pto_take() {
        ptoLeft.set_value(true);
        ptoRight.set_value(true);
        liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        liftMotors.move(0); // Ensure that the lift motors are not moving
        liftMotors.brake();
    }

    void pto_release() {
        ptoLeft.set_value(false);
        ptoRight.set_value(false);
        liftMotors.move(0); // Ensure that the lift motors are not moving, as this could negatively affect the drivetrain. Although the motors being limp is not ideal, it is better than the drivetrain fighting against the motors.
        /*
         When connecting to the Drivetrain, we want the motors to coast so that the Drivetrain can move freely.
         For now, I'm going to leave setting the motorspeed for the controller in the Drivetrain subsystem.
         */
        liftMotors.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
};
#endif