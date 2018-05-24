#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa(){
	seguirLinha();
}
void Estrategia::seguirLinha(){

	if(sensores2.brancoBranco()){

		robo.acionarMotores(50,-50);

	}else if(sensores2.brancoPreto()){

		robo.acionarMotores(50,-50);

	}else if(sensores2.pretoBranco()){

		robo.acionarMotores(-50,50);

	}else if(sensores2.pretoPreto()){

		robo.acionarMotores(50,-50);
	}else{

		robo.acionarMotores(50,-50);

	}

}
void Estrategia::verde(){}
void Estrategia::sala3(){}
void Estrategia::desviarObstaculo(){}
