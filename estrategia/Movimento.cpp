#include "robo_hardware2.h"
#include "Movimento.h"

  void Movimento:: fren(){
    robo.acionarMotores(40,40);
  }
  void Movimento:: frenbaixo(){
    robo.acionarMotores(33,35);
  }
  void Movimento:: dir(){
    robo.acionarMotores(50,-50);
  }
  void Movimento:: esq(){
    robo.acionarMotores(-50,50);
  }
  void Movimento:: exdir(){
    robo.acionarMotores(50,-60);
  }
  void Movimento:: exesq(){
    robo.acionarMotores(-60,50);
  }
 
  void Movimento:: parar(){
    robo.acionarMotores(0, 0);
  }
  void Movimento:: frenlen(){
    robo.acionarMotores(30, 30);
  }
  void Movimento:: girando(){
    robo.acionarMotores(-40, 40);
  }
  void Movimento:: superfrent(){
    robo.acionarMotores(80, 80);
  }
   void Movimento:: esqobs(){
    robo.acionarMotores(50,-55);
  }
  void Movimento:: dirr(){
    robo.acionarMotores(50,80);
  }
  void Movimento:: esqq(){
    robo.acionarMotores(80,50);
  }
   void Movimento:: dirpuch(){
    robo.acionarMotores(0, -30);
  }
  void Movimento:: frenmed(){
    robo.acionarMotores(80,80);
  }
  void Movimento:: rabdir(){
    robo.acionarMotores(50, -65);
  }
  void Movimento:: rabesq(){
    robo.acionarMotores(50, -65);
  }
  void Movimento:: re(){
    robo.acionarMotores(-30, -30);
  }
//Movimento Obstaculo

  void Movimento:: obFren(){
    robo.acionarMotores(40, 40);
  }
  void Movimento:: obDir(){
    robo.acionarMotores(50, -55);
  }
  void Movimento:: obEsq(){
    robo.acionarMotores(-55, 50);
  }
  void Movimento:: obFrenLen(){
    robo.acionarMotores(30, 30);
  }
  void Movimento:: obRe(){
    robo.acionarMotores(-50, -50);
  }
  void Movimento:: obReLen(){
    robo.acionarMotores(-20, -20);
  }
//Movimento Sala3
	void Movimento:: frenS3(){
		robo.acionarMotores(30,30);
	}

	void Movimento:: dirS3(){
		robo.acionarMotores(30,-30);
	}

	void Movimento:: esqS3(){
		robo.acionarMotores(-30,30);
	}

	void Movimento:: reS3(){
		robo.acionarMotores(-30,-30);
	}
 void Movimento:: menos1(){
  robo.acionarMotores(50, 0);
 }
 void Movimento:: menos2(){
  robo.acionarMotores(0, 50);
 }

