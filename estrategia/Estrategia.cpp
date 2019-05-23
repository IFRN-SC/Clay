#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  meio = robo.lerSensorLinhaMeio();

  if (sensorLateralEsq < 10 && sensorLateralDir < 10) {
    rampa();
}
  else if (robo.botao3Pressionado()){
    
    movimento.parar();
    delay(3000);
    contador = contador + 1;
 }
  else if (sensorFrontal < 4) {
    
  contador = contador + 1;

   if (contador == 1){
    obs1();    
 } else if (contador == 2){
    obs2();   
 } else if (contador == 3){
    obs1();
 } else if (contador == 4){
    obs2();
 }
 
}
  else {
    seguirLinha();
}

}
void Estrategia::redutor() {

    movimento.parar();
    delay(500);
    robo.desligarTodosLeds();
    robo.ligarTodosLeds();

    movimento.superfrent();
    delay(500);

    movimento.parar();
    delay(500);

    movimento.parar();
    delay(1000);

    movimento.re();
    delay(200);
    
  if (!sensores.BBBB()){
    seguirLinha();
  }
  if (sensores.BBBB()){
    
    robo.acionarMotores(-30, 30);
     delay(700);   
  
  }

  if (!sensores.BBBB()){
    seguirLinha();
  }
  while(sensores.BBBB()){
     robo.acionarMotores(30, -30);
  }

   movimento.re();
   delay(100);
   movimento.parar();
   delay(1000);
   movimento.fren();
   delay(100);

  robo.desligarTodosLeds();
  seguirLinha();
  
 }
