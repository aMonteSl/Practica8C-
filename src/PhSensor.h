#ifndef PH_SENSOR_H
#define PH_SENSOR_H
#include <string>

#include "Sensor.h"

/**
 * @file PhSensor.h
 * @brief This is the class PhSensor. It contains the attributes and methods of
 * the PhSensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class PhSensor : public Sensor {
public:
  /**
   * @brief Construct a new Ph Sensor object
   *
   * @param id
   * @param active
   * @return PhSensor object
   */
  explicit PhSensor(int id, bool active);
  /**
   * @brief Destroy the Ph Sensor object
   *
   */
  ~PhSensor() override;

  /**
   * @brief Collect data of the Ph Sensor
   *
   * This method collects the data of the Ph Sensor and stores it in the data
   * attribute.
   */
  void collectData() override;
  /**
   * @brief Check if the Ph Sensor is working properly
   *
   * @return true if the Ph Sensor is working properly
   * @return false if the Ph Sensor is not working properly
   */
  bool checkAllgood() const override;
  /**
   * @brief This qualifies the Ph Sensor into Acidic, Neutral or Alkaline
   *
   * @return std::string of the qualification of the Ph Sensor
   */
  std::string qualifyPh() const;
  /**
   * @brief This method prints the data of the Ph Sensor
   *
   */
  void printData() const override;
  /**
   * @brief This method returns the status in a string
   *
   * @return std::string of the status of the Ph Sensor
   */
  std::string stringStatus() const;
  /**
   * @brief Collect and print the data of the Ph Sensor
   *
   */
  void collectAndPrint();

  /**
   * @brief Operator << overload
   */
  friend std::ostream &operator<<(std::ostream &os, const PhSensor &sensor);
};

#endif // PH_SENSOR_H