#include <iostream>

#include "UsersDatabase.h"
#include "UsersServer.h"
using namespace std;

int main() {
  // creamos un server de usuarios
  UsersServer usersServer;
  // Imprimimos usuarios
  usersServer.createUser("Lena", "LJ809K5ES43", "Bagumm.87¡", "admin",
                         "liselese.ratte@aol.com");
  usersServer.createUser("Lena", "LJ809K5ES43", "Bagumm.87¡", "guest",
                         "liselese.ratte@aol.com");
  cout << "*** Users created ***" << endl;
  usersServer.printUsersServer();
  cout << "---------------------" << endl;
  usersServer.deleteUser("LJ809K5ES43");
  usersServer.deleteUser("AJIJIKJIOKDDIJOIOJD");
  usersServer.loadUsersFromFile();

  usersServer.printUsersServer();
  cout << "---------------------" << endl;
  usersServer.createUser("adrian", "47552050X", "employee", "employee",
                         "adrian@example.com");
  usersServer.saveUsersToFile();
  if (usersServer.findUserLogin("adrian", "employee", "47552050X")) {
    cout << "User found" << endl;
  } else {
    cout << "User not found" << endl;
  }
  if (usersServer.findUserLogin("AAA", "employee", "47552050X")) {
    cout << "User found" << endl;
  } else {
    cout << "User not found" << endl;
  }
  cout << usersServer.getPrivileges("47552050X") << endl;
  cout << usersServer.getPrivileges("475ffX") << endl;
  usersServer.updateUser("adrian", "47552050X", "administrador", "admin",
                         "adrian3sAdminAhora");
  usersServer.printUsersServer();
  usersServer.saveUsersToFile();

  /*
  UsersServer usersServer2;
  usersServer2.loadUsersFromFile();
  std::cout << "*** Users loaded from file (SERVER 2) ***" << std::endl;
  usersServer2.printUsersServer();
  */
}
