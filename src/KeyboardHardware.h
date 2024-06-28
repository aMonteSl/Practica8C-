#ifndef KEYBOARDHARDWARE_H
#define KEYBOARDHARDWARE_H
#include "Hardware.h"

/**
 * @file KeyboardHardware.h
 * @brief This is the class KeyboardHardware. It contains the attributes and
 * methods of the KeyboardHardware class, this class is a child of the Hardware
 * class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class KeyboardHardware : public Hardware {
public:
  /**
   * @brief Construct a new Keyboard Hardware object
   *
   * @param active
   * @return KeyboardHardware object
   */
  explicit KeyboardHardware(bool active);
  /**
   * @brief Destroy the Keyboard Hardware object
   *
   */
  ~KeyboardHardware() override;

  /**
   * @brief Ask for an input to the user
   *
   * @return int
   */
  int askInput() override;
  /**
   * @brief Ask for a string input to the user
   *
   * @return std::string
   */
  std::string stringInput();
  /**
   * @brief Display the output of the Keyboard Hardware
   *
   */
  void displayOutput() const override;

private:
  /**
   * @brief The int data of the Keyboard Hardware
   *
   */
  int data_;
  /**
   * @brief The string data of the Keyboard Hardware
   *
   */
  std::string stringData_;
};

#endif // KEYBOARDHARDWARE_H
