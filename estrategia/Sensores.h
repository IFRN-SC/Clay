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

    bool branco1();

    bool branco2();

		bool entSala3();

    inline void setValoresCalibracao(Calibrador c){logica.setValoresCalibracao(c);}
};

#endif
