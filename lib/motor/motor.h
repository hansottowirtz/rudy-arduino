#include <Servo.h>
#include <constants.h>

#define SPREAD_TIME 2000

namespace motor {
  void initialize();
  void setSpeed(uint16_t speed);
  void setDirection(uint16_t direction);
  void stop();
  void update();
}
