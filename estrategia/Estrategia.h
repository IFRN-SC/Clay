#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"
#include "Sala3.h"

class Estrategia{

  private:
  
    #define VERMELHO 1
    #define AMARELO 2
    #define VERDE 3
   
    Sensores sensores;
    Movimento movimento;
    Sala3 sala3;
   
    int contador = 0; 
    const int pinoChave = 50;
    const int pinoChave2 = 21;

    float sensorLateralDir;
    float sensorLateralEsq;
    float sensorFrontal;

    float valorSensorEsq;
    float valorSensorDir;
    float valorSensorMaisEsq;
    float valorSensorMaisDir;
    float meio;
    
    bool parar;

  public:
    
    void obs1();
    void obs2();

    void executa();
    void seguirLinha();
    void verde1();
    void verde2();
    void desviarObstaculo();
    void redutor();
    void voltarParaALinha();
    void rampa();
    void Sala3();
    void led();
    void redutoresq();
    void redutordir();
    
    inline void setValoresCalibracao(Calibrador c){sensores.setValoresCalibracao(c);}

};

#endif
