#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  sensorBaixo = robo.lerSensorSonarDir();
  sensorLateral = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  // if (sensorLateral < 10 && sensores.entSala3()) {
  // oSala3.rampa();
  //} 
  
  if (sensorLateral < 10) {
    oSala3.rampa();
  }

  else if (sensorFrontal < 4) {
    desviarObstaculo();
  }
  
  else {
    seguirLinha();
  }

}
void Estrategia::redutor() {

   movimento.superfrent();
   delay(400);

   movimento.parar();
   delay(500);

   while (sensores.brancoBrancoBrancoBranco() || sensores.brancoBrancoPretoBranco() || sensores.brancoPretoBrancoBranco()){
    robo.acionarMotores(-50, -50);
   }

   movimento.parar();
   delay(500);

   if (sensores.brancoBrancoPretoPreto() || sensores.brancoBrancoPretoBranco() || sensores.brancoBrancoBrancoBranco()){
    
    movimento.fren();
    delay(800);
    movimento.re();
    delay(600);

    while (sensores.brancoBrancoBrancoBranco()){
      robo.acionarMotores(35, -35);
    }
   }
   seguirLinha();   
  
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
    delay(100);
  }
  else if (sensores.pretoPretoPretoBranco())  {
    movimento.dir();
    delay(100);
  }
  else if (sensores.brancoPretoBrancoBranco())  {
    movimento.esq();
    delay(100);
  }
  else if (sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
    delay(100);
  }
  else if (sensores.brancoBrancoPretoPreto())  {
    movimento.dir();
    delay(100);
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

  oSala3.alinhar();
  
}

void Estrategia::desviarObstaculo() {
  
  while (sensores.brancoMdir()){
    robo.acionarMotores(0, -30);
  }
  
  movimento.fren();
  delay(350);
  
  while (sensores.brancoMdir()){
   robo.acionarMotores(-20, -30);
  }

  while (sensores.brancoMesq()){
   robo.acionarMotores(-30, 0);
  }
  
  movimento.parar();
  delay(500);
  
  if (sensores.pretoPretoPretoPreto()){
   movimento.fren();
   delay(900);
   movimento.girando();
   delay(800);
   movimento.parar();
   while(1);
  }


  
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

