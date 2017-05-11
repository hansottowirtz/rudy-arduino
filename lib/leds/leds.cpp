#include <leds.h>

namespace leds {
  enum indicating { off, left, right };
  indicating indicating = off;
  bool loading;
  uint8_t next_loading_led;
  uint32_t last_loading_millis;

  Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, LED_PIN, NEO_GRB + NEO_KHZ800);

  uint32_t front_color = strip.Color(240, 240, 196);
  uint32_t indicator_color = strip.Color(255, 100, 0);
  uint32_t back_color = strip.Color(255, 0, 0);
  uint32_t top_color = strip.Color(200, 150, 10);
  uint32_t loading_color = strip.Color(0, 0, 0);

  uint32_t current_front_left_color = front_color;
  uint32_t current_back_left_color = back_color;
  uint32_t current_front_right_color = front_color;
  uint32_t current_back_right_color = back_color;
  uint32_t current_top_0_color = top_color;
  uint32_t current_top_1_color = top_color;
  uint32_t current_top_2_color = top_color;
  uint32_t current_top_3_color = top_color;

  uint32_t prev_front_left_color = front_color;
  uint32_t prev_back_left_color = back_color;
  uint32_t prev_front_right_color = front_color;
  uint32_t prev_back_right_color = back_color;
  uint32_t prev_top_0_color = top_color;
  uint32_t prev_top_1_color = top_color;
  uint32_t prev_top_2_color = top_color;
  uint32_t prev_top_3_color = top_color;

  int current_brightness = DEFAULT_BRIGHTNESS;
  int prev_brightness = current_brightness;

  void initialize() {
    strip.begin();
    setAdjustedColor(TOP_0_LED, current_top_0_color);
    setAdjustedColor(TOP_1_LED, current_top_1_color);
    setAdjustedColor(TOP_2_LED, current_top_2_color);
    setAdjustedColor(TOP_3_LED, current_top_3_color);
    setAdjustedColor(BACK_LEFT_LED, 0);
    setAdjustedColor(BACK_RIGHT_LED, 0);
    setAdjustedColor(FRONT_LEFT_LED, 0);
    setAdjustedColor(FRONT_RIGHT_LED, 0);
    strip.show();
  }

  void boot() {
    setAdjustedColor(BACK_LEFT_LED, current_back_left_color);
    setAdjustedColor(BACK_RIGHT_LED, current_back_right_color);
    setAdjustedColor(FRONT_LEFT_LED, current_front_left_color);
    setAdjustedColor(FRONT_RIGHT_LED, current_front_right_color);
  }

  void modifyIndicating(uint32_t* current_color, uint32_t default_color) {
    if (millis() % INDICATOR_PERIOD < INDICATOR_PERIOD/2) {
      *current_color = default_color;
    } else {
      *current_color = indicator_color;
    }
  }

  void modifyLoading(uint32_t* current_color, uint32_t default_color, uint8_t n) {
    uint32_t current_millis = millis();
    if (next_loading_led == n && current_millis - last_loading_millis > LOADING_PERIOD) {
      *current_color = loading_color;
      next_loading_led = (n + 1) % 4;
      last_loading_millis = current_millis;
    } else {
      *current_color = default_color;
    }
  }

  void indicateRight() {
    indicating = right;
    current_front_left_color = front_color;
    current_back_left_color = back_color;
  }

  void indicateLeft() {
    indicating = left;
    current_front_right_color = front_color;
    current_back_right_color = back_color;
  }

  void indicateOff() {
    indicating = off;
    current_front_left_color = front_color;
    current_back_left_color = back_color;
    current_front_right_color = front_color;
    current_back_right_color = back_color;
  }

  void enableLoading() {
    loading = true;
  }

  void disableLoading() {
    loading = false;
    current_top_0_color = top_color;
    current_top_1_color = top_color;
    current_top_2_color = top_color;
    current_top_3_color = top_color;
  }

  void update() {
    bool any_change = false;

    if (indicating == left) {
      modifyIndicating(&current_front_left_color, front_color);
      modifyIndicating(&current_back_left_color, back_color);
    } else if (indicating == right) {
      modifyIndicating(&current_front_right_color, front_color);
      modifyIndicating(&current_back_right_color, back_color);
    }

    if (loading) {
      modifyLoading(&current_top_0_color, top_color, 0);
      modifyLoading(&current_top_1_color, top_color, 1);
      modifyLoading(&current_top_2_color, top_color, 2);
      modifyLoading(&current_top_3_color, top_color, 3);
    }

    if (prev_back_left_color != current_back_left_color) {
      setAdjustedColor(BACK_LEFT_LED, current_back_left_color);
      any_change = true;
    }
    if (prev_back_right_color != current_back_right_color) {
      setAdjustedColor(BACK_RIGHT_LED, current_back_right_color);
      any_change = true;
    }
    if (prev_front_left_color != current_front_left_color) {
      setAdjustedColor(FRONT_LEFT_LED, current_front_left_color);
      any_change = true;
    }
    if (prev_front_right_color != current_front_right_color) {
      setAdjustedColor(FRONT_RIGHT_LED, current_front_right_color);
      any_change = true;
    }
    if (prev_top_0_color != current_top_0_color) {
      setAdjustedColor(TOP_0_LED, current_top_0_color);
      any_change = true;
    }
    if (prev_top_1_color != current_top_1_color) {
      setAdjustedColor(TOP_1_LED, current_top_1_color);
      any_change = true;
    }
    if (prev_top_2_color != current_top_2_color) {
      setAdjustedColor(TOP_2_LED, current_top_2_color);
      any_change = true;
    }
    if (prev_top_3_color != current_top_3_color) {
      setAdjustedColor(TOP_3_LED, current_top_3_color);
      any_change = true;
    }
    if (prev_brightness != current_brightness) {
      any_change = true;
      setAdjustedColor(BACK_LEFT_LED, current_back_left_color);
      setAdjustedColor(BACK_RIGHT_LED, current_back_right_color);
      setAdjustedColor(FRONT_LEFT_LED, current_front_left_color);
      setAdjustedColor(FRONT_RIGHT_LED, current_front_right_color);
      setAdjustedColor(TOP_0_LED, current_top_0_color);
      setAdjustedColor(TOP_1_LED, current_top_1_color);
      setAdjustedColor(TOP_2_LED, current_top_2_color);
      setAdjustedColor(TOP_3_LED, current_top_3_color);
    }

    prev_back_left_color = current_back_left_color;
    prev_back_right_color = current_back_right_color;
    prev_front_left_color = current_front_left_color;
    prev_front_right_color = current_front_right_color;
    prev_top_0_color = current_top_0_color;
    prev_top_1_color = current_top_1_color;
    prev_top_2_color = current_top_2_color;
    prev_top_3_color = current_top_3_color;
    prev_brightness = current_brightness;

    if (any_change) strip.show();
  }

  void setAdjustedColor(uint8_t n, uint32_t c) {
    uint8_t r = (uint8_t)(c >> 16);
    uint8_t g = (uint8_t)(c >> 8);
    uint8_t b = (uint8_t)c;
    r = (r * current_brightness) >> 8;
    g = (g * current_brightness) >> 8;
    b = (b * current_brightness) >> 8;
    uint32_t new_c = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
    strip.setPixelColor(n, new_c);
  }

  void setBrightness(uint8_t brightness) {
    current_brightness = brightness;
  }
}
