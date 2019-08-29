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
  
	float sensorLateralDir;
  float sensorLateralEsq;
  float sensorFrontal;    
	
	public:
 
  void executar();

  void procurarAreaResgate();
  void procurar();
  void alinhar();
  void procurarDois();
  void alinharDois();
  void alinharInverso();
  void resgatar();
  void procurarInverso();
  void bolinhaIdentificada();
  void garraAbaixada();
  void garraLevantada();
  void garraFechada();
  void garraAbaixadaBola();
  void repeticaoBolaEncontrada();
  void parar();
  
  
};

#endif
