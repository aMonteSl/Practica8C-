#include "TemperatureSensor.h"

#include <iostream>
#include <random>
#include <string>

#include "Sensor.h"
using namespace std;

TemperatureSensor::TemperatureSensor(int id, bool active)
    : Sensor(id, Sensor::Types::TEMPERATURE, active) {}

TemperatureSensor::~TemperatureSensor() {}

void TemperatureSensor::collectData() {
  // Generamos una temperatura aleatoria entre 19 y 31 grados Centigrados

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(19.0, 31.0);
  float temperature = dis(gen);
  Sensor::setData(temperature);
}

bool TemperatureSensor::checkAllgood() const {
  float data = Sensor::getData();
  // Entre 20 y 30 estara bien la temperatura, en el resto de los casos no
  // estara bien
  if (data >= 20.0f && data <= 30.0f) {
    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const TemperatureSensor &sensor) {
  sensor.printData();
  return os;
}

std::string TemperatureSensor::stringStatus() const {
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

void TemperatureSensor::printData() const {
  // Imprimimos la temperatura actual del sensor, el id que tiene el sensor, y
  // si todo esta bien o no con (True/False)
  if (Sensor::isActive()) {
    std::cout << "Temperature Sensor with "
              << "ID: " << Sensor::getId() << " - Data: " << Sensor::getData()
              << " Cº - Status: " << stringStatus() << endl;
  } else {
    std::cout << "Temperature Sensor with "
              << "ID: " << Sensor::getId() << " - INACTIVE" << endl;
  }
}

void TemperatureSensor::collectAndPrint() {
  collectData();
  printData();
}