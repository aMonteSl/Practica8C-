#include "ManageCameras.h"
#include <iostream>

int main() {
  ManageCameras manageCameras;
  manageCameras.createCamera(3, "RGB");
  manageCameras.createCamera(4, "Temperature");
  manageCameras.displayAllCameras();
  manageCameras.collectData();
  manageCameras.displayAllCameras();
  manageCameras.turnOffCameras();
  manageCameras.displayAllCameras();
  manageCameras.removeCamera(3);
  manageCameras.displayAllCameras();
  manageCameras.createCamera(4, "RGB");
  manageCameras.displayAllCameras();
  manageCameras.createCamera(5, "Temperature");
  manageCameras.createCamera(5, "Rgb");
  manageCameras.displayAllCameras();
  manageCameras.saveCameras();
  // Limpiar terminal
  std::cout << "\033[2J\033[1;1H";
  ManageCameras manageCameras2;
  manageCameras2.loadCameras();
  manageCameras2.displayAllCameras();

  return 0;
}