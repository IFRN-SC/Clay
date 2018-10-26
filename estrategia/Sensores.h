#ifndef SENSORES_H
#define SENSORES_H

#include "Logica.h"
#include "Calibrador.h"

class Sensores{

  private:

    Logica logica;

  public:

    bool brancoBrancoBrancoBranco();

    bool brancoBrancoBrancoPreto();

    bool brancoBrancoPretoBranco();

    bool brancoBrancoPretoPreto();

    bool brancoPretoBrancoBranco();

    bool brancoPretoPretoBranco();

    bool pretoBrancoBrancoBranco();

    bool pretoPretoPretoPreto();

    bool pretoPretoPretoBranco();

    bool brancoPretoPretoPreto();

    bool pretoPretoBrancoBranco();

    bool brancoPretoBrancoPreto();

    bool branco();

    bool Branco();

    bool Preto();

    bool preto();

    bool Brancobranco();

    bool brancoPreto();

    bool brancoBranco();

    
    
    inline void setValoresCalibracao(Calibrador c){logica.setValoresCalibracao(c);}
};

#endif
