#include "ScreenHardware.h"

#include <iostream>

#include "Hardware.h"
using namespace std;

const std::string USER_PROMPT =
    "First the name(intro), then the new password(intro), then the "
    "nif(intro), then the new role(intro), then the status(intro), "
    "then the email(intro)";

const std::string ASK_DATA = "Please enter all the data required";

ScreenHardware::ScreenHardware(bool active)
    : Hardware(active, Hardware::Types_Hardware::SCREEN) {}

ScreenHardware::~ScreenHardware() {}

void ScreenHardware::displayOutput() const {
  std::cout << "Displaying output..." << std::endl;
}

int ScreenHardware::askInput() {
  std::cout << "Screen wating a input..." << std::endl;
  return 0;
}

void ScreenHardware::initialWindow() {
  // Aqui tengo que mostrar un menu principal donde se de la bienvenida
  std::cout << "---_Initial Window_---" << std::endl;
  std::cout << "1. Login" << std::endl;
  std::cout << "2. Exit" << std::endl;
}

void ScreenHardware::exitWindow() {
  // Aqui es el menu de salida
  std::cout << "---_Exit Window_---" << std::endl;
  std::cout << "Thanks for using our system" << std::endl;
}

void ScreenHardware::loginWindow() {
  // Este es el menu de login
  std::cout << "---_Login Window_---" << std::endl;
  std::cout << ASK_DATA << std::endl;
  std::cout
      << "First the name(intro), then the password(intro), then the nif(intro)"
      << std::endl;
}

void ScreenHardware::mainWindowAdmin() {
  // Aqui tengo que mostrar un menu principal donde se muestran todas las
  // opciones para admins
  std::cout << "---_Main Window Admin_---" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de usuarios
  std::cout << "-Users Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "1. Create User" << std::endl;
  std::cout << "2. Delete User" << std::endl;
  std::cout << "3. Update User" << std::endl;
  std::cout << "4. Display Users" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de alarmas y sensores
  std::cout << "-Alarms/Sensors Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "5. Create Sensor" << std::endl;
  std::cout << "6. Delete Sensor" << std::endl;
  std::cout << "7. Display Sensors" << std::endl;
  std::cout << "8. Display Alarms" << std::endl;
  std::cout << "9. Turn On/Off Sensors/Alarms" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de camaras
  std::cout << "-Cameras Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "10. Display Cameras" << std::endl;
  std::cout << "11. Create Camera" << std::endl;
  std::cout << "12. Delete Camera" << std::endl;
  std::cout << "13. Turn On/Off Cameras" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de guardar y salir
  std::cout << "-Save/Exit Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "14. Save Cameras" << std::endl;
  std::cout << "15. Save Users" << std::endl;
  std::cout << "16. Save Sensors" << std::endl;
  std::cout << "17. Exit & Save all" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\n" << std::endl;
}

void ScreenHardware::mainWindowEmployee() {
  // Aqui tengo que mostrar un menu principal donde se muestran todas las
  // opciones para employees
  std::cout << "---_Main Window Employee_---" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de sensores y alarmas
  std::cout << "-Sensors/Alarms Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "1. Create Sensor" << std::endl;
  std::cout << "2. Delete Sensor" << std::endl;
  std::cout << "3. Display Sensors" << std::endl;
  std::cout << "4. Display Alarms" << std::endl;
  std::cout << "5. Turn On/Off Sensors/Alarms" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de camaras
  std::cout << "-Cameras Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "6. Display Cameras" << std::endl;
  std::cout << "7. Create Camera" << std::endl;
  std::cout << "8. Delete Camera" << std::endl;
  std::cout << "9. Turn On/Off Cameras" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de guardar y salir
  std::cout << "-Save/Exit Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "10. Save Cameras" << std::endl;
  std::cout << "11. Save Sensors" << std::endl;
  std::cout << "12. Exit & Save all" << std::endl;
  std::cout << "-------------------------" << std::endl;
}

void ScreenHardware::mainWindowGuest() {
  // Aqui tengo que mostrar un menu principal donde se muestran todas las
  // opciones para guests
  std::cout << "---_Main Window Guest_---" << std::endl;
  std::cout << "\n" << std::endl;
  // Seccion de sensores y alarmas
  std::cout << "-Sensors/Alarms Section-" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "1. Display Sensors" << std::endl;
  std::cout << "2. Display Alarms" << std::endl;
  std::cout << "3. Display Cameras" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "-------------------------" << std::endl;
}

