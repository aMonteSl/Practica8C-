#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

/**
 * @file Camera.h
 * @brief This is the class Camera. It contains the attributes and methods of
 * the Camera class. This class is used to represent a camera of the system, it
 * can collect data, turn on/off the camera and print the camera information.
 * @author Adrián Montes Linares
 * @date 23/05/2024
 *
 */

class Camera {
public:
  /**
   * @brief Construct a new Camera object
   *
   * @param id
   * @param type
   * @param active
   * @return Camera object
   */
  explicit Camera(int id, std::string type, bool active);
  /**
   * @brief Destroy the Camera object
   *
   */
  virtual ~Camera();
  /**
   * @brief Set the id of the camera
   *
   * @param newid
   */
  void setId(int newid);
  /**
   * @brief Get the id of the camera
   *
   * @return int
   */
  int getId() const;
  /**
   * @brief Set the type of the camera
   *
   * @param newtype
   */
  void setType(std::string newtype);
  /**
   * @brief Get the type of the camera
   *
   * @return std::string
   */
  std::string getType() const;
  /**
   * @brief Print the camera information
   *
   */
  virtual void printCamera();
  /**
   * @brief Collect data from the camera
   *
   */
  virtual void collectData();
  /**
   * @brief Turn on the camera
   *
   */
  void turnOn();
  /**
   * @brief Turn off the camera
   *
   */
  void turnOff();
  /**
   * @brief Check if the camera is active
   *
   * @return const bool
   */
  const bool isActive();

private:
  /**
   * @brief This attribute represents the id of the camera
   *
   */
  int id_;
  /**
   * @brief This attribute represents the type of the camera
   *
   */
  std::string type_;
  /**
   * @brief This attribute represents if the camera is active
   *
   */
  bool active_;
};

#endif // CAMERA_H