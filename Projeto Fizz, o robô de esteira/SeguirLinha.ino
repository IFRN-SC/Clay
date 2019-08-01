#include <robo_hardware2.h> 
#include <Servo.h>

//*************PINOS PARA LIGAR MOTORES*************//
//   Motor direito:
//pino1 PWM_RODA_DIREITA	6
//pino2 SENTIDO_RODA_DIREITA	7
//   Motor esquerdo:
//pino1 PWM_RODA_ESQUERDA	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//*********PINOS PARA LIGAR MOTORES*********//

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_ESQUERDO			uno-A1;	mega-A1
//
//SENSOR_LINHA_DIREITO			uno-A2;	mega-A2
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

#define DIVISOR_BRANCO_PRETO 64

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisEsq;
float valorSensorMaisDir;

void setup(){
	robo.configurar(false);
}

void loop(){

	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  
	//Identifica se os dois sensores viram branco
	if(valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO &&
	valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(80,80);	//Aciona os dois motores com a mesma velocidade
	}
  else if (valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO &&
  valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(-45, 50);//Aciona o motor esquerdo e mantem o motor direito desligado
  }
  else if (valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO &&
  valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(50, -45);//Aciona o motor esquerdo e mantem o motor direito desligado
  }
	//Identifica se o sensor da esquerda viu banco e o da direita viu preto
	else if (valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO &&
	valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(-60, 50);//Aciona o motor esquerdo e mantem o motor direito desligado
	}
	//Identifica se o sensor da direita viu banco e o da esquerda viu preto
	else if (valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO &&
	valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(50, -60);	//Aciona o motor direito e mantem o motor esquerdo desligado
	}

}

