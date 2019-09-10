#include "robo_hardware2.h"
#include "Movimento.h"

 void Movimento:: fren(){
    robo.acionarMotores(50, 50);
}
void Movimento:: frenmed(){
    robo.acionarMotores(50,50);
}
void Movimento:: reDir()
{
  robo.acionarMotores(-30, 0);
}
void Movimento:: reEsq()
{
  robo.acionarMotores(0, -35);
}
void Movimento:: frenlen(){
    robo.acionarMotores(20, 20);
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
  robo.acionarMotores(40, -40);
}
 void Movimento:: esqq(){
    robo.acionarMotores(70,40);
}
 void Movimento:: dirr(){
    robo.acionarMotores(40, 70);
}
 void Movimento:: re(){
    robo.acionarMotores(-55, -50);
}
void Movimento:: rodaDirMenos(){
  robo.acionarMotores(0, -35);
}
void Movimento:: rodaEsqMenos(){
  robo.acionarMotores(-35, 35);
}
void Movimento:: rodaDirMais(){
  robo.acionarMotores(0, 35);
}
void Movimento:: rodaEsqMais(){
  robo.acionarMotores(35, 0);
}
