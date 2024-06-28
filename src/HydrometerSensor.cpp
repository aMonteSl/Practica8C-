#include "HydrometerSensor.h"

#include <iostream>
#include <random>

#include "Sensor.h"
using namespace std;

HydrometerSensor::HydrometerSensor(int id, bool active)
    : Sensor(id, Sensor::Types::HYDROMETER, active) {}

HydrometerSensor::~HydrometerSensor() {}

void HydrometerSensor::collectData() {
  // Generate random hydrometer reading between 50-90
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(50, 90);
  int reading = dis(gen);

  // Set data
  Sensor::setData(reading);
}

bool HydrometerSensor::checkAllgood() const {
  float data = Sensor::getData();
  // Reading between 55-85 is considered good
  if (data >= 52 && data <= 88) {
    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const HydrometerSensor &sensor) {
  sensor.printData();
  return os;
}

std::string HydrometerSensor::stringStatus() const {
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

void HydrometerSensor::printData() const {
  if (Sensor::isActive()) {
    std::cout << "Hydrometer Sensor with "
              << "ID: " << Sensor::getId() << " - Data: " << Sensor::getData()
              << " % "
              << "- Status: " << stringStatus() << endl;

  } else {
    cout << "Hydrometer Sensor ID: " << Sensor::getId() << " - INACTIVE"
         << endl;
  }
}

void HydrometerSensor::collectAndPrint() {
  collectData();
  printData();
}
