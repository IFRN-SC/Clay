#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {
  float sensorFrontal;

  sensorFrontal = robo.lerSensorSonarFrontal();
  if(sensorFrontal <= 10){
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
    //delay(200);
    
  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.esq();
    
  } else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exesq();
    //delay(200);
  } else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exdir();
   //delay(150);
  } else if (sensores.pretoPretoPretoPreto()) {
<<<<<<< Updated upstream
    movimento.fren();
  } else if(sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
    //delay(1000);
  } else if(sensores.brancoBrancoPretoBranco()) {
    movimento.exdir();
    delay(150);
  } else if(sensores.pretoPretoPretoBranco())  {
    movimento.esq();
    delay(300);
  } else if(sensores.brancoPretoBrancoBranco())  {
    movimento.dir();
    delay(300);
  } else if(sensores.pretoPretoBrancoBranco())  {
    movimento.esq();
    delay(300);
  } else if(sensores.brancoBrancoPretoPreto())  {
    movimento.esq();
    delay(300);
  } 
  
}
void Estrategia::verde() {

=======
    robo.acionarMotores(50, 50);
  }else if (sensores.pretoPretoPretoBranco()){
    robo.acionarMotores(50, -60);
  }else if (sensores.pretoBrancoBrancoPreto()){
    robo.acionarMotores(50, -60);
>>>>>>> Stashed changes
  }
   else if (sensores.pretoBrancoPretoPreto()){
   robo.acionarMotores(-60, 50);
   }

void Estrategia::sala3() {}
void Estrategia::desviarObstaculo() {
     
     movimento.parar();
     delay(5000);
     movimento.dir();
     delay(450);
     movimento.parar();
     delay(500);
     movimento.fren();
     delay(800);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(400);
     movimento.parar();
     delay(500);
     movimento.fren();
     delay(1400);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(400);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(100);

     while(sensores.brancoBrancoBrancoBranco()){
     movimento.frenlen();

     
     }
 
  }
