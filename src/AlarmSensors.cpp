#include "AlarmSensors.h"

#include <fstream>
#include <iostream>
#include <set>
#include <string>

#include "Sensor.h"

#include "AirQualitySensor.h"
#include "HydrometerSensor.h"
#include "LightSensor.h"
#include "PhSensor.h"
#include "PressureSensor.h"
#include "TemperatureSensor.h"
using namespace std;

// Constructor con las declaraciones antincipadas
AlarmSensors::AlarmSensors() {
  // El set de sensores se inicializa con un sensor de cada tipo
  sensors_.insert(new TemperatureSensor(1, true));
  sensors_.insert(new AirQualitySensor(2, true));
  sensors_.insert(new HydrometerSensor(3, true));
  sensors_.insert(new PressureSensor(4, true));
  sensors_.insert(new LightSensor(5, true));
  sensors_.insert(new PhSensor(6, true));
}

AlarmSensors::~AlarmSensors() {
  // Destructor que elimina todos los sensores
  for (auto sensor : sensors_) {
    delete sensor;
  }
}

bool AlarmSensors::sensorExists(int id) {
  // Ver si existe un sensor
  for (auto sensor : sensors_) {
    if (sensor->getId() == id) {
      return true;
    }
  }
  return false;
}

void AlarmSensors::addSensor(int id, std::string type) {
  // Si el sensor ya existe no se puede añadir
  if (sensorExists(id)) {
    cout << "Sensor already exists" << endl;
    return;
  }
  // Pasar a mayusculas el tipo de sensor
  for (auto &c : type) {
    c = toupper(c);
  }
  // Añadir un sensor al set de sensores
  if (type == "TEMPERATURE") {
    sensors_.insert(new TemperatureSensor(id, true));
  } else if (type == "AIR_QUALITY") {
    sensors_.insert(new AirQualitySensor(id, true));
  } else if (type == "HYDROMETER") {
    sensors_.insert(new HydrometerSensor(id, true));
  } else if (type == "PRESSURE") {
    sensors_.insert(new PressureSensor(id, true));
  } else if (type == "LIGHT") {
    sensors_.insert(new LightSensor(id, true));
  } else if (type == "PH") {
    sensors_.insert(new PhSensor(id, true));
  } else {
    cout << "Sensor type not valid" << endl;
  }
}

void AlarmSensors::deleteSensor(int id) {
  bool found = false;
  // Eliminar un sensor del set de sensores
  for (auto sensor : sensors_) {
    if (sensor->getId() == id) {
      std::cout << "Sensor with id: " << id << " deleted" << std::endl;
      sensors_.erase(sensor);
      delete sensor;
      found = true;
      break;
    }
  }
  if (!found) {
    std::cout << "Sensor with id: " << id << " not found" << std::endl;
  }
}

bool AlarmSensors::sensorsIniticialized() {
  // Los sensores estan iniciados si todos los sensores no tienen el valor por
  // defecto de -1
  for (auto sensor : sensors_) {
    if (sensor->getData() == -1) {
      return false;
    }
  }
  return true;
}

bool AlarmSensors::checkAllgood() {
  // Si los sensores tienen buenas mediciones
  for (auto sensor : sensors_) {
    if (!sensor->checkAllgood()) {
      return false;
    }
  }
  return true;
}

int AlarmSensors::checkSensors() {
  if (!sensorsIniticialized()) {
    return -1;
  } else {
    if (checkAllgood()) {
      return 1;
    } else {
      return 0;
    }
  }
}

void AlarmSensors::displayAlarmStatus() {
  if (status_) {
    if (checkSensors() == 1) {
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|         All sensors are in good status          |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    } else if (checkSensors() == 0) {
      // Dibujar el logo de alarma, el triangulo con la exclamacion en el medio
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|  ¡¡One or more sensors are not in good status¡¡ |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    } else if (checkSensors() == -1) {
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|  ¡¡One or more sensors are not initialized¡¡    |" << endl;
      cout << "|    do a collect of data to initialize them      |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    } else {
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|            ¡¡Error in the system¡¡              |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    }
  } else {
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                 The system its off              |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
  }
}

