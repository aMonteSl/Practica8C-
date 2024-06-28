#include "KeyboardHardware.h"

#include <iostream>
#include <limits>

#include "Hardware.h"
using namespace std;

KeyboardHardware::KeyboardHardware(bool active)
    : Hardware(active, Hardware::Types_Hardware::KEYBOARD) {
  data_ = 0;
  stringData_ = "";
}

KeyboardHardware::~KeyboardHardware() {}

int KeyboardHardware::askInput() {
  bool exit = false;
  int input;

  while (not exit) {
    std::cout << "- Keyboard waiting for input (integer): ";
    std::cin >> input;

    // Verificar si la entrada es un número
    if (std::cin.fail()) {
      std::cin.clear(); // Restablecer el estado de cin
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // Limpiar el buffer de entrada
      std::cout << "Invalid input. Please enter an integer that corresponse to "
                   "one of the options"
                << std::endl;
    } else {
      exit = true;
      data_ = input; // Guardar el valor ingresado en data_
    }
  }

  return data_;
}

std::string KeyboardHardware::stringInput() {
  std::cout << "- Keyboard waiting for input (string): ";
  std::string input;
  std::cin >> input;
  stringData_ = input;
  return stringData_;
}

void KeyboardHardware::displayOutput() const {
  std::cout << "-Last intput(integer) of the keyboard: " << data_ << std::endl;
  std::cout << "-Last intput(string) of the keyboard: " << stringData_
            << std::endl;
}
