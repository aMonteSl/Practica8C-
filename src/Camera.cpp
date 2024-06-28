#include "Camera.h"

using namespace std;

Camera::Camera(int id, std::string type, bool active) {
  id_ = id;
  type_ = type;
  active_ = active;
}

Camera::~Camera() {}

void Camera::setId(int newid) { id_ = newid; }

int Camera::getId() const { return id_; }

void Camera::setType(std::string newtype) { type_ = newtype; }

std::string Camera::getType() const { return type_; }

void Camera::collectData() {
  cout << "Collecting data from camera " << id_ << endl;
}

void Camera::printCamera() {
  cout << "Camera id: " << id_ << " type: " << type_ << " active: " << active_
       << endl;
}

void Camera::turnOn() { active_ = true; }

void Camera::turnOff() { active_ = false; }

const bool Camera::isActive() { return active_; }
