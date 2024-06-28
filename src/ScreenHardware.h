#ifndef SCREENHARDWARE_H
#define SCREENHARDWARE_H
#include "Hardware.h"

/**
 * @file ScreenHardware.h
 * @brief This is the class ScreenHardware. It contains the attributes and
 * methods of the ScreenHardware class, this class is a child of the Hardware
 * class. This class is used to display the output of the system and ask for an
 * input before with the keyboard.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class ScreenHardware : public Hardware {
public:
  /**
   * @brief Construct a new Screen Hardware object
   *
   * @param active
   * @return ScreenHardware object
   */
  explicit ScreenHardware(bool active);
  /**
   * @brief Destroy the Screen Hardware object
   *
   */
  ~ScreenHardware() override;
  /**
   * @brief This method displays the output of the system
   *
   */
  void displayOutput() const override;
  /**
   * @brief Ask for an input to the user (this method in reality is not used, we
   * use the keyboard to ask for an input)
   *
   * @return int
   */
  int askInput() override;

  // All the windows of the system
  /**
   * @brief This method displays the initial window of the system
   *
   */

  void
  initialWindow(); // Funcion que muestra la ventana principal (espera que se
                   // le de a intro para continuar, cuando se le de a intro
                   // muestra la ventana de login y arranca todos los sensores)
  /**
   * @brief This method displays the login window of the system
   *
   */
  void loginWindow(); // Funcion que muestra la ventana de login (admin genera
                      // los guess y employee y puede generar otros admins)
  /**
   * @brief This method displays the main window of the system for the admin
   *
   */
  void mainWindowAdmin(); // Funcion que muestra la ventana principal (muestra
                          // todas las opciones) Admin

  /**
   * @brief This method displays the main window of the system for the employee
   *
   */
  void mainWindowEmployee(); // Funcion que muestra la ventana principal
                             // (muestra todas las opciones) Employee
  /**
   * @brief This method displays the main window of the system for the guest
   *
   */
  void mainWindowGuest(); // Funcion que muestra la ventana principal (muestra
                          // todas las opciones) Guest
  /**
   * @brief Create a User object window
   *
   */
  void
  createUserWindow(); // Funcion que muestra la ventana para crear un usuario
  /**
   * @brief Delete a User object window
   *
   */
  void
  deleteUserWindow(); // Funcion que muestra la ventana para borrar un usuario
  /**
   * @brief Update a User object window
   *
   */
  void updateUserWindow(); // Funcion que muestra la ventana para actualizar un
                           // usuario
  /**
   * @brief Display all Users window
   *
   */
  void displayUsersWindow(); // Funcion que muestra la ventana para ver todos
                             // los usuarios

  /**
   * @brief Save the users window
   *
   */
  void saveUsersWindow();

  /**
   * @brief Create a Alarm Window object
   *
   */
  void createAlarmWindow(); // Funcion que muestra la ventana para crear una
                            // alarma
  /**
   * @brief Delete a Alarm Window object
   *
   */
  void deleteAlarmWindow(); // Funcion que muestra la ventana para borrar una
                            // alarma
  /**
   * @brief Display all Sensors window
   *
   */
  void displaySensorsWindow(); // Funcion que muestra la ventana para ver todos
                               // los sensores
  /**
   * @brief Display all Alarms window
   *
   */
  void displayAlarmsWindow(); // Funcion que muestra la ventana para ver todas
                              // las alarmas
  /**
   * @brief Save Alarm Window object
   *
   */
  void saveAlarmWindow(); // Funcion que muestra la ventana para guardar una
                          // alarma
  /**
   * @brief Turn on or off the system window
   *
   */
  void turnOnOffSystemWindow(); // Funcion que muestra la ventana para encender
                                // y apagar el sistema
  /**
   * @brief Display the error window
   *
   */
  void displayErrorWindow(); // Funcion que muestra la ventana de error
  /**
   * @brief Clean the screen
   *
   */
  void cleanScreen();
  /**
   * @brief Exit the window
   *
   */
  void exitWindow();

  /**
   * @brief Display the camera window
   *
   */
  void displayCameraWindow();

  /**
   * @brief Create a camera window
   *
   */
  void createCameraWindow();

  /**
   * @brief Delete a camera window
   *
   */
  void deleteCameraWindow();

  /**
   * @brief Turn on or off the camera window
   *
   */
  void turnOnOffCameraWindow();

  /**
   * @brief Save a camera window
   *
   */
  void saveCameraWindow();
};

#endif // SCREENHARDWARE_H