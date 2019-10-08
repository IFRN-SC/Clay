#include "robo_hardware2.h"
#include "Movimento.h"

 void Movimento:: fren()
{
    robo.acionarMotores(50, 57);
}
 void Movimento:: stopp()
{
    robo.acionarMotores(0, 0);
    while(1);
}
 void Movimento:: re(){
    robo.acionarMotores(-50, -50);
}
void Movimento:: girarEsq45()
{
  robo.acionarMotores(60, -60);
  delay(550);
}
void Movimento:: girarEsq90()
{
    robo.acionarServoGarra1(40); //BRAÇO
    robo.acionarServoGarra2(20); //GARRA
  
    robo.acionarMotores(60, -60);
    delay(1030);
}
void Movimento:: girarDir90()
{
    robo.acionarServoGarra1(40); //BRAÇO
    robo.acionarServoGarra2(20); //GARRA
    
    robo.acionarMotores(-60, 60);
    delay(1030);
}
void Movimento:: girarDir45()
{
    robo.acionarMotores(-60, 60);
    delay(550);
}
void Movimento:: frenmed(){
    robo.acionarMotores(50,50);
}
void Movimento:: superfrent(){
    robo.acionarMotores(70, 70);
}
 void Movimento:: esq(){
    robo.acionarMotores(65,-55);
}
 void Movimento:: dir(){
    robo.acionarMotores(-55, 65);
}
 void Movimento:: exesq(){
    robo.acionarMotores(60, -60);
}
 void Movimento:: exdir(){
    robo.acionarMotores(-60, 60);
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
    robo.acionarMotores(70,40);
}
 void Movimento:: dirr(){
    robo.acionarMotores(40, 70);
}
