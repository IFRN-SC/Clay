#include "robo_hardware2.h"
#include "Movimento.h"

  void Movimento:: fren(){
    robo.acionarMotores(30,29);
  }
  void Movimento:: dir(){
    robo.acionarMotores(-55,50);
  }
  void Movimento:: esq(){
    robo.acionarMotores(50,-55);
  }
  void Movimento:: exdir(){
    robo.acionarMotores(-60,50);
  }
  void Movimento:: exesq(){
    robo.acionarMotores(50,-60);
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
    robo.acionarMotores(95, 95);
  }
  void Movimento:: dirr(){
    robo.acionarMotores(50,80);
  }
  void Movimento:: esqq(){
    robo.acionarMotores(80,50);
  }
  void Movimento:: frenmed(){
    robo.acionarMotores(80,80);
  }
  void Movimento:: rabdir(){
    robo.acionarMotores(-65, 50);
  }
  void Movimento:: rabesq(){
    robo.acionarMotores(50, -65);
  }
  void Movimento:: re(){
    robo.acionarMotores(-50, -50);
  }
  void Movimento:: obFren(){
    robo.acionarMotores(40, 40);
  }
  void Movimento:: obDir(){
    robo.acionarMotores(-55, 50);
  }
  void Movimento:: obEsq(){
    robo.acionarMotores(50, -55);
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

