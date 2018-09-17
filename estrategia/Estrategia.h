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
    
    bool parar;

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
