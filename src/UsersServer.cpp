#include "UsersServer.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include <set>

#include "Exceptions.h"
#include "UsersDatabase.h"

using namespace std;

// Constructor, el sevidor al construirse guardara en su base de datos tres
// usuarios de casa tipo
UsersServer::UsersServer() {
  // Creamos tres usuarios por defecto
  createUser("admin", "12345678X", "admin", "ADMIN", "admin@example.com");
  createUser("employee", "12345678Y", "employee", "EMPLOYEE",
             "employee@example.com");
  createUser("guest", "12345678Z", "guest", "GUEST", "guest@example.com");
}

UsersServer::~UsersServer() {
  // Esto destruira el set de punteros de la base de datos
}

void UsersServer::createUser(const std::string name, const std::string nif,
                             const std::string password,
                             const std::string privileges,
                             const std::string email) {
  // Debe de crear el usuario y añadir el puntero al set de usuarios
  User *user = new User(name, nif, password, privileges, email);
  usersDatabase_.addUser(user);
}

void UsersServer::deleteUser(const std::string nif) {
  usersDatabase_.deleteUserByNif(nif);
}

std::string UsersServer::getPrivileges(std::string nif) {
  User *user = usersDatabase_.findUserByNif(nif);
  if (user != nullptr) {
    return user->getPrivileges();
  } else {
    return "GUEST";
  }
}

bool UsersServer::findUserLogin(std::string name, std::string password,
                                std::string nif) {
  // Debemos de buscar encontrar a un usuario por su nombre, contraseña y nif
  // Si tienen el mismo puntero devolver true, si no false
  if (usersDatabase_.findUserByNif(nif) != nullptr) {
    if (usersDatabase_.findUserByNif(nif)->getName() == name &&
        usersDatabase_.findUserByNif(nif)->getPassword() == password) {
      return true;
    }
  }

  return false;
}

void UsersServer::updateUser(const std::string name, const std::string nif,
                             const std::string password,
                             const std::string privileges,
                             const std::string email) {
  User *userToUpdate = usersDatabase_.findUserByNif(nif);
  // Si el usuario existe, y los privilegios que se quieren cambiar
  // isValidPrivileges entonces se cambian los privilegios y el email
  if (userToUpdate != nullptr && usersDatabase_.isValidPrivileges(privileges)) {
    userToUpdate->setPrivileges(privileges);
    userToUpdate->setEmail(email);
  } else {
    std::cout << "User dosen't change, maybe correct privileges" << std::endl;
  }
}

void UsersServer::printUsersServer() const {
  this->usersDatabase_.printUsers();
}

