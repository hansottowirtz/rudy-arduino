#include <sonar.h>

namespace sonar {
  uint8_t triggerPins[4] = {TRIGGER_PIN_0, TRIGGER_PIN_1, TRIGGER_PIN_2, TRIGGER_PIN_3};
  uint8_t echoPins[4] = {ECHO_PIN_0, ECHO_PIN_1, ECHO_PIN_2, ECHO_PIN_3};

  uint32_t distances[4] = {0, 0, 0, 0};

  void initialize() {
    for (uint8_t i = 0; i <= 3; i++) {
      pinMode(triggerPins[i], OUTPUT);
      pinMode(echoPins[i], INPUT);
    }
  }

  uint32_t measure(uint8_t n) {
    noInterrupts();
    digitalWrite(triggerPins[n], HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPins[n], LOW);
    uint32_t duration = pulseIn(echoPins[n], HIGH, 30000);
    uint32_t distance = duration / 58;
    distances[n] = distance;
    interrupts();
    return distance;
  }

  uint32_t getDistance(uint8_t n) {
    return distances[n];
  }
}
