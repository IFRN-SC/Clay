#include "robo_hardware2.h"
#include "Sensores.h"

#define CINMESQ 41.38
#define CINESQ  50.37
#define CINDIR  47.67
#define CINMDIR 44.64

void Sensores:: atualizar() {
  valorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorEsq = robo.lerSensorLinhaEsq();
  valorDir = robo.lerSensorLinhaDir();
  valorMaisDir = robo.lerSensorLinhaMaisDir();

  calibrador
}

bool Sensores:: brancoBrancoBrancoBranco() {

  atualizar();

  return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

  //return(calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.bValorDir() && calibracao.bValorMaisDir());
}

bool Sensores:: brancoBrancoBrancoPreto() {

  atualizar();

  return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir <= CINZA);

  //return(calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.bValorDir() && calibracao.pValorMaisDir());

}

bool Sensores:: brancoBrancoPretoBranco() {

  atualizar();

  return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

  //return (calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.pValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: brancoBrancoPretoPreto() {

  atualizar();

  return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

  //return(calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

}

bool Sensores:: brancoPretoBrancoBranco() {

  atualizar();

  return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir > CINZA && valorMaisDir > CINZA);

  //return (calibracao.bValorMaisEsq() && calibracao.pValorEsq() && calibracao.bValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: brancoPretoPretoBranco() {

  atualizar();

  return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

  //return (calibracao.bValorMaisDir() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: pretoBrancoBrancoBranco() {

  atualizar();

  return (valorMaisEsq <= CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

  //return (calibracao.pValorMaisEsq() && calibracao.bValorEsq() && calibracao.bValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: pretoPretoPretoPreto() {

  atualizar();

  return (valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

  //return (calibracao.pValorMaisEsq() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

}
bool Sensores:: pretoPretoPretoBranco() {

  atualizar();

  return (valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

  //return (calibracao.pValorMaisEsq() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

} bool Sensores:: brancoPretoPretoPreto() {

  atualizar();

  return (valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

  //return (calibracao.pValorMaisEsq() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

} bool Sensores:: pretoPretoBrancoBranco() {

  atualizar();

  return (valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

  //return (calibracao.pValorMaisEsq() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

} bool Sensores:: brancoPretoBrancoPreto() {

  atualizar();

  return (valorMaisEsq <= CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

  //return (calibracao.pValorMaisEsq() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

}

