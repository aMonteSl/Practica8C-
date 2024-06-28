#ifndef SWITCHHARDWARE_H
#define SWITCHHARDWARE_H
#include "Hardware.h"

/**
 * @file SwitchHardware.h
 * @brief This is the class SwitchHardware. It contains the attributes and
 * methods of the SwitchHardware class, this class is a child of the Hardware
 * class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class SwitchHardware : public Hardware {
public:
  /**
   * @brief Construct a new Switch Hardware object
   *
   * @param active
   * @return SwitchHardware object
   */
  explicit SwitchHardware(bool active);
  /**
   * @brief Destroy the Switch Hardware object
   *
   */
  ~SwitchHardware() override;
  /**
   * @brief Ask for an input
   *
   * @return int
   */
  int askInput() override;
  /**
   * @brief Display the output of the Switch Hardware
   *
   */
  void displayOutput() const override;

private:
  /**
   * @brief The data of the Switch Hardware
   *
   */
  void translateInput(int input);
};

#endif // SWITCHHARDWARE_H