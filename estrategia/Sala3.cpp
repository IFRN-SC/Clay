#include "robo_hardware2.h"
#include "Sala3.h"

void Sala3::executar() 
{
  robo.desligarTodosLeds();
  garraAbaixada(); 
  movimento.fren();
  delay(600);
  
  movimento.fren();
  delay(450);
  garraFechada();
  movimento.parar();
  delay(400);
  
  bolinhaIdentificada();

  robo.acionarServoGarra1(30); //BRAÇO
  robo.acionarServoGarra2(75); //GARRA
  
  pinMode(fimdocurso, INPUT_PULLUP);
  pinMode(fimdocurso2, INPUT_PULLUP);
  
  robo.desligarTodosLeds();
  delay(400);

  sensorLateralDir = robo.lerSensorSonarDir();
  sensorLateralEsq = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  if (sensorLateralDir < 15 || sensorLateralEsq > 15)
{
    tipoSala = tipoSala + 1;
    procurarAreaResgate1();
}
  else if (sensorLateralEsq < 15 || sensorLateralDir > 15)
{
    tipoSala = tipoSala + 2;
    procurarAreaResgate2();
}
}


// --> PROCURAR AREA DE RESGATE (1, 2)


void Sala3::procurarAreaResgate1()
{
    movimento.fren();
    delay(700);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(1000);         //ROBO PRONTO PARA FAZER SUA PRIMEIRA TENTATIVA DE RESGATE
    garraAbaixada();
    
    garraFechada();
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada(); 
    garraAbaixada();
    
    movimento.fren();  //PRIMEIRA LIMPA
    delay(1200);
    
    garraFechada();
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada(); 
    garraAbaixada();
    
    movimento.fren();    //SEGUNDA LIMPA
    delay(1200);
    
    garraFechada();
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();   //FIM DA PRIMEIRA TENTATIVA

    movimento.re();
    delay(3000);
    movimento.fren();
    delay(500);
    movimento.girarDir90();
    movimento.re();
    delay(800);
    movimento.girarEsq90();
    movimento.re();
    delay(1500);

    garraAbaixada();
    
    movimento.fren();  //PRIMEIRA LIMPA
    delay(1200);
    
    garraFechada();
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada(); 
    garraAbaixada();
    
    movimento.fren();    //SEGUNDA LIMPA
    delay(1200);

    garraFechada();
    movimento.parar();
    delay(500);
    
    movimento.re();
    delay(600);
    
    movimento.girarDir90(); 
    
    movimento.re();
    delay(1300);

    garraAbaixada();  //ROBO IRA IDENTIFICAR A AREA DE RESGATE
    
    movimento.fren();
    delay(1200);      //PRIMEIRA LIMPA

    garraFechada();
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();
    
    movimento.parar();
    delay(500);
    
    garraAbaixada();
    
    movimento.fren();   //SEGUNDA LIMPA
    delay(1300);    

    garraFechada();
    
    movimento.re();
    delay(300);  
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada(); 
    
    movimento.girarEsq45();  //VAI OLHAR PARA A ESQUERDA
    
    movimento.re();
    delay(200);
    
    sensorFrontal = robo.lerSensorSonarFrontal(); //TIPO SALA 1
    if (sensorFrontal < 30)
{
    tipoArea = tipoArea + 1;
}
    if (tipoArea == 1)
{
    tipoArea = tipoArea - 1;
    movimento.girarDir45(); //VOLTA PARA PROXIMO A ENTRADA DA SALA3
    
    movimento.re();
    delay(2500);
    movimento.fren();
    delay(600);
    
    movimento.girarEsq90();
    
    movimento.re();       //SE ALINHA PROXIMO A ENTRADA
    delay(2500);  
    movimento.parar();
    delay(1000);
    movimento.fren();
    delay(400);
    
    movimento.girarDir90();  // SE PREPARA PARA FAZER A LIMPA DA PARTE DA FRENTE DA SALA3

    garraAbaixada();
    
    movimento.fren();  //LIMPA 1
    delay(1000);
    
    garraFechada(); 
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();

    garraAbaixada();
    
    movimento.fren();  //LIMPA 2
    delay(700);
    
    garraFechada();
     
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();
    
    movimento.re();  //VOLTA PARA EM SEGUIDA SE ALINHAR NOVAMENTE 
    delay(1600);
    
    movimento.girarEsq90();
    
    movimento.re();   //ALINHADA 
    delay(1000);
    movimento.parar();
    delay(500);
    movimento.fren();    //LIMPA NA PARTE ESQ DA SALA3
    delay(3200);
    
    movimento.girarDir90();
    
    movimento.re();
    delay(2000);
    
    garraAbaixada();

    movimento.fren(); //LIMPA UNICA
    delay(1250);

    garraFechada();
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();

    movimento.re();
    delay(2500);
    movimento.fren();
    delay(900);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(3500);     //SE ALINHA NOVAMENTE PROX A ENTRADA 
    
   tipoArea = tipoArea + 1;
    
    alinhar(); 
}
    movimento.girarDir90();
    garraAbaixada();
    
    movimento.fren();
    delay(150);
    
    garraFechada(); 
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();
    
    movimento.re();
    delay(200);
    
    
    sensorFrontal = robo.lerSensorSonarFrontal(); // TIPO SALA 2
    if (sensorFrontal < 30)
{
    tipoArea = tipoArea + 2;
}
    if (tipoArea == 2)
{
    movimento.girarEsq45();

    movimento.re();
    delay(3000);
    movimento.fren();
    delay(500);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(2500);
    movimento.parar();
    delay(1000);
    movimento.fren();
    delay(400);
    
    movimento.girarDir90();

    garraAbaixada();
  
    movimento.fren();
    delay(800);

    garraFechada(); 
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();  
    movimento.girarEsq90();
    
    movimento.re();
    delay(1200);

    garraAbaixada();
    
    movimento.fren();
    delay(1200);

    garraFechada(); 
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();

    garraAbaixada();
    
    movimento.fren();
    delay(1200);

    garraFechada(); 
    
    movimento.parar();
    delay(500);
    
    bolinhaIdentificada();
    
    movimento.parar();
    delay(500);
    movimento.fren();
    delay(800);
    
    movimento.girarDir90();
   
    movimento.re();
    delay(2500);

    procurar();
}

   if (tipoArea == 0)
{
    movimento.girarEsq45();
    
    movimento.re();
    delay(2500);
    movimento.fren();
    delay(600);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(2500);
    movimento.parar();
    delay(1000);

    movimento.fren();
    delay(300);
    
    movimento.girarDir90();
    
    movimento.fren();
    delay(2500);
    movimento.re();
    delay(2400);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(1000);
    movimento.parar();
    delay(1000);
    procurar(); 
}
}


