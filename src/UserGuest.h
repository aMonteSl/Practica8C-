#ifndef USERGUEST_H
#define USERGUEST_H

#include "User.h"
#include <string>

/**
 * @file UserGuest.h
 * @brief This is the class UserGuest. It contains the attributes and methods of
 * the UserGuest class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// Clase Admin clase hija de Usuario
class UserGuest : public User {
public:
  // Constructor por defecto
  /**
   * @brief Construct a new User Guest object
   *
   * Creates a new UserGuest object with the default values (name, nif,
   * password, email).
   *
   * @return UserGuest object
   */
  UserGuest();
  // Constructor con parametros
  /**
   * @brief Construct a new User Guest object
   *
   * Creates a new UserGuest object with the values passed as parameters.
   *
   * @param name of the user
   * @param nif of the user
   * @param password of the user
   * @param email of the user
   * @return UserGuest object
   */
  explicit UserGuest(const std::string name, const std::string nif,
                     std::string password, std::string email);
  // Destructor
  /**
   * @brief Destroy the User Guest object
   *
   */
  virtual ~UserGuest();
};

#endif // USERGUEST_H