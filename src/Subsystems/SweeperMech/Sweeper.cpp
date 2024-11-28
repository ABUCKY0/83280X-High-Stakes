#include "main.h"  // IWYU pragma: keep
#include "Subsystems/SweeperMech/Sweeper.hpp"

namespace LCHS {

SweeperMech::SweeperMech(std::uint8_t adi_port) : sweeper(adi_port, false) {};

SweeperMech::SweeperMech(pros::adi::ext_adi_port_pair_t port_pair) : sweeper(port_pair, false) {};

void SweeperMech::swingout() {  
    sweeper.extend();
}

void SweeperMech::swingin() {
    sweeper.retract();
}

void SweeperMech::toggle() {
  this->sweeper.toggle();
}


SweeperState SweeperMech::getState() {
  return this->sweeper.is_extended() ? SweeperState::DOWN : SweeperState::UP;
}



} // namespace LCHS