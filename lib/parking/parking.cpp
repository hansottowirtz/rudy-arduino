#include <parking.h>

#define LEFT_PIN 1
#define RIGHT_PIN 3
#define WHEEL_CIRCUM 29

namespace parking {
  enum state_t {none, findingSpot};
  state_t state = none;

  void park() {
    findSpotRight();
  }

  // int distanceRight = 0;
  // int distanceLeft = 0;
  // int travelDistance = 0;
  // int wheelCircum = 29;
  // int backDistance = 0;
  // int frontDistance = 0;
  // int average = 0;
  // int hall = 0; //of boolean
  //
  //
  // String side;

  void findSpotRight() {
    // uint16_t travelDistance;
    // uint16_t hallCount;

    motor::setSpeed(800);

    state = findingSpot;

    // delay(1000);

    // hall::startCount();
    //
    // while(sonar::getDistance(LEFT_PIN) < 30) {
    //   delay(100);
    // }
      // hallCount = hall::getCount();
      // travelDistance = hallCount * WHEEL_CIRCUM;
      // if(travelDistance >= 71) {
      //   // startAutoPark("right");
      // }
    // }

    motor::setSpeed(500);
  }
  //
  // void findSpotLeft() {
  //   while(distanceLeft > 30) {
  //     if(hall == 1) {
  //       travelDistance =+ wheelCircum;
  //       if(travelDistance >= 50) {
  //         startAutoPark("left");
  //         travelDistance = 0;
  //       }
  //     }
  //   }
  // }
  //
  // void autoPark(String side) {
  //   if(side.equals("right")) {
  //     turnWheel(1000);
  //     driveDistance(450, 20); //snelheid (dus zacht achteruit) , afstand
  //     turnWheel(500);
  //     turnWheel(0);
  //     driveDistance(450, 10);
  //     turnWheel(500);
  //     if(frontDistance > backDistance) {
  //       average = (frontDistance - backDistance)/2;
  //       driveDistance(550, (frontDistance - average));
  //     }
  //
  //     else if(frontDistance < backDistance) {
  //       average = (backDistance - frontDistance)/2;
  //       driveDistance(450, (backDistance - average));
  //     }
  //   }
  //
  //   if(side.equals("left")) {
  //     turnWheel(0);
  //     driveDistance(450, 20); //snelheid (dus zacht achteruit) , afstand
  //     turnWheel(500);
  //     turnWheel(1000);
  //     driveDistance(450, 10);
  //     turnWheel(500);
  //     if(frontDistance > backDistance) {
  //       average = (frontDistance - backDistance)/2;
  //       driveDistance(550, (frontDistance - average));
  //     }
  //
  //     else if(frontDistance < backDistance) {
  //       average = (backDistance - frontDistance)/2;
  //       driveDistance(450, (backDistance - average));
  //     }
  //   }
  // }
}
