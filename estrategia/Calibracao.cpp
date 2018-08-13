#include "robo_hardware2.h"
#include "Calibracao.h"



#define CINMESQ 58
#define CINESQ  59
#define CINDIR  61
#define CINMDIR 64

//Funções para atualizar os valores de cada sensor
void Calibracao:: atualizarVME(){
   valorMaisEsq=robo.lerSensorLinhaMaisEsq();
}
void Calibracao:: atualizarVE(){
	valorEsq=robo.lerSensorLinhaEsq();
}
void Calibracao:: atualizarVD(){
	valorDir= robo.lerSensorLinhaDir();
}
void Calibracao:: atualizarVMD(){
	valorMaisDir=robo.lerSensorLinhaMaisDir();
}

//Calibracao Sensor Mais Esquerdo
bool Calibracao:: bValorMaisEsq(){
	atualizarVME();
  return (valorMaisEsq > CINMESQ);
}

bool Calibracao:: pValorMaisEsq(){
	atualizarVME();
	return (valorMaisEsq <= CINMESQ);
}

//Calibracao Sensor Esquerdo
bool Calibracao:: bValorEsq(){
	atualizarVE();
	return (valorEsq > CINESQ);
}

bool Calibracao:: pValorEsq(){
	atualizarVE();
	return (valorEsq <= CINESQ);
}

//Calibracao Sensor Direito
bool Calibracao:: bValorDir(){
	atualizarVD();
	return (valorDir > CINDIR);
}

bool Calibracao:: pValorDir(){
	atualizarVD();
	return (valorDir <= CINDIR);
}

//Calibracao Sensor Mais Direito
bool Calibracao:: bValorMaisDir(){
	atualizarVMD();
	return(valorMaisDir > CINMDIR);
}

bool Calibracao:: pValorMaisDir(){
	atualizarVMD();
	return(valorMaisDir <= CINDIR);
}





