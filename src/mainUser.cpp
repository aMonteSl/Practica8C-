#include <iostream>

#include "User.h"
using namespace std;

int main() {
  // Create a user with no name, NIF, password, privileges, and email
  // Values are assigned to the attributes using setters
  User user1;
  user1.setName("Adrian");
  user1.setNif("234453Y");
  user1.setPassword("ORANGE_JUICE");
  user1.setEmail("correoDeAdrian@potatoe.com");
  user1.setPrivileges("admin");
  // Print each attribute separately using getters
  cout << "Name: " << user1.getName() << endl;
  cout << "NIF: " << user1.getNif() << endl;
  cout << "Password: " << user1.getPassword() << endl;
  cout << "Privileges: " << user1.getPrivileges() << endl;
  cout << "Email: " << user1.getEmail() << endl;

  User user2("Lena", "LJ809K5ES43", "Bagumm.87¡", "guest",
             "liselese.ratte@aol.com");
  user2.printUser();

  // Compare users
  // If user 1 is greater than user 2 (privileges)
  if (user1.operator>(user2)) {
    cout << "The user " << user1.getName() << " has higher rank than "
         << user2.getName() << endl;
  } else {
    cout << "User " << user1.getName() << " has lower rank than "
         << user2.getName() << endl;
  }

  if (user1.operator<(user2)) {
    cout << "The user " << user1.getName() << " has lower rank than "
         << user2.getName() << endl;
  } else {
    cout << "User " << user1.getName() << " has higher rank than "
         << user2.getName() << endl;
  }

  // If user 1 is equal to user 2 (NIF)
  if (user1.operator==(user2)) {
    cout << "User " << user1.getName() << " is equal to user "
         << user2.getName() << endl;
  } else {
    cout << "User " << user1.getName() << " is NOT equal to user "
         << user2.getName() << endl;
  }
  // If user 1 is equal to user 1 (name, NIF, and password)
  if (user1.operator==(user1)) {
    cout << "User " << user1.getName() << " is equal to user "
         << user1.getName() << endl;
  } else {
    cout << "User " << user1.getName() << " is NOT equal to user "
         << user1.getName() << endl;
  }

  // Print a user using std::ostream
  User user3("Carlos", "010303403L", "1234_password", "employee",
             "carlos_sainz@gmail.com");
  cout << "PRINT USER WITH std::ostream" << endl;
  cout << user3 << endl;

  // Create a user using std::istream
  User user4;
  std::cout << "CREATE USER WITH std::istream" << endl;
  std::cout << "NAME, NIF, PASSWORD, PRIVILEGES, EMAIL" << endl;
  cin >> user4;
  user4.printUser();
  cout << "PRINT USER WITH std::ostream" << endl;
  cout << user4 << endl;

  return 0;
}
