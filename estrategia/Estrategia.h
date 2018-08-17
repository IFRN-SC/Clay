#include "Sensores.h"
#include "Movimento.h"
#include "CalibradorGT.h"

class Estrategia {

    CalibradorGT calibrador;
    Sensores sensores;
    Movimento movimento;

  public:

    void calibracao();
    void executa();
    void seguirLinha();
    void verde();
    void sala3();
    void desviarObstaculo();


};