// --> PROCURAR AREA DE RESGATE 2

void Sala3:: procurarAreaResgate2()
{
  movimento.girando();
}


// --> PROCURAR (PERCURSO CONSTANTE)


void Sala3:: procurar()
{
   if (tipoArea == 1)
{
   contadorTipoArea1 = contadorTipoArea1 + 1;
   
   garraAbaixada();
   movimento.fren();
   delay(1900);
   
   garraFechada();
   
   movimento.parar();
   delay(500);
   bolinhaIdentificada();
    
   movimento.parar();
   delay(200);
   movimento.re();
   delay(3500);
   
   alinhar();
}
   else if (tipoArea == 2)
{
   contadorTipoArea2 = contadorTipoArea2 + 1;
   
   garraAbaixada();
   
   movimento.fren();
   delay(1250);
   
   garraFechada();
   
   movimento.parar();
   delay(500);
   bolinhaIdentificada();

   garraAbaixada();
   
   movimento.fren();
   delay(1250);
   
   garraFechada();
   
   movimento.parar();
   delay(500);
   bolinhaIdentificada();
   
   movimento.re();
   delay(3500);
   
   if (contadorTipoArea2 == 4)
{
   resgatar();
}
   alinhar();
}


   else if (tipoArea == 0)
{
   if (contadorAuxiliarTipoArea3 < 1)
{
   contadorAuxiliarTipoArea3 = contadorAuxiliarTipoArea3 + 1;
   movimento.fren();
   delay(2000);
   movimento.re();
   delay(2500);
   alinhar();
}
  else if (contadorAuxiliarTipoArea3 == 1)
{
   movimento.fren();
   delay(3000);
   movimento.re();
   delay(3500);
   
    sensorLateralDir = robo.lerSensorSonarDir();
   if (sensorLateralDir < 10)
{
   movimento.parar();
   while(1);
}
   alinhar();
}
}
}


