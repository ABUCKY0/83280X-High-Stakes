#include "Subsystems/FishMech/FishMech.hpp"
#include "main.h"  // IWYU pragma: keep

LCHS::FishMech::FishMech(std::initializer_list<std::int8_t> motorPorts) :
    motors(motorPorts) {
  motors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void LCHS::FishMech::spinUp() {
  motors.move_velocity(200);
}

void LCHS::FishMech::spinDown() {
  motors.move_velocity(-200);
}

void LCHS::FishMech::spin(int velocity) {
  motors.move_velocity(velocity);
}

void LCHS::FishMech::stop() {
  motors.move_velocity(0);
  motors.brake();
}
