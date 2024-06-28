#include "PhSensor.h"

#include <iostream>
#include <random>

#include "Sensor.h"
using namespace std;

PhSensor::PhSensor(int id, bool active)
    : Sensor(id, Sensor::Types::PH_SENSOR, active) {}
PhSensor::~PhSensor() {}

void PhSensor::collectData() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(6, 8);
  float reading = dis(gen);

  Sensor::setData(reading);
}

bool PhSensor::checkAllgood() const {
  float data = Sensor::getData();

  if (data >= 6.2 && data <= 7.8) {
    return true;
  } else {
    return false;
  }
}

std::string PhSensor::qualifyPh() const {
  float data = Sensor::getData();
  if (this->checkAllgood()) {
    return "Ideal";
  } else if (data < 6.5f) {
    return "Acidic";
  } else {
    return "Alkaline";
  }
}

void PhSensor::printData() const {
  if (Sensor::isActive()) {
    std::cout << "Ph Sensor with "
              << "ID: " << Sensor::getId() << " - Data: " << Sensor::getData()
              << " - Status: " << stringStatus()
              << " - Qualification: " << qualifyPh() << endl;
  } else {
    std::cout << "Ph Sensor ID: " << Sensor::getId()
              << " - Status: " << stringStatus() << endl;
  }
}

std::ostream &operator<<(std::ostream &os, const PhSensor &sensor) {
  sensor.printData();
  return os;
}

std::string PhSensor::stringStatus() const {
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

void PhSensor::collectAndPrint() {
  collectData();
  printData();
}