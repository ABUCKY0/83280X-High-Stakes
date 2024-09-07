#ifndef SUBSYSTEM_INTAKE_HPP
#define SUBSYSTEM_INTAKE_HPP
#include "main.h"      // IWYU pragma: keep
#include "pros/apix.h" // IWYU pragma: keep
#include <atomic> // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep

enum class PTOState {
    DRIVETRAIN,
    LIFT
};

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
    PTOState ptoState = PTOState::LIFT;
    std::atomic_bool ptoLock = false;

public:
    /**
     * @brief Default constructor, deleted to prevent usage
     */
    Intake() = delete;

    /**
     * @brief Intake subsystem
     *
     * Creates a new instance of the intake subsystem.
     * @param motors The ports of the intake motors, named motors to prevent collision with the actual MotorGroup, liftMotors
     * @param liftmotors The ports of the lift motors
     * @param pneumaticLeft The port of the left PTO
     * @param pneumaticRight The port of the right PTO
     * @param rotationPort The port of the rotation sensor
     * @see pros::MotorGroup
     */
    Intake(std::initializer_list<std::int8_t> motors, std::initializer_list<std::int8_t> liftmotors, std::uint8_t pneumaticLeft, std::uint8_t pneumaticRight, const std::int8_t rotationPort);
    
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
};
#endif