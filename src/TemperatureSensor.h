#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <string>

#include "Sensor.h"

/**
 * @file TemperatureSensor.h
 * @brief This is the class TemperatureSensor. It contains the attributes and
 * methods of the TemperatureSensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class TemperatureSensor : public Sensor {
public:
  /**
   * @brief Construct a new Temperature Sensor object
   *
   * @param id
   * @param active
   * @return TemperatureSensor object
   */
  explicit TemperatureSensor(int id, bool active);
  /**
   * @brief Destroy the Temperature Sensor object
   *
   */
  ~TemperatureSensor() override;

  /**
   * @brief Collect data of the Temperature Sensor
   *
   * This method collects the data of the Temperature Sensor and stores it in
   * the data attribute.
   */
  void collectData() override;
  /**
   * @brief Check if the Temperature Sensor is working properly
   *
   * @return true if the Temperature Sensor is working properly
   * @return false if the Temperature Sensor is not working properly
   */
  bool checkAllgood() const override;
  /**
   * @brief Print the data of the Temperature Sensor
   *
   */
  void printData() const override;
  /**
   * @brief String status of the Temperature Sensor
   *
   */
  std::string stringStatus() const;
  /**
   * @brief Collect and print the data of the Temperature Sensor
   *
   */
  void collectAndPrint();

  /**
   * @brief Overloaded operator<<
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const TemperatureSensor &sensor);
};

#endif // TEMPERATURESENSOR_H