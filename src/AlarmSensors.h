#ifndef ALARMSENSORS_H
#define ALARMSENSORS_H

#include <set>
#include <string>

#include "Sensor.h"

/**
 * @file AlarmSensors.h
 * @brief This is the class AlarmSensors. It contains the attributes and methods
 * of the AlarmSensors class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// Declaracion anticipada de cada uno de los sensores
class TemperatureSensor;
class AirQualitySensor;
class HydrometerSensor;
class PressureSensor;
class LightSensor;
class PhSensor;

class AlarmSensors {
public:
  // Constructor con las declaraciones antincipadas
  /**
   * @brief Construct a new Alarm Sensors object
   *
   */
  explicit AlarmSensors();
  // Destructor
  /**
   * @brief Destroy the Alarm Sensors object
   *
   */
  ~AlarmSensors();

  // Funcion añadir un sensor al set de sensores
  /**
   * @brief Add a Sensor object
   *
   * @param id
   * @param type
   */
  void addSensor(int id, std::string type);

  // Funcion para eliminar un sensor del set de sensores
  /**
   * @brief Delete a Sensor object
   *
   * @param id
   */
  void deleteSensor(int id);

  // Mostrar estado de la alarma
  /**
   * @brief Display the Alarm Status
   *
   */
  void displayAlarmStatus();
  // Tambien debemos de dar la opcion de mostrar los datos de todos los sensores
  // Mostrar los datos de todos los sensores
  /**
   * @brief Display all Sensors Data
   *
   */
  void displayAllSensorsData();
  // Opcion de poder apagar o encender el sistema
  /**
   * @brief This method turns on or off the system.
   *
   * @param input
   */
  void turnOnOffSystem(int input);

  /**
   * @brief This method saves the sensors data to a file, one .txt and other one
   * .dat.
   *
   */
  void saveSensorsData();
  /**
   * @brief This method loads the sensors data from a file .dat, but you can
   * change to loads the sensor from a .txt.
   *
   */
  void loadSensorsData();

  /**
   * @brief This method saves the sensors data to a file .txt.
   *
   */
  void saveSensorsDataTxt();
  /**
   * @brief This method loads the sensors data from a file .txt.
   *
   */
  void loadSensorsDataTxt();

  /**
   * @brief This method saves the sensors data to a file .dat.
   *
   */
  void saveSensorsDataBin();
  /**
   * @brief This method loads the sensors data from a file .dat.
   *
   */
  void loadSensorsDataBin();

private:
  // Set de punteros a sensores
  /**
   * @brief This is the set of Sensor pointers
   *
   */
  std::set<Sensor *> sensors_;

  // File names
  /**
   * @brief This is the name of the file .txt
   *
   */
  std::string fileNameTxt = "sensors.txt";
  /**
   * @brief This is the name of the file .dat
   *
   */
  std::string fileNameBin = "sensors.dat";

  // El sistema de alarma tiene que chequear todos los sensores
  /**
   * @brief Check the Sensors
   *
   * @return int
   */
  int checkSensors();
  // El sistema que todos los sensores no tienen el valor por defecto de -1
  /**
   * @brief Check if the Sensors are Initialized
   *
   * @return true if the Sensors are Initialized
   * @return false if the Sensors are not Initialized
   */
  bool sensorsIniticialized();
  // Ver si existe un sensor
  /**
   * @brief Check if a Sensor exists
   *
   * @param id
   * @return true if the Sensor exists
   * @return false if the Sensor does not exist
   */
  bool sensorExists(int id);
  // Si los sensores tienen buenas mediciones
  /**
   * @brief Check if the Sensors have good measurements
   *
   * @return true if the Sensors have good measurements
   * @return false if the Sensors do not have good measurements
   */
  bool checkAllgood();
  // Encender el sistema
  /**
   * @brief Turn on the System
   *
   */
  void turnOnSystem();
  /**
   * @brief Turn off the System
   *
   */
  // Apagar el sistema
  void turnOffSystem();

  // Estado de la alarma
  /**
   * @brief The status of the alarm
   *
   */
  bool status_ = true;
};

#endif // ALARMSENSORS_H