void ScreenHardware::createUserWindow() {
  // Aqui tengo que mostrar un menu para crear un usuario
  std::cout << "---_Create User Window_---" << std::endl;
  std::cout << ASK_DATA << std::endl;
  std::cout << USER_PROMPT << std::endl;
}

void ScreenHardware::deleteUserWindow() {
  // Aqui tengo que mostrar un menu para borrar un usuario
  std::cout << "---_Delete User Window_---" << std::endl;
  std::cout << "First the name(intro), then the password(intro), then the "
               "nif(intro)"
            << std::endl;
}

void ScreenHardware::updateUserWindow() {
  // Aqui tengo que mostrar un menu para actualizar un usuario
  std::cout << "---_Update User Window_---" << std::endl;
  std::cout << ASK_DATA << std::endl;
  std::cout << "You can change the role / the email / if you want to change "
               "password delete the user and create a new one"
            << std::endl;
  std::cout << USER_PROMPT << std::endl;
}

void ScreenHardware::displayUsersWindow() {
  // Aqui tengo que mostrar un menu para ver todos los usuarios
  std::cout << "---_Display Users Window_---" << std::endl;
}

void ScreenHardware::createAlarmWindow() {
  // Aqui tengo que mostrar un menu para crear una alarma
  std::cout << "---_Create Alarm Window_---" << std::endl;
  std::cout << "First the type(intro), then the id(intro)" << std::endl;
}
void ScreenHardware::deleteAlarmWindow() {
  // Aqui tengo que mostrar un menu para borrar una alarma
  std::cout << "---_Delete Alarm Window_---" << std::endl;
  std::cout << "Enter the id of the alarm you want to delete" << std::endl;
}

void ScreenHardware::displaySensorsWindow() {
  // Aqui tengo que mostrar un menu para ver todos los sensores
  std::cout << "---_Display Sensors Window_---" << std::endl;
}

void ScreenHardware::displayAlarmsWindow() {
  // Aqui tengo que mostrar un menu para ver todas las alarmas
  std::cout << "---_Display Alarms Window_---" << std::endl;
}

void ScreenHardware::turnOnOffSystemWindow() {
  // Aqui tengo que mostrar un menu para encender y apagar el sistema
  std::cout << "---_Turn On/Off System Window_---" << std::endl;
  std::cout << "1. ON \n2. OFF" << std::endl;
}

void ScreenHardware::displayErrorWindow() {
  // Aqui tengo que mostrar un menu de error
  std::cout << "---_Display Error Window_---" << std::endl;
  std::cout << "And error happend" << std::endl;
}

void ScreenHardware::cleanScreen() {
  // Aqui tengo que limpiar la pantalla
  system("clear");
}

void ScreenHardware::saveAlarmWindow() {
  // Aqui tengo que mostrar un menu para guardar una alarma
  std::cout << "---_Save Alarm Window_---" << std::endl;
  std::cout << "Saving all the sensors(txt/dat)..." << std::endl;
}

void ScreenHardware::displayCameraWindow() {
  // Aqui tengo que mostrar un menu para ver la camara
  std::cout << "---_Display Camera Window_---" << std::endl;
}

void ScreenHardware::createCameraWindow() {
  // Aqui tengo que mostrar un menu para crear una camara
  std::cout << "---_Create Camera Window_---" << std::endl;
  std::cout << "Creating a new camera..." << std::endl;
}

void ScreenHardware::deleteCameraWindow() {
  // Aqui tengo que mostrar un menu para borrar una camara
  std::cout << "---_Delete Camera Window_---" << std::endl;
  std::cout << "Deleting a camera..." << std::endl;
}

void ScreenHardware::turnOnOffCameraWindow() {
  // Aqui tengo que mostrar un menu para encender y apagar la camara
  std::cout << "---_Turn On/Off Camera Window_---" << std::endl;
  std::cout << "1. ON \n2. OFF" << std::endl;
}

void ScreenHardware::saveCameraWindow() {
  // Aqui tengo que mostrar un menu para guardar una camara
  std::cout << "---_Save Camera Window_---" << std::endl;
  std::cout << "Saving all the cameras(txt)..." << std::endl;
}

void ScreenHardware::saveUsersWindow() {
  // Aqui tengo que mostrar un menu para guardar un usuario
  std::cout << "---_Save User Window_---" << std::endl;
  std::cout << "Saving all the users(txt/dat)..." << std::endl;
}