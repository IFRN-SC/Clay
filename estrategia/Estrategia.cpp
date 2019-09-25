#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() 
{
  pinMode(pinoChave, INPUT_PULLUP);
  pinMode(pinoChave2, INPUT_PULLUP);

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  meio = robo.lerSensorLinhaMeio();

   if (sensorLateralEsq < 20 && sensorLateralDir < 20) 
{
    rampa();
}  
   else if (robo.botao3Pressionado())
{
    
    movimento.parar();
    delay(1000);
    contador = contador + 1;
}
   else if (sensorFrontal < 4) {
    
   contador = contador + 0;

   if (contador == 0){
    obs1();    
} /*else if (contador == 2){
    obs2();   
} else if (contador == 3){
    obs1();
} else if (contador == 4){
    obs2();
}
*/
}
  else 
{
    seguirLinha();
}
}
void Estrategia::redutor() {

   movimento.superfrent();
   delay(400);

   seguirLinha();
   delay(200);

   movimento.parar();
   delay(300);
   
   if (!sensores.BBBBB()){
    seguirLinha();
}
   while (sensores.BBBBB()){ //pararara
    robo.acionarMotores(-30, -30);
}
  seguirLinha();
}
void Estrategia::seguirLinha() {

  if (sensores.BBBB()) { //BRANCO-BRANCO-BRANCO-BRANCO
    //reconhecerRampa();
    movimento.fren();
}
  else if (sensores.BPBB()) { ;//BRANCO-PRETO-BRANCO-BRANCO
    //reconhecerRampa();
    movimento.esq();
}
  else if (sensores.BBPB()) { //BRANCO-BRANCO-PRETO-BRANCO
    //reconhecerRampa();
    movimento.dir();
}
  else if (sensores.PBBB()) { //PRETO-BRANCO-BRANCO-BRANCO
    movimento.exesq();
}
 else if (sensores.BBBP()) { //BRANCO-BRANCO-BRANCO-PRETO
    movimento.exdir();
}
  else if (sensores.PPPP()) { //PRETO-PRETO-PRETO-PRETO 
    movimento.parar();
    delay(1000);

    movimento.fren();
    delay(500);
}
  else if (sensores.BPPB()){ //BRANCO-PRETO-PRETO-BRANCO
    movimento.re();
    delay(300);
}
  else if (sensores.PPBB())  { //PRETO-PRETO-BRANCO-BRANCO
       
     movimento.parar();
     delay(300);
     
     robo.ligarLed(3);
 
     movimento.fren();
     delay(180);
    
     while (sensores.MB()){
      movimento.exesq();  
}    
    movimento.exesq();
    delay(100);
    robo.desligarLed(3);

} else if (sensores.BBPP())  { //BRANCO-BRANCO-PRETO-PRETO
    
    movimento.parar();
     delay(300);
     
    robo.ligarLed(2);
    
    movimento.fren();
    delay(180);
    
    while (sensores.MB()){
      movimento.exdir();
}   
    movimento.exdir();
    delay(100);
    robo.desligarLed(2);

} else if (sensores.PPPD())  { //BRANCO-BRANCO-PRETO-PRETO
 
    movimento.parar();
     delay(300);
     
    robo.ligarLed(2);
    
    movimento.fren();
    delay(180);
    
    while (sensores.MB()){
      movimento.exdir();
}   
    movimento.exdir();
    delay(100);
    robo.desligarLed(2);

} else if (sensores.PPPE())  { //PRETO-PRETO-BRANCO-BRANCO
   
     movimento.parar();
     delay(300);
     
     robo.ligarLed(3);
     
     movimento.fren();
     delay(180);
    
     while (sensores.MB()){
      movimento.exesq();  
}    
     movimento.exesq();
     delay(100);
     robo.desligarLed(3);
     
} else if (sensores.PPPBB()) { //PRETO-PRETO-PRETO-BRANCO-BRANCO

     movimento.parar();
     delay(300);
     
     robo.ligarLed(3);
     
     movimento.fren();
     delay(180);
     
     while (sensores.MB()){
      movimento.exesq();  
}    
    movimento.exesq();
    delay(100);
    robo.desligarLed(3);

} else if (sensores.BBPPP()){  //BRANCO-BRANCO-PRETO-PRETO-PRETO
    
    movimento.parar();
     delay(300);
     
    robo.ligarLed(2);
    
    movimento.fren();
    delay(180);
    
    while (sensores.MB()){
      movimento.exdir();
}   
    movimento.exdir();
    delay(100);
    robo.desligarLed(2);

} else if (sensores.BBBPP()){  //BRANCO-BARNCO-BRANCO-PRETO-PRETO
    
    movimento.parar();
    delay(300);
     
    robo.ligarLed(2);
    
    movimento.fren();
    delay(180);
    
    while (sensores.MB()) {
      movimento.exdir();
}   
    movimento.exdir();
    delay(100);
    robo.desligarLed(2);
} else if (sensores.PPBBB()) {   //PRETO-PRETO-BRANCO-BRANCO-BRANCO
      
     movimento.parar();
     delay(300);
     
     robo.ligarLed(3);
     movimento.fren();
     delay(180); 
      
     while (sensores.MB()) {
      movimento.exesq();  
}    
    movimento.exesq();
    delay(100);
    robo.desligarLed(3);
}
}  
void Estrategia::reconhecerRampa()
{
  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();

   if (sensorLateralEsq < 30 && sensorLateralDir < 30) 
{
    rampa();
} 
}
void Estrategia::rampa() 
{
  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  delay(500);
  
   robo.ligarTodosLeds();

 while(robo.lerSensorSonarEsq() < 30 && robo.lerSensorSonarDir() < 30){
      if (sensores.BBPBB()) 
   {      
        movimento.superfrent();
   }
      else if (sensores.BPBBB()) 
   {
        movimento.esqq();
   }
      else if (sensores.BBBPB()) 
   {
        movimento.dirr();
   }  
 }

  sala3.executar();
}
void Estrategia::desviarObstaculo() { //15/05/2019 "RIP"
    movimento.re();
    delay(100);

    while (sensores.brancoMesq()){
        movimento.dir();    
    }
    while (sensores.pretoMesq()){
        movimento.dir();    
    }
    while (sensores.brancoMdir()){
        movimento.dir();    
    }

    robo.acionarMotores (0,0);
    delay (5000);


    

 
}
void Estrategia:: obs1()
{
    movimento.re();
    delay(100);
  
    while (sensores.brancoMesq()){
        movimento.dir();    
    }
    while (sensores.pretoMesq()){
        movimento.dir();    
    }
    
    movimento.dir();    
    delay (800);
    
    while (robo.lerSensorSonarEsq() < 40){
        movimento.fren();      
    }
    
    robo.acionarMotores(0, 0);   
    delay(1000);
    movimento.fren();      
    delay (1100);
  
  
    



    

    movimento.stopp();
}
  /*robo.ligarLed(3);
  
  movimento.fren();
  delay(100);
  
  while (sensores.brancoEsq()){
    robo.acionarMotores(-55, 0);
}
  while (sensores.brancoDir()){
    robo.acionarMotores(-55, 0);
}
 
  movimento.frenmed();
  delay(450);
  movimento.rodaEsqMais();
  delay(1150);
  robo.ligarLed(1);

  movimento.frenmed();
  delay(500);
  
  movimento.parar();
  delay(300);
  movimento.rodaEsqMais();
  delay(1050);
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
  movimento.re();
  delay(100);
  
  if (sensores.MB()){
  seguirLinha();
}
  
  while(sensores.MB()){
    robo.acionarMotores(40, -40);
}  
  robo.ligarTodosLeds();
  movimento.parar();
  delay(2000); 
  seguirLinha(); 
}*/
void Estrategia:: obs2(){

 robo.acionarMotores(0, 0);
}
