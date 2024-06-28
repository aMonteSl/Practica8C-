#include "TemperatureCamera.h"

int main() {
  TemperatureCamera camera1(1);
  camera1.printCamera();
  camera1.collectData();
  camera1.printCamera();
  return 0;
}