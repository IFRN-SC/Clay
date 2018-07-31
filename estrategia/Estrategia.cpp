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
void Estrategia::verde() {}
void Estrategia::sala3() {}
void Estrategia::desviarObstaculo() {
    while(true){
     robo.acionarMotores(0,0);
    }
   
  }
