#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Servo.h"

Estrategia estrategia;

void setup() {
  robo.configurar(false);
  estrategia.calibracao();
}
void loop() {
  estrategia.executa();


}
