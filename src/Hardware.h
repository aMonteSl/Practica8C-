#ifndef HARDWARE_H
#define HARDWARE_H
#include <string>

/**
 * @file Hardware.h
 * @brief This is the class Hardware. It contains the attributes and methods of
 * the Hardware class, this class is the parent of the hole hardware system.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

// Clase hardware que luego tendra clases hijas, pantalla, teclado, microfono e
// interruptor
class Hardware {
public:
  /**
   * @brief Enum of the types of hardware
   *
   */
  enum Types_Hardware { NONE, SCREEN, KEYBOARD, SWITCH };

  /**
   * @brief Construct a new Hardware object
   *
   */
  Hardware();
  /**
   * @brief Construct a new Hardware object
   *
   * @param active
   * @param type
   */
  explicit Hardware(bool active, Types_Hardware type);
  /**
   * @brief Destroy the Hardware object
   *
   */
  virtual ~Hardware();

  /**
   * @brief Get the Type object
   *
   * @return std::string
   */
  std::string getType() const;
  /**
   * @brief Set the Type object
   *
   * @param newtype
   */
  void setType(std::string newtype);

  /**
   * @brief If the hardware is active
   *
   * @return true if the hardware is active
   * @return false if the hardware is not active
   */
  bool isActive() const;
  /**
   * @brief Turn on the hardware
   *
   */
  void turnOn();
  /**
   * @brief Turn off the hardware
   *
   */
  void turnOff();
  /**
   * @brief This method returns if the hardware is active or not in a string.
   *
   * @return std::string
   */
  std::string stringStatus() const;

  /**
   * @brief This method asks the user for an input.
   *
   * @return int
   */
  virtual int askInput();
  /**
   * @brief This method displays the output of the hardware.
   *
   */
  virtual void displayOutput() const;

private:
  /**
   * @brief This atrribute is the status of the hardware.
   *
   */
  bool active_;
  /**
   * @brief This attribute is the type of the hardware.
   *
   */
  Types_Hardware type_;

  /**
   * @brief This method converts the type of hardware to a string.
   *
   * @param type
   * @return std::string
   */
  std::string typeToString(Types_Hardware type) const;
  /**
   * @brief This method converts the string to a type of hardware.
   *
   * @param type
   * @return Types_Hardware
   */
  Types_Hardware stringToType(std::string type) const;
};

#endif // HARDWARE_H