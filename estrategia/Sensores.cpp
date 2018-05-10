#include "robo_hardware2.h"
#include "Sensores.h"
#define CINZA 50

double valorMaisEsq = lerSensorLinhaMaisEsq();
double valorEsq = lerSensorLinhaEsq();
double valorDir = lerSensorLinhaDir();
double valorMaisDir = lerSensorLinhaMaisDir();


bool Sensores:: brancoBrancoBrancoBranco(){
 int contValor;
 if(valorMaisEsq > CINZA){
   contValor++;
}
 else if(valorEsq > CINZA){
  contValor++;
}
 else if(valorDir > CINZA){
   contValor++;
}
 else if(valorMaisDir > CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: brancoBrancoBrancoPreto(){
 int contValor;
 if(valorMaisEsq > CINZA){
   contValor++;
}
 else if(valorEsq > CINZA){
  contValor++;
}
 else if(valorDir > CINZA){
   contValor++;
}
 else if(valorMaisDir <= CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: brancoBrancoPretoBranco(){
 int contValor;
 if(valorMaisEsq > CINZA){
   contValor++;
}
 else if(valorEsq > CINZA){
  contValor++;
}
 else if(valorDir <= CINZA){
   contValor++;
}
 else if(valorMaisDir > CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: brancoBrancoPretoPreto(){
 int contValor;
 if(valorMaisEsq > CINZA){
   contValor++;
}
 else if(valorEsq > CINZA){
  contValor++;
}
 else if(valorDir <= CINZA){
   contValor++;
}
 else if(valorMaisDir <= CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: brancoPretoBrancoBranco(){
 int contValor;
 if(valorMaisEsq > CINZA){
   contValor++;
}
 else if(valorEsq <= CINZA){
  contValor++;
}
 else if(valorDir > CINZA){
   contValor++;
}
 else if(valorMaisDir > CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: brancoPretoPretoBranco(){
 int contValor;
 if(valorMaisEsq > CINZA){
   contValor++;
}
 else if(valorEsq <= CINZA){
  contValor++;
}
 else if(valorDir <= CINZA){
   contValor++;
}
 else if(valorMaisDir > CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: pretoBrancoBrancoBranco(){
 int contValor;
 if(valorMaisEsq <= CINZA){
   contValor++;
}
 else if(valorEsq > CINZA){
  contValor++;
}
 else if(valorDir > CINZA){
   contValor++;
}
 else if(valorMaisDir > CINZA){
  contValor++;
}

  if(contValor==4){
    return true;
}
  else{
   return false;
}

}

bool Sensores:: senao(){
}

