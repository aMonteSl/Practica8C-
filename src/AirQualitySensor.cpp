#include "AirQualitySensor.h"

#include <iostream>
#include <random>
#include <string>

#include "Sensor.h"

AirQualitySensor::AirQualitySensor(int id, bool active)
    : Sensor(id, Sensor::Types::AIR_QUALITY, active) {}

AirQualitySensor::~AirQualitySensor() {}

void AirQualitySensor::collectData() {
  // Generamos un numero random entre 0 y 70 para simular la calidad del aire en
  // microgramos/m3
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 70);
  int airQuality = dis(gen);
  Sensor::setData(airQuality);
}

bool AirQualitySensor::checkAllgood() const {
  // Por debajo de 65 microgramos/m3 se considera buena calidad del aire
  float data = Sensor::getData();

  if (data <= 65) {
    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const AirQualitySensor &sensor) {
  sensor.printData();
  return os;
}

std::string AirQualitySensor::stringStatus() const {
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

void AirQualitySensor::printData() const {
  // Imprimimos las particulas por microgramo/m3, el id del sensor, y si todo
  // esta bien o no
  if (Sensor::isActive()) {
    std::cout << "Air Quality Sensor with "
              << "ID: " << Sensor::getId() << " - Data: " << Sensor::getData()
              << " microgram/m3 - Status: " << stringStatus() << std::endl;
  } else {
    std::cout << "Air Quality Sensor ID: " << Sensor::getId() << " - INACTIVE"
              << std::endl;
  }
}

void AirQualitySensor::collectAndPrint() {
  collectData();
  printData();
}