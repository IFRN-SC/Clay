#include "Estrategia.h"
#include "robo_hardware2.h"


  void Estrategia::executa() {

    float valorSensorMaisEsq;
    float valorSensorEsq;
    float valorSensorDir;
    float valorSensorMaisDir;
    
    sensorBaixo = robo.lerSensorSonarDir();
    sensorLateral = robo.lerSensorSonarEsq();
    sensorFrontal = robo.lerSensorSonarFrontal();

    valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
    valorSensorEsq = robo.lerSensorLinhaEsq();
    valorSensorDir = robo.lerSensorLinhaDir();
    valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
    
    if (sensorFrontal < 10) {    
      desviarObstaculo();
    }
    else if (sensorLateral < 10) {
      rampa();
    }
    //else if (valorSensorMaisEsq > 97){
    // redutor();
    //}
    else if (valorSensorMaisEsq >= 40 && valorSensorMaisEsq <= 45){
    verde();
    }
    else if (valorSensorMaisDir >= 40 && valorSensorMaisDir <= 45){
    verde1();
    }

    else {
      seguirLinha();
    }

  }
  void Estrategia::redutor() {

    movimento.frenmed();
    delay(400);
    movimento.parar();
    delay(2000);

    while (sensores.brancoBrancoBrancoBranco()) {
      seguirLinha();
    } 
    
    seguirLinha();
  }
  void Estrategia::sala3() {}
  void Estrategia::seguirLinha() {
    
 // CONDIÇÕES BASICAS SEGUIR LINHA
 
    if (sensores.brancoBrancoBrancoBranco()) {
      movimento.fren();
      
    } 
    else if (sensores.brancoPretoBrancoBranco()) {
      movimento.dir();

    } 
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.esq();
      
  // CONDIÇÕES NORMAIS SEGUIR LINHA 
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
      movimento.esq();
      delay(250);
      movimento.frenlen();
      delay(200);
      
    } 
    else if (sensores.brancoPretoPretoBranco()) {
      movimento.frenlen(); 
    }
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.exdir();
      delay(250);
      movimento.frenlen();
      delay(200);
    }
    else if (sensores.pretoPretoPretoBranco())  {
      movimento.exdir();
      delay(250);
      movimento.frenlen();
      delay(200);
    } 
    else if (sensores.brancoPretoBrancoBranco())  {
      movimento.dir();
      delay(250);
      movimento.frenlen();
      delay(200);
    } 
    else if (sensores.pretoPretoBrancoBranco())  {
      movimento.exdir();
      delay(250);
      movimento.frenlen();
      delay(200);
    } 
    else if (sensores.brancoBrancoPretoPreto())  {
      movimento.exesq();
      delay(250);
      movimento.frenlen();
      delay(200);
      
    }else if (sensores.brancoPretoPretoPreto())  {
      movimento.exdir();
      delay(250);
      movimento.frenlen();
      delay(200);
    }
    
  }
  void Estrategia::verde() {

    movimento.parar();
    delay(2000);
    movimento.frenlen();
    delay(200);
    movimento.dir();
    delay(200);
    
    while (sensores.brancoBrancoBrancoBranco()) {
    seguirLinha();
    } 
    
  }
  void Estrategia::verde1(){

    movimento.parar();
    delay(2000);
    movimento.frenlen();
    delay(200);
    movimento.esq();
    delay(400);
    movimento.frenlen();
    delay(300);
    
    while (sensores.brancoBrancoBrancoBranco()) {
    seguirLinha();
    }
    
  }
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
      
      else if (sensores.pretoPretoPretoPreto()) {
        
        movimento.frenmed();
        delay(600);
        movimento.rabesq();
        delay(300);
        movimento.frenmed();
        delay(500);
        movimento.rabesq();
        delay(300);
      

        movimento.parar();
        while(true);
   
      }
    }

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

