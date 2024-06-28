#ifndef USER_H
#define USER_H

#include <string>

/**
 * @file User.h
 * @brief This is the class User. It contains the attributes and methods of the
 * User class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class User {
public:
  /**
   * @brief Construct a new User object
   *
   * Creates a new User object with the default values (name, nif, password,
   * privileges, email).
   *
   * @return User object
   */
  User();

  /**
   * @brief Construct a new User object
   *
   * Creates a new User object with the values passed as parameters.
   *
   * @param name of the user
   * @param nif of the user
   * @param password of the user
   * @param privileges of the user
   * @param email of the user
   * @return User object
   */
  explicit User(const std::string name, const std::string nif,
                std::string password, std::string privileges,
                std::string email);

  /**
   * @brief Get the Name object
   *
   * @return std::string
   */
  std::string getName() const;
  /**
   * @brief Get the Nif object
   *
   * @return std::string
   */
  std::string getNif() const;
  /**
   * @brief Get the Password object
   *
   * @return std::string
   */
  std::string getPassword() const;
  /**
   * @brief Get the Privileges object
   *
   * @return std::string
   */
  std::string getPrivileges() const;
  /**
   * @brief Get the Email object
   *
   * @return std::string
   */
  std::string getEmail() const;

  /**
   * @brief Set the Name object
   *
   * @param name
   */
  void setName(const std::string name);
  /**
   * @brief Set the Nif object
   *
   * @param nif
   */
  void setNif(const std::string nif);
  /**
   * @brief Set the Password object
   *
   * @param password
   */
  void setPassword(const std::string password);
  /**
   * @brief Set the Privileges object
   *
   * @param privileges
   */
  virtual void setPrivileges(const std::string privileges);
  /**
   * @brief Set the Email object
   *
   * @param email
   */
  void setEmail(const std::string email);

  // Reciben como parametro el puntero a un objeto de la clase User y devuelven
  // un booleano
  /**
   * @brief Operator < overload (this comparison is made by the privileges)
   *
   * @param user
   * @return true
   * @return false
   */
  bool operator<(const User &user) const;
  /**
   * @brief Operator > overload (this comparison is made by the privileges)
   *
   * @param user
   * @return true
   * @return false
   */
  bool operator>(const User &user) const;
  /**
   * @brief Operator == overload (this comparison is made by the nif)
   *
   * @param user
   * @return true
   * @return false
   */
  bool operator==(const User &user) const;
  /**
   * @brief Operator << overload
   *
   * @param os
   * @param user
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os, const User &user);
  /**
   * @brief Operator >> overload
   *
   * @param is
   * @param user
   * @return std::istream&
   */
  friend std::istream &operator>>(std::istream &is, User &user);
  /**
   * @brief Print the user
   *
   */
  void printUser() const;

  // Destructor
  /**
   * @brief Destroy the User object
   *
   */
  virtual ~User();

private:
  /**
   * @brief This is the name of the user
   *
   */
  std::string name;
  /**
   * @brief This is the nif of the user
   *
   */
  std::string nif;
  /**
   * @brief This is the password of the user
   *
   */
  std::string password;
  /**
   * @brief This is the privileges of the user
   *
   */
  std::string privileges;
  /**
   * @brief This is the email of the user
   *
   */
  std::string email;
};

#endif