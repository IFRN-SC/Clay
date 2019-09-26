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
    robo.acionarMotores(-57, -50);
}
void Movimento:: girarEsq45()
{
  robo.acionarMotores(60, -60);
  delay(500);
}
void Movimento:: girarEsq90()
{
    robo.acionarServoGarra1(50); //BRAÇO
    robo.acionarServoGarra2(100); //GARRA
    
    //robo.acionarMotores(0, 0);
    //delay(500);
  
    robo.acionarMotores(60, -60);
    delay(1055);
}
void Movimento:: girarDir90()
{
    robo.acionarServoGarra1(50); //BRAÇO
    robo.acionarServoGarra2(100); //GARRA
    
    //robo.acionarMotores(0, 0);
    //delay(500);
    
    robo.acionarMotores(-60, 60);
    delay(1140);
}
void Movimento:: girarDir45()
{
    robo.acionarMotores(-60, 60);
    delay(500);
}
void Movimento:: frenmed(){
    robo.acionarMotores(50,50);
}
void Movimento:: superfrent(){
    robo.acionarMotores(70, 70);
}
 void Movimento:: esq(){
    robo.acionarMotores(45,-45);
}
 void Movimento:: dir(){
    robo.acionarMotores(-45, 45);
}
 void Movimento:: exesq(){
    robo.acionarMotores(70, -50);
}
 void Movimento:: exdir(){
    robo.acionarMotores(-50, 70);
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
