#include "MobileGoalGrabber.hpp"   
MobileGoalGrabber::MobileGoalGrabber(std::uint8_t pneumaticPort, std::uint8_t limitSwitchPort) : piston(pneumaticPort, false), limitSwitch(limitSwitchPort), mobileGoalTask(&MobileGoalGrabber::taskEntry, this, "mogo"){
    
}

void MobileGoalGrabber::grab() {
    piston.set_value(true); // Assuming true grabs the mobile goal
}

void MobileGoalGrabber::release() {
    piston.set_value(false); // Assuming false releases the mobile goal
}

void MobileGoalGrabber::mobileGoalTaskFunction() {
    // Task function logic here
    while (true) {
        if (limitSwitch.get_value()) {
            piston.set_value(true);
        }
        pros::delay(100); // Prevent busy waiting
    }
}

void MobileGoalGrabber::taskEntry(void* thisPtr) {
    static_cast<MobileGoalGrabber*>(thisPtr)->mobileGoalTaskFunction();
}