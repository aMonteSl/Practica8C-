#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H
#include <string>

#include "Sensor.h"

/**
 * @file AirQualitySensor.h
 * @brief This is the class AirQualitySensor. It contains the attributes and
 * methods of the AirQualitySensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class AirQualitySensor : public Sensor {
public:
  /**
   * @brief Construct a new Air Quality Sensor object
   *
   * @param id
   * @param active
   * @return AirQualitySensor object
   */
  explicit AirQualitySensor(int id, bool active);
  /**
   * @brief Destroy the Air Quality Sensor object
   *
   */
  ~AirQualitySensor() override;

  /**
   * @brief Collect data of the Air Quality Sensor
   *
   * This method collects the data of the Air Quality Sensor and stores it in
   * the data attribute.
   */
  void collectData() override;
  /**
   * @brief Check if the Air Quality Sensor is working properly
   *
   * @return true if the Air Quality Sensor is working properly
   * @return false if the Air Quality Sensor is not working properly
   */
  bool checkAllgood() const override;
  /**
   * @brief Print the data of the Air Quality Sensor
   *
   */
  void printData() const override;
  /**
   * @brief Collect and print the data of the Air Quality Sensor
   *
   */
  void collectAndPrint();
  /**
   * @brief This method returns if the Air Quality Sensor is active or not and
   * if its active, it returns if its good or bad the data.
   *
   * @return std::string
   */
  std::string stringStatus() const;

  /**
   * @brief This method prints the AirQualitySensor object.
   *
   * @param os
   * @param sensor
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const AirQualitySensor &sensor);
};

#endif // AIRQUALITYSENSOR_H