#include <motor.h>

namespace motor {
  Servo drivingServo;
  Servo steeringServo;

  void initialize() {
    drivingServo.attach(3);
    steeringServo.attach(5);
    setSpeed(500);
    setDirection(500);
  }

  void setSpeed(uint16_t speed) {
    drivingServo.writeMicroseconds(1000 + speed);
  }

  void setDirection(uint16_t direction) {
    steeringServo.writeMicroseconds(1000 + direction);
  }

  void stop() {
    drivingServo.writeMicroseconds(1500);
    steeringServo.writeMicroseconds(1500);
  }
}
