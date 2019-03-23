#include "robo_hardware2.h"
#include "Logica.h"


  void Logica:: valores(){
    sRME = calibrador.getSRME();
    sRE = calibrador.getSRE();
    sRD = calibrador.getSRD();
    sRMD = calibrador.getSRMD();
  }
  
  //Funções para atualizar os valores de cada sensor
  void Logica:: atualizarVME(){
    valorMaisEsq=robo.lerSensorLinhaMaisEsqSemRuido();
  }
  void Logica:: atualizarVE(){
	  valorEsq=robo.lerSensorLinhaEsqSemRuido();
  }
  void Logica:: atualizarVD(){
	  valorDir= robo.lerSensorLinhaDirSemRuido();
  }
  void Logica:: atualizarVMD(){
	  valorMaisDir=robo.lerSensorLinhaMaisDirSemRuido();
  }

  //Calibracao Sensor Mais Esquerdo
  bool Logica:: bValorMaisEsq(){
	  atualizarVME();
    return (valorMaisEsq > sRME);
  }
  
  bool Logica:: pValorMaisEsq(){
	  atualizarVME();
	  return (valorMaisEsq <= sRME);
  }

  bool Logica:: superBrancoME(){
    atualizarVME();
    return (valorMaisEsq + 20 >= sRME);
  }

  //Calibracao Sensor Esquerdo
  bool Logica:: bValorEsq(){
	  atualizarVE();
	  return (valorEsq > sRE);
  }

  bool Logica:: pValorEsq(){
	  atualizarVE();
	  return (valorEsq <= sRE);
  }

  //Calibracao Sensor Direito
  bool Logica:: bValorDir(){
	  atualizarVD();
	  return (valorDir > sRD);
  }

  bool Logica:: pValorDir(){
	  atualizarVD();
	  return (valorDir <= sRD);
  }

  //Calibracao Sensor Mais Direito
  bool Logica:: bValorMaisDir(){
	  atualizarVMD();
	  return(valorMaisDir > sRMD);
  }

  bool Logica:: pValorMaisDir(){
	  atualizarVMD();
	  return(valorMaisDir <= sRMD);
  }


  void Logica::setValoresCalibracao(Calibrador c){
    calibrador=c;
    valores();
  }
