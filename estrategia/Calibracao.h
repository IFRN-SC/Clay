#ifndef CALIBRACAO
#define CALIBRACAO

  
  class Calibracao{

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

};

#endif
