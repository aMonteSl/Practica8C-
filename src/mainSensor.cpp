#include <iostream>

#include "Sensor.h"
using namespace std;

int main() {
  // Creamos un sensor de cada tipo
  Sensor tempSensor(1, Sensor::Types::TEMPERATURE, true);
  Sensor airSensor(2, Sensor::Types::AIR_QUALITY, true);
  Sensor pressureSensor(5, Sensor::Types::PRESSURE, true);
  Sensor hSensor(6, Sensor::Types::HYDROMETER, true);
  Sensor lightSensor(3, Sensor::Types::LIGHT_SENSOR, true);
  Sensor phSensor(4, Sensor::Types::PH_SENSOR, true);

  // Ahora jugamos con los datos de los sensores
  tempSensor.collectData();
  cout << "Type: " << tempSensor.getType() << endl;
  // Ahora apagamos y encendemos
  tempSensor.turnOff();
  if (tempSensor.isActive()) {
    cout << "Sensor is active" << endl;
  } else {
    cout << "Sensor is inactive" << std::endl;
  }
  tempSensor.turnOn();
  if (tempSensor.isActive()) {
    cout << "Sensor is active" << endl;
  } else {
    cout << "Sensor is inactive" << std::endl;
  }
  // Asignamos un valor a la variable data_
  tempSensor.setData(25.5);
  cout << "Data: " << tempSensor.getData() << endl;
  // Cambiamos el id
  tempSensor.setId(10);
  cout << "ID: " << tempSensor.getId() << endl;
  // Cambiamos el tipo
  tempSensor.setType("AIR_QUALITY");
  cout << "Type: " << tempSensor.getType() << endl;

  // Print data
  tempSensor.printData();
  if (tempSensor.checkAllgood()) {
    cout << "All good!" << endl;
  } else {
    cout << "Not all good" << endl;
  }

  return 0;
}