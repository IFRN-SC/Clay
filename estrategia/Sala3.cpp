#include "robo_hardware2.h"
#include "Sala3.h"

void Sala3::executar() 
{
  pinMode(fimdocurso, INPUT_PULLUP);
  pinMode(fimdocurso2, INPUT_PULLUP);
  
  robo.desligarTodosLeds();
  delay(400);

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  movimento.parar();
  delay(500);

  if (sensorLateralDir < 15 || sensorLateralEsq > 15)
{
    tipoSala = tipoSala + 1; //TIPO SALA 1
    procurarAreaResgate();
}
  else if (sensorLateralEsq < 15 || sensorLateralDir > 15)
{
    tipoSala = tipoSala + 2; //TIPO SALA 2
    procurarAreaResgate();
}
}
void Sala3:: procurarAreaResgate()
{
  if (tipoSala == 1)
  {
    garraAbaixada();
    movimento.parar();
    delay(500);
    movimento.fren();
    delay(1000);
    garraFechada();
    garraLevantada();

    movimento.girandoEsq();
    delay(500);
    movimento.re();
    delay(400);
    robo.acionarMotores(-43, -40);
    delay(800);
    movimento.fren();
    delay(50);
    
    movimento.fren();
    delay(1500);
    movimento.girando();
    delay(500);
    movimento.re();
    delay(2500);
    movimento.fren();
    delay(50);
    
    garraAbaixada();
    movimento.fren();
    delay(2000);
    garraFechada();
    garraLevantada();
    movimento.parar();
    delay(500);
    movimento.girandoEsq();   //SOB OBSERVAÇÃO
    delay(400);

    sensorFrontal = robo.lerSensorSonarFrontal(); //TIPOAREA 1
    if (sensorFrontal < 40)
{ 
    tipoArea = tipoArea + 1; 
    movimento.girando();
    delay(500);
    movimento.re();
    delay(400);
    movimento.girandoEsq();
    delay(100);
    movimento.re();
    delay(2000);
    movimento.fren();
    delay(350);
    movimento.girandoEsq();
    delay(500);
    movimento.re();
    delay(2000);
 
    movimento.parar();
    delay(500);
    procurar();
}
    //AREA 2
    
    movimento.girando();
    delay(600);
    
    sensorFrontal = robo.lerSensorSonarFrontal();
    if (sensorFrontal < 40)
{
    tipoArea = tipoArea + 2;
    parar();
}
    movimento.girando();
    delay(900);

    sensorFrontal = robo.lerSensorSonarFrontal();
    if (tipoArea == 0)
{
    tipoArea = tipoArea + 3;
    parar();
}
}
}
void Sala3:: procurar()
{
  if (tipoArea == 1)
{
  garraAbaixada();
  movimento.fren();
  delay(2500);
  garraFechada();

  robo.acionarMotores(-36, -30);
  delay(3100);
  
    if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
{
    resgatar(); 
}
    alinhar();
}
}
void Sala3:: alinhar()
{
  if (tipoArea == 1)
{
  movimento.fren();
  delay(400);
  movimento.girando();
  delay(400);
  garraAbaixada();
  movimento.fren();
  delay(500);
  garraFechada();
  movimento.girandoEsq();
  delay(500);
  movimento.re();
  delay(900);

  procurar();
}
}
void Sala3:: resgatar()
{
  robo.ligarTodosLeds();
  if (tipoArea == 1)
{
  movimento.fren();
  delay(1600);
  movimento.parar();
  delay(400);
  movimento.girando();
  delay(500);
  movimento.parar();
  delay(400);
  movimento.re();
  delay(2500);
  movimento.fren();
  delay(50);
  movimento.fren();
  delay(1800);
  movimento.girando();
  delay(600);
  movimento.re();
  delay(1600);
  movimento.parar();
  delay(500);
  movimento.fren();
  delay(500);
  movimento.parar();
  delay(500);
  movimento.girandoEsq();
  delay(900);
  movimento.parar();
  delay(500);
  movimento.fren();
  delay(500);
  repeticaoBolaEncontrada();
  parar();
}
}















void Sala3:: garraAbaixada()
{
  robo.acionarServoGarra1(180);
  robo.acionarServoGarra2(180);
}
void Sala3:: garraLevantada()
{
  robo.acionarServoGarra1(100);
  robo.acionarServoGarra2(140);
}
void Sala3:: garraFechada()
{
  robo.acionarServoGarra2(110);
  movimento.parar();
  delay(400);
  robo.acionarServoGarra1(90);
}
void Sala3:: garraAbaixadaBola()
{
  robo.acionarServoGarra2(170);
  movimento.parar();
  delay(1000);
  robo.acionarServoGarra1(130);
}
void Sala3:: repeticaoBolaEncontrada()
{
  garraAbaixadaBola();
  movimento.parar();
  delay(500);
  garraFechada();
  movimento.parar();
  delay(500);
  garraAbaixadaBola();
}
void Sala3:: parar()
{
  movimento.parar();
  while (1);
}
void Sala3::bolinhaIdentificada()
{
  if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
  {
    robo.acionarMotores(0, 0);//resgatar(); 
    while(1);
  }
}
