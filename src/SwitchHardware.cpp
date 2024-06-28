#include "SwitchHardware.h"

#include <iostream>

#include "Hardware.h"

SwitchHardware::SwitchHardware(bool active)
    : Hardware(active, Hardware::Types_Hardware::SWITCH) {}

SwitchHardware::~SwitchHardware() {}

void SwitchHardware::translateInput(int input) {
  if (input) {
    turnOn();
  } else {
    turnOff();
  }
}

int SwitchHardware::askInput() {
  int input;
  std::string input_string;
  // Preguntamos al usuario si ON of OFF y luego el input se lo pasamos a
  // translateInputToBool
  std::cout << "Switch wating a input(ON/OFF)..." << std::endl;
  std::cin >> input_string;
  if (input_string == "ON") {
    input = 1;
  }
  if (input_string == "OFF") {
    input = 0;
  }

  translateInput(input);
  return input;
  // El valor de active_ sera true o false dependiendo de si se activa o se
  // desactiva el switch
}

void SwitchHardware::displayOutput() const {
  std::cout << stringStatus() << std::endl;
}