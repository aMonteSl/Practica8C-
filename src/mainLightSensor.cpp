#include <iostream>

#include "LightSensor.h"

int main() {
  LightSensor lightSensor(1, true);
  // Imprimo la luz por defecto
  lightSensor.printData();
  // Cambio el valor de la luz
  lightSensor.collectData();
  // Imprimo la nueva luz
  lightSensor.printData();
  // Print collect and print
  std::cout << "Light: " << lightSensor.getData() << std::endl;
  // Print collect and print
  std::cout << "Status: " << lightSensor.stringStatus() << std::endl;
  // Imprimo el sensor de nuevo
  lightSensor.collectData();
  // Imprimo el sensor de nuevo
  lightSensor.printData();
  // Print collect and print
  lightSensor.collectAndPrint();

  return 0;
}