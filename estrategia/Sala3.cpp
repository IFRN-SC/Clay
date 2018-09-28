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
      parar = true;
    }
    else if (sensores.pretoPretoBrancoBranco()) {
      movimento.exesq();
      parar = true;
    }
    else if (sensores.brancoBrancoPretoPreto()) {
      movimento.exdir();
      parar = true;
    }
  }
}
