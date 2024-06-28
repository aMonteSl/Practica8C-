#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H
#include <string>

#include "Sensor.h"

/**
 * @file PressureSensor.h
 * @brief This is the class PressureSensor. It contains the attributes and
 * methods of the PressureSensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class PressureSensor : public Sensor {
public:
  /**
   * @brief Construct a new Pressure Sensor object
   *
   * @param id
   * @param active
   * @return PressureSensor object
   */
  explicit PressureSensor(int id, bool active);
  /**
   * @brief Destroy the Pressure Sensor object
   *
   */
  ~PressureSensor() override;

  /**
   * @brief Collect data of the Pressure Sensor
   *
   * This method collects the data of the Pressure Sensor and stores it in the
   * data attribute.
   */
  void collectData() override;
  /**
   * @brief Check if the Pressure Sensor is working properly
   *
   * @return true if the Pressure Sensor is working properly
   * @return false if the Pressure Sensor is not working properly
   */
  bool checkAllgood() const override;
  /**
   * @brief Print the data of the Pressure Sensor
   *
   */
  void printData() const override;
  /**
   * @brief This method returns the status in a string
   *
   * @return std::string of the status of the Pressure Sensor
   */
  std::string stringStatus() const;
  /**
   * @brief Collect and print the data of the Pressure Sensor
   *
   */
  void collectAndPrint();

  /**
   * @brief Operator << overload
   *
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const PressureSensor &sensor);
};

#endif // PRESSURESENSOR_H