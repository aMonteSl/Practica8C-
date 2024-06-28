#ifndef TEMPERATURECAMERA_H
#define TEMPERATURECAMERA_H

#include "Camera.h"
#include <iostream>

/**
 * @file TemperatureCamera.h
 * @brief This is the class Temperature
 * Camera. It contains the attributes and methods of the TemperatureCamera
 * class. This class is used to represent a temperature camera of the system, it
 * can collect data, print the camera information and set the temperature of the
 * camera.
 * @author Adrián Montes Linares
 * @date 23/05/2024
 *
 */

class TemperatureCamera : public Camera {
public:
  /**
   * @brief Construct a new Temperature Camera object
   *
   * @param id
   * @return TemperatureCamera object
   */
  explicit TemperatureCamera(int id);
  /**
   * @brief Destroy the Temperature Camera object
   *
   */
  ~TemperatureCamera();

  /**
   * @brief This method sets the temperature of the camera
   *
   * @param temperature
   */
  void setTemperature(float temperature);
  /**
   * @brief This method gets the temperature of the camera
   *
   * @return float
   */
  float getTemperature();

  /**
   * @brief This method collects the data of the camera
   *
   */
  void collectData() override;
  /**
   * @brief This method prints the camera information
   *
   */
  void printCamera() override;

private:
  /**
   * @brief This method generates a random temperature
   *
   * @return float
   */
  float randomTemperature();
  /**
   * @brief This attribute stores the temperature of the camera
   *
   */
  float temperature_;
};

#endif // TEMPERATURECAMERA_H