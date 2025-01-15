using namespace std;
#include <cmath>  // Include cmath for fabs()
namespace LCHS {
class PID {
 public:
  // Constructor
  PID(float kP, float kI, float kD);

  // Member function to update PID
  float update(const float error);

  // Member function to reset PID
  void reset();

 protected:
  // Member variables
  float kP;
  float kI;
  float kD;
  float integral = 0;
  float prevError = 0;

  // Member functions can also be added here!
};
}  // namespace LCHS