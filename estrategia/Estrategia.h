#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"

class Estrategia{

  private:
    #define VERMELHO 1
    #define AMARELO 2
    #define VERDE 3
   
    Sensores sensores;
    Movimento movimento;

    float sensorFrontal;
    float sensorLateral;
    float sensorBaixo;
    
    bool parar;

  public:

    void led();
    void executa();
    void seguirLinha();
    void verde();
    void rampa();
    void desviarObstaculo();
    void redutor();
    void voltarParaALinha();
    void sala3();

    inline void setValoresCalibracao(Calibrador c){sensores.setValoresCalibracao(c);}

};

#endif
