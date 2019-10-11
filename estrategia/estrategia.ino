#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Servo.h"
#include "Menu.h"

  Estrategia estrategia;
  Menu menu;
  
  void setup() 
{  
    robo.configurar(true);
    Serial.begin(9600);
    robo.acionarServoGarra1(40); //BRAÇO
    robo.acionarServoGarra2(75); //GARRA
    menu.menuLon(); 
    
    estrategia.setValoresCalibracao(menu.getValoresCalibracao());
    //estrategia.defineObs();
    estrategia.calibrarVerdes();
}
  void loop() 
{  
    estrategia.executa();
}
