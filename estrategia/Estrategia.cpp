#include "Estrategia.h"
#define CINZA 50

void Estrategia::executa(){

}
void Estrategia::seguirLinha(){

if(refletancia_mais_dir<=CINZA && refletancia_dir<=CINZA && refletancia_esq<=CINZA && refletancia_mais_esq<=CINZA){

robo.acionarMotores(-50,50);

}else if(refletancia_mais_dir<=CINZA && refletancia_dir<=CINZA && refletancia_esq<=CINZA && refletancia_mais_esq>=CINZA){

robo.acionarMotores(-50,-50);

}else if(refletancia_mais_dir<=CINZA && refletancia_dir<=CINZA && refletancia_esq>=CINZA && refletancia_mais_esq<=CINZA){

robo.acionarMotores(-50,50);

}else if(refletancia_mais_dir<=CINZA && refletancia_dir<=CINZA && refletancia_esq>=CINZA && refletancia_mais_esq>=CINZA){

robo.acionarMotores(-50,-50);

}else if(refletancia_mais_dir<=CINZA && refletancia_dir>=CINZA && refletancia_esq<=CINZA && refletancia_mais_esq<=CINZA){

robo.acionarMotores(50,50);

}else if(refletancia_mais_dir<=CINZA && refletancia_dir>=CINZA && refletancia_esq>=CINZA && refletancia_mais_esq<=CINZA){

robo.acionarMotores(50,50);

}else{

robo.acionarMotores(-50,50);

}

}
void Estrategia::verde(){}
void Estrategia::sala3(){}
void Estrategia::desviarObstaculo(){}
