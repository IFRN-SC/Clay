#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  float sensorFrontal;
  float sensorLateral;
  float sensorLateralDir;

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateral = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();
  if (sensorFrontal < 5) {
    robo.acionarMotores(-15, -15);
    delay(500);
    desviarObstaculo();

  }
  else if (sensorLateralDir > 3.5) {
    redutor();
  }
  else if (sensorLateral < 10) {
    sala3();
  }

  else {
    seguirLinha();
  }

}

void Estrategia::redutor()
{
  movimento.frenmed();
  delay(100);

  seguirLinha();
}

void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.fren();

  } else if (sensores.brancoPretoBrancoBranco()) {
    movimento.esq();

  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.dir();

  } else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exdir();
  } else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exesq();
  } else if (sensores.pretoPretoPretoPreto()) {
    movimento.frenlen();
  } else if (sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.dir();
  } else if (sensores.pretoPretoPretoBranco())  {
    movimento.esq();
  } else if (sensores.brancoPretoBrancoBranco())  {
    movimento.esq();
  } else if (sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
  } else if (sensores.brancoBrancoPretoPreto())  {
    movimento.dir();
  }

}
void Estrategia::verde() {}

void Estrategia::led() {

  static long redLedInterval = 300;
  static bool redLedState = false;
  static   long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > redLedInterval)
  {
    previousMillis = currentMillis;

    if (redLedState == LOW) {
      robo.ligarTodosLeds();
      redLedState = HIGH;

    } else {

      robo.desligarTodosLeds();
      redLedState = LOW;

    }
  }
}

void Estrategia::sala3() {


  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.frenmed();
  }
  else if (sensores.brancoPretoBrancoBranco()) {
    movimento.esqq();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.dirr();
  }
  else if (sensores.pretoPretoPretoPreto()) {
    led();
    movimento.superfrent();
    delay(400);
    led();
    movimento.rabdir();
    delay(200);
    led();
    movimento.superfrent();
    delay(400);
    led();
    movimento.rabdir();
    delay(200);
    led();
    movimento.superfrent();
    delay(400);
    led();
    movimento.rabdir();
    delay(200);
    led();

    movimento.parar();
    while (true);
  }
  else if (sensores.pretoPretoBrancoBranco()) {
    movimento.dirr();
  }
  else if (sensores.brancoBrancoPretoPreto()) {
    movimento.esqq();
  }


}
void Estrategia::desviarObstaculo() {
  //movimento.parar();
  robo.acionarMotores(-20, -20);
  delay(500);
  movimento.dir();
  delay(440);
  movimento.parar();
  delay(2000);
  movimento.fren();
  delay(900);
  movimento.parar();
  delay(2000);
  movimento.esq();
  delay(330);
  movimento.parar();
  delay(2000);
  movimento.fren();
  delay(1400);
  movimento.parar();
  delay(2000);
  movimento.esq();
  delay(280);
  movimento.parar();
  delay(2000);
  movimento.frenlen();
  delay(300);
  float sensorLateral;

  while (!parar) {


    sensorLateral = robo.lerSensorSonarEsq();
    if (sensores.pretoPretoPretoPreto() && sensorLateral < 20) {
      voltarParaALinha();

    }
    else if (sensorLateral < 15) {
      voltarParaALinha();
    }
    else if (sensorLateral < 15) {
    voltarParaALinha();
    }
    else if (sensorLateral < 15) {
    voltarParaALinha();
    }
    else if (sensorLateral < 15) {
    voltarParaALinha();
    }

  }

}

void Estrategia:: voltarParaALinha() {
  robo.ligarLed(1);
  robo.acionarMotores(-15, -15);
  delay(500);
  movimento.parar();
  delay(500);
  movimento.frenmed();
  delay(120);
  movimento.parar();
  delay(2000);
  movimento.dir();
  delay(400);
  movimento.parar();
  delay(2000);
  robo.acionarMotores(-50, -50);
  delay(120);
  movimento.parar();
  delay(2000);
  parar = true;
}

