#include "robo_hardware2.h"
#include "Sensores.h"

#define CINMESQ 50
#define CINESQ 50
#define CINDIR 50
#define CINMDIR 50

double valorMaisEsq = robo.lerSensorLinhaMaisEsq();
double valorEsq = robo.lerSensorLinhaEsq();
double valorDir = robo.lerSensorLinhaDir();
double valorMaisDir = robo.lerSensorLinhaMaisDir();


void Sensores:: atualizar(){
	valorMaisEsq = robo.lerSensorLinhaMaisEsq();
	valorEsq = robo.lerSensorLinhaEsq();
	valorDir = robo.lerSensorLinhaDir();
	valorMaisDir = robo.lerSensorLinhaMaisDir();

}

bool Sensores:: brancoBrancoBrancoBranco(){

	atualizar();

	return (valorMaisEsq > CINMESQ && valorEsq > CINESQ && valorDir > CINDIR && valorMaisDir > CINMDIR);

	//return(calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.bValorDir() && calibracao.bValorMaisDir());
}

bool Sensores:: brancoBrancoBrancoPreto(){

	atualizar();

	return (valorMaisEsq > CINMESQ && valorEsq > CINESQ && valorDir > CINDIR && valorMaisDir <= CINMDIR);

	//return(calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.bValorDir() && calibracao.pValorMaisDir());

}

bool Sensores:: brancoBrancoPretoBranco(){

	atualizar();

	return (valorMaisEsq > CINMESQ && valorEsq > CINESQ && valorDir <= CINDIR && valorMaisDir > CINMDIR);

	//return (calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.pValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: brancoBrancoPretoPreto(){

	atualizar();

	return (valorMaisEsq > CINMESQ && valorEsq > CINESQ && valorDir <= CINDIR && valorMaisDir <= CINMDIR);

	//return(calibracao.bValorMaisEsq() && calibracao.bValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());

}

bool Sensores:: brancoPretoBrancoBranco(){

	atualizar();

	return (valorMaisEsq > CINMESQ && valorEsq <= CINESQ && valorDir > CINDIR && valorMaisDir > CINMDIR);

	//return (calibracao.bValorMaisEsq() && calibracao.pValorEsq() && calibracao.bValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: brancoPretoPretoBranco(){

	atualizar();

	return (valorMaisEsq > CINMESQ && valorEsq <= CINESQ && valorDir <= CINDIR && valorMaisDir > CINMDIR);

	//return (calibracao.bValorMaisDir() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: pretoBrancoBrancoBranco(){

	atualizar();

	return (valorMaisEsq <= CINMESQ && valorEsq > CINESQ && valorDir > CINDIR && valorMaisDir > CINMDIR);

	//return (calibracao.pValorMaisEsq() && calibracao.bValorEsq() && calibracao.bValorDir() && calibracao.bValorMaisDir());

}

bool Sensores:: pretoPretoPretoPreto(){

  	atualizar();

  	return(valorMaisEsq <= CINMESQ && valorEsq <= CINESQ && valorDir <= CINDIR && valorMaisDir <= CINMDIR);

	//return (calibracao.pValorMaisEsq() && calibracao.pValorEsq() && calibracao.pValorDir() && calibracao.pValorMaisDir());
  
  }

