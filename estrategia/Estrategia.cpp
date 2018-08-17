#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::calibracao() {
  calibrador.calibrar();
}

void Estrategia::executa() {
  float sensorFrontal;
  sensorFrontal = robo.lerSensorSonarFrontal();
  if (sensorFrontal < 10) {
    desviarObstaculo();
  }
  else {
    seguirLinha();
  }
  verde();
}
void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.fren();
  } else if (sensores.brancoPretoBrancoBranco()) {
    movimento.dir();

  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.esq();

  } else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exesq();
    delay(300);
  } else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exdir();
    delay(300);
  } else if (sensores.pretoPretoPretoPreto()) {
    movimento.fren();
  } else if (sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.exdir();
    delay(200);
  } else if (sensores.pretoPretoPretoBranco())  {
    movimento.esq();
    delay(200);
  } else if (sensores.brancoPretoBrancoBranco())  {
    movimento.esq();
    delay(200);
  } else if (sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
    delay(200);
  } else if (sensores.brancoBrancoPretoPreto())  {
    movimento.esq();
    delay(200);
  }

}
void Estrategia::verde() {

}

void Estrategia::sala3() {}
void Estrategia::desviarObstaculo() {

  movimento.parar();
  delay(500);
  movimento.dir();
  delay(400);
  movimento.parar();
  delay(500);
  movimento.fren();
  delay(600);
  movimento.parar();
  delay(500);
  movimento.esq();
  delay(400);
  movimento.parar();
  delay(500);
  movimento.fren();
  delay(1400);
  movimento.parar();
  delay(500);
  movimento.esq();
  delay(400);
  movimento.parar();
  delay(500);
  movimento.dir();
  delay(150);

  while (sensores.brancoBrancoBrancoBranco()) {
    movimento.frenlen();

  }
}
