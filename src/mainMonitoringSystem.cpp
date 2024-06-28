#include <iostream>

#include "KeyboardHardware.h"
#include "MonitoringSystem.h"
#include "ScreenHardware.h"
#include "SwitchHardware.h"
using namespace std;

int main() {
  // Creo un MonitoringSystem
  MonitoringSystem *ms =
      new MonitoringSystem(new ScreenHardware(true), new KeyboardHardware(true),
                           new SwitchHardware(true));
  // Llamo a la funcion initialScreen() que muestra el menu inicial
  ms->initialScreen();
  if (ms->getSelection() == 1) {
    ms->loginScreen();
    // (SUponemos que ha entrado bien el usuario y que es admin)
    bool exit = false;
    do {
      ms->mainWindowAdmin();
      // Ahora probamos la ventana de employee
      // ms->mainWindowEmployee();
      // Ahora probamos la ventana de guest
      // ms->mainWindowGuest();
      if (ms->getSelection() == 1) {
        ms->createUserScreen();
      } else if (ms->getSelection() == 2) {
        ms->deleteUserScreen();
      } else if (ms->getSelection() == 3) {
        ms->updateUserScreen();
      } else if (ms->getSelection() == 4) {
        ms->displayUsersScreen();
      } else if (ms->getSelection() == 5) {
        ms->displaySensorsScreen();
      } else if (ms->getSelection() == 6) {
        ms->displayAlarmsScreen();
      } else if (ms->getSelection() == 7) {
        ms->turnOnOffSystemScreen();
      } else if (ms->getSelection() == 8) {
        ms->exitScreen();
        exit = true;
      }
    } while (!exit);

    /*ms->createUserScreen();
    ms->deleteUserScreen();
    ms->updateUserScreen();
    ms->displayUsersScreen();
    ms->displaySensorsScreen();
    ms->displayAlarmsScreen();
    ms->turnOnOffSystemScreen();
    ms->displayErrorScreen();*/
  } else {
    // Llamo a la funcion exitScreen() que muestra el exitWindow
    ms->exitScreen();
  }

  return 0;
}
