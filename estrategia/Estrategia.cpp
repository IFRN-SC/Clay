#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {
  
  float valorSensorMaisEsq;
  float valorSensorEsq;
  float valorSensorDir;
  float valorSensorMaisDir;

  //sensorLaterald = robo.lerSensorSonarDir();
  sensorLateral = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();

  if (sensorLateral < 10 && sensores.entSala3()) {
    sala3();
  } 
  else if (sensorLateral < 10) {
    rampa();
  }
  //else (sensorLateral < 10 && sensorLaterald > 60){
   // sala3.2();
  //}
  else if (valorSensorMaisEsq > 97){
   redutor();
  }
  else if (valorSensorMaisEsq >= 39 && valorSensorMaisEsq <= 45){
  verde();
  }
  //else if (valorSensorMaisDir >= 80 && valorSensorMaisDir <= 90){
  //verde1();
  //}
  else if (sensorFrontal < 10) {
    desviarObstaculo();
  }
  else {
    seguirLinha();
  }

}
void Estrategia::redutor() {
  
   movimento.frenmed();
    delay(350);
    movimento.parar();
    delay(2000);
    movimento.re();
    delay(400);

    while (sensores.brancoBrancoBrancoBranco()) {
    seguirLinha();
  }
}

void Estrategia::verde1() {

    movimento.parar();
    delay(2000);
    movimento.frenlen();
    delay(200);
    movimento.dir();
    delay(400);
    movimento.frenlen();
    delay(300);
    
    while (sensores.brancoBrancoBrancoBranco()) {
    seguirLinha();
    }
}
void Estrategia::funverde(){

    movimento.frenlen();
    delay(200);
    movimento.girando();
    delay(500);
  
}
void Estrategia::verde(){

    movimento.frenlen();
    delay(200);
    movimento.girando();
    delay(500);
    movimento.fren();
    delay(400);
    
    while (sensores.brancoBrancoBrancoBranco()) {
    seguirLinha();
    } 
}
void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.fren();
  }
  else if (sensores.brancoPretoBrancoBranco()) {
    movimento.esq();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.dir();
  }
  else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exdir();
  }
  else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exesq();
  }
  else if (sensores.pretoPretoPretoPreto()) {
    movimento.frenlen();
  }
  else if (sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.exesq();
  }
  else if (sensores.pretoPretoPretoBranco())  {
    movimento.dir();
  }
  else if (sensores.brancoPretoBrancoBranco())  {
    movimento.esq();
  }
  else if (sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
  }
  else if (sensores.brancoBrancoPretoPreto())  {
    movimento.dir();
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

void Estrategia::sala3() {

  oSala3.alinhar();
  
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
 

}

void Estrategia:: voltarParaALinha() {
  robo.ligarLed(1);
  movimento.obRe();
  delay(300);
  robo.acionarMotores(70, 15);
  delay(660);
  robo.acionarMotores(-15, -50);
  delay(550);
  parar = true;
}

