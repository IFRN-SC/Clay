#ifndef SALA3_H
#define SALA3_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"

class Sala3 
{	
	private:
	
	Movimento movimento;
	Sensores sensores;
  
  const int fimdocurso = 30;
  const int fimdocurso2 = 42;
  
  int tipoSala = 0;
  int tipoArea = 0;
  int contadorInverso = 0;
  int contadorAuxiliar = 0;
  int contadorAuxiliarTipoArea3 = 0;
  
	float sensorLateralDir;
  float sensorLateralEsq;
  float sensorFrontal;    
	
	public:
 
  void executar();

  void procurarAreaResgate1();
  void procurarAreaResgate2();
  void procurar();
  void alinhar();
  void resgatar();
  
  void procurarMenor();
  void alinharMenor();
  
  void alinharInverso();
  void procurarInverso();
  void reiniciar();
  
  void bolinhaIdentificada();
  

  void abrirGarraLento();
  void abrirGarraLento2();
  void garraAbaixada();
  void garraLevantada();
  void garraFechada();
  void garraAbaixadaBola();
  void repeticaoBolaEncontrada();
  void parar();
  
  
};

#endif
