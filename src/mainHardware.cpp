#include <iostream>
#include <string>

#include "Hardware.h"
using namespace std;

int main() {
  // Aqui tengo que probar los distintos metodos de un objeto Hardware
  Hardware hardware(true, Hardware::Types_Hardware::SWITCH);
  // Pruebas get type set type
  std::cout << hardware.getType() << std::endl;
  hardware.setType("SCREEN");
  std::cout << hardware.getType() << std::endl;

  // Vamos a ver si esta activado y luego desactivamos
  if (hardware.isActive()) {
    std::cout << "Esta activo" << std::endl;
  } else {
    std::cout << "No esta activo" << std::endl;
  }
  hardware.turnOff();
  if (hardware.isActive()) {
    std::cout << "Esta activo" << std::endl;
  } else {
    std::cout << "No esta activo" << std::endl;
  }
  std::cout << hardware.stringStatus() << std::endl;
}