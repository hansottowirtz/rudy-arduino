#include <Arduino.h>
#include <constants.h>

namespace sonar {
  void initialize();
  uint32_t measure(uint8_t n);
  uint32_t getDistance(uint8_t n);
}
