#include "Subsystems/MogoMech/MobileGoalGrabber.hpp"

LCHS::MobileGoalGrabber::MobileGoalGrabber(std::uint8_t pneumaticPort,
                                           std::uint8_t limitSwitchPort)
    : piston(pneumaticPort, false, false), limitSwitch(limitSwitchPort){}
      //mobileGoalTask(&MobileGoalGrabber::taskEntry, this, "mogo") {}

LCHS::MobileGoalGrabber::MobileGoalGrabber(pros::adi::ext_adi_port_pair_t portPair,
                                           std::uint8_t limitSwitchPort) :
    piston(portPair, false, false),
    limitSwitch(limitSwitchPort){}

std::int32_t LCHS::MobileGoalGrabber::grab() {
  return piston.extend(); // Assuming true grabs the mobile goal
}

std::int32_t LCHS::MobileGoalGrabber::release() {
  return piston.retract(); // Assuming false releases the mobile goal
}

std::int32_t LCHS::MobileGoalGrabber::toggle() {
  return piston.toggle();
}

bool LCHS::MobileGoalGrabber::getState() {
  return piston.is_extended();
}

void LCHS::MobileGoalGrabber::mobileGoalTaskFunction() {
  // Task function logic here
  // while (true) {
  //   if (limitSwitch.get_value()) {
  //     piston.set_value(true);
  //   }
  //   pros::delay(100); // Prevent busy waiting
  // }
}

void LCHS::MobileGoalGrabber::taskEntry(void *thisPtr) {
  static_cast<MobileGoalGrabber *>(thisPtr)->mobileGoalTaskFunction();
}