#ifndef MONITORINGSYSTEM_H
#define MONITORINGSYSTEM_H
#include <iostream>
#include <string>

/**
 * @file MonitoringSystem.h
 * @brief This is the class MonitoringSystem. It contains the attributes and
 * methods of the MonitoringSystem class, this class
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// Delcaracion anticipada de ScreenHardware, KeyboardHardware y SwitchHardware
class ScreenHardware;
class KeyboardHardware;
class SwitchHardware;

extern const int MAIN_MENU_OPTIONS;
extern const int ADMIN_MENU_OPTIONS;
extern const int EMPLOYEE_MENU_OPTIONS;
extern const int GUEST_MENU_OPTIONS;

class MonitoringSystem {
public:
  // Constructor con las declaraciones anticipadas
  /**
   * @brief Construct a new Monitoring System object
   *
   * @param screen
   * @param keyboard
   * @param sw
   */
  explicit MonitoringSystem(ScreenHardware *screen, KeyboardHardware *keyboard,
                            SwitchHardware *sw);
  // Destructor
  /**
   * @brief Destroy the Monitoring System object
   *
   */
  ~MonitoringSystem();

  // Getters
  /**
   * @brief Get the Selection object
   *
   * @return int
   */
  int getSelection();
  /**
   * @brief Get the Name object
   *
   * @return std::string
   */
  std::string getName();
  /**
   * @brief Get the NIF object
   *
   * @return std::string
   */
  std::string getNIF();
  /**
   * @brief Get the Password object
   *
   * @return std::string
   */
  std::string getPassword();

  // Getters de nuevo usuario
  /**
   * @brief Get the Name Selected User object
   *
   * @return std::string
   */
  std::string getNameSelectedUser();
  /**
   * @brief Get the NIF Selected User object
   *
   * @return std::string
   */
  std::string getNIFSelectedUser();
  /**
   * @brief Get the Password Selected User object
   *
   * @return std::string
   */
  std::string getPasswordSelectedUser();
  /**
   * @brief Get the Privileges Selected User object
   *
   * @return std::string
   */
  std::string getPrivilegesSelectedUser();
  /**
   * @brief Get the Email Selected User object
   *
   * @return std::string
   */
  std::string getEmailSelectedUser();

  // Get alarm
  /**
   * @brief Get the Id Alarm object
   *
   * @return int
   */
  int getIdAlarm();
  /**
   * @brief Get the Type Alarm object
   *
   * @return std::string
   */
  std::string getTypeAlarm();
  /**
   * @brief Get the Id Selected Alarm object
   *
   * @return int
   */
  int getIdSelectedAlarm();

  /**
   * @brief Get the Type Camera object
   *
   * @return std::string
   */
  std::string getTypeCamera();
  /**
   * @brief Get the Id Camera object
   *
   * @return int
   */
  int getIdCamera();
  /**
   * @brief Get the Id Selected Camera object
   *
   * @return int
   */
  int getIdSelectedCamera();

  /**
   * @brief This method initializes the screen and keyboard.
   *
   */
  void
  initialScreen(); // Llama a initialWindow de Screen y askInput de Keyboard
  // ***********************
  /**
   * @brief This method exits the screen.
   *
   */
  void exitScreen(); // Llama a exitWindow de Screen
  /**
   * @brief This method shows the login screen.
   *
   */
  void loginScreen(); // Llama a loginWindow de Screen y stringInput de Keyboard
  // ***********************
  /**
   * @brief This method shows the main menu for the admins.
   *
   */
  void mainWindowAdmin(); // Llama a mainWindowAdmin de Screen
  /**
   * @brief This method shows the main menu for the employees.
   *
   */
  void mainWindowEmployee(); // Llama a mainWindowEmployee de Screen
  /**
   * @brief This method shows the main menu for the guests.
   *
   */
  void mainWindowGuest(); // Llama a mainWindowGuest de Screen
  // ***********************
  // Opciones menu
  /**
   * @brief This method shows the message to create a new user.
   *
   */
  void createUserScreen(); // Llama a createUserWindow de Screen y stringInput
                           // de Keyboard
  /**
   * @brief This method shows the message to delete a user.
   *
   */
  void deleteUserScreen(); // Llama a deleteUserWindow de Screen y stringInput
                           // de Keyboard
  /**
   * @brief This method shows the message to update a user.
   *
   */
  void updateUserScreen(); // Llama a updateUserWindow de Screen y stringInput
                           // de Keyboard
  /**
   * @brief This method shows the message to show the users.
   *
   */
  void displayUsersScreen(); // Llama a displayUsersWindow de Screen
  /**
   * @brief This method shows the message to show the sensors.
   *
   */
  void displaySensorsScreen(); // Llama a displaySensorsWindow de Screen
  /**
   * @brief This method shows the message to show the alarms.
   *
   */
  void displayAlarmsScreen(); // Llama a displayAlarmsWindow de Screen
  /**
   * @brief This method shows the message to turn on or off the system.
   *
   */
  void turnOnOffSystemScreen(); // Llama a turnOnOffSystemWindow de Screen
  /**
   * @brief This method shows the message if and error occurs.
   *
   */
  void displayErrorScreen(); // Llama a displayErrorWindow de Screen
  /**
   * @brief This method shows the message to create a new alarm.
   *
   */
  void createAlarmScreen(); // Llama a createAlarmWindow de Screen
  /**
   * @brief This method shows the message to delete an alarm.
   *
   */
  void deleteAlarmScreen(); // Llama a deleteAlarmWindow de Screen
  /**
   * @brief This method shows the message to save an alarm.
   *
   */
  void saveAlarmScreen(); // Llama a saveAlarmWindow de Screen

  /**
   * @brief Display the camera screen
   *
   */
  void displayCameraScreen(); // Llama a displayCameraWindow de Screen

  /**
   * @brief Create a Camera Screen object
   *
   */
  void createCameraScreen(); // Llama a createCameraWindow de Screen

  /**
   * @brief Delete a Camera Screen object
   *
   */
  void deleteCameraScreen(); // Llama a deleteCameraWindow de Screen

  /**
   * @brief Turn on or off a Camera Screen object
   *
   */
  void turnOnOffCameraScreen(); // Llama a turnOnOffCameraWindow de Screen

  /**
   * @brief Save a Camera Screen object
   *
   */
  void saveCameraScreen(); // Llama a saveCameraWindow de Screen

  /**
   * @brief Clean the screen
   *
   */
  void cleanScreen(); // Llama a cleanScreen de Screen

  /**
   * @brief Save the users screen
   *
   */
  void saveUsersScreen(); // Llama a saveUsersWindow de Screen

