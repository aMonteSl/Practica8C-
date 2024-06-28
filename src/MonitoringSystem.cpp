#include "MonitoringSystem.h"

#include <iostream>

#include "KeyboardHardware.h"
#include "ScreenHardware.h"
#include "SwitchHardware.h"
using namespace std;

const int MAIN_MENU_OPTIONS = 2;
const int ADMIN_MENU_OPTIONS = 17;
const int EMPLOYEE_MENU_OPTIONS = 12;
const int GUEST_MENU_OPTIONS = 4;

MonitoringSystem::MonitoringSystem(ScreenHardware *screen,
                                   KeyboardHardware *keyboard,
                                   SwitchHardware *sw)
    : screen(screen), keyboard(keyboard), sw(sw) {}

MonitoringSystem::~MonitoringSystem() {
  delete screen;
  delete keyboard;
  delete sw;
}

int MonitoringSystem::getSelection() { return selection_; }

void MonitoringSystem::selectUser() {
  nameSelectedUser_ = askName();
  passwordSelectedUser_ = askPassword();
  nifSelectedUser_ = askNIF();
  privilegesSelectedUser_ = askPrivileges();
  emailSelectedUser_ = askEmail();
}

void MonitoringSystem::shortSelectUser() {
  nameSelectedUser_ = askName();
  passwordSelectedUser_ = askPassword();
  nifSelectedUser_ = askNIF();
}

void MonitoringSystem::askMainUser() {
  name_ = askName();
  password_ = askPassword();
  nif_ = askNIF();
}

std::string MonitoringSystem::getTypeAlarm() { return typeAlarm_; }

int MonitoringSystem::getIdAlarm() { return idAlarm_; }

int MonitoringSystem::getIdSelectedAlarm() { return idSelectedAlarm_; }

std::string MonitoringSystem::getName() { return name_; }

std::string MonitoringSystem::getNIF() { return nif_; }

std::string MonitoringSystem::getPassword() { return password_; }

std::string MonitoringSystem::getNameSelectedUser() {
  return nameSelectedUser_;
}

std::string MonitoringSystem::getNIFSelectedUser() { return nifSelectedUser_; }

std::string MonitoringSystem::getPasswordSelectedUser() {
  return passwordSelectedUser_;
}

std::string MonitoringSystem::getPrivilegesSelectedUser() {
  return privilegesSelectedUser_;
}

std::string MonitoringSystem::getEmailSelectedUser() {
  return emailSelectedUser_;
}

bool MonitoringSystem::inputCorrect(int input, int max) {
  bool correct = input >= 1 && input <= max;
  if (!correct) {
    cout << "Invalid input. Please enter an integer that corresponds to one of "
            "the options"
         << endl;
  }
  // Input debe de estar entre 1 y max
  return correct;
}

int MonitoringSystem::askInputInt(int max) {
  int input;

  do {
    input = keyboard->askInput();
  } while (!inputCorrect(input, max));

  return input;
}

void MonitoringSystem::initialScreen() {
  screen->cleanScreen();
  int options = MAIN_MENU_OPTIONS;
  // Muestro de screen la initialWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->initialWindow();
  selection_ = askInputInt(options);
}

void MonitoringSystem::exitScreen() {
  // Borrar terminal y mostrar el exitWindow
  screen->cleanScreen();
  screen->exitWindow();
}

std::string MonitoringSystem::askName() {
  std::cout << "(NAME) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askPassword() {
  std::cout << "(PASSWORD) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askNIF() {
  std::cout << "(NIF) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askPrivileges() {
  std::cout << "(PRIVILEGES) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askEmail() {
  std::cout << "(EMAIL) ";
  return keyboard->stringInput();
}

void MonitoringSystem::loginScreen() {
  // Muestro de screen la loginWindow, luego pido con el keyboard un input hasta
  // que este entre los valores correctos
  screen->cleanScreen();
  screen->loginWindow();
  askMainUser();
  // std::cout << name_ << " " << password_ << " " << nif_ << endl;
}

void MonitoringSystem::mainWindowAdmin() {
  // Muestro de screen la mainWindowAdmin, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->cleanScreen();
  int options = ADMIN_MENU_OPTIONS;
  screen->mainWindowAdmin();
  selection_ = askInputInt(options);
}

void MonitoringSystem::mainWindowEmployee() {
  // Muestro de screen la mainWindowEmployee, luego pido con el keyboard un
  // input hasta que este entre los valores correctos
  screen->cleanScreen();
  int options = EMPLOYEE_MENU_OPTIONS;
  screen->mainWindowEmployee();
  selection_ = askInputInt(options);
}

void MonitoringSystem::mainWindowGuest() {
  // Muestro de screen la mainWindowGuest, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->cleanScreen();
  int options = GUEST_MENU_OPTIONS;
  screen->mainWindowGuest();
  selection_ = askInputInt(options);
}

