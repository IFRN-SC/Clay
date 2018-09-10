#include "robo_hardware2.h"
#include "Calibracao.h"


void Calibracao:: valores(){
  sRME = calibrador.getSRME();
  sRE = calibrador.getSRE();
  sRD = calibrador.getSRD();
  sRMD = calibrador.getSRMD();/*
  Serial.println(sRME);
  Serial.println(sRE);  
  Serial.println(sRD);  
  Serial.println(sRMD);  */
}

void Calibracao::calibrar(){
//  calibrador.calibrar();
}
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
  return (valorMaisEsq > sRME);
}

bool Calibracao:: pValorMaisEsq(){
	atualizarVME();
	return (valorMaisEsq <= sRME);
}

//Calibracao Sensor Esquerdo
bool Calibracao:: bValorEsq(){
	atualizarVE();
	return (valorEsq > sRE);
}

bool Calibracao:: pValorEsq(){
	atualizarVE();
	return (valorEsq <= sRE);
}

//Calibracao Sensor Direito
bool Calibracao:: bValorDir(){
	atualizarVD();
	return (valorDir > sRD);
}

bool Calibracao:: pValorDir(){
	atualizarVD();
	return (valorDir <= sRD);
}

//Calibracao Sensor Mais Direito
bool Calibracao:: bValorMaisDir(){
	atualizarVMD();
	return(valorMaisDir > sRMD);
}

bool Calibracao:: pValorMaisDir(){
	atualizarVMD();
	return(valorMaisDir <= sRMD);
}


void Calibracao::setValoresCalibracao(Calibrador c){
  calibrador=c;
  valores();
}


