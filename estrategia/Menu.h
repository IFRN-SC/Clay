#ifndef MENU_H
#define MENU_H


#include "Calibrador.h"

class Menu{
  
  private:
    
    Calibrador calibrador;
    bool pare;
    
    calibracao_dados val; //dados de calibracao para sensores de cor e sensores de refletancia
    
      /*****  Dados existentes na Struct calibracao_dados  *******************


        int refletanciaDir;
        int refletanciaMaisDir;
        int refletanciaEsq;
        int refletanciaMaisEsq;

     ************************/

  
  public:
    void menuLon();
    void printDados();
    const Calibrador getValoresCalibracao(){return calibrador;}
 
};

#endif
