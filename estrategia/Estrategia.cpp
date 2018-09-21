#include "Estrategia.h"
#include "robo_hardware2.h"

  void Estrategia::executa() {
    
    sensorBaixo = robo.lerSensorSonarDir();
    sensorLateral = robo.lerSensorSonarEsq();
    sensorFrontal = robo.lerSensorSonarFrontal();
    
    if (sensorFrontal < 10) {
      desviarObstaculo();
    }
    else if (sensorLateral < 10) {
      rampa();
    }
    else if(sensorFrontal <= 70 && sensorFrontal > 30){
      sala3();
    }
    else {
      seguirLinha();
    }

  }
  void Estrategia::redutor() {
    movimento.superfrent();
    delay(50);

    seguirLinha();
  }
  void Estrategia::sala3() {
    
  movimento.esq();
  delay(200);
  movimento.fren();
  delay(500);
  movimento.girando();
  delay(1800);
  movimento.re();
  delay(800); 
  movimento.parar();
  delay(2000);
  movimento.fren();
  delay(1000);
  movimento.parar();
  delay(1000);
  movimento.girando();
  while(true);
    
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

  void Estrategia::rampa() {

    parar = false;

    while (!parar) {

      if (sensores.brancoBrancoBrancoBranco()) {
        movimento.frenmed();
      }
      else if (sensores.brancoPretoBrancoBranco()) {
        movimento.dirr();
      }
      else if (sensores.brancoBrancoPretoBranco()) {
        movimento.esqq();
      }
      else if (sensores.brancoBrancoBrancoPreto()) {
      movimento.exesq();
      } 
      else if (sensores.pretoBrancoBrancoBranco()) {
      movimento.exdir();
      } 
      else if (sensores.pretoPretoPretoPreto()) {
        
        movimento.superfrent();
        delay(700);
      

        movimento.parar();
        while(true);
        parar = true;
      }
      else if (sensores.pretoPretoBrancoBranco()) {
        robo.acionarMotores(80, 100);
        delay(1000);
     
        movimento.parar();

        parar = true;
      }
      else if (sensores.brancoBrancoPretoPreto()) {
        robo.acionarMotores(100, 80);
        delay(1000);
      

        movimento.parar();

        parar = true;
      }
    }

    while(!robo.botao2Pressionado());

  }

  void Estrategia::desviarObstaculo() {
    parar = false;
    movimento.obReLen();
    delay(500);
    movimento.obEsq();
    delay(480);
    movimento.obFren();
    delay(560);
    movimento.obDir();
    delay(390);
    movimento.obFren();
    delay(1300);
    movimento.obDir();
    delay(400);
    movimento.obFrenLen();
    delay(300);

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
    movimento.obRe();
    delay(300);
    movimento.parar();
    delay(500);
    movimento.obFren();
    delay(210);
    movimento.parar();
    delay(500);
    movimento.obEsq();
    delay(100);
    movimento.parar();
    delay(500);
    movimento.obFren();
    delay(100);
    movimento.parar();
    delay(500);
    movimento.obDir();
    delay(400);
    movimento.parar();
    delay(500);
    movimento.obRe();
    delay(130);
    movimento.parar();
    delay(500);
    parar = true;
  }