void AlarmSensors::displayAllSensorsData() {
  // Imprimir los datos de todos los sensores
  for (auto sensor : sensors_) {
    sensor->collectAndPrint();
  }
}

void AlarmSensors::turnOnSystem() {
  // Encender todos los sensores del set
  for (auto sensor : sensors_) {
    sensor->turnOn();
  }
}

void AlarmSensors::turnOffSystem() {
  // Apagar todos los sensores del set
  for (auto sensor : sensors_) {
    sensor->turnOff();
  }
}

void AlarmSensors::turnOnOffSystem(int input) {
  // Si el input es igual a true entonces encender todos los sensores
  if (input == 1) {
    turnOnSystem();
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                 System turned on                |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
    status_ = true;
  } else if (input == 2) {
    turnOffSystem();
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                 System turned off               |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
    status_ = false;
  }
}

void AlarmSensors::saveSensorsDataTxt() {
  // Guardar los datos de los sensores en un archivo de texto
  ofstream file;
  file.open(fileNameTxt);
  for (auto sensor : sensors_) {
    file << sensor->getId() << " " << sensor->getType() << " "
         << sensor->getData() << endl;
    std::cout << "Sensor with id: " << sensor->getId() << " saved (txt)"
              << std::endl;
  }
  file.close();
}

void AlarmSensors::saveSensorsDataBin() {
  ofstream file(fileNameBin, ios::binary | ios::trunc);
  for (auto sensor : sensors_) {
    int id = sensor->getId();
    file.write(reinterpret_cast<char *>(&id), sizeof(int));

    size_t typeLength = sensor->getType().length();
    file.write(reinterpret_cast<char *>(&typeLength), sizeof(size_t));
    file.write(sensor->getType().c_str(), typeLength);

    int data = sensor->getData();
    file.write(reinterpret_cast<char *>(&data), sizeof(int));

    std::cout << "Sensor with id: " << sensor->getId() << " saved (binary)"
              << std::endl;
  }
  file.close();
}

void AlarmSensors::saveSensorsData() {
  // Guardar los datos de los sensores en un archivo binario
  saveSensorsDataBin();
  // GUardar los datos de los sensores en un archivo de texto
  saveSensorsDataTxt();
}

void AlarmSensors::loadSensorsDataTxt() {
  // Cargar los datos de los sensores de un archivo de texto
  ifstream file;
  file.open(fileNameTxt);
  int id;
  string type;
  int data;
  while (file >> id >> type >> data) {
    addSensor(id, type);
    for (auto sensor : sensors_) {
      if (sensor->getId() == id) {
        sensor->setData(data);
      }
    }
    std::cout << "Sensor with id: " << id << " loaded (txt)" << std::endl;
  }
  file.close();
}

void AlarmSensors::loadSensorsDataBin() {
  // Cargar los datos de los sensores de un archivo binario usando trunc
  ifstream file(fileNameBin, ios::binary);
  int id;
  string type;
  int data;
  while (file.read(reinterpret_cast<char *>(&id), sizeof(int))) {
    // Strings cannot be read directly as binary data due to their dynamic size
    // First, read the length of the string
    size_t typeLength;
    if (file.read(reinterpret_cast<char *>(&typeLength), sizeof(size_t))) {
      // Resize the string to the read length
      type.resize(typeLength);
      // Now, read the string data
      file.read(&type[0], typeLength);
    }
    file.read(reinterpret_cast<char *>(&data), sizeof(int));
    addSensor(id, type);
    for (auto sensor : sensors_) {
      if (sensor->getId() == id) {
        sensor->setData(data);
      }
    }
    std::cout << "Sensor with id: " << id << " loaded (binary)" << std::endl;
  }
  file.close();
}

void AlarmSensors::loadSensorsData() {
  // Cargar los datos de los sensores de un archivo binario
  loadSensorsDataBin();
  // Cargar los datos de los sensores de un archivo de texto
  // loadSensorsDataTxt();
}