#include "robo_hardware2.h"
#include "Movimento.h"

 void Movimento:: fren()
{
    robo.acionarMotores(50, 55);
}
 void Movimento:: stopp()
{
    robo.acionarMotores(0, 0);
    while(1);
}
 void Movimento:: re(){
    robo.acionarMotores(-56, -50);
}
void Movimento:: girarEsq45()
{
  robo.acionarMotores(60, -65);
  delay(450);
}
void Movimento:: girarEsq90()
{
    robo.acionarServoGarra1(40); //BRAÇO
    robo.acionarServoGarra2(75); //GARRA
    robo.acionarMotores(0, 0);
    delay(500);
  
    robo.acionarMotores(60, -65);
    delay(900);
}
void Movimento:: girarDir90()
{
    robo.acionarServoGarra1(40); //BRAÇO
    robo.acionarServoGarra2(75); //GARRA

     robo.acionarMotores(0, 0);
    delay(500);
    robo.acionarMotores(-60, 65);
    delay(1100);
}
void Movimento:: girarDir45()
{
    robo.acionarMotores(-60, 65);
    delay(550);
}
void Movimento:: frenmed(){
    robo.acionarMotores(50,50);
}
void Movimento:: superfrent(){
    robo.acionarMotores(70, 75);
}
 void Movimento:: esq(){
    robo.acionarMotores(61,-65);
}
 void Movimento:: dir(){
    robo.acionarMotores(-71, 55);
}
 void Movimento:: exesq(){
    robo.acionarMotores(66, -60);
}
 void Movimento:: exdir(){
    robo.acionarMotores(-66, 60);
}
 void Movimento:: parar(){
    robo.acionarMotores(0, 0);
}
 void Movimento:: girando(){
    robo.acionarMotores(-60, 60);
}
 void Movimento:: girandoEsq()
{
  robo.acionarMotores(60, -60);
}
 void Movimento:: esqq(){
    robo.acionarMotores(66,50);
}
 void Movimento:: dirr(){
    robo.acionarMotores(56, 60);
}
