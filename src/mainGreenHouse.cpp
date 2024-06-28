#include "AlarmSensors.h"
#include "GreenHouse.h"
#include "MonitoringSystem.h"
#include "UsersServer.h"

int main() {
  GreenHouse gh;
  gh.startSystem();
  gh.mainSystem();
  return 0;
}