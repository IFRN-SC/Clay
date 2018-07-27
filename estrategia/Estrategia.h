#include "Sensores.h"
#include "Movimento.h"
#include "Calibracao.h"

class Estrategia{

Sensores sensores;
Movimento movimento;

public:

void executa();
void seguirLinha();
void verde();
void sala3();
void desviarObstaculo();


};
