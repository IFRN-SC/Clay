#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"

class Estrategia{

Sensores sensores;
Movimento movimento;

public:

void executa();
void seguirLinha();
void verde();
void sala3();
void desviarObstaculo();

inline void setValoresCalibracao(Calibrador c){sensores.setValoresCalibracao(c);}

};
