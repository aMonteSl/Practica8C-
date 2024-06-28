#ifndef SENSOR_H
#define SENSOR_H
#include <string>

/**
 * @file Sensor.h
 * @brief This is the class Sensor. It contains the attributes and methods of
 * the Sensor class.
 * @author Adrián Montes Linares
 * @date 21/04/2024
 */

class Sensor {
public:
  /**
   * @brief This is the enum Types. It contains the types of the sensors.
   *
   */
  enum Types {
    NONE,
    TEMPERATURE,
    AIR_QUALITY,
    HYDROMETER,
    PRESSURE,
    LIGHT_SENSOR,
    PH_SENSOR,
  };

  /**
   * @brief Construct a new Sensor object
   *
   * Creates a new Sensor object with the default values (id, type, active).
   *
   * @return Sensor object
   */
  Sensor();
  /**
   * @brief Construct a new Sensor object
   *
   * Creates a new Sensor object with the values passed as parameters.
   *
   * @param id of the sensor
   * @param type of the sensor
   * @param active of the sensor
   * @return Sensor object
   */
  explicit Sensor(int id, Types type, bool active);
  /**
   * @brief Destroy the Sensor object
   *
   */
  virtual ~Sensor();

  // Estas funciones se van a poder modificiar en las clases derivadas gracias a
  // la palabra virtual
  /**
   * @brief Collect data of the Sensor
   *
   */
  virtual void collectData();
  /**
   * @brief Collect and print the data of the Sensor
   *
   */
  virtual void collectAndPrint();

  /**
   * @brief Return if is active or not the sensor
   *
   * @return true
   * @return false
   */
  bool isActive() const;
  /**
   * @brief Turn off the sensor
   *
   */
  void turnOff();
  /**
   * @brief Turn on the sensor
   *
   */
  void turnOn();
  /**
   * @brief Get the Data object
   *
   * @return float
   */
  float getData() const;
  /**
   * @brief Set the Data object
   *
   * @param data
   */
  void setData(float data);
  /**
   * @brief Get the Id object
   *
   * @return int
   */
  int getId() const;
  /**
   * @brief Set the Id object
   *
   * @param newid
   */
  void setId(int newid);
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

  // chekea, cambia state_ y devuelve el valor de state_
  // No tengo un setState() porque cuando chequeas el sensor primero debes de
  // ver el estado del sensor
  /**
   * @brief Check if the Sensor is working properly
   *
   * @return true if the Sensor is working properly
   * @return false if the Sensor is not working properly
   */
  virtual bool checkAllgood() const;

  /**
   * @brief Operator < overload
   *
   * @param Sensor
   * @return true
   * @return false
   */
  bool operator<(const Sensor &Sensor) const;
  /**
   * @brief Operator > overload
   *
   * @param Sensor
   * @return true
   * @return false
   */
  bool operator>(const Sensor &Sensor) const;
  /**
   * @brief Operator == overload
   *
   * @param Sensor
   * @return true
   * @return false
   */
  bool operator==(const Sensor &Sensor) const;
  /**
   * @brief Operator << overload
   *
   * @param os
   * @param Sensor
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os, const Sensor &Sensor);
  /**
   * @brief Operator >> overload
   *
   * @param is
   * @param Sensor
   * @return std::istream&
   */
  friend std::istream &operator>>(std::istream &is, Sensor &Sensor);

  /**
   * @brief Print the data of the Sensor
   *
   */
  virtual void printData() const;

private:
  /**
   * @brief The id of the sensor
   *
   */
  int id_;
  /**
   * @brief The type of the sensor
   *
   */
  Types type_;
  /**
   * @brief The state of the sensor
   *
   */
  bool active_;
  /**
   * @brief The data of the sensor
   *
   */
  float data_;

  /**
   * @brief Convert the string to the type
   *
   * @param type
   * @return Types
   */
  Types stringToType(const std::string &type) const;
  /**
   * @brief Convert the type to the string
   *
   * @param type
   * @return std::string
   */
  std::string typeToString(Types type) const;
};

#endif // SENSOR_H
