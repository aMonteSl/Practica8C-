#include "UserAdmin.h"
#include <iostream>

// SOURCES = User.cpp mainUserAdmin.cpp UserAdmin.cpp

int main() {
  // Create a user with no name, NIF, password, privileges, and email
  // Values are assigned to the attributes using setters
  UserAdmin user1;
  user1.setName("Adrian");
  user1.setNif("234453Y");
  user1.setPassword("ORANGE_JUICE");
  user1.setEmail("adrian.adyra@gmail.com");
  // Imprimir el usuario
  user1.printUser();

  UserAdmin user2("Lena", "LJ809K5ES43", "Bagumm.87¡",
                  "liselese.ratte@aol.com");
  user2.printUser();
}