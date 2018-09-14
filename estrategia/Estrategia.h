#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"

class Estrategia{
  bool parar;

Sensores sensores;
Movimento movimento;

public:

void led();
void executa();
void seguirLinha();
void verde();
void sala3();
void desviarObstaculo();
void redutor();
void voltarParaALinha();

inline void setValoresCalibracao(Calibrador c){sensores.setValoresCalibracao(c);}

};
