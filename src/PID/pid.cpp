#include "PID/pid.hpp" // Include the PID header file

// Constructor
LCHS::PID::PID(float kP, float kI, float kD) : kP(kP), kI(kI), kD(kD) {}
float LCHS::PID::update(const float error) {
  // calculate integral
  integral += error;

  // calculate derivative
  const float derivative = error - prevError;
  prevError = error;

  // calculate output
  return error * kP + integral * kI + derivative * kD;
}

void LCHS::PID::reset() {
  integral = 0;
  prevError = 0;
} 
