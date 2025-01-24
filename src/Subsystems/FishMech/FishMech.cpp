#include "Subsystems/FishMech/FishMech.hpp"
#include "main.h"  // IWYU pragma: keep

LCHS::FishMech::FishMech(std::initializer_list<std::int8_t> motorPorts) :
    motors(motorPorts, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees) {
  motors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  motors.tare_position_all();
  std::cout << "FishMech init " << std::endl;
}

void LCHS::FishMech::onStartMatchSetup() {
  motors.move_absolute(-25,100);
}

void LCHS::FishMech::spinUp() {
  motors.move_absolute(200, 100);
}

void LCHS::FishMech::spinDown() {
  motors.move_absolute(-10, 100);
}

void LCHS::FishMech::spin(int velocity) {
  // if (motors.get_position() > 150) {
  //   motors.move_absolute(150, velocity);
  // } else if (motors.get_position() < -10) {
  //   motors.move_absolute(-100, velocity);
  // }
  std::cout << "FISHMECH V" << velocity << std::endl;
  if (velocity >= 0 && motors.get_position() < 190) {
    motors.move_velocity(velocity);
  }
  else if (velocity < 0 && motors.get_position() > -20 ) {
    motors.move_velocity(velocity);
  }
  else {
    motors.brake();
  }
  //motors.move_velocity(velocity);
}

void LCHS::FishMech::overrideSpin(int velocity) {
  motors.move_velocity(velocity);
}

void LCHS::FishMech::stop() {
  motors.move_velocity(0);
  motors.brake();
}

void LCHS::FishMech::calibrate() {
  motors.tare_position_all();
}