#ifndef HYDROMETER_SENSOR_H
#define HYDROMETER_SENSOR_H
#include <string>

#include "Sensor.h"

/**
 * @file HydrometerSensor.h
 * @brief This is the class HydrometerSensor. It contains the attributes and
 * methods of the HydrometerSensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class HydrometerSensor : public Sensor {
public:
  /**
   * @brief Construct a new Hydrometer Sensor object
   *
   * @param id
   * @param active
   * @return HydrometerSensor object
   */
  explicit HydrometerSensor(int id, bool active);
  /**
   * @brief Destroy the Hydrometer Sensor object
   *
   */
  ~HydrometerSensor() override;

  /**
   * @brief Collect data of the Hydrometer Sensor
   *
   * This method collects the data of the Hydrometer Sensor and stores it in the
   * data attribute.
   */
  void collectData() override;
  /**
   * @brief Check if the Hydrometer Sensor is working properly
   *
   * @return true if the Hydrometer Sensor is working properly
   * @return false if the Hydrometer Sensor is not working properly
   */
  bool checkAllgood() const override;
  /**
   * @brief Print the data of the Hydrometer Sensor
   *
   */
  void printData() const override;
  /**
   * @brief Collect and print the data of the Hydrometer Sensor
   *
   * @return std::string of the status of the Hydrometer Sensor
   */
  std::string stringStatus() const;

  /**
   * @brief Collect and print the data of the Hydrometer Sensor
   *
   */
  void collectAndPrint();

  /**
   * @brief Get the Data object
   *
   * @return double
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const HydrometerSensor &sensor);
};

#endif // HYDROMETER_SENSOR_H