#include <iostream>

#include "KeyboardHardware.h"
using namespace std;

int main() {
  KeyboardHardware keyboard(true);
  if (keyboard.isActive()) {
    std::cout << "Active" << std::endl;
  } else {
    std::cout << "No Active" << std::endl;
  }
  // apagamos
  keyboard.turnOff();
  std::cout << keyboard.stringStatus() << std::endl;
  // encnedemos
  keyboard.turnOn();
  std::cout << keyboard.stringStatus() << std::endl;

  // Preguntamos un input y luego mostramos el ultimo input
  std::cout << keyboard.askInput() << std::endl;
  std::cout << keyboard.stringInput() << std::endl;
  keyboard.displayOutput();

  return 0;
}