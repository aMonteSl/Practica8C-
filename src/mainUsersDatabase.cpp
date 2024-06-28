#include <iostream>

#include "UserAdmin.h"
#include "UserEmployee.h"
#include "UserGuest.h"
#include "UsersDatabase.h"

int main() {
  // Crear una instancia de UsersDatabase
  UsersDatabase usersDatabase;

  // Agregar un alumno de cada tipo
  usersDatabase.addUser(
      new UserAdmin("Lena", "LJ809K5ES43", "Bagumm.87¡", "correoDeAdmin"));
  usersDatabase.addUser(
      new UserEmployee("PEPE", "NIFPEPE", "hhhhheh.rrrrr", "correoDeEmpleado"));
  usersDatabase.addUser(new UserGuest(
      "Juan", "slslslMINIFG", "sssdsdqadqwddddrrwwwrrr", "correoDeInvitado"));
  usersDatabase.addUser(new UserGuest(
      "Juan", "slslslMINIFG", "sssdsdqadqwddddrrwwwrrr", "correoDeInvitado"));
  usersDatabase.addUser(new UserGuest(
      "Sujeto -1", "-1", "sssdsdqadqwddddrrwwwrrr", "correoDeInvitado"));
  usersDatabase.addUser(new UserGuest(
      "Sujeto 1", "1", "sssdsdqadqwddddrrwwwrrr", "correoDeInvitado"));
  usersDatabase.addUser(new UserGuest(
      "Sujeto 2", "2", "sssdsdqadqwddddrrwwwrrr", "correoDeInvitado"));
  usersDatabase.addUser(
      new UserGuest("Sujeto 0", "0", "sssdsdqadqwddddrrwwwrrr", "correo0"));

  // Imprimir los usuarios
  usersDatabase.printUsers();

  // Obtener una copia de los usuarios
  UsersDatabase usersDatabaseCopy;
  std::set<const User *, UserPtrComparator> usersCopy =
      usersDatabase.getUsers();
  usersDatabaseCopy.setUsers(usersCopy);
  std::cout
      << "\n\n------------------------------------------------------\n\n\n"
      << std::endl;

  usersDatabaseCopy.printUsers();

  // Intentamos encontrar un usuario
  User *user = usersDatabaseCopy.findUser(
      UserAdmin("Lena", "LJ809K5ES43", "Bagumm.87¡", "correoDeAdmin"));
  if (user) {
    std::cout << "User found" << std::endl;
  } else {
    std::cout << "User not found" << std::endl;
  }

  // Intentamos encontrar un usuario por nombre
  user = usersDatabaseCopy.findUserByName("d");
  if (user) {
    std::cout << "User found" << std::endl;
  } else {
    std::cout << "User not found" << std::endl;
  }

  // Intentamos encontrar un usuario por NIF
  user = usersDatabaseCopy.findUserByNif("slslslMINIFG");
  if (user) {
    std::cout << "User found" << std::endl;
  } else {
    std::cout << "User not found" << std::endl;
  }

  // Intentamos encontrar un usuario por correo electrónico
  user = usersDatabaseCopy.findUserByEmail("correoDeInvitado");
  if (user) {
    std::cout << "User found" << std::endl;
  } else {
    std::cout << "User not found" << std::endl;
  }

  // Borrar un usuario
  usersDatabase.deleteUser(
      UserAdmin("Lena", "LJ809K5ES43", "Bagumm.87¡", "correoDeAdmin"));

  // Borrar por nombre
  usersDatabase.deleteUserByName("PEPE");

  // Borrar por NIF
  usersDatabase.deleteUserByNif("2");
  usersDatabase.deleteUserByNif("2");

  // Borrar por correo electrónico
  usersDatabase.deleteUserByEmail("correo0");

  std::cout
      << "\n\n------------------------------------------------------\n\n\n"
      << std::endl;

  // Imprimir los usuarios
  usersDatabase.printUsers();

  return 0;
}
