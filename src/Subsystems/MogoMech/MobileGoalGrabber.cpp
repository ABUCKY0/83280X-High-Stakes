#include "Subsystems/MogoMech/MobileGoalGrabber.hpp"
#include "pros/misc.h"

LCHS::MobileGoalGrabber::MobileGoalGrabber(std::uint8_t pneumaticPort,
                                           std::uint8_t distancePort) :
    piston(pneumaticPort, false, false),
    distance(distancePort),
    mobileGoalTask(&MobileGoalGrabber::taskEntry, this, "mogo") {
  std::cout << "Mogo Mech (MobileGoalGrabber) init, pp: " << pneumaticPort
            << " dist:" << distancePort << std::endl;
}

LCHS::MobileGoalGrabber::MobileGoalGrabber(
    pros::adi::ext_adi_port_pair_t portPair, std::uint8_t distancePort) :
    piston(portPair, true, false),
    distance(distancePort),
    mobileGoalTask(&MobileGoalGrabber::taskEntry, this, "mogo") {
  std::cout << "Mogo Mech (MobileGoalGrabber) init, pneumatic: " << portPair.first
            << " " << portPair.second << " dist:" << distancePort << std::endl;
}

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
  // bool test = true;
  // bool grabButtonPressed = false;
  // std::uint32_t grabButtonPressTime = 0;
  // std::uint32_t distanceBelow15Time = 0;
  // std::uint32_t distanceAbove15Time = 0;

  // while (true) {
  //   std::uint32_t currentTime = pros::millis();
  //   std::int32_t distanceReading = distance.get_distance();

  //   // // Check if the distance is below 15mm
  //   // if (distanceReading < 15) {
  //   //   if (distanceBelow15Time == 0) {
  //   //     distanceBelow15Time = currentTime;
  //   //   } else if (currentTime - distanceBelow15Time >= 100) {
  //   //     grab();
  //   //     distanceBelow15Time = 0;
  //   //   }
  //   // } else {
  //   //   distanceBelow15Time = 0;
  //   // }

  //   // // Check if the distance is above 15mm
  //   // if (distanceReading > 15) {
  //   //   if (distanceAbove15Time == 0) {
  //   //     distanceAbove15Time = currentTime;
  //   //   } else if (currentTime - distanceAbove15Time >= 150) {
  //   //     release();
  //   //     distanceAbove15Time = 0;
  //   //   }
  //   // } else {
  //   //   distanceAbove15Time = 0;
  //   // }

  //   // // Check if the mogo grab button is pressed
  //   // if (pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_R1)) {
  //   //   if (!grabButtonPressed) {
  //   //     grabButtonPressed = true;
  //   //     grabButtonPressTime = currentTime;
  //   //   }
  //   // } else {
  //   //   grabButtonPressed = false;
  //   // }

  //   // // Prevent grabbing for 150ms after the button is pressed
  //   // if (grabButtonPressed && currentTime - grabButtonPressTime < 150) {
  //   //   pros::delay(150 - (currentTime - grabButtonPressTime));
  //   // }

    pros::delay(200000);
  // }
}

void LCHS::MobileGoalGrabber::taskEntry(void *thisPtr) {
  static_cast<MobileGoalGrabber *>(thisPtr)->mobileGoalTaskFunction();
}