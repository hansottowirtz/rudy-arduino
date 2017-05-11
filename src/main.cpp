#include <main.h>

uint8_t sonarN = 0;
uint32_t previousMillis;

void setup() {
  leds::initialize();
  messenger::initialize();
  motor::initialize();
  sonar::initialize();
  hall::initialize();
  messenger::send(F("I"));
  leds::enableLoading();
}

void loop() {
  uint32_t currentMillis = millis();

  if (messenger::hasReadCommand()) {
    char* arguments = messenger::getCommand();
    char type = arguments[0];
    switch(type) {
      case 'M': {
        motor::setSpeed(String(&arguments[1]).toInt());
        break;
      }
      case 'S': {
        uint8_t direction = String(&arguments[1]).toInt();
        if (direction < 100) {
          leds::indicateLeft();
        } else if (direction > 900) {
          leds::indicateRight();
        } else {
          leds::indicateOff();
        }
        motor::setDirection(direction);
        break;
      }
      case 'B': {
        uint8_t brightness = String(&arguments[1]).toInt();
        leds::setBrightness(brightness);
        break;
      }
      case 'L': {
        if (arguments[3] == '1') {
          leds::enableLoading();
        } else {
          leds::disableLoading();
        }
      }
      case 'I': {
        leds::disableLoading();
        leds::boot();
      }
      case 'E': {
        motor::stop();
      }
    }
  }
  messenger::update();

  if (currentMillis - previousMillis >= 10) {
    previousMillis = currentMillis;
    leds::update();
  }

  Serial.print('D');
  Serial.print(sonarN);
  Serial.println(sonar::trigger(sonarN));

  sonarN = (sonarN + 1) % 4;

  delay(60);
}
//
// void hallCallback() {
//   messenger::send(F("H"));
// }
