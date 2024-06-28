#include "UsersDatabase.h"

#include <fstream>
#include <iostream>
#include <new>
#include <set>
#include <string>

#include "UserAdmin.h"
#include "UserEmployee.h"
#include "UserGuest.h"

UsersDatabase::UsersDatabase() {}

UsersDatabase::~UsersDatabase() {
  // Liberar la memoria de los usuarios
  for (auto user : users_) {
    delete user;
  }
}

bool UsersDatabase::isValidPrivileges(const std::string privileges) const {
  // Compruebo si los privilegios son validos
  return privileges == "ADMIN" || privileges == "EMPLOYEE" ||
         privileges == "GUEST";
}

void UsersDatabase::addUser(const User *user) {
  // Intento añadir un usuario al set de usuarios si no existe, si existe no lo
  // añado y llamo a su destructor, tambien tiene que tener unos privilegios
  // validos

  if (findUserByNif(user->getNif()) == nullptr &&
      (isValidPrivileges(user->getPrivileges()))) {
    users_.insert(user);
  } else {
    if (!isValidPrivileges(user->getPrivileges())) {
      std::cout << "Privileges are not valid (ADMIN/EMPLOYEE/GUEST)"
                << std::endl;
    } else {
      std::cout << "User already exists" << std::endl;
    }
    delete user;
  }
}

std::set<const User *, UserPtrComparator> UsersDatabase::getUsers() const {
  return users_;
}

void UsersDatabase::setUsers(
    const std::set<const User *, UserPtrComparator> &users) {
  // El set users debe de convertir los punteros de usuarios a Objetos de
  // usuarios y luego añadirlos al set de usuarios Bucle para convertirlos en
  // objetos usuario
  for (auto user : users) {
    try {
      if (user->getPrivileges() == "ADMIN") {
        users_.insert(new UserAdmin(*static_cast<const UserAdmin *>(user)));
      } else if (user->getPrivileges() == "EMPLOYEE") {
        users_.insert(
            new UserEmployee(*static_cast<const UserEmployee *>(user)));
      } else if (user->getPrivileges() == "GUEST") {
        users_.insert(new UserGuest(*static_cast<const UserGuest *>(user)));
      } else {
        std::cerr << "Unknown user privilege: " << user->getPrivileges()
                  << '\n';
      }
    } catch (std::bad_alloc &ba) {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
      // Borrar el usuario que no se ha podido añadir
      delete user;
      throw;
    }
  }
}

User *UsersDatabase::findUser(const User &user) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::set<const User *, UserPtrComparator>::const_iterator it =
           users_.begin();
       it != users_.end(); it++) {
    if (*(*it) == user) {
      return const_cast<User *>(*it);
    }
  }

  return nullptr;
}

User *UsersDatabase::findUserByName(const std::string name) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::set<const User *, UserPtrComparator>::const_iterator it =
           users_.begin();
       it != users_.end(); it++) {
    if ((*it)->getName() == name) {
      return const_cast<User *>(*it);
    }
  }

  return nullptr;
}

User *UsersDatabase::findUserByNif(const std::string nif) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::set<const User *, UserPtrComparator>::const_iterator it =
           users_.begin();
       it != users_.end(); it++) {
    if ((*it)->getNif() == nif) {
      return const_cast<User *>(*it);
    }
  }

  return nullptr;
}

User *UsersDatabase::findUserByPassword(const std::string password) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::set<const User *, UserPtrComparator>::const_iterator it =
           users_.begin();
       it != users_.end(); it++) {
    if ((*it)->getPassword() == password) {
      return const_cast<User *>(*it);
    }
  }

  return nullptr;
}

User *UsersDatabase::findUserByEmail(const std::string email) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::set<const User *, UserPtrComparator>::const_iterator it =
           users_.begin();
       it != users_.end(); it++) {
    if ((*it)->getEmail() == email) {
      return const_cast<User *>(*it);
    }
  }

  return nullptr;
}

void UsersDatabase::deleteUser(const User &user) {
  for (std::set<const User *>::iterator it = users_.begin(); it != users_.end();
       it++) {
    // Si encuentro el usuario lo borro y también el puntero con el destructor
    // de la clase User
    if (*(*it) == user) {
      printDeletedUser(*it);
      delete *it; // Llama al destructor de User y libera la memoria
      users_.erase(it);
      return;
    }
  }

  std::cout << "User not found" << std::endl;
  std::cout << std::endl;
}

void UsersDatabase::deleteUserByName(const std::string name) {
  for (std::set<const User *>::iterator it = users_.begin(); it != users_.end();
       it++) {
    // Si esta el usuario lo borro y tambien borro el puntero
    if ((*it)->getName() == name) {
      printDeletedUser(*it);
      delete *it; // Llama al destructor de User y libera la memoria
      users_.erase(it);
      return;
    }
  }
  std::cout << "User not found" << std::endl;
  std::cout << std::endl;
}

void UsersDatabase::deleteUserByNif(const std::string nif) {
  for (std::set<const User *>::iterator it = users_.begin(); it != users_.end();
       it++) {
    if ((*it)->getNif() == nif) {
      printDeletedUser(*it);
      delete *it; // Llama al destructor de User y libera la memoria
      users_.erase(it);
      return;
    }
  }

  std::cout << "User not found" << std::endl;
  std::cout << std::endl;
}

void UsersDatabase::deleteUserByEmail(const std::string email) {
  for (std::set<const User *>::iterator it = users_.begin(); it != users_.end();
       it++) {
    if ((*it)->getEmail() == email) {
      printDeletedUser(*it);
      delete *it; // Llama al destructor de User y libera la memoria
      users_.erase(it);
      return;
    }
  }

  std::cout << "User not found" << std::endl;
  std::cout << std::endl;
}

void UsersDatabase::printUsers() const {
  std::cout << "*** LIST OF USERS ***" << std::endl;
  // Imprimir todos los usuarios
  /*
  for (auto it = users_.rbegin(); it != users_.rend(); ++it) {
    (*it)->printUser();
    std::cout << std::endl;
  }
  */
  for (const auto &user : users_) {
    (*user).printUser();
    std::cout << std::endl;
  }

  std::cout << "*** END OF LIST ***" << std::endl;
}

void UsersDatabase::printDeletedUser(const User *user) const {
  std::cout << "User deleted: " << (*user).getName() << "-" << (*user).getNif()
            << std::endl;
  std::cout << std::endl;
}

std::set<const User *, UserNameComparator> UsersDatabase::getUsersSortedByName() const {
  std::set<const User *, UserNameComparator> sortedUsers(users_.begin(), users_.end());
  return sortedUsers;
}