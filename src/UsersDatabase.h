#ifndef USERSDATABASE_H
#define USERSDATABASE_H

#include "User.h"
#include <set>

//  SOURCES = User.cpp UsersDatabase.cpp mainUsersDatabase.cpp UserAdmin.cpp
//  UserEmployee.cpp UserGuest.cpp

/**
 * @file UsersDatabase.h
 * @brief This is the class UsersDatabase. It contains the attributes and
 * methods of the UsersDatabase class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// Declaracion anticipada de la cada clase de User
class UserAdmin;
class UserEmployee;
class UserGuest;

class UserPtrComparator {
public:
  bool operator()(const User *us1, const User *us2) const {
    // Comparar dnis de usuarios si tienen el mismo dni no se puede añadir el
    // usuario
    return us1->getNif() < us2->getNif();
  }
};

class UserNameComparator {
public:
  bool operator()(const User *lhs, const User *rhs) const {
    return lhs->getName() < rhs->getName();
  }
};

// UserDatabase:es para controlar todos los usuarios
class UsersDatabase {
public:
  // Constructor por defecto
  // Tengo que hacer un set de usuarios para luego añadirlos con .insert en el
  // metodo setUsers
  /**
   * @brief Construct a new Users Database object
   * Creates a new UsersDatabase object that contains the pointers to users.
   * @return UsersDatabase object
   */
  UsersDatabase();

  // Destructor
  /**
   * @brief Destroy the Users Database object
   *
   */
  ~UsersDatabase();

  // Funcion para añadir un usuario al set de usuarios, el set de usuarios es el
  // conjunto de direcciones de memoria, almacena los punteros
  /**
   * @brief Add a user to the set of users
   *
   * @param user
   */
  void addUser(const User *user);
  // getUsers devuelve un set de usuarios, getUsers devuelve un set de punteros
  // a usuarios
  /**
   * @brief Get the Users object
   *
   * @return std::set<const User *, UserPtrComparator>
   */
  std::set<const User *, UserPtrComparator> getUsers() const;
  // setUsers recibe un set de usuarios, setUsers recibe un set de punteros a
  // usuarios
  /**
   * @brief Set the Users object
   *
   * @param users
   */
  void setUsers(const std::set<const User *, UserPtrComparator> &users);

  // Ahora se implementan funciones para buscar un usuario por usuario, por
  // nombre, por NIF, por correo electrónico
  /**
   * @brief Find a user in the set of users
   *
   * @param user
   * @return User*
   */
  User *findUser(const User &user) const;
  /**
   * @brief Find a user in the set of users with the name
   *
   * @param name
   * @return User*
   */
  User *findUserByName(const std::string name) const;
  /**
   * @brief Fiend a user in the set of users with the NIF
   *
   * @param nif
   * @return User*
   */
  User *findUserByNif(const std::string nif) const;
  /**
   * @brief Find a user in the set of users with the password
   *
   * @param password
   * @return User*
   */
  User *findUserByPassword(const std::string password) const;
  /**
   * @brief Find a user in the set of users with the email
   *
   * @param email
   * @return User*
   */
  User *findUserByEmail(const std::string email) const;

  // Ahora se implementa la funcion para eliminar un usuario por usuario, por
  // nombre, por NIF, por correo electrónico

  /**
   * @brief Delete a user from the set of users
   *
   * @param user
   */
  void deleteUser(const User &user);
  /**
   * @brief Delete a user from the set of users with the name
   *
   * @param name
   */
  void deleteUserByName(const std::string name);
  /**
   * @brief Delete a user from the set of users with the NIF
   *
   * @param nif
   */
  void deleteUserByNif(const std::string nif);
  /**
   * @brief Delete a user from the set of users with the email
   *
   * @param email
   */
  void deleteUserByEmail(const std::string email);

  /**
   * @brief This method checks if the privileges are valid
   *
   * @param privileges
   * @return true
   * @return false
   */
  bool isValidPrivileges(const std::string privileges) const;

  // Ahora imprimimos todos los usuarios
  /**
   * @brief Print all the users
   *
   */
  void printUsers() const;

private:
  // Aqui se definen los atributos privados de la clase UsersDatabase
  // Hacer el conjunto de ususarios con set
  /**
   * @brief This is the set of pointers to users
   *
   * This is the atributte that contains the pointers to users.
   *
   */
  std::set<const User *, UserPtrComparator> users_;
  /**
   * @brief This method prints the user that has been deleted
   *
   * This method prints the user that has been deleted, is private method
   * becouse to print a delete user first you have to delete one. So when you
   * delete a user, this method print the user that has been deleted.
   *
   * @param user
   */
  void printDeletedUser(const User *user) const;

  std::set<const User *, UserNameComparator> getUsersSortedByName() const;
};

#endif // UsersDatabase