private:
  // Atributos privados
  /**
   * @brief This is the pointer to the ScreenHardware object
   *
   */
  ScreenHardware *screen;
  /**
   * @brief This is the pointer to the KeyboardHardware object
   *
   */
  KeyboardHardware *keyboard;
  /**
   * @brief This is the pointer to the SwitchHardware object
   *
   */
  SwitchHardware *sw;

  // Metodos privados
  /**
   * @brief This method checks if the input is correct.
   *
   * @param input
   * @param max
   * @return true
   * @return false
   */
  bool inputCorrect(int input, int max);
  /**
   * @brief This method asks the user for an int input.
   *
   * @param max
   * @return int
   */
  int askInputInt(int max);
  /**
   * @brief This method asks the user for an input for the name.
   *
   * @return std::string
   */
  std::string askName();
  /**
   * @brief This method asks the user for an input for the NIF.
   *
   * @return std::string
   */
  std::string askNIF();
  /**
   * @brief This method asks the user for an input for the password.
   *
   * @return std::string
   */
  std::string askPassword();
  /**
   * @brief This method asks the user for an input for the privileges.
   *
   * @return std::string
   */
  std::string askPrivileges();
  /**
   * @brief This method asks the user for an input for the email.
   *
   * @return std::string
   */
  std::string askEmail();

  // Atributos de nuevo usuario
  /**
   * @brief This is the selection of the user.
   *
   */
  int selection_;
  /**
   * @brief This is the name of the user.
   *
   */
  std::string name_;
  /**
   * @brief This is the NIF of the user.
   *
   */
  std::string nif_;
  /**
   * @brief This is the password of the user.
   *
   */
  std::string password_;

  // data new user
  /**
   * @brief This is the method to select a user.
   *
   * In this selection you have to introduce all the parameters of the user.
   *
   */
  void selectUser();
  /**
   * @brief This is the method to select a short user.
   *
   * In this selection you have to introduce the name, the password and the NIF
   * of the user.
   *
   */
  void shortSelectUser();
  /**
   * @brief This is the method to ask the main user, the one that its going to
   * loggin.
   *
   *
   */
  void askMainUser();
  /**
   * @brief This is the name of the selected user.
   *
   */
  /**
   * @brief This is the NIF of the selected user.
   */
  std::string nameSelectedUser_;
  /**
   * @brief This is the password of the selected user.
   *
   */
  std::string nifSelectedUser_;
  /**
   * @brief This is the privileges of the selected user.
   *
   */
  std::string passwordSelectedUser_;
  /**
   * @brief This is the privileges of the selected user.
   *
   */
  std::string privilegesSelectedUser_;
  /**
   * @brief This is the email of the selected user.
   *
   */
  std::string emailSelectedUser_;

  // Datos de nueva alarma
  /**
   * @brief This is the method to ask the type of the alarm.
   *
   */
  std::string askTypeAlarm();
  /**
   * @brief This is the method to ask the id of the alarm.
   *
   */
  int askIdAlarm();
  /**
   * @brief This attribute is the id of the alarm.
   */
  int idAlarm_;
  /**
   * @brief This attribute is the type of the alarm.
   */
  std::string typeAlarm_;
  /**
   * @brief This attribute is the id of the selected alarm.
   */
  int idSelectedAlarm_;

  /**
   * @brief This is the method to ask the type of the camera.
   *
   * @return std::string
   */
  std::string askTypeCamera();
  /**
   * @brief This is the method to ask the id of the camera.
   *
   * @return int
   */
  int askIdCamera();
  /**
   * @brief This attribute is the id of the camera.
   *
   *
   */
  int idCamera_;
  /**
   * @brief This attribute is the type of the camera.
   *
   */
  std::string typeCamera_;
  /**
   * @brief This attribute is the id of the selected camera.
   *
   */
  int idSelectedCamera_;
};

#endif // MONITORINGSYSTEM_H