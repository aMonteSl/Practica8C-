#include "ManageCameras.h"
#include "RGBCamera.h"
#include "TemperatureCamera.h"

#include <fstream>
#include <iostream>
#include <new>

using namespace std;

ManageCameras::ManageCameras() {
  // Crear las camaras por defecto
  cameras_.insert(new RGBCamera(1));
  cameras_.insert(new TemperatureCamera(2));
}

ManageCameras::~ManageCameras() { clearCameras(); }

void ManageCameras::clearCameras() {
  for (auto camera : cameras_) {
    delete camera;
  }
  cameras_.clear();
}

void ManageCameras::createCamera(int id, std::string type) {
  // Pasar a mayusculas el tipo
  for (char &c : type) {
    c = toupper(c);
  }
  // Crear la camara y añadir el puntero a cameras_
  // SI ya esta ese id, no se crea la camara y se informa
  if (findCamera(id) == nullptr) {
    if (type == "RGB") {
      cameras_.insert(new RGBCamera(id));
    } else if (type == "TEMPERATURE") {
      cameras_.insert(new TemperatureCamera(id));
    } else {
      cout << "Invalid camera type" << endl;
    }
  } else {
    cout << "Camera with id " << id << " already exists" << endl;
  }
}

void ManageCameras::addCamera(Camera *camera) { cameras_.insert(camera); }

void ManageCameras::removeCamera(int id) {
  // Usar findcamera para encontrar la camara con el id dado
  Camera *camera = findCamera(id);
  // Si la camara existe, borrarla
  if (camera != nullptr) {
    cout << "Removing camera with id " << id << endl;
    cameras_.erase(camera);
    delete camera;
  } else {
    cout << "Camera with id " << id << " does not exist" << endl;
  }
}

Camera *ManageCameras::findCamera(int id) {
  // Encontrar la camara con el id dado y retornar el puntero
  for (Camera *camera : cameras_) {
    if (camera->getId() == id) {
      return camera;
    }
  }
  return nullptr;
}

void ManageCameras::displayAllCameras() {
  for (Camera *camera : cameras_) {
    camera->printCamera();
  }
}

void ManageCameras::collectData() {
  for (Camera *camera : cameras_) {
    camera->collectData();
  }
}

void ManageCameras::collectAndDisplayData() {
  collectData();
  displayAllCameras();
}

void ManageCameras::turnOnCameras() {
  cout << "Turning on the cameras...\n" << endl;
  for (Camera *camera : cameras_) {
    camera->turnOn();
  }
}

void ManageCameras::turnOffCameras() {
  cout << "Turning off the cameras...\n" << endl;
  for (Camera *camera : cameras_) {
    camera->turnOff();
  }
}

void ManageCameras::turnOnOffCameras(int status) {
  if (status == 1) {
    turnOnCameras();
  } else if (status == 2) {
    turnOffCameras();
  } else {
    cout << "Invalid status" << endl;
  }
}

void ManageCameras::saveCameras() {
  // Crear un archivo de salida
  std::ofstream file(filename_);
  if (file.is_open()) {
    for (Camera *camera : cameras_) {
      // Guardar el id, tipo y sus datos rgb o temperatura dependiendo del tipo
      // Guardando en este orden las cosa TIPO ID Datos
      if (camera->getType() == "RGB") {
        std::cout << "Saving RGB camera (" << camera->getId() << ")"
                  << std::endl;
        RGBCamera *rgbCamera = static_cast<RGBCamera *>(camera);
        file << camera->getId() << " " << camera->getType() << " "
             << rgbCamera->getRed() << " " << rgbCamera->getGreen() << " "
             << rgbCamera->getBlue() << std::endl;
      } else if (camera->getType() == "TEMPERATURE") {
        std::cout << "Saving Temperature camera (" << camera->getId() << ")"
                  << std::endl;
        TemperatureCamera *temperatureCamera =
            static_cast<TemperatureCamera *>(camera);
        file << camera->getId() << " " << camera->getType() << " "
             << temperatureCamera->getTemperature() << std::endl;
      }
    }
    file.close();
    std::cout << "Cameras saved" << std::endl;
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
}

void ManageCameras::loadCameras() {
  // Crear un archivo de entrada
  std::ifstream file(filename_);
  if (file.is_open()) {
    // Hay que recorrer cada linea del archivo
    // Primero se leera el id, luego el tipo y luego los datos rgb o temperatura
    // dependiendo del tipo
    // Primero borrar las camaras actuales
    clearCameras();
    while (!file.eof()) {
      int id;
      std::string type;
      file >> id >> type;

      if (type == "RGB") {
        int red, green, blue;
        file >> red >> green >> blue;
        if (findCamera(id) != nullptr) {
          cout << "Camera with id " << id << " already exists" << endl;
          continue; // Si ya existe la camara, no se crea y se pasa a la
                    // siguiente
        }
        RGBCamera *rgbCamera = new RGBCamera(id);
        rgbCamera->setRGB(red, green, blue);
        cameras_.insert(rgbCamera);
      } else if (type == "TEMPERATURE") {
        float temperature;
        file >> temperature;
        if (findCamera(id) != nullptr) {
          cout << "Camera with id " << id << " already exists" << endl;
          continue; // Si ya existe la camara, no se crea y se pasa a la
                    // siguiente
        }
        TemperatureCamera *temperatureCamera = new TemperatureCamera(id);
        temperatureCamera->setTemperature(temperature);
        cameras_.insert(temperatureCamera);
      }
    }
    file.close();
    std::cout << "Cameras loaded" << std::endl;
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
}