void Estrategia::seguirLinha() {

  if (sensores.BBBB()) { //BRANCO-BRANCO-BRANCO-BRANCO
    movimento.fren();
}
  else if (sensores.BPBB()) { ;//BRANCO-PRETO-BRANCO-BRANCO
    movimento.esq();
}
  else if (sensores.BBPB()) { //BRANCO-BRANCO-PRETO-BRANCO
    movimento.dir();
}
  else if (sensores.PBBB()) { //PRETO-BRANCO-BRANCO-BRANCO
    movimento.exesq();
}
 else if (sensores.BBBP()) { //BRANCO-BRANCO-BRANCO-PRETO
    movimento.exdir();
}
  else if (sensores.PPPP()) { //PRETO-PRETO-PRETO-PRETO  

    movimento.re();
    delay(300); 
    movimento.parar();
    delay(200); 
    
    seguirLinha();
}
  else if (sensores.BPPB()){ //BRANCO-PRETO-PRETO-BRANCO
    movimento.re();
    delay(300);
}
  else if (sensores.PPBB())  { //PRETO-PRETO-BRANCO-BRANCO
     
     robo.ligarLed(3);
     movimento.fren();
     delay(50);
     
     movimento.parar();
     delay(300);

     if (sensores.PB()){
      movimento.fren();
      delay(200);
}
     
     while (sensores.MB()){
      movimento.exesq();  
}    
    robo.desligarLed(3);
}
  else if (sensores.BBPP())  { //BRANCO-BRANCO-PRETO-PRETO

    robo.ligarLed(2);
    movimento.fren();
    delay(50);
     
    movimento.parar();
     delay(300);

    if (sensores.PB()){
      movimento.fren();
      delay(200);
}
    while (sensores.MB()){
      movimento.exdir();
}   
    robo.desligarLed(2);
}
 else if (sensores.PPPD())  { //BRANCO-BRANCO-PRETO-PRETO

    robo.ligarLed(2);
    movimento.fren();
    delay(50);
     
    movimento.parar();
     delay(300);

    if (sensores.PB()){
      movimento.fren();
      delay(200);
}
    while (sensores.MB()){
      movimento.exdir();
}   
    robo.desligarLed(2);
}
 else if (sensores.PPPE())  { //PRETO-PRETO-BRANCO-BRANCO
 
     robo.ligarLed(3);
     movimento.fren();
     delay(50);
     
     movimento.parar();
     delay(300);

     if (sensores.PB()){
      movimento.fren();
      delay(200);
}
     
     while (sensores.MB()){
      movimento.exesq();  
}    
    robo.desligarLed(3);
}
}  
void Estrategia::verde2() {
  movimento.fren();
  delay(300);
  robo.acionarMotores(30, -35);
  delay(500);
  movimento.fren();
  delay(200);

  movimento.parar();
  delay(100);
  seguirLinha();
}
void Estrategia::verde1() {
  movimento.fren();
  delay(300);
  robo.acionarMotores(-35, 30);
  delay(500);
  movimento.fren();
  delay(200);

  movimento.parar();
  delay(100);
  seguirLinha();
}
void Estrategia::rampa() {
  
   robo.ligarLed(3);  
   parar = false;

  while (!parar) {

    if (sensores.BBBB()) {
      movimento.superfrent();
 }
    else if (sensores.BPBB()) {
      movimento.esqq();
 }
    else if (sensores.BBPB()) {
      movimento.dirr();
 }
    else if (sensores.PPPB()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500);
       Sala3();       
    }
    else if (sensores.BPPP()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500);
       Sala3(); 
    }
    else if (sensores.PPPP()) {
      movimento.superfrent();
      delay(500);
      movimento.parar();
      delay(500); 
      Sala3(); 
    }  
  }
}
void Estrategia::Sala3() {

    for (int a= 0; a  < 5; a++){
        robo.ligarLed(1);
        delay(100);
        robo.ligarLed(2);
        delay(100);
        robo.ligarLed(3);
        delay(100);
        robo.desligarLed(1);
        delay(100);
        robo.desligarLed(2);
        delay(100);
        robo.desligarLed(3);
        delay(100);
}

    movimento.parar();
    delay(2000);

    movimento.re();
    delay(400);
    movimento.fren();
    delay(400);
    movimento.girando();
    delay(700);
    movimento.re();
    delay(700);
    robo.acionarMotores(28, 24);
    delay(400);
    robo.acionarMotores(-45, -45);
    delay(500);
    robo.acionarMotores(28, 24);
    delay(500);
    robo.acionarMotores(-28, -24);
    delay(700);

for(int i=0; i<8; i++){
    sala3.procurar();
    sala3.alinhar(); 
 }  
}
void Estrategia::desviarObstaculo() { //15/05/2019 "RIP"
 
 robo.ligarLed(3);
  
  movimento.fren();
  delay(100);
  
  while (sensores.brancoEsq()){
    robo.acionarMotores(-45, 0);
}
  while (sensores.brancoDir()){
    robo.acionarMotores(-45, 0);
}
 
  movimento.frenmed();
  delay(450);
  movimento.rodaEsqMais();
  delay(1050);
  robo.ligarLed(1);

  movimento.frenmed();
  delay(500);
  
  movimento.parar();
  delay(300);
  movimento.rodaEsqMais();
  delay(950);
  robo.ligarLed(2);

  movimento.re();
  delay(300);
  movimento.parar();
  delay(300);

  if (sensores.PB()){
    movimento.re();
    delay(200);
}
  while (sensores.brancoMesq()){
    movimento.frenmed();
}

  robo.acionarMotores(-40, 40);
  delay(600);
    
  seguirLinha();
}
void Estrategia:: led(){

  for (int o = 0; o < 3; o++){
    movimento.parar();
    delay(200);
    robo.ligarLed(1);
    delay(100);
    robo.ligarLed(3);
    delay(100);
    robo.ligarLed(2);
    delay(100);
    robo.desligarTodosLeds();
    delay(100);
    robo.ligarTodosLeds();
    delay(100);
    robo.desligarTodosLeds();
    
}
}
void Estrategia:: obs1(){

  robo.ligarLed(3);
  
  movimento.fren();
  delay(100);
  
  while (sensores.brancoEsq()){
    robo.acionarMotores(-35, 0);
}
  while (sensores.brancoDir()){
    robo.acionarMotores(-35, 0);
}
 
  movimento.frenmed();
  delay(450);
  movimento.rodaEsqMais();
  delay(1050);
  robo.ligarLed(1);

  movimento.frenmed();
  delay(350);
  
  movimento.parar();
  delay(300);
  movimento.rodaEsqMais();
  delay(950);
  robo.ligarLed(2);

  movimento.re();
  delay(300);
  movimento.parar();
  delay(300);

  if (sensores.PB()){
    movimento.re();
    delay(200);
}
  while (sensores.brancoMesq()){
    movimento.frenmed();
}    
  robo.acionarMotores(-40, 40);
  delay(600);

  while(sensores.MB()){
    robo.acionarMotores(40, -40);
}
    
  seguirLinha(); 
}
void Estrategia:: obs2(){

 robo.ligarLed(3);
  
  movimento.fren();
  delay(100);
  
  while (sensores.brancoEsq()){
    robo.acionarMotores(-35, 0);
}
  while (sensores.brancoDir()){
    robo.acionarMotores(-35, 0);
}
 
  movimento.frenmed();
  delay(450);
  movimento.rodaEsqMais();
  delay(1050);
  robo.ligarLed(1);

  movimento.frenmed();
  delay(350);
  
  movimento.parar();
  delay(300);
  movimento.rodaEsqMais();
  delay(950);
  robo.ligarLed(2);

  movimento.re();
  delay(300);
  movimento.parar();
  delay(300);

  if (sensores.PB()){
    movimento.re();
    delay(200);
}
 while (sensores.brancoMesq()){
    movimento.frenmed();
}  
 robo.acionarMotores(-40, 40);
 delay(600);
 
 while(sensores.MB()){
    robo.acionarMotores(-40, 40);
}
    
  seguirLinha(); 
}
