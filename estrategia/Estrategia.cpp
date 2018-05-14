#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa(){
	seguirLinha();
}
void Estrategia::seguirLinha(){

	if(sensores.brancoBrancoBrancoBranco()){

		robo.acionarMotores(-50,50);

	}else if(sensores.brancoBrancoBrancoPreto()){

		robo.acionarMotores(-50,-50);

	}else if(sensores.brancoBrancoPretoBranco()){

		robo.acionarMotores(-50,50);

	}else if(sensores.brancoBrancoPretoPreto()){

		robo.acionarMotores(-50,-50);

	}else if(sensores.brancoPretoBrancoBranco()){

		robo.acionarMotores(50,50);

	}else if(sensores.brancoPretoPretoBranco()){

		robo.acionarMotores(50,50);

	}else if(sensores.pretoBrancoBrancoBranco()){

		robo.acionarMotores(50,50);

	}else{

		robo.acionarMotores(-50,50);

	}

}
void Estrategia::verde(){}
void Estrategia::sala3(){}
void Estrategia::desviarObstaculo(){}
