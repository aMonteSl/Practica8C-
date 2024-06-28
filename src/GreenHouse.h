#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "AlarmSensors.h"
#include "ManageCameras.h"
#include "MonitoringSystem.h"
#include "UsersServer.h"

/**
 * @file GreenHouse.h
 * @brief This is the class GreenHouse. It contains the attributes and methods
 * of the GreenHouse class, this class is the main of the hole system.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class GreenHouse {
public:
  /**
   * @brief Construct a new Green House object
   *
   */
  GreenHouse();
  /**
   * @brief Destroy the Green House object
   *
   */
  ~GreenHouse();

  /**
   * @brief Start the system
   *
   */
  void startSystem();
  /**
   * @brief Main system, after the system is started, you call this method to
   * manage the system with your options that contains your privilege.
   *
   */
  void mainSystem();

private:
  /**
   * @brief Save the system
   *
   */
  void save(int id);
  /**
   * @brief Sleep the system
   *
   */
  void sleep();
  /**
   * @brief Manage the login
   *
   */
  void manageLogin();
  /**
   * @brief Manage the admin
   *
   */
  void manageAdmin();
  /**
   * @brief Manage the employee
   *
   */
  void manageEmployee();
  /**
   * @brief Manage the guest
   *
   */
  void manageGuest();
  /**
   * @brief Manage the update user
   *
   */
  void manageUpdateUser();
  /**
   * @brief Manage the create user
   *
   */
  void manageCreateUser();
  /**
   * @brief Manage the delete user
   *
   */
  void manageDeleteUser();
  /**
   * @brief Manage search user
   *
   */
  bool searchUser(std::string name, std::string password, std::string nif);

  /**
   * @brief This attribute is the AlarmSensors object (set of pointers to
   * sensors).
   *
   */
  AlarmSensors *alarm_;

  /**
   * @brief This attribute is the MonitoringSystem object.
   *
   */
  MonitoringSystem *ms_;

  /**
   * @brief This attribute is the UsersServer object (set of pointers to users).
   *
   */
  UsersServer *us_;

  /**
   * @brief This attribute is the ManageCameras object (set of pointers to
   * cameras).
   *
   */
  ManageCameras *mc_;
};

#endif // GREENHOUSE_H
