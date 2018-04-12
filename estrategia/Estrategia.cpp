#include "Estrategia.h"
#include "robo_hardware.h"
#define CINZA 50

void Estrategia::executa(){

}
void Estrategia::seguirLinha(){

if(lerSensorLinhaMaisDir()<=CINZA && lerSensorLinhaDir()<=CINZA && lerSensorLinhaEsq()<=CINZA && lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(-50,50);

}else if(lerSensorLinhaMaisDir()<=CINZA && lerSensorLinhaDir()<=CINZA && lerSensorLinhaEsq()<=CINZA && lerSensorLinhaMaisEsq()>=CINZA){

robo.acionarMotores(-50,-50);

}else if(lerSensorLinhaMaisDir()<=CINZA && lerSensorLinhaDir()<=CINZA && lerSensorLinhaEsq()>=CINZA && lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(-50,50);

}else if(lerSensorLinhaMaisDir()<=CINZA && lerSensorLinhaDir()<=CINZA && lerSensorLinhaEsq()>=CINZA && lerSensorLinhaMaisEsq()>=CINZA){

robo.acionarMotores(-50,-50);

}else if(lerSensorLinhaMaisDir()<=CINZA && lerSensorLinhaDir()>=CINZA && lerSensorLinhaEsq()<=CINZA && lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(50,50);

}else if(lerSensorLinhaMaisDir()<=CINZA && lerSensorLinhaDir()>=CINZA && lerSensorLinhaEsq()>=CINZA && lerSensorLinhaMaisEsq()<=CINZA){

robo.acionarMotores(50,50);

}else{

robo.acionarMotores(-50,50);

}

}
void Estrategia::verde(){}
void Estrategia::sala3(){}
void Estrategia::desviarObstaculo(){}
