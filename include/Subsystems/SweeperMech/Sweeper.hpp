#ifndef SWEEPER_MECH_HPP
#define SWEEPER_MECH_HPP

#include "main.h"
#include "pros/adi.hpp"

namespace LCHS {

enum class SweeperState { DOWN, UP };

class SweeperMech {
 public:
  SweeperMech() = delete;
  
  /**
   * @brief Construct a new Sweeper Mech object
   * 
   * @param adi_port Builtin ADI port the solenoid is connected to
   */
  SweeperMech(std::uint8_t adi_port);

  /**
   * @brief Construct a new Sweeper Mech object
   * 
   * @param port_pair SmartPort and ADI port combo the solenoid is connected to
   */
  SweeperMech(pros::adi::ext_adi_port_pair_t port_pair);

  /**
   * @brief Swings the sweeper mech down to allow to remove rings from the corner
   */
  void swingout();

  /**
   * @brief Swings the sweeper mech up out of the way when not moving rings.
   * 
   */
  void swingin();

  /**
   * @brief Toggles to the opposite state of the current state. 
   * @note useful for button presses
   * 
   */
  void toggle();

  /**
   * @brief Get the current state of the sweeper as a SweeperState enum
   * 
   * @return SweeperState the current state as a SweeperState enum
   */
  SweeperState getState();

 protected:
  pros::adi::Pneumatics sweeper;
};

}  // namespace LCHS

#endif