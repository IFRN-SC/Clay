#include "Sala3.h"
#include "robo_hardware2.h"

void Sala3:: alinhar() {

  movimento.dirS3();
  delay(100);
  while (!robo.botao2Pressionado());
}

void Sala3:: rampa() {

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


