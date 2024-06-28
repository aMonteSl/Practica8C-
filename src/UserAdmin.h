#ifndef USERADMIN_H
#define USERADMIN_H

#include "User.h"
#include <string>

/**
 * @file UserAdmin.h
 * @brief This is the class UserAdmin. It contains the attributes and methods of
 * the UserAdmin class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// Clase Admin clase hija de Usuario
class UserAdmin : public User {
public:
  // Constructor por defecto
  /**
   * @brief Construct a new User Admin object
   *
   * Creates a new UserAdmin object with the default values (name, nif,
   * password, email).
   *
   * @return UserAdmin object
   */
  UserAdmin();
  // Constructor con parametros
  /**
   * @brief Construct a new User Admin object
   *
   * Creates a new UserAdmin object with the values passed as parameters.
   *
   * @param name of the user
   * @param nif of the user
   * @param password of the user
   * @param email of the user
   * @return UserAdmin object
   */
  explicit UserAdmin(const std::string name, const std::string nif,
                     std::string password, std::string email);
  // Destructor
  /**
   * @brief Destroy the User Admin object
   *
   */
  virtual ~UserAdmin();
};

#endif // USERADMIN_H
