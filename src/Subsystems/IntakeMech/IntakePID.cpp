#include <algorithm>  // for std::clamp
#include "Subsystems/Intake/IntakePID.hpp"
#include "main.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

// Constructor with separate gains for up and down
LCHS::IntakePID::IntakePID(double kp_up, double ki_up, double kd_up,
                           double kp_down, double ki_down, double kd_down) :
    kp_up(kp_up),
    ki_up(ki_up),
    kd_up(kd_up),
    kp_down(kp_down),
    ki_down(ki_down),
    kd_down(kd_down) {}

// Function to compute the motor output given the current error
double LCHS::IntakePID::update(double error) {
  // Get the current time and calculate delta time
  std::uint32_t current_time = pros::millis();
  double delta_time = (last_time == 0) ? 0
                                       : (current_time - last_time) /
                                             1000.0;  // Convert ms to seconds
  last_time = current_time;

  // Determine if we're moving up or down based on the error
  double kp, ki, kd;
  if (error > 0) {
    // Moving up (error is positive)
    kp = kp_up;
    ki = ki_up;
    kd = kd_up;
    std::cout << "Moving Up" << std::endl;
  } else {
    // Moving down (error is negative)
    kp = kp_down;
    ki = ki_down;
    kd = kd_down;
    std::cout << "Moving Down" << std::endl;
  }

  // Calculate integral and derivative
  integral += error * delta_time;
  double derivative = (delta_time > 0) ? (error - prev_error) / delta_time : 0;

  // Compute the PID output
  double output = (kp * error) + (ki * integral) + (kd * derivative);

  // Save the current error for the next iteration
  prev_error = error;

  // Return the PID output
  return output;
};

void LCHS::IntakePID::reset() {
  integral = 0;
  prev_error = 0;
  last_time = 0;
}  // namespace LCHS