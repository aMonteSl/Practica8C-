#include "TemperatureCamera.h"

#include <random>

using namespace std;

// Constructor de la clase TemperatureCamera, inicializa el atributo
// temperature_ a -1 y llama al constructor de la clase Camera con los
// parametros id, "TEMPERATURE" y true
TemperatureCamera::TemperatureCamera(int id) : Camera(id, "TEMPERATURE", true) {
  temperature_ = -1;
  std::cout << "Temperature Camera id (" << getId() << ") created" << std::endl;
}

TemperatureCamera::~TemperatureCamera() {}

void TemperatureCamera::setTemperature(float temperature) {
  temperature_ = temperature;
}

float TemperatureCamera::getTemperature() { return temperature_; }

float TemperatureCamera::randomTemperature() {
  // Random temperature entre 19.0 y 31.0
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(19.0, 31.0);
  float temperature = dis(gen);
  temperature = std::round(temperature * 100) / 100; // Redondea a dos decimales
  return temperature;
}

void TemperatureCamera::collectData() { setTemperature(randomTemperature()); }

void TemperatureCamera::printCamera() {
  if (isActive() and temperature_ != -1) {
    cout << "Temperature camera (" << getId() << ") record this temperature "
         << temperature_ << " ºC" << endl;
  } else if (isActive() and temperature_ == -1) {
    cout << "Temperature camera " << getId()
         << " is active but has not collected data yet" << endl;
  } else {
    cout << "Temperature camera " << getId() << " is not active" << endl;
  }
}