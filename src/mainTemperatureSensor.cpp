#include <iostream>

#include "TemperatureSensor.h"
using namespace std;

int main() {
  // Genero un sensor tipo temperatura
  TemperatureSensor tempSensor(1, true);
  // Imprimo la temperatura por defecto
  tempSensor.printData();
  // Cambio el valor de la temperatura
  tempSensor.collectData();
  // Imprimo la nueva temperatura
  tempSensor.printData();
  // Vuelvo a imprimir la temperatura
  cout << "Temperature: " << tempSensor.getData() << endl;
  cout << "Status: " << tempSensor.stringStatus() << endl;
  tempSensor.collectData();
  // Imprimo el sensor de nuevo
  tempSensor.printData();

  // Print collect and print
  tempSensor.collectAndPrint();
}