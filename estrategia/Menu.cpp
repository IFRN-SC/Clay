#include "robo_hardware2.h"
#include "Menu.h"


void Menu::menuLon(){

  while(!pare){
    if(!robo.botao1Pressionado()){
      calibracao.calibrar();
      pare = true;
    }
  }
  
}

