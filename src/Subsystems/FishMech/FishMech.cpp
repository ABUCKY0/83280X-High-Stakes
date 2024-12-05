#include "Subsystems/FishMech/FishMech.hpp"
#include "main.h"  // IWYU pragma: keep

LCHS::FishMech::FishMech(std::initializer_list<std::int8_t> motorPorts) :
    motors(motorPorts, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees) {
  motors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  motors.set_zero_position(0);
}

void LCHS::FishMech::onStartMatchSetup() {
  motors.move_absolute(15,200);
}

void LCHS::FishMech::spinUp() {
  motors.move_absolute(150, 200);
}

void LCHS::FishMech::spinDown() {
  motors.move_absolute(-10, 200);
}

void LCHS::FishMech::spin(int velocity) {
  if (motors.get_position() > 150) {
    motors.move_absolute(150, 200);
  } else if (motors.get_position() < -10) {
    motors.move_absolute(-10, 200);
  }
  //motors.move_velocity(velocity);
}

void LCHS::FishMech::stop() {
  motors.move_velocity(0);
  motors.brake();
}
