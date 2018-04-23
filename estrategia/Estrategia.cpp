#include "Estrategia.h"
#include "robo_hardware2.h"
#define CINZA 50

void Estrategia::executa(){

}
void Estrategia::seguirLinha(){

if(robo.lerSensorLinhaMaisDir()<=CINZA && robo.lerSensorLinhaDir()<=CINZA && robo.lerSensorLinhaEsq()<=CINZA && robo.lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(-50,50);

}else if(robo.lerSensorLinhaMaisDir()<=CINZA && robo.lerSensorLinhaDir()<=CINZA && robo.lerSensorLinhaEsq()<=CINZA && robo.lerSensorLinhaMaisEsq()>=CINZA){

robo.acionarMotores(-50,-50);

}else if(robo.lerSensorLinhaMaisDir()<=CINZA && robo.lerSensorLinhaDir()<=CINZA && robo.lerSensorLinhaEsq()>=CINZA && robo.lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(-50,50);

}else if(robo.lerSensorLinhaMaisDir()<=CINZA && robo.lerSensorLinhaDir()<=CINZA && robo.lerSensorLinhaEsq()>=CINZA && robo.lerSensorLinhaMaisEsq()>=CINZA){

robo.acionarMotores(-50,-50);

}else if(robo.lerSensorLinhaMaisDir()<=CINZA && robo.lerSensorLinhaDir()>=CINZA && robo.lerSensorLinhaEsq()<=CINZA && robo.lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(50,50);

}else if(robo.lerSensorLinhaMaisDir()<=CINZA && robo.lerSensorLinhaDir()>=CINZA && robo.lerSensorLinhaEsq()>=CINZA && robo.lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(50,50);

}else{

robo.acionarMotores(-50,50);

}

}
void Estrategia::verde(){}
void Estrategia::sala3(){}
void Estrategia::desviarObstaculo(){}
