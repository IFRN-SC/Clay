#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  float sensorFrontal;
  float sensorLateral;

  sensorLateral = robo.lerSensorSonarDir();
  sensorFrontal = robo.lerSensorSonarFrontal();
  if (sensorFrontal < 10) {
    desviarObstaculo();
  }

  else if (sensorLateral < 10) {
    sala3();
  }

  else {
    seguirLinha();
  }

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
    movimento.frenlen();
  } else if (sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.exdir();
    delay(250);
  } else if (sensores.pretoPretoPretoBranco())  {
    movimento.esq();
    delay(250);
  } else if (sensores.brancoPretoBrancoBranco())  {
    movimento.dir();
    delay(250);
  } else if (sensores.pretoPretoBrancoBranco())  {
    movimento.dir();
    delay(250);
  } else if (sensores.brancoBrancoPretoPreto())  {
    movimento.esq();
    delay(250);
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
    movimento.dirr();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.esqq();
  }
  else if (sensores.pretoPretoPretoPreto()) {
    led();
    movimento.superfrent();
    delay(400);
    led();
    movimento.rabesq();
    delay(200);
    led();
    movimento.superfrent();
    delay(400);
    led();
    movimento.rabesq();
    delay(200);
    led();
    movimento.superfrent();
    delay(400);
    led();
    movimento.rabesq();
    delay(200);
    led();

    movimento.parar();
    while (true);
  }
  else if (sensores.pretoPretoBrancoBranco()) {
    movimento.esqq();
  }
  else if (sensores.brancoBrancoPretoPreto()) {
    movimento.dirr();
  }


}
void Estrategia::desviarObstaculo() {
  //movimento.parar();
  robo.acionarMotores(-10,-10);
  delay(2000);
  movimento.esq();
  delay(460);
  movimento.parar();
  delay(2000);
  movimento.fren();
  delay(580);
  movimento.parar();
  delay(2000);
  movimento.dir();
  delay(450);
  movimento.parar();
  delay(2000);
  movimento.fren();
  delay(740);

 
  movimento.parar();
  delay(2000);
  movimento.dir();
  delay(350);
  movimento.parar();
  delay(2000);
  movimento.esq();
  delay(120);
  movimento.fren();
  delay(500);
  movimento.esq();
  delay(450);
  robo.acionarMotores(-30,-30);
  delay(200);
  movimento.parar();
  delay(2000);
  movimento.esq();
  delay(100);
  movimento.parar();
  delay(2000);

}