// --> ALINHAR


void Sala3:: alinhar()
{
  if (tipoArea == 1)
{
  movimento.fren();
  delay(400);
    
  movimento.girarDir90();
    
  movimento.fren();
  delay(600);
    
  movimento.girarEsq90();
    
  movimento.re();
  delay(1200);
    
    if (contadorTipoArea1 == 2)
{
    procurarMenor();
}
    procurar();
}

  else if (tipoArea == 2)
{
    if (contadorAuxiliar > 0)
{
    movimento.fren();
    delay(400);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(2000);
    movimento.parar();
    while(1);
}
    movimento.fren();
    delay(300);
    
    movimento.girarDir90();
    
    movimento.fren();
    delay(500);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(1000);
    procurar();
}
  else if (tipoArea == 0)
{
    movimento.fren();
    delay(400);
    
    movimento.girarDir90();
    
    movimento.fren();
    delay(600);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(1200);
    procurar();
}
}


// --> PROCURAR MENOR


void Sala3:: procurarMenor()
{
   if (tipoArea == 1 || tipoArea == 2)
{
   garraAbaixada();
   
   movimento.fren();
   delay(1600);
   
   garraFechada();
   movimento.parar();
   delay(500);
   bolinhaIdentificada();
   
   movimento.re();
   delay(3000);

   resgatar();
}
}


// --> ALINHAR MENOR


void Sala3:: alinharMenor()
{
  if (tipoArea == 1)
{
    movimento.fren();
    delay(400);
    
    movimento.girarDir90();
    
    movimento.fren();
    delay(600);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(1200);

    movimento.fren();
    delay(2000);
    movimento.re();
    delay(2000);

    alinharInverso();
}
}


// --> ALINHAR INVERSO (INVERTE O SENTIDO DE PROCURAR DO ROBO)


void Sala3:: alinharInverso()
{
  contadorInverso = contadorInverso + 1;
  
  movimento.fren();
  delay(400);
  
  movimento.girarEsq90();
  
  movimento.fren();
  delay(600);
  
  movimento.girarDir90();
  
  movimento.re();
  delay(1000);
  
  procurarInverso();
}


// --> PROCURAR INVERSO


void Sala3:: procurarInverso()
{
  if (contadorInverso == 1)
{
   if (tipoArea == 1 || tipoArea == 2)
{
   movimento.fren();
   delay(2500);
   movimento.re();
   delay(3300);
   
   alinharInverso();
}
}
  else if (contadorInverso > 1)
{
   movimento.fren();
   delay(3000);
   movimento.re();
   delay(3500);

   sensorLateralDir = robo.lerSensorSonarDir();
   if (sensorLateralDir > 70)
{
   movimento.parar();
   while(1);
}
   alinharInverso(); 
}
}


