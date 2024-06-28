#include <iostream>

#include "ScreenHardware.h"
using namespace std;

int main() {
  ScreenHardware screenHardware(true);
  if (screenHardware.isActive()) {
    std::cout << "Active" << std::endl;
  } else {
    std::cout << "No Active" << std::endl;
  }
  // apagamos
  screenHardware.turnOff();
  std::cout << screenHardware.stringStatus() << std::endl;
  // encnedemos
  screenHardware.turnOn();
  std::cout << screenHardware.stringStatus() << std::endl;
  // Ahora mostramos cada tipo de pantalla para comprobar que funciona
  screenHardware.initialWindow();
  screenHardware.loginWindow();
  screenHardware.mainWindowAdmin();
  screenHardware.mainWindowEmployee();
  screenHardware.mainWindowGuest();
  screenHardware.createUserWindow();
  screenHardware.deleteUserWindow();
  screenHardware.updateUserWindow();
  screenHardware.displayUsersWindow();
  screenHardware.displaySensorsWindow();
  screenHardware.displayAlarmsWindow();
  screenHardware.turnOnOffSystemWindow();
  screenHardware.displayErrorWindow();
  screenHardware.exitWindow();
}