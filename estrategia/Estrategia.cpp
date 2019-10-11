#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::calibrarVerdes()
{
  movimento.parar();
  delay(1000);
  while (!robo.botao1Pressionado())
  {
    movimento.parar();

   if (robo.botao2Pressionado()) //DIR
   {
    movimento.parar();
    delay(500);
    verdes = verdes + 10;
   }
   else if (robo.botao3Pressionado()) //ESQ
   {
    movimento.parar();
    delay(500);
    verdes = verdes + 4;
   }
  }
}
void Estrategia::defineObs()
{
   while (!robo.botao3Pressionado())
{
    
   if (robo.botao1Pressionado()) 
{ 
    movimento.parar();
    delay(1000);

    contador = contador + 1;
}
}
}
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
    verdes = verdes + 1;
    movimento.fren();
    delay(200);
    
    if (verdes == 2)
{
    movimento.exesq();
    delay(1750);
    movimento.re();
    delay(200);
}
    else if (!sensores.BBBBB())
{
    movimento.parar();
    delay(500);

    if (verdes >= 4 && verdes < 7)
  {
     while (sensores.PB())
  {
    movimento.exesq();
  }
    while (sensores.MB())
  {
    movimento.exesq();
  }
    while (sensores.PB())
  {
    movimento.exesq();
  }
    movimento.fren();
    delay(400);
    movimento.re();
    delay(200);
    seguirLinha();
  }

  
    else if (verdes > 8)
  {

    while (sensores.PB())
  {
    movimento.exdir();
  }
    while (sensores.MB())
  {
    movimento.exdir();
  }
    while (sensores.PB())
  {
    movimento.exdir();
  }
    movimento.fren();
    delay(400);
    movimento.re();
    delay(200);
    seguirLinha();
  }
    seguirLinha();
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
void Estrategia:: desviarObs()
{
    movimento.re();
    delay(150);
  
    movimento.girarDir90();
    while (sensores.BBBBB())
    {
      movimento.re();
    }

    while (!sensores.BBBBB())
    {
      movimento.fren();
    }

    while (!sensores.MB())
    {
      robo.acionarMotores(-50, 0);
    }
    movimento.fren();
    delay(1250);
    robo.acionarMotores(60, -65);
    delay(900);
    movimento.fren();
    delay(1700);
    robo.acionarMotores(60, -65);
    delay(900);

    while(sensores.BBBBB())
    {
      movimento.fren();
    }
    movimento.fren();
    delay(250);

    
    robo.acionarMotores(-60, 65);
    delay(1000);

    movimento.re();
    delay(200);

    while (sensores.MB())
    {
      movimento.exesq();
    }

    while (sensores.PB())
    {
      movimento.exesq();
    }

    movimento.re();
    delay(100);
 
    seguirLinha();
}
void Estrategia:: desviarObs2()
{
     movimento.re();
    delay(150);
  
    movimento.girarDir90();
    while (sensores.BBBBB())
    {
      movimento.re();
    }

    while (!sensores.BBBBB())
    {
      movimento.fren();
    }

    while (!sensores.MB())
    {
      robo.acionarMotores(-50, 0);
    }
    movimento.fren();
    delay(1250);
    robo.acionarMotores(60, -65);
    delay(900);
    movimento.fren();
    delay(1700);
    robo.acionarMotores(60, -65);
    delay(900);

    while(sensores.BBBBB())
    {
      movimento.fren();
    }
    movimento.fren();
    delay(250);

    
    robo.acionarMotores(-60, 65);
    delay(1000);

    movimento.re();
    delay(200);

    while (sensores.MB())
    {
      movimento.exdir();
    }

    while (sensores.PB())
    {
      movimento.exdir();
    }

    movimento.re();
    delay(100);
 
    seguirLinha();
}
