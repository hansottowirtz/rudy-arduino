#include <Arduino.h>
#include <messenger.h>
#include <constants.h>

namespace hall {
  void initialize();
  // void setCallback(void (*cb)(void));
  void callback();
  void startCount();
  uint16_t getCount();
}
