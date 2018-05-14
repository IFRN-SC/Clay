#include "robo_hardware2.h"
#include "Sensores.h"
#define CINZA 50

void Sensores:: atualizar(){
double valorMaisEsq = robo.lerSensorLinhaMaisEsq();
double valorEsq = robo.lerSensorLinhaEsq();
double valorDir = robo.lerSensorLinhaDir();
double valorMaisDir = robo.lerSensorLinhaMaisDir();

}

bool Sensores:: brancoBrancoBrancoBranco(){

atualizar();

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoBrancoBrancoPreto(){

atualizar();

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir <= CINZA);

}

bool Sensores:: brancoBrancoPretoBranco(){

atualizar();

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoBrancoPretoPreto(){

atualizar();

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

}

bool Sensores:: brancoPretoBrancoBranco(){

atualizar();

return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoPretoPretoBranco(){

atualizar();

return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

}

bool Sensores:: pretoBrancoBrancoBranco(){

atualizar();

return (valorMaisEsq <= CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}


bool Sensores:: senao(){

atualizar();

}

