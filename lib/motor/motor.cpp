#include <motor.h>

namespace motor {
  Servo drivingServo;
  Servo steeringServo;
  int16_t targetSpeed;
  uint32_t setSpeedMillis;

  void initialize() {
    drivingServo.attach(SERVO_PIN_M);
    steeringServo.attach(SERVO_PIN_S);
    setSpeed(500);
    setDirection(500);
  }

  void setSpeed(uint16_t speed) {
    setSpeedMillis = millis();
    targetSpeed = speed - 500;
  }

  void setDirection(uint16_t direction) {
    steeringServo.writeMicroseconds(2000 - direction);
  }

  void stop() {
    drivingServo.writeMicroseconds(1500);
    steeringServo.writeMicroseconds(1500);
  }

  void update() {
    int16_t speed;
    uint32_t currentMillis = millis();
    uint32_t timeDelta = currentMillis - setSpeedMillis;
    int8_t sign = (targetSpeed > 0) ? 1 : ((targetSpeed < 0) ? -1 : 0);
    if (timeDelta < 100) {
      speed = 200 * sign;
    } else {
      // timeDelta = min(timeDelta, SPREAD_TIME);
      // float multiplier = ((float)timeDelta) / SPREAD_TIME;
      float multiplier = 1;
      speed = targetSpeed * multiplier;
    }
    drivingServo.writeMicroseconds(1500 + speed);
  }
}
