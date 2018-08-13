#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {
  float sensorFrontal;

  sensorFrontal = robo.lerSensorSonarFrontal();
  if(sensorFrontal < 10){
    desviarObstaculo();  
  }
  else{
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
  } else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exdir();
  } else if (sensores.pretoPretoPretoPreto()) {
    movimento.fren();
  } else if(sensores.brancoPretoPretoBranco()) {
    movimento.exdir();
  } else if(sensores.brancoBrancoPretoBranco()) {
    movimento.exdir();
  } else if(sensores.pretoPretoPretoBranco())  {
    movimento.fren();
  }
}
void Estrategia::verde() {
  
   if(sensores.brancoPretoPretoBranco())  {
    movimento.frenlen();
    
  }else if(sensores.pretoPretoPretoBranco())  {
    movimento.esq();
    
  }else if(sensores.pretoPretoPretoBranco())  {
    movimento.esq();
  }

  
  }
 
  
  
void Estrategia::sala3() {}
void Estrategia::desviarObstaculo() {
  
     movimento.parar();
     delay(500);
     movimento.dir();
     delay(500);
     movimento.parar();
     delay(500);
     movimento.fren();
     delay(800);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(500);
     movimento.parar();
     delay(500);
     movimento.fren();
     delay(1100);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(400);
     movimento.parar();
     delay(500);
     movimento.frenlen();
     delay(400);
     movimento.exesq();
     delay(400);

     while(sensores.brancoBrancoBrancoBranco()){
     movimento.frenlen();
     
     }
     
     
     
  }