void Sala3:: resgatar()
{
  if (tipoArea == 1)
{
    movimento.re();
    delay(500);

    movimento.fren();
    delay(400);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(2300);
    
    movimento.fren();
    delay(400);
    movimento.girarDir90();
    movimento.re();
    delay(1000);
    
    garraAbaixada();
    movimento.fren();
    delay(1500);
    
    garraFechada();
    bolinhaIdentificada();

    movimento.fren();
    delay(300);
    
    movimento.girarEsq90();
    movimento.re();
    delay(1000);

    movimento.fren();
    delay(1700);
    
    movimento.girarEsq45();
    movimento.re();
    delay(3500);
    movimento.fren();
    delay(70);

    robo.acionarServoGarra2(150);
    movimento.parar();
    delay(500);
    robo.acionarPassoAngDir(120, 50);

    movimento.parar();
    delay(500);
    
    robo.acionarPassoAngDir(120, -50);
    movimento.parar();
    delay(1000);
    robo.acionarServoGarra1(10);
    movimento.parar();
    delay(500);
    robo.acionarServoGarra1(50);
    movimento.re();
    delay(500);
    robo.acionarPassoAngDir(30, 50);

    movimento.stopp();   
}
   if (tipoArea == 2)
{
    movimento.fren();
    delay(500);  
    
    movimento.girarEsq90();
    movimento.re();
    delay(2000);
    
    movimento.fren();
    delay(1700);  
    movimento.parar();
    delay(500);
    
    movimento.girarDir90();
    movimento.re();
    delay(1500);
    
    movimento.fren();
    delay(2000);

    
    movimento.parar();
    delay(500);
    
    //movimento.fren();
    //delay(600);
    
    movimento.girarEsq90();
    movimento.girarEsq45();
    movimento.re();
    delay(3500);
    movimento.fren();
    delay(70);

    
    robo.acionarServoGarra2(150);
    movimento.parar();
    delay(500);
    robo.acionarPassoAngDir(120, 50);

    movimento.parar();
    delay(500);
    
    robo.acionarPassoAngDir(120, -50);
    movimento.parar();
    delay(1000);
    robo.acionarServoGarra1(20);
    movimento.parar();
    delay(500);
    robo.acionarServoGarra1(50);
    movimento.re();
    delay(500);
    robo.acionarPassoAngDir(180, 50);

    movimento.stopp(); 
}
}

















































void Sala3:: guardar()
{
  quantidadeDeBolas = quantidadeDeBolas + 1;
  robo.acionarServoGarra2(120);
}
void Sala3:: guardarComCautela()
{
  quantidadeDeBolas = quantidadeDeBolas + 1;
  robo.acionarServoGarra2(60, 150, 15); //GARRA
  movimento.parar();
  delay(1000);
}
void Sala3:: garraAbaixada()
{
  robo.acionarServoGarra2(150);
  movimento.parar();
  delay(400);
  robo.acionarServoGarra1(175); 
  movimento.parar();
  delay(500);
}
void Sala3:: garraLevantada()
{
  robo.acionarServoGarra1(100); //braço
  robo.acionarServoGarra2(140);
}
void Sala3:: garraFechada()
{ 
  movimento.parar();
  robo.acionarServoGarra2(60); //GARRA
  movimento.parar();
  delay(500);
  robo.acionarServoGarra1(40); //BRAÇO
}
void Sala3::bolinhaIdentificada()
{ 
  if (tipoArea == 1)
 {
    if (digitalRead(fimdocurso) == LOW)
 {
    if (quantidadeDeBolas == 0)
   {
    guardarComCautela();
   }
    else if (quantidadeDeBolas == 1 || quantidadeDeBolas == 2 || quantidadeDeBolas == 3 || quantidadeDeBolas == 5 || quantidadeDeBolas == 6)
  {
    guardarComCautela();
   }
 }
 }
  else{ 
  if (digitalRead(fimdocurso) == LOW)
 {
    if (quantidadeDeBolas == 0)
  {
    guardar();
   }
    else if (quantidadeDeBolas == 1 || quantidadeDeBolas == 2 || quantidadeDeBolas == 3 || quantidadeDeBolas == 5 || quantidadeDeBolas == 6)
  {
    guardarComCautela();
   }
  }
  }
}
     
