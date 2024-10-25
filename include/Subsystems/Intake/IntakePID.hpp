#pragma once
#include <algorithm>  // for std::clamp
#include "main.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

namespace LCHS {
class IntakePID {
 private:
  // PID gains for moving up and down
  double kp_up, ki_up, kd_up;
  double kp_down, ki_down, kd_down;

  // Variables for the PID controller
  double integral = 0;
  double prev_error = 0;
  std::uint32_t last_time = 0;
public:
  IntakePID(double kp_up, double ki_up, double kd_up, double kp_down,
            double ki_down, double kd_down);

  double update(double error);
  void reset();
};
}  // namespace LCHS