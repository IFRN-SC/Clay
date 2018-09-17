#include "Estrategia.h"
#include "robo_hardware2.h"

  void Estrategia::executa() {

    float sensorFrontal;
    float sensorLateral;
    float sensorBaixo;

    sensorBaixo = robo.lerSensorSonarDir();
    sensorLateral = robo.lerSensorSonarEsq();
    sensorFrontal = robo.lerSensorSonarFrontal();
    if (sensorFrontal < 10) {
      desviarObstaculo();

    }
    else if (sensorBaixo > 3.5) {
      redutor();
    }
    else if (sensorLateral < 10) {
      sala3();
    }
    else {
      seguirLinha();
    }

  }

  void Estrategia::redutor() {
    movimento.frenmed();
    delay(60);

    seguirLinha();
  }

  void Estrategia::seguirLinha() {

    if (sensores.brancoBrancoBrancoBranco()) {
      movimento.fren();

    } 
    else if (sensores.brancoPretoBrancoBranco()) {
      movimento.dir();

    } 
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.esq();

    } 
    else if (sensores.brancoBrancoBrancoPreto()) {
      movimento.exesq();
      delay(300);
    } 
    else if (sensores.pretoBrancoBrancoBranco()) {
      movimento.exdir();
      delay(300);
    } 
    else if (sensores.pretoPretoPretoPreto()) {
      movimento.frenlen();
    } 
    else if (sensores.brancoPretoPretoBranco()) {
      movimento.frenlen();
    }
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.exdir();
      delay(250);
    }
    else if (sensores.pretoPretoPretoBranco())  {
      movimento.esq();
      delay(250);
    } 
    else if (sensores.brancoPretoBrancoBranco())  {
      movimento.dir();
      delay(250);
    } 
    else if (sensores.pretoPretoBrancoBranco())  {
      movimento.dir();
      delay(250);
    } 
    else if (sensores.brancoBrancoPretoPreto())  {
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

    if (currentMillis - previousMillis > redLedInterval) {
      previousMillis = currentMillis;

      if (redLedState == LOW) {
        robo.ligarTodosLeds();
        redLedState = HIGH;

      } 
      else {

        robo.desligarTodosLeds();
        redLedState = LOW;

      }
    }
  }

  void Estrategia::sala3() {

    parar = false;

    while (!parar) {

      if (sensores.brancoBrancoBrancoBranco()) {
        movimento.superfrent();
      }
      else if (sensores.brancoPretoBrancoBranco()) {
        movimento.dirr();
      }
      else if (sensores.brancoBrancoPretoBranco()) {
        movimento.esqq();
      }
      else if (sensores.pretoPretoBrancoBranco()) {
        movimento.esqq();
      }
      else if (sensores.brancoBrancoPretoPreto()) {
        movimento.dirr();
      }
      else if (sensores.pretoPretoPretoPreto()) {
        movimento.superfrent();
        delay(700);
      
         movimento.rabdir();
         delay(200);

         movimento.superfrent();
         delay(400);

         movimento.rabdir();
         delay(200);

         movimento.superfrent();
         delay(400);

         movimento.rabdir();
         delay(200);

         parar = true;

      }
    }

  }

  void Estrategia::desviarObstaculo() {
    parar = false;
    robo.desligarLed(1);
    robo.acionarMotores(-20, -20);
    delay(500);
    movimento.dir();
    delay(425);
    movimento.parar();
    delay(500);
    movimento.fren();
    delay(560);
    movimento.parar();
    delay(500);
    movimento.esq();
    delay(400);
    movimento.parar();
    delay(500);
    movimento.fren();
    delay(1030);
    movimento.parar();
    delay(500);
    movimento.esq();
    delay(320);
    movimento.parar();
    delay(2000);
    movimento.frenlen();
    delay(300);
    float sensorLateral;

    while (!parar) {


      sensorLateral = robo.lerSensorSonarEsq();
      if (sensores.pretoPretoPretoPreto() && sensorLateral < 15) {
        voltarParaALinha();

      }
      else if (sensorLateral < 15 && sensores.pretoPretoPretoPreto()) {
        voltarParaALinha();
      }
      else if (sensorLateral < 15 && sensores.pretoPretoBrancoBranco()) {
        voltarParaALinha();
      }
      else if (sensorLateral < 15 && sensores.brancoPretoPretoPreto()) {
        voltarParaALinha();
      }
      else if (sensorLateral < 15 && sensores.pretoPretoBrancoBranco()) {
        voltarParaALinha();
      }
      else if (sensorLateral < 15 && sensores.brancoPretoPretoPreto()) {
        voltarParaALinha();
      }
      else if (sensorLateral < 15 && sensores.brancoBrancoPretoPreto()) {
        voltarParaALinha();
      }

    }

  }

  void Estrategia:: voltarParaALinha() {
    robo.ligarLed(1);
    robo.acionarMotores(-40, -40);
    delay(300);
    movimento.parar();
    delay(500);
    movimento.fren();
    delay(210);
    movimento.parar();
    delay(500);
    movimento.dir();
    delay(100);
    movimento.fren();
    delay(100);
    movimento.dir();
    delay(400);
    movimento.parar();
    delay(500);
    robo.acionarMotores(-50, -50);
    delay(130);
    movimento.parar();
    delay(500);
    parar = true;
  }

