#include "Hardware.h"

#include <iostream>
#include <string>
using namespace std;

Hardware::Hardware() : active_(false), type_(Types_Hardware::NONE) {}
Hardware::Hardware(bool active, Types_Hardware type)
    : active_(active), type_(type) {}
Hardware::~Hardware() {}

std::string Hardware::getType() const { return typeToString(type_); }

void Hardware::setType(std::string newtype) { type_ = stringToType(newtype); }

bool Hardware::isActive() const { return active_; }

void Hardware::turnOn() { active_ = true; }

void Hardware::turnOff() { active_ = false; }

std::string Hardware::stringStatus() const {
  std::string status;
  if (isActive()) {
    status = "ON";
  } else {
    status = "OFF";
  }
  status += " - ";
  status += getType();
  return status;
}

int Hardware::askInput() {
  return 0;
  // esta funcion sera definida en clases hijas
  // pero la idea es qeu muestre un mensaje estilo Pantalla: (Aqui viene el
  // input del usuario)
}

void Hardware::displayOutput() const {
  // Esta funcion sera definida en las clases hijas
  // Por ahora mostramos un mensaje generico
  cout << "Hardware cannot display output for this type" << endl;
}

std::string Hardware::typeToString(Types_Hardware type) const {
  switch (type) {
  case Types_Hardware::SCREEN:
    return "SCREEN";
  case Types_Hardware::KEYBOARD:
    return "KEYBOARD";
  case Types_Hardware::SWITCH:
    return "SWITCH";
  default:
    return "None";
  }
}

Hardware::Types_Hardware Hardware::stringToType(std::string type) const {
  if (type == "SCREEN") {
    return Hardware::Types_Hardware::SCREEN;
  } else if (type == "KEYBOARD") {
    return Hardware::Types_Hardware::KEYBOARD;
  } else if (type == "SWITCH") {
    return Hardware::Types_Hardware::SWITCH;
  } else {
    return Hardware::Types_Hardware::NONE;
  }
}