#include "robo_hardware2.h"
#include "Movimento.h"

void Movimento:: fren(){
	robo.acionarMotores(45,45);
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
