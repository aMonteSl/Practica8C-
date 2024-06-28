#include <iostream>

#include "SwitchHardware.h"
using namespace std;

int main() {
  // Generamos un swithc activado, luego preguntamos un input, displayamos el
  // output, y luego repetimos
  SwitchHardware sw(true);
  sw.displayOutput();
  sw.askInput();
  sw.displayOutput();
  sw.askInput();
  sw.displayOutput();
}