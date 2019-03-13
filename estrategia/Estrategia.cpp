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
    rampa();
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

void Estrategia::rampa() {
  
  parar = false;

  while (!parar) {

    if (sensores.brancoBrancoBrancoBranco()) {
      movimento.superfrent();
    }
    else if (sensores.brancoPretoBrancoBranco()) {
      movimento.esqq();
    }
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.dirr();
    }
    else if (sensores.brancoBrancoBrancoPreto()) {
      movimento.exesq();
    }
    else if (sensores.pretoBrancoBrancoBranco()) {
      movimento.exdir();
    }
    else if (sensores.pretoPretoPretoPreto()) {
      movimento.superfrent();
      delay(900);
    }
    else if (sensores.pretoPretoPretoBranco()) {
      movimento.superfrent();
      delay(900);
    }
    else if (sensores.brancoPretoPretoPreto()) {
      movimento.superfrent();
      delay(900);
    }
    else if (sensores.pretoPretoBrancoBranco()) {
      robo.acionarMotores(-60, 60);
      delay(1000);

      movimento.parar();

      parar = true;
    }
    else if (sensores.brancoBrancoPretoPreto()) {
      robo.acionarMotores(60, -60);
      delay(1000);
      movimento.parar();
      parar = true;
    }
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

void Estrategia::desviarObstaculo() {

  
  while (sensores.brancoMdir()){
    robo.acionarMotores(0, -30);
  }
  
  movimento.fren();
  delay(250);
  
  while (sensores.brancoMdir()){
   robo.acionarMotores(-30, -40);
  }

  while (sensores.brancoMesq()){
   robo.acionarMotores(-40, 0);
  }
  
  movimento.parar();
  delay(500);
  
  if (sensores.pretoPretoPretoPreto()){

   movimento.fren();
   delay(800);
   movimento.parar();
   delay(500);
   robo.acionarMotores(-40, 40);
   delay(800);
   movimento.parar();
   delay(500);
   robo.acionarMotores(70, 70);
   delay(700);
   /*movimento.parar();
   delay(100);
   robo.acionarMotores(0, - 40);
   delay(200);
   movimento.parar();
   delay(100);
   movimento.fren();
   delay(400);
   movimento.parar();
   delay(100);
   movimento.fren(); //É esse!!! hgkgkyh
   delay(500);*/
   
   movimento.parar();
   delay(500);
   robo.acionarMotores(-40, 40);
   delay(700);
   
   while(!sensores.pretoPretoPretoPreto()){
    movimento.frenlen();
   }
   if(!sensores.brancoBrancoBrancoBranco()){
    
    robo.acionarMotores(30, 30);
    delay(600);
    robo.acionarMotores(50, -50);
    delay(500);
    movimento.parar();
    delay(100);
    robo.acionarMotores(-30, -30);
    delay(500);
    movimento.parar();
    delay(1000);

   }
  }
   seguirLinha();
  
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

