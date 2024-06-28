#include "AirQualitySensor.h"
#include "AlarmSensors.h"
#include "HydrometerSensor.h"
#include "LightSensor.h"
#include "PhSensor.h"
#include "PressureSensor.h"
#include "TemperatureSensor.h"

int main() {
  /*
  TemperatureSensor temp(1, true);
  AirQualitySensor air(2, true);
  HydrometerSensor hyd(3, true);
  PressureSensor pres(4, true);
  LightSensor light(5, true);
  PhSensor ph(6, true);
  */

  AlarmSensors *alarm = new AlarmSensors(
      new TemperatureSensor(1, true), new AirQualitySensor(2, true),
      new HydrometerSensor(3, true), new PressureSensor(4, true),
      new LightSensor(5, true), new PhSensor(6, true));
  // Todas las opetaciones de la clase AlarmSensors
  // AlarmSensors alarm(&temp, &air, &hyd, &pres, &light, &ph);
  alarm->displayAlarmStatus();
  alarm->displayAllSensorsData();
  alarm->displayAlarmStatus();
  alarm->turnOnOffSystem(0);
  alarm->displayAllSensorsData();
  alarm->displayAlarmStatus();

  return 0;
}