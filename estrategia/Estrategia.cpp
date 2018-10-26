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
    
    if (sensorFrontal < 5) {    
      desviarObstaculo();
    }
    else if (sensorLateral < 10) {
      rampa();
    }
    else if (valorSensorMaisEsq > 97){
     redutor();
    }
    //else if (valorSensorMaisEsq >= 60 && valorSensorMaisEsq <= 65){
   // verde();
    //}
    //else if (valorSensorMaisDir >= 60 && valorSensorMaisDir <= 65){
    ///verde1();
    //}

    else {
      seguirLinha();
    }

  }
  void Estrategia::redutor() {

    movimento.redutor();
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

    movimento.parar();
    delay(1000);

    movimento.girando();
    delay(700);

    movimento.parar();
    delay(1000);

    while (sensores.brancoBrancoBrancoBranco()) {
      movimento.re();
    }
    while (sensores.brancoBrancoBrancoBranco()){
      movimento.obs1();
    }

    movimento.fren();
    delay(1100);

    movimento.obs1();
    delay(600);

    movimento.fren();
    delay(400);

    movimento.esq();
    delay(400);

    movimento.fren();
    delay(1300);

    movimento.fren();
    delay(500);

    movimento.esq();
    delay(400);

    movimento.fren();
    delay(400);

    movimento.fren();
    delay(500);

    while (sensores.brancoBrancoBrancoBranco()) {
     seguirLinha();
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

