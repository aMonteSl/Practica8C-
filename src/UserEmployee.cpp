#include "UserEmployee.h"

UserEmployee::UserEmployee() {
  // Utilizar los setters para asignar valores a los atributos
  setName("");
  setNif("");
  setPassword("");
  setEmail("");
  setPrivileges("EMPLOYEE");
}

UserEmployee::UserEmployee(const std::string name, const std::string nif,
                           std::string password, std::string email) {
  // Utilizar los setters para asignar valores a los atributos
  setName(name);
  setNif(nif);
  setPassword(password);
  setEmail(email);
  setPrivileges("EMPLOYEE");
}

UserEmployee::~UserEmployee() {}