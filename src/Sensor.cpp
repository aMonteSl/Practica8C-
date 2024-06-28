#include "Sensor.h"

#include <iostream>
using namespace std;

Sensor::Sensor() {
  id_ = -1;
  type_ = Types::NONE;
  active_ = false;
  data_ = -1;
}

Sensor::Sensor(int id, Types type, bool active) {
  id_ = id;
  type_ = type;
  active_ = active;
  data_ = -1;
}

Sensor::~Sensor() {}

void Sensor::collectData() {
  cout << "Collecting data from sensor id" << id_ << " wich is: " << getType()
       << endl;
  setData(-10000);
  // This function will be implemented in the derived classes
  // en la clase derivada se implementara la funcion, generaremos de manera
  // aleatoria el valor y despues lo asignaremos al atributo data_ con setData()
}

void Sensor::collectAndPrint() {
  collectData();
  printData();
}

bool Sensor::isActive() const { return active_; }

void Sensor::turnOff() { active_ = false; }

void Sensor::turnOn() { active_ = true; }

float Sensor::getData() const { return data_; }

void Sensor::setData(float data) { data_ = data; }

int Sensor::getId() const { return id_; }

void Sensor::setId(int newid) { id_ = newid; }

std::string Sensor::getType() const {
  std::string type = typeToString(type_);
  return type;
}

void Sensor::setType(std::string newtype) { type_ = stringToType(newtype); }

Sensor::Types Sensor::stringToType(const std::string &type) const {
  if (type == "TEMPERATURE") {
    return Types::TEMPERATURE;
  } else if (type == "AIR_QUALITY") {
    return Types::AIR_QUALITY;
  } else if (type == "HYDROMETER") {
    return Types::HYDROMETER;
  } else if (type == "PRESSURE") {
    return Types::PRESSURE;
  } else if (type == "LIGHT_SENSOR") {
    return Types::LIGHT_SENSOR;
  } else if (type == "PH_SENSOR") {
    return Types::PH_SENSOR;
  } else {
    return Types::NONE;
  }
}

std::string Sensor::typeToString(Types type) const {
  switch (type) {
  case Types::TEMPERATURE:
    return "TEMPERATURE";
  case Types::AIR_QUALITY:
    return "AIR_QUALITY";
  case Types::HYDROMETER:
    return "HYDROMETER";
  case Types::PRESSURE:
    return "PRESSURE";
  case Types::LIGHT_SENSOR:
    return "LIGHT_SENSOR";
  case Types::PH_SENSOR:
    return "PH_SENSOR";
  default:
    return "NONE";
  }
}

bool Sensor::operator<(const Sensor &Sensor) const { return id_ < Sensor.id_; }

bool Sensor::operator>(const Sensor &Sensor) const { return id_ > Sensor.id_; }

bool Sensor::operator==(const Sensor &Sensor) const {
  return id_ == Sensor.id_;
}

std::ostream &operator<<(std::ostream &os, const Sensor &Sensor) {
  os << "ID: " << Sensor.getId() << " Type: " << Sensor.getType()
     << " Active: " << Sensor.isActive() << " Data: " << Sensor.getData()
     << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Sensor &sensor) {
  cout << "Enter sensor ID: ";
  is >> sensor.id_;
  cout << "Enter the type: ";
  std::string type;
  is >> type;
  sensor.setType(type);
  cout << "Enter sensor active: ";
  is >> sensor.active_;

  return is;
}

void Sensor::printData() const {
  cout << "This prints the data of sensor " << getType() << " with id" << id_
       << " please use the correct function to print the data" << endl;
  // This function will be implemented in the derived classes
}

bool Sensor::checkAllgood() const { return true; }
