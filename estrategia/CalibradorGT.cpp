#include <robo_hardware2.h>
#include <Servo.h>
#include "CalibradorGT.h"

void CalibradorGT :: atualizar(){
     v1 = robo.lerSensorLinhaMaisEsq();
     v2 = robo.lerSensorLinhaEsq();
     v3 = robo.lerSensorLinhaDir();
     v4 = robo.lerSensorLinhaMaisDir();
}

void CalibradorGT :: calibrar(){
        robo.ligarLed(1);


      while (!continu1) {

        while (!robo.botao1Pressionado());
        delay(1000);

        Serial.println("Branco Iniciado!");

        atualizar();

        s1B = v1 + s1B;
        s2B = v2 + s2B;
        s3B = v3 + s3B;
        s4B = v4 + s4B;



        Serial.print("BRANCO PRONTO");
        robo.ligarLed(2);

        while (!robo.botao1Pressionado());
        delay(1000);

        Serial.println("Preto Iniciado! ");

        atualizar();

        s1P = v1 + s1P;
        s2P = v2 + s2P;
        s3P = v3 + s3P;
        s4P = v4 + s4P;

        Serial.println("PRETO ACABOU! ");
        robo.ligarLed(3);

        while (!continu2) {
          if (robo.botao1Pressionado()) {
            continu2 = true;
            robo.desligarLed(2);
            robo.desligarLed(3);
            delay(1000);
          }
          else if (robo.botao2Pressionado()) {
            continu2 = true;
            continu1 = true;
            robo.desligarLed(1);


          }
        }

        vezes++;
      }

      md1b = s1B / vezes;
      md2b = s2B / vezes;
      md3b = s3B / vezes;
      md4b = s4B / vezes;

      md1p = s1P / vezes;
      md2p = s2P / vezes;
      md3p = s3P / vezes;
      md4p = s4P / vezes;



      sRME = (md1b + md1p) / 2;
      sRE = (md2b + md2p) / 2;
      sRD = (md3b + md3p) / 2;
      sRMD = (md4b + md4p) / 2;


      Serial.println("Mais Esquerdo: ");
      Serial.println(sRME);
      Serial.println("Esquerdo: ");
      Serial.println(sRE);
      Serial.println("Direito: ");
      Serial.println(sRD);
      Serial.println("Mais Direito: ");
      Serial.println(sRMD);

      Serial.print("PRONTO!!!");




}
