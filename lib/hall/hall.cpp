#include <hall.h>

namespace hall {
  void initialize() {
    attachInterrupt(digitalPinToInterrupt(HALL_PIN), callback, RISING);
  }

  void callback() {
    messenger::send(F("H"));
  }
}
