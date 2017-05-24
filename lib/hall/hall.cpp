#include <hall.h>

namespace hall {
  volatile uint8_t count;

  void initialize() {
    attachInterrupt(digitalPinToInterrupt(HALL_PIN), callback, FALLING);
  }

  void callback() {
    messenger::send(F("H"));
    count++;
  }

  void startCount() {
    count = 0;
  }

  uint16_t getCount() {
    return count;
  }
}
