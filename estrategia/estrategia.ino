#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Servo.h"
#include "Menu.h"

Estrategia estrategia;
Menu menu;

void setup() {
  robo.configurar(false);
  menu.menuLon();
}
void loop() {
  estrategia.executa();
}s
