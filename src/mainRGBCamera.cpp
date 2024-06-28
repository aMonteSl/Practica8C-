#include "RGBCamera.h"

int main() {
  RGBCamera camera1(1);
  camera1.printCamera();
  camera1.collectData();
  camera1.printCamera();
  camera1.turnOff();
  camera1.printCamera();
  return 0;
}