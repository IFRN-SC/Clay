#include "Calibrador.h"
#include "robo_hardware2.h"
#include "Calibrador.h"
#include "Calibracao.h"

Calibracao calibracao;

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

void Calibrador:: calibrar() {

  robo.ligarLed(1);

  while ( !robo.botao1Pressionado() );

  Serial.print("BRANCO COMEÇOU!");

  for (int i = 0; i < 20; i++) {             //Armazenamento de leitura no Branco (15x)
    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();

    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;

    delay(500);
  }

  md1b = s1 / 20;
  md2b = s2 / 20;
  md3b = s3 / 20;
  md4b = s4 / 20;


  Serial.print("BRANCO PRONTO!");
  robo.ligarLed(2);

  while ( !robo.botao1Pressionado() );

  Serial.print("PRETO COMEÇOU!");




  s1 = 0; //ZERANDO ÀS VÁRIAVEIS PARA SEREM REUTILIZADAS
  s2 = 0;
  s3 = 0;
  s4 = 0;

  for (int i = 0; i < 20; i++) {             //Armazenamento de leitura no Preto (15x)
    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();


    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;

    delay(500);

  }



  md1p = s1 / 20;
  md2p = s2 / 20;
  md3p = s3 / 20;
  md4p = s4 / 20;



  sRME = (md1b + md1p) / 2;
  sRE = (md2b + md2p) / 2;
  sRD = (md3b + md3p) / 2;
  sRMD = (md4b + md4p) / 2;

  Serial.print("PRETO PRONTO!");
  robo.ligarLed(3);

  calibracao.valores();

  while ( !robo.botao2Pressionado() );

  robo.desligarLed(1);

}

