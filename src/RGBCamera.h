#ifndef RGBCAMERA_H
#define RGBCAMERA_H

#include <iostream>

#include "Camera.h"

/**
 * @file RGBCamera.h
 * @brief This is the class RGBCamera. It contains the attributes and methods of
 * the RGBCamera class. This class is used to represent a RGB camera of the
 * system, it can collect data, turn on/off the camera, print the camera
 * information and set the RGB values of the camera.
 * @author Adrián Montes Linares
 * @date 23/05/2024
 *
 */

class RGBCamera : public Camera {
public:
  /**
   * @brief Construct a new RGB Camera object
   *
   * @param id
   * @return RGBCamera object
   */
  explicit RGBCamera(int id);
  /**
   * @brief Destroy the RGB Camera object
   *
   */
  ~RGBCamera();
  /**
   * @brief This method sets the RGB values of the camera
   *
   * @param red
   * @param green
   * @param blue
   */
  void setRGB(int red, int green, int blue);
  /**
   * @brief This method sets the red value of the camera
   *
   * @param red
   */
  void setRed(int red);
  /**
   * @brief This method sets the green value of the camera
   *
   * @param green
   */
  void setGreen(int green);
  /**
   * @brief This method sets the blue value of the camera
   *
   * @param blue
   */
  void setBlue(int blue);

  /**
   * @brief This method returns the red value of the camera
   *
   * @return int
   */
  int getRed();
  /**
   * @brief This method returns the green value of the camera
   *
   * @return int
   */
  int getGreen();
  /**
   * @brief This method returns the blue value of the camera
   *
   * @return int
   */
  int getBlue();

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
  /**
   * @brief This method returns a random number between 0 and 255
   *
   * @return int
   */
  int randomComponent();

private:
  /**
   * @brief This attribute represents the red value of the camera
   *
   */
  int red_;
  /**
   * @brief This attribute represents the green value of the camera
   *
   */
  int green_;
  /**
   * @brief This attribute represents the blue value of the camera
   *
   */
  int blue_;
};

#endif // RGBCAMERA_H