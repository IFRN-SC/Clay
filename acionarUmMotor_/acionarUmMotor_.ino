#include <robo_hardware2.h> 
#include <Servo.h>

//*********PINOS PARA LIGAR MOTORES*********//
//    Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//    Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//*********PINOS PARA LIGAR MOTORES*********//

float valor_sensor_dir;

void setup(){
	//Configura o robo.
	robo.configurar(false);
}

void loop(){
        valor_sensor_dir = robo.lerSensorLinhaDir(); //le um valor do sensor. O sensor retornar um valor de 0 100
        if (valor_sensor_dir > 50 ){
          robo.acionarMotores(80, 80);
        }
        else {
          robo.acionarMotores(0, 0);  
        }
         
         
       
}
