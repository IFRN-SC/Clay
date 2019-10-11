#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"
#include "Sala3.h"


class Estrategia
{
 private:
   
    Sensores sensores;
    Movimento movimento;
    Sala3 sala3;
    
    const int pinoChave = 50; 
    const int pinoChave2 = 21;
    int contador = 0; 
    int calibrador = 0;
    int verdes = 0;
    int beco = 0;
    int delayObs = 0;
    int delayObs2 = 0;
    
    float sensorFrontal;
    float sensorLateralDir;
    float sensorLateralEsq;
    
    float valorSensorMaisEsq;
    float valorSensorEsq;
    float meio;
    float valorSensorDir;
    float valorSensorMaisDir;
    
    bool parar;

 public:

    void regularDelays();
    void desviarObs();
    void desviarObs2();
    void executa();
    void seguirLinha();
    void desviarObstaculo();
    void rampa();
    void Sala3();
    void defineObs();

    void calibrarVerdes();
    inline void setValoresCalibracao(Calibrador c){sensores.setValoresCalibracao(c);}
};
#endif
