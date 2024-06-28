#ifndef USERSSERVER_H
#define USERSSERVER_H
#include <string>

#include "Exceptions.h"
#include "UsersDatabase.h"

/**
 * @file UsersServer.h
 * @brief This is the class UsersServer. It contains the attributes and methods
 * of the UsersServer class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// UsersServer:es para controlar todos los usuarios
// Los usuarios estan almacenados en un objeto de la clase UsersDatabase

class UsersServer {
public:
  // Constructor (necesario pasarle la base de datos)
  /**
   * @brief Construct a new Users Server object
   * Creates a new UsersServer object that contains the UsersDatabase object.
   * @return UsersServer object
   */
  UsersServer();
  // Destructor
  /**
   * @brief Destroy the Users Server object
   *
   */
  ~UsersServer();

  /**
   * @brief Create a User object
   *
   * @param name
   * @param nif
   * @param password
   * @param privileges
   * @param email
   */
  void createUser(const std::string name, const std::string nif,
                  const std::string password, const std::string privileges,
                  const std::string email);
  /**
   * @brief Delete a User object
   *
   * @param nif
   */
  void deleteUser(const std::string nif);
  /**
   * @brief Print all Users
   * Print all users in the UsersDatabase object.
   */
  void printUsersServer() const;
  /**
   * @brief Load Users from File
   * Load users from a file.
   */
  void loadUsersFromFile();
  /**
   * @brief Save Users to File
   * Save users to a file.
   */
  void saveUsersToFile();
  /**
   * @brief Find User Login
   *
   * @param name
   * @param password
   * @param nif
   * @return true
   * @return false
   */
  bool findUserLogin(std::string name, std::string password, std::string nif);
  /**
   * @brief Get Privileges
   *
   * @param nif
   * @return std::string the privileges
   */
  std::string getPrivileges(std::string nif);
  /**
   * @brief Update User
   *
   * @param name
   * @param nif
   * @param password
   * @param privileges
   * @param email
   */
  void updateUser(const std::string name, const std::string nif,
                  const std::string password, const std::string privileges,
                  const std::string email);

private:
  // Aqui se definen los atributos privados de la clase UsersServer
  /**
   * @brief This is the UsersDatabase object
   *
   */
  UsersDatabase usersDatabase_;
  // File
  /**
   * @brief This is the name of the file
   *
   */
  std::string fileNameTxt_ = "users.txt";
  /**
   * @brief This is the name of the binary file
   *
   */
  std::string fileNameBi_ = "users.dat";

  /**
   * @brief This method reads the users from a file txt
   *
   */
  void readUsersFromFileTxt();
  /**
   * @brief This method writes the users to a file txt
   *
   */
  void writeUserToFileTxt();

  /**
   * @brief This method writes the users from a file binary
   */
  void writeUserToFileBi();

  /**
   * @brief This method reads the users from a file binary
   *
   */
  void readUsersFromFileBi();
};

#endif // USERSSERVER_H