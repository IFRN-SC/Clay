#include "robo_hardware2.h"
#include "Sensores.h"


  bool Sensores:: brancoBrancoBrancoBranco() {

    return (logica.bValorMaisEsq() && logica.bValorEsq() && logica.bValorDir() && logica.bValorMaisDir());
  }

  bool Sensores:: brancoBrancoBrancoPreto() {

    return (logica.bValorMaisEsq() && logica.bValorEsq() && logica.bValorDir() && logica.pValorMaisDir());

  }

  bool Sensores:: brancoBrancoPretoBranco() {

    return (logica.bValorMaisEsq() && logica.bValorEsq() && logica.pValorDir() && logica.bValorMaisDir());

  }

  bool Sensores:: brancoBrancoPretoPreto() {

    return (logica.bValorMaisEsq() && logica.bValorEsq() && logica.pValorDir() && logica.pValorMaisDir());

  }

  bool Sensores:: brancoPretoBrancoBranco() {

    return (logica.bValorMaisEsq() && logica.pValorEsq() && logica.bValorDir() && logica.bValorMaisDir());

  }

  bool Sensores:: brancoPretoPretoBranco() {

    return (logica.bValorMaisDir() && logica.pValorEsq() && logica.pValorDir() && logica.bValorMaisDir());

  }

  bool Sensores:: pretoBrancoBrancoBranco() {

    return (logica.pValorMaisEsq() && logica.bValorEsq() && logica.bValorDir() && logica.bValorMaisDir());

  }

  bool Sensores:: pretoPretoPretoPreto() {

    return (logica.pValorMaisEsq() && logica.pValorEsq() && logica.pValorDir() && logica.pValorMaisDir());

  }
  bool Sensores:: pretoPretoPretoBranco() {

    return (logica.pValorMaisEsq() && logica.pValorEsq() && logica.pValorDir() && logica.pValorMaisDir());

  } 
  bool Sensores:: brancoPretoPretoPreto() {

    return (logica.pValorMaisEsq() && logica.pValorEsq() && logica.pValorDir() && logica.pValorMaisDir());

  } 
  bool Sensores:: pretoPretoBrancoBranco() {

    return (logica.pValorMaisEsq() && logica.pValorEsq() && logica.pValorDir() && logica.pValorMaisDir());

  } 
  bool Sensores:: brancoPretoBrancoPreto() {

    return (logica.pValorMaisEsq() && logica.pValorEsq() && logica.pValorDir() && logica.pValorMaisDir());

  }
    bool Sensores:: branco() {

    return (logica.pValorMaisEsq());

  }
  bool Sensores:: Branco() {

    return (logica.pValorMaisDir());

  }
  
  bool Sensores:: preto() {

    return (logica.pValorMaisEsq());
  }
  
  bool Sensores:: Preto() {

    return (logica.pValorMaisDir());
  }

  bool Sensores:: brancoPreto() {

    return (logica.pValorMaisEsq() && logica.pValorEsq ());
  }

   bool Sensores:: brancoBranco() {

    return (logica.pValorDir() && logica.pValorMaisDir());

  }
  

