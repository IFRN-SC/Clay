class CalibradorGT {
    float v1, v2, v3, v4; //Armazena valores para 12 testes BRANCO E PRETO(faremos varios testes, pois assim o resultado mais preciso)
    float s1B, s2B, s3B, s4B;
    float s1P, s2P, s3P, s4P;
    float md1b, md2b, md3b, md4b; //Armazena as medias tiradas DO BRANCO no primeiro instante(Nao as definitivas)
    float md1p, md2p, md3p, md4p; //Armazena as medias tiradas DO PRETO no primeiro instante(Nao as definitivas)
    float sRME, sRE, sRD, sRMD; //VALOR CALIBRADO DE CADA SENSOR(MEDIA FINAL)
    bool continu1, continu2;
    float vezes;
    
  public:
     void calibrar();
     float vsMEsq(float md1b, float md1p);
     float vsEsq(float md2b, float md2p);
     float vsDir(float md3b, float md3p);
     float vsMDir(float md4b, float md4p);
     void atualizar();

};

