#include "Calibrador.h"

class Menu{
  Calibrador calibrador;
  bool pare;
  
//  float sensorMEE;
//  float sensorEE;
//  float sensorDE;
//  float sensorMDE;
  


  void printDados();
  
  public:
  void menuLon();

  const Calibrador getValoresCalibracao(){return calibrador;}

  calibracao_dados val; //dados de calibracao para sensores de cor e sensores de refletancia
/*****  Dados existentes na Struct calibracao_dados  *******************


  int refletanciaDir;
  int refletanciaMaisDir;
  int refletanciaEsq;
  int refletanciaMaisEsq;
  



************************/

 
};

