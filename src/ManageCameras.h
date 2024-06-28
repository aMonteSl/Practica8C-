#ifndef MANAGECAMERAS_H
#define MANAGECAMERAS_H

#include <iostream>
#include <set>

#include "RGBCamera.h"
#include "TemperatureCamera.h"

/**
 * @file ManageCameras.h
 * @brief This is the class ManageCameras. It contains the attributes and
 * methods of the ManageCameras class. This class is used to manage the cameras
 * of the system, it can create, remove, display, collect data, turn on/off the
 * cameras and save/load the cameras to/from a file.
 * @author Adrián Montes Linares
 * @date 23/05/2024
 *
 */

class ManageCameras {
public:
  /**
   * @brief Construct a new Manage Cameras object
   *
   */
  ManageCameras();
  /**
   * @brief Destroy the Manage Cameras object
   *
   */
  ~ManageCameras();

  /**
   * @brief Create a Camera object
   *
   * @param id
   * @param type
   */
  void createCamera(int id, std::string type);
  /**
   * @brief Clear all the cameras
   *
   */
  void clearCameras();

  /**
   * @brief Add a Camera object
   *
   * @param camera
   */
  void addCamera(Camera *camera);
  /**
   * @brief Remove a Camera object
   *
   * @param id
   */
  void removeCamera(int id);
  /**
   * @brief Find a Camera object
   *
   * @param id
   * @return Camera*
   */
  Camera *findCamera(int id);
  /**
   * @brief Display all the cameras
   *
   */
  void displayAllCameras();
  /**
   * @brief Collect and display the data of all the cameras
   *
   */
  void collectAndDisplayData();
  /**
   * @brief Collect the data of all the cameras
   *
   */
  void collectData();
  /**
   * @brief Turn on all the cameras
   *
   */
  void turnOnCameras();
  /**
   * @brief Turn off all the cameras
   *
   */
  void turnOffCameras();
  /**
   * @brief Turn on or off the cameras
   *
   * @param status
   */
  void turnOnOffCameras(int status);
  /**
   * @brief Save the cameras to a file
   *
   */
  void saveCameras();
  /**
   * @brief Load the cameras from a file
   *
   */
  void loadCameras();

  // void setRGB(int id, int red, int green, int blue);
  // void setTemperature(int id, float temperature);

private:
  /**
   * @brief This attribute is a set of Camera pointers
   *
   */
  std::set<Camera *> cameras_;
  /**
   * @brief This attribute is the name of the file where the cameras are saved
   *
   */
  std::string filename_ = "cameras.txt";
};

#endif // MANAGECAMERAS_H
