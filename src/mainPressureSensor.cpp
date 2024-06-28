#include <iostream>

#include "PressureSensor.h"
using namespace std;

int main() {
  PressureSensor pressureSensor(1, true);
  // Imprimo la presion por defecto
  pressureSensor.printData();
  // Cambio el valor de la presion
  pressureSensor.collectData();
  // Imprimo la nueva presion
  pressureSensor.printData();
  // Vuelvo a imprimir la presion
  cout << "Pressure: " << pressureSensor.getData() << endl;
  cout << "Status: " << pressureSensor.stringStatus() << endl;
  pressureSensor.collectData();
  // Imprimo el sensor de nuevo
  pressureSensor.printData();
  // Print collect and print
  pressureSensor.collectAndPrint();
}