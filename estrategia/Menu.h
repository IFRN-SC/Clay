#include "Calibrador.h"

class Menu{
  Calibrador calibrador;
  bool pare;

  void printDados();
  
  public:
  void menuLon();

  const Calibrador getValoresCalibracao(){return calibrador;}
 
};

