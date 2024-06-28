#include "UserAdmin.h"

UserAdmin::UserAdmin() {
  // Utilizar los setters para asignar valores a los atributos
  setName("");
  setNif("");
  setPassword("");
  setEmail("");
  setPrivileges("ADMIN");
}

UserAdmin::UserAdmin(const std::string name, const std::string nif,
                     std::string password, std::string email) {
  // Utilizar los setters para asignar valores a los atributos
  setName(name);
  setNif(nif);
  setPassword(password);
  setEmail(email);
  setPrivileges("ADMIN");
}

UserAdmin::~UserAdmin() {}