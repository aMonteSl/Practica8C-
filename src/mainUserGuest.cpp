#include "UserGuest.h"
#include <iostream>

// SOURCES = User.cpp mainUserGuest.cpp UserGuest.cpp

int main() {
  UserGuest user1("Adrian", "234453Y", "ORANGE_JUICE", "correo");
  user1.printUser();

  UserGuest user2;
  user2.setName("Lena");
  user2.setNif("LJ809K5ES43");
  user2.setPassword("Bagumm.87¡");
  user2.setEmail("correo2");
  user2.printUser();

  return 0;
}