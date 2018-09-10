#ifndef CALIBRACAO_H
#define CALIBRACAO_H

#include "Calibrador.h"
  
class Calibracao{

Calibrador calibrador;

float sRME;
float sRE;
float sRD;
float sRMD;
float valorMaisEsq;
float valorEsq;
float valorDir;
float valorMaisDir;

public:

bool bValorMaisEsq();
bool pValorMaisEsq();

bool bValorEsq();
bool pValorEsq();

bool bValorDir();
bool pValorDir();

bool bValorMaisDir();
bool pValorMaisDir();

void valores();
void calibrar();
void atualizarVME();
void atualizarVE();
void atualizarVD();
void atualizarVMD();

void setValoresCalibracao(Calibrador c);

};

#endif
