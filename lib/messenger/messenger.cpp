#include <messenger.h>

#define MESSAGE_LENGTH 4

namespace messenger {
  char buffer[MESSAGE_LENGTH];
  uint8_t index = 0;
  bool read = false;

  void initialize() {
    buffer[MESSAGE_LENGTH - 1] = '\0';
    Serial.begin(9600);
  }

  bool hasReadCommand() {
    return read;
  }

  char* getCommand() {
    read = false;
    index = 0;
    return buffer;
  }

  void update() {
    if (Serial.available() > 0) {
      char c = Serial.read();
      if (c == '\n' || c == '\r') {
        read = true;
      } else if (index < MESSAGE_LENGTH) {
        buffer[index] = c;
        index++;
      }
      Serial.print(c);
    }
  }

  void send(String text) {
    Serial.println(text);
  }
}
