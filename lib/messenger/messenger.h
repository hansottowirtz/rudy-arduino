#include <String.h>
#include <HardwareSerial.h>

namespace messenger {
  void initialize();
  bool hasReadCommand();
  char* getCommand();
  void update();
  void send(String text);
}
