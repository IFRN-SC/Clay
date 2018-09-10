#ifndef CALIBRADOR_H
#define CALIBRADOR_H

#include "robo_hardware2.h"


class Calibrador {
//    Calibracao calibracao;
    float v1, v2, v3, v4; //Armazena valores para 12 testes BRANCO E PRETO(faremos vários testes, pois assim o resultado é mais preciso)
    float s1, s2, s3, s4; //Armazena as somas dos 12 testes REFLETE-BRANCO ou REFLETE-PRETO
    float md1b, md2b, md3b, md4b; //Armazena as médias tiradas DO BRANCO no primeiro instante(Não as definitivas)
    float md1p, md2p, md3p, md4p; //Armazena as médias tiradas DO PRETO no primeiro instante(Não as definitivas)
    float sRME, sRE, sRD, sRMD; //VALOR CALIBRADO DE CADA SENSOR(MÉDIA FINAL)
    

  public:

    void calibrar();
    float getSRME();
    float getSRE();
    float getSRD();
    float getSRMD();
    

};

#endif
