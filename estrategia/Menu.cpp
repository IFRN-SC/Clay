#include "robo_hardware2.h"
#include "Menu.h"


void Menu::menuLon(){

  Serial.println("Pressione botao1 para calibrar.");
  while(!pare){
    
    if(!robo.botao1Pressionado()){
      calibrador.calibrar();
      pare = true;
    }
  }

  printDados();
}

void Menu::printDados(){
  Serial.println("Dados calibrados:");
  Serial.print("Media mais esquerdo: ");
  Serial.println(calibrador.getSRME());
}

