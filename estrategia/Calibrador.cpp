#include "Calibrador.h"
#include "robo_hardware2.h"

float Calibrador:: getSRME() {
  return sRME;
}
float Calibrador:: getSRE() {
  return sRE;
}
float Calibrador:: getSRD() {
  return sRD;
}
float Calibrador:: getSRMD() {
  return sRME;
}
void Calibrador::setSRME(float sRME2){
  sRME = sRME2;
}

void Calibrador::setSRE(float sRE2){
  sRE = sRE2;
}

void Calibrador::setSRD(float sRD2){
  sRD = sRD2;
}

void Calibrador::setSRMD(float sRMD2){
  sRMD = sRMD2;
}


void Calibrador:: calibrar() {    
delay(1000);
  robo.ligarLed(1);
  
 
  while ( !robo.botao1Pressionado() );

  Serial.println("BRANCO COMEÇOU!");

  for (int i = 0; i < 200; i++) {             //Armazenamento de leitura no Branco (15x)
    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();

    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;

    delay(50);
  }

  md1b = s1 / 200;
  md2b = s2 / 200;
  md3b = s3 / 200;
  md4b = s4 / 200;


  Serial.print("BRANCO PRONTO!");
  robo.ligarLed(2);

  while ( !robo.botao1Pressionado() );

  Serial.print("PRETO COMEÇOU!");




  s1 = 0; //ZERANDO ÀS VÁRIAVEIS PARA SEREM REUTILIZADAS
  s2 = 0;
  s3 = 0;
  s4 = 0;

  for (int i = 0; i < 200; i++) {             //Armazenamento de leitura no Preto (15x)
    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();


    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;

    delay(50);

  }



  md1p = s1 / 200;
  md2p = s2 / 200;
  md3p = s3 / 200;
  md4p = s4 / 200;



  sRME = (md1b + md1p) / 2;
  sRE = (md2b + md2p) / 2;
  sRD = (md3b + md3p) / 2;
  sRMD = (md4b + md4p) / 2;

  Serial.print("PRETO PRONTO!");
  robo.ligarLed(3);

 // calibracao.valores();

  while ( !robo.botao2Pressionado() );

  robo.desligarLed(1);

 

}

