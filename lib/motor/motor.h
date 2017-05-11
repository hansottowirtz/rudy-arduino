#include <Servo.h>

namespace motor {
  void initialize();
  void setSpeed(uint16_t speed);
  void setDirection(uint16_t direction);
  void stop();
}
