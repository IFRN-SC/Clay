#include "robo_hardware2.h"
#include "Movimento.h"

void Movimento:: fren(){
	robo.acionarMotores(50,50);
}
void Movimento:: dir(){
	robo.acionarMotores(-50,50);
}
void Movimento:: esq(){
	robo.acionarMotores(50,-50);
}
void Movimento:: exdir(){
	robo.acionarMotores(-60,50);
}
void Movimento:: exesq(){
	robo.acionarMotores(50,-60);
}
void Movimento:: parar(){
  robo.acionarMotores(0, 0);
}
void Movimento:: frenlen(){
  robo.acionarMotores(30, 30);
}

