#ifndef MOGO_GRABBER_HPP
#define MOGO_GRABBER_HPP

#include "main.h" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/apix.h" // IWYu pragma: keep
class MobileGoalGrabber {
    pros::Task mobileGoalTask;
    pros::adi::Pneumatics piston;
    pros::adi::DigitalIn limitSwitch;

public:
    MobileGoalGrabber() = delete;
    MobileGoalGrabber(std::uint8_t pneumaticPort, std::uint8_t limitSwitchPort);
    
    void grab();
    void release();
    void mobileGoalTaskFunction();
    static void taskEntry(void* thisPtr);
};

#endif