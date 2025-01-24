#ifndef MOGO_GRABBER_HPP
#define MOGO_GRABBER_HPP

#include "main.h" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/apix.h" // IWYu pragma: keep
#include "pros/distance.hpp"
namespace LCHS {
class MobileGoalGrabber {
    pros::Task mobileGoalTask;
    pros::adi::Pneumatics piston;
    // pros::adi::DigitalIn limitSwitch;
    pros::Distance distance;

public:
    MobileGoalGrabber() = delete;
    MobileGoalGrabber(std::uint8_t pneumaticPort, std::uint8_t distancePort);
    MobileGoalGrabber(pros::adi::ext_adi_port_pair_t portPair, std::uint8_t distancePort);
    std::int32_t grab();
    std::int32_t release();
    std::int32_t toggle();
    bool getState();
    void mobileGoalTaskFunction();
    static void taskEntry(void* thisPtr);
};
};
#endif