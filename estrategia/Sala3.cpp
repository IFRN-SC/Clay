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
  delay(500); 

  sensorLateralDir = robo.lerSensorSonarDir();
  if (sensorLateralDir < 31)
 {
    procurardois();
 }
    procurar();
}
void Sala3::procurar()
{
  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(35, 30);
  delay(2300);

  robo.acionarServoGarra1(80); //BRAÇO
  robo.acionarServoGarra2(120); //GARRA

  alinhar();
}
void Sala3::procurardois()
{
  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(35, 30);
  delay(1700);

  robo.acionarServoGarra1(80); //BRAÇO
  robo.acionarServoGarra2(120); //GARRA

  alinhar();
}
void Sala3::entregar()
{
  robo.acionarMotores(56, 50);
  delay(1300);
  robo.acionarMotores(40, -40);
  delay(400);
  robo.acionarMotores(-40, -34);
  delay(2200);
  robo.acionarMotores(35, 30);       //marca
  delay(1600);
  movimento.girando();
  delay(1200);
  robo.acionarMotores(-40, -34);
  delay(1350);
  robo.acionarMotores(35, 30);
  delay(500);
  robo.acionarMotores(40, -40);
  delay(900);
  robo.acionarMotores(35, 30);
  delay(800);
  
  robo.acionarServoGarra1(110); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  movimento.parar();
  while(1);
}
void Sala3::umalinhar()
{
  movimento.parar();
  delay(2000);
  movimento.re();
  delay(50);
  movimento.girando();
  delay(550);
  robo.acionarMotores(-40, -40);
  delay(1000);
  movimento.re();
  delay(300);
  
  robo.acionarMotores(37, 30);
  delay(600);

  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(37, 30);
  delay(1600);
  
  robo.acionarServoGarra1(80); //BRAÇO
  robo.acionarServoGarra2(120); //GARRA

  movimento.parar();
  delay(1000);
  if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    robo.acionarMotores(0, -50);
    delay(300);
    robo.acionarMotores(-50, 0);
    delay(300);
    
    robo.acionarMotores(-40, -34);
    delay(3000);
    robo.ligarTodosLeds();
    entregar();
 }
  robo.acionarMotores(37, 30);
  delay(600);
  
  robo.acionarMotores(40, -40);
  delay(400);
  movimento.re();
  delay(1300);

  robo.acionarServoGarra1(180); //BRAÇO
  robo.acionarServoGarra2(180); //GARRA
  
  robo.acionarMotores(30, 30);
  delay(1500);

  robo.acionarServoGarra1(80); //BRAÇO
  robo.acionarServoGarra2(120); //GARRA

  movimento.parar();
  delay(1000);
  
  if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    movimento.girando();
    delay(600);
    robo.acionarMotores(-40, -34);
    delay(3000);
    robo.ligarTodosLeds();
    entregar();
 }

   robo.acionarMotores(40, -40); // volta pra pegar a bola 
   delay(600);
   movimento.re();
   delay(800);
   
   robo.acionarServoGarra1(180); //BRAÇO
   robo.acionarServoGarra2(180); //GARRA
   
   robo.acionarMotores(35, 30);
   delay(2300);
   
   robo.acionarServoGarra1(80); //BRAÇO
   robo.acionarServoGarra2(120); //GARRA

   robo.acionarMotores(40, -40);
   delay(1000);
   robo.acionarMotores(-40, -34);
   delay(1000);
   
    if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    robo.ligarTodosLeds();
    entregar();
 }
   robo.acionarMotores(37, 30);
   delay(400);
   robo.acionarMotores(40, -40);
   delay(500);
   robo.acionarServoGarra1(180); //BRAÇO
   robo.acionarServoGarra2(180); //GARRA
   
   robo.acionarMotores(37, 30);
   delay(1300);

   robo.acionarServoGarra1(80); //BRAÇO
   robo.acionarServoGarra2(120); //GARRA

   robo.acionarMotores(0, -50);
   delay(2000);
   movimento.re();
   delay(1500);
   
   if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    robo.ligarTodosLeds();
    entregar();
 }
 
   robo.acionarMotores(37, 30);
   delay(400);
   movimento.girando();
   delay(500);

   robo.acionarServoGarra1(180); //BRAÇO
   robo.acionarServoGarra2(180); //GARRA
   
   robo.acionarMotores(35, 30);
   delay(2300);

   robo.acionarServoGarra1(80); //BRAÇO
   robo.acionarServoGarra2(120); //GARRA  

   robo.acionarMotores(40, -40);
   delay(600);
   movimento.re();
   delay(1000);
   
   if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
 {
    robo.ligarTodosLeds();
    entregar();
 }
 
   robo.desligarTodosLeds();

   procurar();
}

