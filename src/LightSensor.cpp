#include "LightSensor.h"

#include <iostream>
#include <random>
#include <string>
using namespace std;

LightSensor::LightSensor(int id, bool active)
    : Sensor(id, Sensor::Types::LIGHT_SENSOR, active) {}

LightSensor::~LightSensor() {}

void LightSensor::collectData() {
  // Medido en lux entre 200-4000 lux
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(200, 4000);
  int reading = dis(gen);

  Sensor::setData(reading);
}

bool LightSensor::checkAllgood() const {
  float data = Sensor::getData();

  if (data >= 300 && data <= 3900) {
    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const LightSensor &sensor) {
  sensor.printData();
  return os;
}

void LightSensor::printData() const {
  if (Sensor::isActive()) {
    std::cout << "Light Sensor with "
              << "ID: " << Sensor::getId() << " - Data: " << Sensor::getData()
              << " lux - Status: " << stringStatus() << endl;
  } else {
    std::cout << "Light Sensor ID: " << Sensor::getId()
              << " - Status: " << stringStatus() << endl;
  }
}

std::string LightSensor::stringStatus() const {
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

void LightSensor::collectAndPrint() {
  collectData();
  printData();
}