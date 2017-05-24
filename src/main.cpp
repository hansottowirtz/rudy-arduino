#include <main.h>

uint8_t sonarN = 0;
uint32_t previousSonarMillis;

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
        uint16_t speed = String(&arguments[1]).toInt();
        motor::setSpeed(speed);
        break;
      }
      case 'S': {
        uint16_t direction = String(&arguments[1]).toInt();
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
        break;
      }
      case 'I': {
        leds::disableLoading();
        leds::boot();
        break;
      }
      case 'P': {
        parking::park();
        break;
      }
      case 'E': {
        motor::stop();
        break;
      }
    }
  }

  messenger::update();
  motor::update();
  leds::update();

  if (currentMillis - previousSonarMillis >= 1000) {
    previousSonarMillis = currentMillis;

    noInterrupts();
    Serial.print('D');
    Serial.print(sonarN);
    Serial.println(sonar::measure(sonarN));
    interrupts();

    sonarN = (sonarN + 1) % 4;
  }
}
