#include <Arduino.h>

#define ECHO_PIN_0 4
#define ECHO_PIN_1 6
#define ECHO_PIN_2 7
#define ECHO_PIN_3 8
#define TRIGGER_PIN_0 9
#define TRIGGER_PIN_1 10
#define TRIGGER_PIN_2 11
#define TRIGGER_PIN_3 12

namespace sonar {
  void initialize();
  uint32_t measure(uint8_t n);
  uint32_t getDistance(uint8_t n);
}
