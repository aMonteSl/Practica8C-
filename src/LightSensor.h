#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#include <string>

#include "Sensor.h"

/**
 * @file LightSensor.h
 * @brief This is the class LightSensor. It contains the attributes and methods
 * of the LightSensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class LightSensor : public Sensor {
public:
  /**
   * @brief Construct a new Light Sensor object
   *
   * @param id
   * @param active
   * @return LightSensor object
   */
  explicit LightSensor(int id, bool active);
  /**
   * @brief Destroy the Light Sensor object
   *
   */
  ~LightSensor() override;

  /**
   * @brief Collect data of the Light Sensor
   *
   * This method collects the data of the Light Sensor and stores it in the data
   * attribute.
   */
  void collectData() override;
  /**
   * @brief Check if the Light Sensor is working properly
   *
   * @return true if the Light Sensor is working properly
   * @return false if the Light Sensor is not working properly
   */
  bool checkAllgood() const override;
  /**
   * @brief Print the data of the Light Sensor
   *
   */
  void printData() const override;
  /**
   * @brief Collect and print the data of the Light Sensor
   *
   */
  std::string stringStatus() const;
  /**
   * @brief Collect and print the data of the Light Sensor
   *
   */
  void collectAndPrint();

  /**
   * @brief Get the Light object
   *
   * @return int
   */
  friend std::ostream &operator<<(std::ostream &os, const LightSensor &sensor);
};

#endif // LIGHTSENSOR_H