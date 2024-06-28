#include <iostream>

#include "AirQualitySensor.h"
using namespace std;

int main() {
  // Genero un sensor tipo calidad del aire
  AirQualitySensor airQualitySensor(1, true);
  // Imprimo la calidad del aire por defecto
  airQualitySensor.printData();
  // Cambio el valor de la calidad del aire
  airQualitySensor.collectData();
  // Imprimo la nueva calidad del aire
  airQualitySensor.printData();
  // Vuelvo a imprimir la calidad del aire
  cout << "Air Quality: " << airQualitySensor.getData() << endl;
  cout << "Status: " << airQualitySensor.stringStatus() << endl;

  airQualitySensor.collectData();
  // Imprimo el sensor de nuevo
  airQualitySensor.printData();

  // Print collect and print
  airQualitySensor.collectAndPrint();
}