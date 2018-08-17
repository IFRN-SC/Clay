#include "robo_hardware2.h"
#include "Movimento.h"

void Movimento:: fren() {
  robo.acionarMotores(45, 45);
}
void Movimento:: dir() {
  robo.acionarMotores(-55, 50);
}
void Movimento:: esq() {
  robo.acionarMotores(50, -55);
}
void Movimento:: exdir() {
  robo.acionarMotores(-60, 50);
}
void Movimento:: exesq() {
  robo.acionarMotores(50, -60);
}
void Movimento:: parar() {
  robo.acionarMotores(0, 0);
}
void Movimento:: frenlen() {
  robo.acionarMotores(30, 30);
}
void Movimento:: girando() {
  robo.acionarMotores(-40, -40);
}

