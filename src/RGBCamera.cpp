#include "RGBCamera.h"

#include <iostream>
#include <random>

RGBCamera::RGBCamera(int id) : Camera(id, "RGB", true) {
  red_ = -1;
  green_ = -1;
  blue_ = -1;
  std::cout << "RGB Camera id (" << getId() << ") created" << std::endl;
}

RGBCamera::~RGBCamera() {}

void RGBCamera::setRGB(int red, int green, int blue) {
  setRed(red);
  setGreen(green);
  setBlue(blue);
}

void RGBCamera::setRed(int red) { red_ = red; }

void RGBCamera::setGreen(int green) { green_ = green; }

void RGBCamera::setBlue(int blue) { blue_ = blue; }

int RGBCamera::getRed() { return red_; }

int RGBCamera::getGreen() { return green_; }

int RGBCamera::getBlue() { return blue_; }

int RGBCamera::randomComponent() {
  // Random number entre 0 y 255
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 255);
  return dis(gen);
}

void RGBCamera::collectData() {
  setRGB(randomComponent(), randomComponent(), randomComponent());
}

void RGBCamera::printCamera() {
  if (isActive() and red_ != -1 and green_ != -1 and blue_ != -1)
    std::cout << "RGB Camera id (" << getId() << ")"
              << ": "
              << " red: " << red_ << " green: " << green_ << " blue: " << blue_
              << std::endl;
  else if (isActive() and red_ == -1 and green_ == -1 and blue_ == -1)
    std::cout << "RGB Camera " << getId()
              << " is active but has not collected data yet" << std::endl;
  else
    std::cout << "RGB Camera " << getId() << " is not active" << std::endl;
}