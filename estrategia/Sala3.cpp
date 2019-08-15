#include "robo_hardware2.h"
#include "Sala3.h"

void Sala3::executar()  //EXECUTA_TODA_A_RESENHA
{
  pinMode(fimdocurso, INPUT_PULLUP);
  pinMode(fimdocurso2, INPUT_PULLUP);
 
  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  umalinhar();
}
void Sala3::alinhar()
{
  contador = contador + 2;
  robo.acionarMotores(-40, -34);
  delay(3000);
  movimento.re();
  delay(300);
  robo.acionarMotores(-40, -40);
  delay(500);

  if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    robo.ligarTodosLeds();
    entregar();
 }
  robo.acionarMotores(54, 50);
  delay(300);
  robo.acionarMotores(40, -40);
  delay(550);
  robo.acionarMotores(36, 30);
  delay(600);
  movimento.girando();
  delay(550);
  robo.acionarMotores(-40, -40);
  delay(400);
  movimento.fren();
  delay(200);
  robo.acionarMotores(-50, -50);
  delay(800); 

  sensorLateralDir = robo.lerSensorSonarDir();
  if (sensorLateralDir < 31)
 {
    procurardois();
 }
    procurar();
}
void Sala3::procurar() //VAGABUNDO
{
  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(47, 40);
  delay(1850);

  movimento.parar();
  delay(1000);
  
  robo.acionarServoGarra2(120); //GARRA
  movimento.parar();
  delay(500);
  robo.acionarServoGarra1(80); //BRAÇO
  

  alinhar();
}
void Sala3::procurardois()
{
  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(47, 40);
  delay(1400);

  robo.acionarServoGarra1(80); //BRAÇO
  robo.acionarServoGarra2(120); //GARRA

  alinhar();
}
void Sala3::entregar()
{
  if (contador == 1)
  {
    movimento.parar();
    while(1);
  }
  robo.acionarMotores(47, 40);
  delay(1400);
  robo.acionarMotores(40, -40);
  delay(500);
  robo.acionarMotores(-40, -34);
  delay(2200);
  robo.acionarMotores(45, 40);       //marca
  delay(1400);
  movimento.parar();
  delay(1000);
  movimento.girando();
  delay(1300);
  robo.acionarMotores(-40, -34);
  delay(1350);
  robo.acionarMotores(47, 40);
  delay(200);
  robo.acionarMotores(40, -40);
  delay(900);
  robo.acionarMotores(47, 40);
  delay(500);
  robo.acionarMotores(0, -45);
  delay(200);
  
  robo.acionarServoGarra1(130); //BRAÇO
  movimento.parar();
  delay(1000);
  robo.acionarServoGarra2(180); //GARRA
  
  movimento.parar();
  while(1);
}
void Sala3::umalinhar()
{
  contador = contador + 1;
  
  movimento.fren();
  delay(50);
  movimento.girando();
  delay(550);
  robo.acionarMotores(-40, -40);
  delay(1000);
  movimento.re();
  delay(300);
  robo.acionarMotores(47, 40);
  delay(300);
  robo.acionarMotores(-40, -40);
  delay(600);
  
 
  robo.desligarTodosLeds();

  procurar();
}

