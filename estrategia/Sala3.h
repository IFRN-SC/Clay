#ifndef SALA3_H
#define SALA3_H

#include "Sensores.h"
#include "Movimento.h"
#include "Calibrador.h"

class Sala3 {
	
	 private:
	
	Movimento movimento;
	Sensores sensores;

  int salas = 0;
  int contador = 0;
  
	float sensorLateralDir;
  float sensorLateralEsq;
  float sensorFrontal;
    
  const int fimdocurso = 28;
  const int fimdocurso2 = 42;

  bool parar;
	
	 public:
 
	void alinhar();
  void executar();
  void umalinhar();
  void procurar();
  void entregar();
  void procurardois();
	
};

#endif
