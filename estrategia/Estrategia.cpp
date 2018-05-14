#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Sensores.cpp"

void Estrategia::executa(){

}
void Estrategia::seguirLinha(){

if(Sensores::brancoBrancoBrancoBranco()){

robo.acionarMotores(-50,50);

}else if(Sensores:: brancoBrancoBrancoPreto()){

robo.acionarMotores(-50,-50);

}else if(Sensores:: brancoBrancoPretoBranco()){

robo.acionarMotores(-50,50);

}else if(Sensores:: brancoBrancoPretoPreto()){

robo.acionarMotores(-50,-50);

}else if(Sensores:: brancoPretoBrancoBranco()){

robo.acionarMotores(50,50);

}else if(Sensores:: brancoPretoPretoBranco(){

robo.acionarMotores(50,50);

}else if(Sensores:: pretoBrancoBrancoBranco()){

robo.acionarMotores(50,50);

}else{

robo.acionarMotores(-50,50);

}

}
void Estrategia::verde(){}
void Estrategia::sala3(){}
void Estrategia::desviarObstaculo(){}
