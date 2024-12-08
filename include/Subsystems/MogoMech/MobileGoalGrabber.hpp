#ifndef MOGO_GRABBER_HPP
#define MOGO_GRABBER_HPP

#include "main.h" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/apix.h" // IWYu pragma: keep
namespace LCHS {
class MobileGoalGrabber {
    pros::Task mobileGoalTask;
    pros::adi::Pneumatics piston;
    pros::adi::DigitalIn limitSwitch;

public:
    MobileGoalGrabber() = delete;
    MobileGoalGrabber(std::uint8_t pneumaticPort, std::uint8_t limitSwitchPort);
    MobileGoalGrabber(pros::adi::ext_adi_port_pair_t portPair, std::uint8_t limitSwitchPort);
    std::int32_t grab();
    std::int32_t release();
    std::int32_t toggle();
    bool getState();
    void mobileGoalTaskFunction();
    static void taskEntry(void* thisPtr);
};
};
#endif