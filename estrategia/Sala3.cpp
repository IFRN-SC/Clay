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
  robo.acionarMotores(-40, -34);
  delay(2200);
  movimento.re();
  delay(300);
  movimento.fren();
  delay(200);
  movimento.re();
  delay(600);

  if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    robo.ligarTodosLeds();
    entregar();
 }
  robo.acionarMotores(54, 50);
  delay(300);
  robo.acionarMotores(40, -40);
  delay(400);
  robo.acionarMotores(36, 30);
  delay(600);
  movimento.girando();
  delay(450);
  robo.acionarMotores(-40, -40);
  delay(400);
  movimento.fren();
  delay(200);
  movimento.re();
  delay(200); 

  procurar();
}
void Sala3::procurar()
{
  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(36, 30);
  delay(2200);

  robo.acionarServoGarra1(80); //BRAÇO
  robo.acionarServoGarra2(120); //GARRA

  alinhar();
}
void Sala3::entregar()
{
  robo.acionarMotores(56, 50);
  delay(1000);
  robo.acionarMotores(40, -40);
  delay(400);
  robo.acionarMotores(-40, -34);
  delay(2200);
  robo.acionarMotores(35, 30);       ////sgnyiphiogsbhioio
  delay(1300);
  movimento.girando();
  delay(1200);
  robo.acionarMotores(-40, -34);
  delay(1250);
  robo.acionarMotores(35, 30);
  delay(500);
  robo.acionarMotores(40, -40);
  delay(900);
  robo.acionarMotores(35, 30);
  delay(500);
  
  robo.acionarServoGarra1(160); //BRAÇO
  robo.acionarServoGarra2(160); //GARRA
  
  movimento.parar();
  while(1);
}
void Sala3::umalinhar()
{
  robo.acionarMotores(54, 50);
  delay(150);
  movimento.girando();
  delay(450);
  robo.acionarMotores(-40, -40);
  delay(400);
  movimento.fren();
  delay(200);
  movimento.re();
  delay(200);

  robo.desligarTodosLeds();

  procurar();
}

