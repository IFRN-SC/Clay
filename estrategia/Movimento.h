#ifndef MOVIMENTO_H
#define MOVIMENTO_H

class Movimento{


  public:

    void fren();
    void dir();
    void esq();
    void exdir();
    void exesq();
    void parar();
    void frenlen();
    void girando();
    void superfrent();
    void dirr();
    void esqq();
    void rabesq();
    void frenmed();
    void rabdir();
    void re();
    void dirpuch();

//Movimento obstaculo
    void obFren();
    void obDir();
    void obEsq();
    void obFrenLen();
    void obRe();
    void obReLen();
    void esqobs();
    void frenbaixo();

//Movimento sala3

	void frenS3();
	void dirS3();
	void esqS3();
	void reS3();
  void menos1();
  void menos2();
};

#endif
