#include <Adafruit_NeoPixel.h>
#include <constants.h>

#define BACK_LEFT_LED 0
#define BACK_RIGHT_LED 1
#define FRONT_LEFT_LED 3
#define FRONT_RIGHT_LED 2
#define TOP_0_LED 4
#define TOP_1_LED 5
#define TOP_2_LED 6
#define TOP_3_LED 7
#define INDICATOR_PERIOD 800
#define LOADING_PERIOD 50
#define DEFAULT_BRIGHTNESS 200

namespace leds {
  void initialize();
  void indicateLeft();
  void indicateRight();
  void indicateOff();
  void enableLoading();
  void disableLoading();
  void update();
  void boot();
  void setAdjustedColor(uint8_t n, uint32_t color);
  void setBrightness(uint8_t brightness);
}
