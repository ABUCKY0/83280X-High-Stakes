#include "MobileGoalGrabber.hpp"
LCHS::MobileGoalGrabber::MobileGoalGrabber(std::uint8_t pneumaticPort,
                                           std::uint8_t limitSwitchPort)
    : piston(pneumaticPort, false), limitSwitch(limitSwitchPort),
      mobileGoalTask(&MobileGoalGrabber::taskEntry, this, "mogo") {}

void LCHS::MobileGoalGrabber::grab() {
  piston.set_value(true); // Assuming true grabs the mobile goal
}

void LCHS::MobileGoalGrabber::release() {
  piston.set_value(false); // Assuming false releases the mobile goal
}

void LCHS::MobileGoalGrabber::mobileGoalTaskFunction() {
  // Task function logic here
  while (true) {
    if (limitSwitch.get_value()) {
      piston.set_value(true);
    }
    pros::delay(100); // Prevent busy waiting
  }
}

void LCHS::MobileGoalGrabber::taskEntry(void *thisPtr) {
  static_cast<MobileGoalGrabber *>(thisPtr)->mobileGoalTaskFunction();
}