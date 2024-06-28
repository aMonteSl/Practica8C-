#include <iostream>

#include "PhSensor.h"
using namespace std;

int main() {
  PhSensor phsensor(1, true);
  // Imprimo el ph por defecto
  phsensor.printData();
  // Cambio el valor de la luz
  phsensor.collectData();
  // Imprimo la nueva luz
  phsensor.printData();
  // Print collect and print
  std::cout << "PH: " << phsensor.getData() << std::endl;
  // Print collect and print
  std::cout << "Status: " << phsensor.stringStatus() << std::endl;
  // Imprimo el sensor de nuevo
  phsensor.collectData();
  // Imprimo el sensor de nuevo
  phsensor.printData();
  // Print collect and print
  phsensor.collectAndPrint();
}