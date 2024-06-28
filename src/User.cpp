#include "User.h"

#include <iostream>

User::User() {
  name = "";
  nif = "";
  password = "";
  privileges = "";
  email = "";
}

User::User(const std::string name, const std::string nif, std::string password,
           std::string privileges, std::string email) {
  // LLamar a los metodos set para que se encarguen de hacer las conversiones
  // necesarias
  setName(name);
  setNif(nif);
  setPassword(password);
  setPrivileges(privileges);
  setEmail(email);
}

// Destructor
User::~User() {}

std::string User::getName() const { return name; }

std::string User::getNif() const { return nif; }

std::string User::getPassword() const { return password; }

std::string User::getPrivileges() const { return privileges; }

std::string User::getEmail() const { return email; }

void User::setName(std::string name) { this->name = name; }

void User::setNif(std::string nif) { this->nif = nif; }

void User::setPassword(std::string password) { this->password = password; }

void User::setPrivileges(std::string privileges) {
  for (std::string::size_type i = 0; i < privileges.length(); i++) {
    privileges[i] = toupper(privileges[i]);
  }
  this->privileges = privileges;
}

void User::setEmail(std::string email) { this->email = email; }

void User::printUser() const {
  std::cout << "----------User------------" << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "NIF: " << nif << std::endl;
  std::cout << "Password: " << password << std::endl;
  std::cout << "Privileges: " << privileges << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "--------------------------" << std::endl;
}

bool User::operator<(const User &other) const {
  return privileges > other.privileges;
}

// Devuelve true si el usuario a comparar es menor que el usuario actual para
// ello compara los privilegios
bool User::operator>(const User &other) const {
  return privileges < other.privileges;
};

// Devuelve true si el usuario a comparar es igual al usuario actual
bool User::operator==(const User &other) const { return nif == other.nif; }

// Devuelve un string con los datos del usuario
std::ostream &operator<<(std::ostream &os, const User &user) {
  os << user.getName() << " " << user.getNif() << " " << user.getPassword()
     << " " << user.getPrivileges() << " " << user.getEmail() << std::endl;
  return os;
}

// Devuelve los datos del usuario en un string
std::istream &operator>>(std::istream &is, User &user) {
  std::string privilege;
  is >> user.name >> user.nif >> user.password >> privilege >> user.email;
  user.setPrivileges(privilege);
  return is;
}
