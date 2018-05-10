#include "robo_hardware2.h"
#include "Sensores.h"
#define CINZA 50

valorMaisEsq = robo.lerSensorLinhaMaisEsq();
double valorEsq = robo.lerSensorLinhaEsq();
double valorDir = robo.lerSensorLinhaDir();
double valorMaisDir = robo.lerSensorLinhaMaisDir();


bool Sensores:: brancoBrancoBrancoBranco(){

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoBrancoBrancoPreto(){

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir <= CINZA);

}

bool Sensores:: brancoBrancoPretoBranco(){

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoBrancoPretoPreto(){

return (valorMaisEsq > CINZA && valorEsq > CINZA && valorDir <= CINZA && valorMaisDir <= CINZA);

}

bool Sensores:: brancoPretoBrancoBranco(){

return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: brancoPretoPretoBranco(){

return (valorMaisEsq > CINZA && valorEsq <= CINZA && valorDir <= CINZA && valorMaisDir > CINZA);

}

bool Sensores:: pretoBrancoBrancoBranco(){
 
return (valorMaisEsq <= CINZA && valorEsq > CINZA && valorDir > CINZA && valorMaisDir > CINZA);

}

bool Sensores:: senao(){
}

