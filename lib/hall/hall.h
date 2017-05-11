#include <Arduino.h>
#include <messenger.h>

#define HALL_PIN 2

namespace hall {
  void initialize();
  // void setCallback(void (*cb)(void));
  void callback();
}
