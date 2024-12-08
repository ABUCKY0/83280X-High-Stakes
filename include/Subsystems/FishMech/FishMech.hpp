#ifndef FISH_MECH_HPP
#define FISH_MECH_HPP
#include "main.h"  // IWYU pragma: keep
namespace LCHS {
class FishMech {
  public:
  FishMech() = delete;
  FishMech(std::initializer_list<std::int8_t> motors);

  void onStartMatchSetup();
  void spinUp();
  void spinDown();
  void spin(int velocity);
  void stop();
  void overrideSpin(int velocity);
  void calibrate();

  protected:
  pros::MotorGroup motors;
};
}  // namespace LCHS

#endif