void UsersServer::readUsersFromFileBi() {
  std::cout << "Reading users from file " << fileNameBi_ << "..." << std::endl;

  std::ifstream file(fileNameBi_, std::ios::binary);
  if (file.is_open()) {
    while (file) {
      User *user = new User();

      // Read the user name
      size_t nameLength;
      file.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
      if (!file) {
        delete user;
        break;
      }
      char *name = new char[nameLength];
      file.read(name, nameLength);
      if (!file) {
        delete[] name;
        delete user;
        break;
      }
      user->setName(std::string(name, nameLength));
      delete[] name;

      // Read the user nif
      size_t nifLength;
      file.read(reinterpret_cast<char *>(&nifLength), sizeof(nifLength));
      if (!file) {
        delete user;
        break;
      }
      char *nif = new char[nifLength];
      file.read(nif, nifLength);
      if (!file) {
        delete[] nif;
        delete user;
        break;
      }
      user->setNif(std::string(nif, nifLength));
      delete[] nif;

      // Read the user password
      size_t passwordLength;
      file.read(reinterpret_cast<char *>(&passwordLength),
                sizeof(passwordLength));
      if (!file) {
        delete user;
        break;
      }
      char *password = new char[passwordLength];
      file.read(password, passwordLength);
      if (!file) {
        delete[] password;
        delete user;
        break;
      }
      user->setPassword(std::string(password, passwordLength));
      delete[] password;

      // Read the user privileges
      size_t privilegesLength;
      file.read(reinterpret_cast<char *>(&privilegesLength),
                sizeof(privilegesLength));
      if (!file) {
        delete user;
        break;
      }
      char *privileges = new char[privilegesLength];
      file.read(privileges, privilegesLength);
      if (!file) {
        delete[] privileges;
        delete user;
        break;
      }
      user->setPrivileges(std::string(privileges, privilegesLength));
      delete[] privileges;

      // Read the user email
      size_t emailLength;
      file.read(reinterpret_cast<char *>(&emailLength), sizeof(emailLength));
      if (!file) {
        delete user;
        break;
      }
      char *email = new char[emailLength];
      file.read(email, emailLength);
      if (!file) {
        delete[] email;
        delete user;
        break;
      }
      user->setEmail(std::string(email, emailLength));
      delete[] email;

      if (file.eof()) {
        delete user; // prevent adding incomplete user due to eof
        break;
      }

      std::cout << "Read user: " << user->getName() << "-" << user->getNif()
                << "-" << user->getPrivileges() << std::endl;
      usersDatabase_.addUser(user);
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for reading." << std::endl;
  }
}

void UsersServer::readUsersFromFileTxt() {
  std::cout << "Loading users from file " << fileNameTxt_ << "..." << std::endl;
  try {
    std::ifstream file(fileNameTxt_);

    if (!file.good()) {
      file.close();
      throw FileNotFoundError(fileNameTxt_);
    }
    if (!file.is_open()) {
      throw FileOpenError(fileNameTxt_);
    }

    std::string name, nif, password, privileges, email;
    while (file >> name >> nif >> password >> privileges >> email) {
      std::cout << "Read user: " << name << " " << nif << " " << password << " "
                << privileges << " " << email << std::endl;
      createUser(name, nif, password, privileges, email);
    }

    file.close();

    if (file.is_open()) {
      throw FileCloseError(fileNameTxt_);
    }
  } catch (std::exception &e) {
    // std::cerr << e.what() << std::endl;
    throw;
  }
}

void UsersServer::loadUsersFromFile() {
  // Cargo los usuarios del archivo
  // Siguiendo el formato de nombre nif password privilegios email

  try {
    // readUsersFromFileTxt();
    readUsersFromFileBi();
  } catch (FileReadError &e) {
    std::cerr << e.what() << std::endl;

  } catch (FileCloseError &e) {
    std::cerr << e.what() << std::endl;

  } catch (FileOpenError &e) {
    std::cerr << e.what() << std::endl;

  } catch (FileNotFoundError &e) {
    std::cerr << e.what() << std::endl;
  }

  /*
  if (file.is_open()) {
    std::string name, nif, password, privileges, email;
    while (file >> name >> nif >> password >> privileges >> email) {
      createUser(name, nif, password, privileges, email);
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for reading." << std::endl;
  }
  */
}

void UsersServer::writeUserToFileBi() {
  std::cout << "Saving users to file " << fileNameBi_ << "..." << std::endl;

  std::ofstream file(fileNameBi_, std::ios::binary | std::ios::trunc);
  // Tengo que guardar los usuarios en un archivo binario, recorriendo el set de
  // usuarios Los guardaremos en el binario siguiendo el formato de nombre nif
  // password privilegios email y cuando se lea se leera en el mismo formato
  if (file.is_open()) {
    for (const User *user : usersDatabase_.getUsers()) {

      // Guardar el nombre
      size_t nameLength = user->getName().length();
      file.write(reinterpret_cast<const char *>(&nameLength),
                 sizeof(nameLength));
      file.write(user->getName().c_str(), nameLength);

      // Guardar el nif
      size_t nifLength = user->getNif().length();
      file.write(reinterpret_cast<const char *>(&nifLength), sizeof(nifLength));
      file.write(user->getNif().c_str(), nifLength);

      // Guardar el password
      size_t passwordLength = user->getPassword().length();
      file.write(reinterpret_cast<const char *>(&passwordLength),
                 sizeof(passwordLength));
      file.write(user->getPassword().c_str(), passwordLength);

      // Guardar el privilegios
      size_t privilegesLength = user->getPrivileges().length();
      file.write(reinterpret_cast<const char *>(&privilegesLength),
                 sizeof(privilegesLength));
      file.write(user->getPrivileges().c_str(), privilegesLength);

      // Guardar el email
      size_t emailLength = user->getEmail().length();
      file.write(reinterpret_cast<const char *>(&emailLength),
                 sizeof(emailLength));
      file.write(user->getEmail().c_str(), emailLength);

      // Imprimir el usuario que se ha guardado
      std::cout << "User saved: " << user->getName() << "-" << user->getNif()
                << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for writing." << std::endl;
  }
}

void UsersServer::writeUserToFileTxt() {
  std::cout << "Saving users to file " << fileNameTxt_ << "..." << std::endl;

  try {
    std::ofstream file(fileNameTxt_);
    if (!file.good()) {
      file.close();
      throw FileNotFoundError(fileNameTxt_);
    }
    if (!file.is_open()) {
      throw FileOpenError(fileNameTxt_);
    }

    // Write users to file
    for (const User *user : usersDatabase_.getUsers()) {
      file << user->getName() << " " << user->getNif() << " "
           << user->getPassword() << " " << user->getPrivileges() << " "
           << user->getEmail() << std::endl;
      std::cout << "User saved: " << user->getName() << "-" << user->getNif()
                << std::endl;
    }

    // Close the file
    file.close();

    // Check if file was closed properly
    if (file.is_open()) {
      throw FileCloseError(fileNameTxt_);
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void UsersServer::saveUsersToFile() {
  // Guardo los usuarios en el archivo

  try {
    writeUserToFileTxt();
    writeUserToFileBi();
  } catch (FileOpenError &e) {
    std::cerr << e.what() << std::endl;

  } catch (FileCloseError &e) {
    std::cerr << e.what() << std::endl;

  } catch (FileWriteError &e) {
    std::cerr << e.what() << std::endl;

  } catch (FileNotFoundError &e) {
    std::cerr << e.what() << std::endl;
  }
  /*
  std::cout << "Saving users to file..." << std::endl;
  std::ofstream file(fileNameTxt_);
  if (file.is_open()) {
    for (const User *user : usersDatabase_.getUsers()) {
      file << user->getName() << " " << user->getNif() << " "
           << user->getPassword() << " " << user->getPrivileges() << " "
           << user->getEmail() << std::endl;
      std::cout << "User saved: " << user->getName() << "-" << user->getNif()
                << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for writing." << std::endl;
  }
  */
}
