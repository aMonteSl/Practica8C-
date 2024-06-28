#include "PressureSensor.h"

#include <iostream>
#include <random>

#include "Sensor.h"
using namespace std;

PressureSensor::PressureSensor(int id, bool active)
    : Sensor(id, Sensor::Types::PRESSURE, active) {}

PressureSensor::~PressureSensor() {}

void PressureSensor::collectData() {
  // Numero random entre 0.90 y 1.10 bares
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.9, 1.1);
  float pressure = dis(gen);
  Sensor::setData(pressure);
}

bool PressureSensor::checkAllgood() const {
  float data = Sensor::getData();
  if (data >= 0.91f && data <= 1.09f) {
    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const PressureSensor &sensor) {
  sensor.printData();
  return os;
}

void PressureSensor::printData() const {
  if (Sensor::isActive()) {
    std::cout << "Pressure Sensor with "
              << "ID: " << Sensor::getId() << " - Data: " << Sensor::getData()
              << " bar - Status: " << stringStatus() << endl;
  } else {
    std::cout << "Pressure Sensor ID: " << Sensor::getId()
              << " - Status: " << stringStatus() << endl;
  }
}

std::string PressureSensor::stringStatus() const {
  if (Sensor::isActive()) {
    if (this->checkAllgood()) {
      return "ACTIVE - GOOD STATUS";
    } else {
      return "ACTIVE - BAD STATUS";
    }
  } else {
    return "INACTIVE";
  }
}

void PressureSensor::collectAndPrint() {
  collectData();
  printData();
}