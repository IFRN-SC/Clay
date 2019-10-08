#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() 
{ 
  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  meio = robo.lerSensorLinhaMeio();

   if (sensorLateralEsq < 20 && sensorLateralDir < 20) 
{
    rampa();
}  
   else if (robo.botao1Pressionado())
{
    movimento.parar();
    delay(1000);
    
    delayObs = delayObs + 200;
}
   else if (robo.botao3Pressionado()) 
{ 
    movimento.parar();
    delay(1000);

    contador = contador + 1;
}

   else if (sensorFrontal < 4) 
{
   if (contador < 2)
  {
      desviarObs();    
  }
   if (contador > 1)
  {
      desviarObs2();
  }
}
   else 
{
    seguirLinha();
}
}
void Estrategia::seguirLinha() 
{
  if (sensores.BBBB()){movimento.fren();}
  
  else if (sensores.BPBB()){movimento.esq();}
  
  else if (sensores.BBPB()){movimento.dir();}
  
  else if (sensores.PBBB()){movimento.exesq();}

  else if (sensores.BBBP()){movimento.exdir();}
 
  else if (sensores.BPPB()){movimento.re();delay(200);}

  else if (sensores.PPPP()) 
{   
    movimento.fren();
    delay(200);

    if (!sensores.BBBBB())
{
    verdes = verdes + 1;
    movimento.parar();
    delay(500);

    if (verdes == 2)
  {
    movimento.fren();
    delay(300);
    movimento.girarEsq90();
    movimento.fren();
    delay(400);
    movimento.re();
    delay(200);
    seguirLinha();
  }
    else if (verdes == 3)
  {
    movimento.fren();
    delay(200);
    movimento.girarDir90();
    movimento.fren();
    delay(400);
    movimento.re();
    delay(200);
    seguirLinha();
  }
    seguirLinha();
}

    if (sensores.BBBBB())
{
    movimento.dir();
    delay(150);
    
    if (!sensores.BBBBB())
{
    verdes = verdes + 1;
}
    movimento.esq();
    delay(300);
    
    if (!sensores.BBBBB())
{   
    verdes = verdes + 1;
    //movimento.stopp();
}
    movimento.dir();
    delay(150);
    movimento.exesq();
    delay(1750);
    movimento.re();
    delay(100);
}
  
} else if (sensores.PPBB() || sensores.PPPE() || sensores.PPPBB() || sensores.PPBBB()){
      
    movimento.parar();
    delay(300);
    robo.ligarLed(3);
    movimento.fren();
    delay(300);

    if (!sensores.BBBBB())
  {
    movimento.fren();
    delay(600);
    
    while (sensores.BBBBB())
   {
     movimento.re();
   }
    movimento.exdir();
    delay(200);
  }
    while (sensores.MB()){
    movimento.exesq();  
}    
    while (sensores.PB()){
    movimento.exesq();
}
    movimento.re();
    delay(250);

} else if (sensores.BBPP() || sensores.PPPD() || sensores.BBPPP() || sensores.BBBPP()){ 
    
    movimento.parar();
    delay(300);
    robo.ligarLed(2);
    movimento.fren();
    delay(300);

     if (!sensores.BBBBB())
  {
    movimento.fren();
    delay(600);
    
    while (sensores.BBBBB())
   {
     movimento.re();
   }
    movimento.exesq();
    delay(200);
  }
    while (sensores.MB()){
    movimento.exdir();
}   
    while (sensores.PB()){
    movimento.exdir();
} 
    movimento.re();
    delay(250);
} 

 }
void Estrategia::rampa() 
{
   robo.acionarServoGarra1(140); //BRAÇO
   robo.acionarServoGarra2(75); //GARRA
   
   robo.ligarTodosLeds();
   
   sensorLateralDir = robo.lerSensorSonarDir();
   sensorLateralEsq = robo.lerSensorSonarEsq();

   delay(500);
   
   while(robo.lerSensorSonarEsq() < 20)
 {
     if (sensores.BBPBB()) 
 {      
       movimento.superfrent();
 }
     else if (sensores.BPBBB()) 
 {
       movimento.esqq();
 }
     else if (sensores.BBBPB()) 
 {
       movimento.dirr();
 }  
 }
     sala3.executar();
}
void Estrategia::desviarObstaculo() 
{ 
    movimento.re();
    delay(100);

    while (sensores.brancoMesq()){
        movimento.dir();    
    }
    while (sensores.pretoMesq()){
        movimento.dir();    
    }
    while (sensores.brancoMdir()){
        movimento.dir();    
    }

    robo.acionarMotores (0,0);
    delay (5000);
 
}
void Estrategia:: desviarObs()
{
    movimento.re();
    delay(100);
  
    while (sensores.brancoMesq())
{
    movimento.dir();    
}
    while (sensores.pretoMesq())
{
    movimento.dir();    
}
    movimento.exdir();    
    delay (700);
    
    while (robo.lerSensorSonarEsq() < 40)
{
    movimento.fren();      
}
    movimento.parar();
    delay(500);
    
    movimento.fren();      
    delay(1000);
    movimento.girarEsq90();
    movimento.fren();
    delay(1600 + delayObs);
    movimento.girarEsq90();
    movimento.fren();
    delay(200);

    while(sensores.BBBBB())
{
    movimento.fren();
}
    movimento.fren();
    delay(300);

    movimento.girarDir90();
    movimento.re();
    delay(200);
    
    if (sensores.BBBBB())
{
    movimento.girarEsq45();
}
    seguirLinha();
}
void Estrategia:: desviarObs2()
{
    movimento.re();
    delay(100);
  
    while (sensores.brancoMesq())
{
    movimento.dir();    
}
    while (sensores.pretoMesq())
{
    movimento.dir();    
}
    movimento.exdir();    
    delay (700);
    
    while (robo.lerSensorSonarEsq() < 40)
{
    movimento.fren();      
}
    movimento.parar();
    delay(500);
    
    movimento.fren();      
    delay(1000);
    movimento.girarEsq90();
    movimento.fren();
    delay(1600 + delayObs);
    movimento.girarEsq90();
    movimento.fren();
    delay(200);

    while(sensores.BBBBB())
{
    movimento.fren();
}
    movimento.fren();
    delay(300);

    movimento.girarDir90();
    movimento.re();
    delay(200);
    
    if (sensores.BBBBB())
{
    movimento.girarDir45();
}
    seguirLinha();
}
