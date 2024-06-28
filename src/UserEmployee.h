#ifndef USEREMPLOYEE_H
#define USEREMPLOYEE_H

#include "User.h"
#include <string>

/**
 * @file UserEmployee.h
 * @brief This is the class UserEmployee. It contains the attributes and methods
 * of the UserEmployee class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class UserEmployee : public User {
public:
  // Constructor por defecto
  /**
   * @brief Construct a new User Employee object
   *
   * Creates a new UserEmployee object with the default values (name, nif,
   * password, email).
   *
   * @return UserEmployee object
   */
  UserEmployee();
  // Constructor con parametros
  /**
   * @brief Construct a new User Employee object
   *
   * Creates a new UserEmployee object with the values passed as parameters.
   *
   * @param name of the user
   * @param nif of the user
   * @param password of the user
   * @param email of the user
   * @return UserEmployee object
   */
  explicit UserEmployee(const std::string name, const std::string nif,
                        std::string password, std::string email);
  // Destructor
  /**
   * @brief Destroy the User Employee object
   *
   */
  virtual ~UserEmployee();
};

#endif // USEREMPLOYEE_H