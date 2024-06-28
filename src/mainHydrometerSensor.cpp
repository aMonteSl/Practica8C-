#include <iostream>

#include "HydrometerSensor.h"
using namespace std;

int main() {
  // Genero un sensor tipo hidrometro (mide la humedad del aire)
  HydrometerSensor hydrometer(1, true);
  // Imprimo la hidrometro (mide la humedad del aire) por defecto
  hydrometer.printData();
  // Cambio el valor de la hidrometro (mide la humedad del aire)
  hydrometer.collectData();
  // Imprimo la nueva hidrometro (mide la humedad del aire)
  hydrometer.printData();
  // Vuelvo a imprimir la hidrometro (mide la humedad del aire)
  cout << "Air Quality: " << hydrometer.getData() << endl;
  cout << "Status: " << hydrometer.stringStatus() << endl;

  hydrometer.collectData();
  // Imprimo el sensor de nuevo
  hydrometer.printData();

  // Print collect and print
  hydrometer.collectAndPrint();
}