// Opciones del menu

void MonitoringSystem::createUserScreen() {
  // Muestro de screen la createUserWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->cleanScreen();
  screen->createUserWindow();
  selectUser();
}

void MonitoringSystem::deleteUserScreen() {
  // Muestro de screen la deleteUserWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->cleanScreen();
  screen->deleteUserWindow();
  shortSelectUser();
}

void MonitoringSystem::updateUserScreen() {
  // Muestro de screen la updateUserWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->cleanScreen();
  screen->updateUserWindow();
  selectUser();
}

void MonitoringSystem::displayUsersScreen() {
  // Muestro de screen la displayUsersWindow
  screen->cleanScreen();
  screen->displayUsersWindow();
  // keyboard->stringInput();
}

void MonitoringSystem::displaySensorsScreen() {
  // Muestro de screen la displaySensorsWindow
  screen->cleanScreen();
  screen->displaySensorsWindow();
  // keyboard->stringInput();
}

void MonitoringSystem::displayAlarmsScreen() {
  // Muestro de screen la displayAlarmsWindow
  screen->cleanScreen();
  screen->displayAlarmsWindow();
  // keyboard->stringInput();
}

void MonitoringSystem::turnOnOffSystemScreen() {
  // Muestro de screen la turnOnOffSystemWindow
  screen->cleanScreen();
  int options = 2;
  screen->turnOnOffSystemWindow();
  selection_ = askInputInt(options);
}

void MonitoringSystem::displayErrorScreen() {
  // Muestro de screen la displayErrorWindow
  screen->cleanScreen();
  screen->displayErrorWindow();
  keyboard->stringInput();
  exitScreen();
}

std::string MonitoringSystem::askTypeAlarm() {
  std::cout << "(TYPE ALARM) ";
  return keyboard->stringInput();
}

int MonitoringSystem::askIdAlarm() {
  std::cout << "(ID ALARM) ";
  return keyboard->askInput();
}

void MonitoringSystem::createAlarmScreen() {
  // Muestro de screen la createAlarmWindow
  screen->cleanScreen();
  screen->createAlarmWindow();
  typeAlarm_ = askTypeAlarm();
  idAlarm_ = askIdAlarm();
}

void MonitoringSystem::deleteAlarmScreen() {
  // Muestro de screen la deleteAlarmWindow
  screen->cleanScreen();
  screen->deleteAlarmWindow();
  idSelectedAlarm_ = askIdAlarm();
}

void MonitoringSystem::saveAlarmScreen() {
  // Muestro de screen la saveAlarmWindow
  screen->cleanScreen();
  screen->saveAlarmWindow();
}

std::string MonitoringSystem::getTypeCamera() { return typeCamera_; }

int MonitoringSystem::getIdCamera() { return idCamera_; }

int MonitoringSystem::getIdSelectedCamera() { return idSelectedCamera_; }

void MonitoringSystem::displayCameraScreen() {
  // Muestro de screen la displayCameraWindow
  screen->cleanScreen();
  screen->displayCameraWindow();
}

std::string MonitoringSystem::askTypeCamera() {
  // Pido con el keyboard un input que sera el tipo de la camara
  std::cout << "(TYPE CAMERA) ";
  return keyboard->stringInput();
}

int MonitoringSystem::askIdCamera() {
  // Pido con el keyboard un input que sera el id de la camara
  std::cout << "(ID CAMERA) ";
  return keyboard->askInput();
}

void MonitoringSystem::createCameraScreen() {
  // Muestro de screen la createCameraWindow
  screen->cleanScreen();
  screen->createCameraWindow();
  idCamera_ = askIdCamera();
  typeCamera_ = askTypeCamera();
}

void MonitoringSystem::deleteCameraScreen() {
  // Muestro de screen la deleteCameraWindow
  screen->cleanScreen();
  screen->deleteCameraWindow();
  idSelectedCamera_ = askIdCamera();
}

void MonitoringSystem::turnOnOffCameraScreen() {
  // Muestro de screen la turnOnOffCameraWindow
  screen->cleanScreen();
  int options = 2;
  screen->turnOnOffCameraWindow();
  selection_ = askInputInt(options);
}

void MonitoringSystem::saveCameraScreen() {
  // Muestro de screen la saveCameraWindow
  screen->cleanScreen();
  screen->saveCameraWindow();
}

void MonitoringSystem::cleanScreen() {
  // Muestro de screen la cleanScreen
  screen->cleanScreen();
}

void MonitoringSystem::saveUsersScreen() {
  // Muestro de screen la saveUsersWindow
  screen->cleanScreen();
  screen->saveUsersWindow();
}