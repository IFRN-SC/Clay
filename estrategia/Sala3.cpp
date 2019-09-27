#include "robo_hardware2.h"
#include "Sala3.h"

void Sala3::executar() 
{
  robo.desligarTodosLeds();

  movimento.fren();
  delay(400);
  garraAbaixada();
  
  movimento.parar();
  delay(500);
  
  movimento.fren();
  delay(1000);
  garraFechada();
  
  movimento.parar();
  delay(500);
  
  bolinhaIdentificada();
  
  robo.acionarServoGarra1(50); //BRAÇO
  robo.acionarServoGarra2(100); //GARRA
  
  movimento.parar();
  delay(1000);
  
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
    movimento.girarEsq90();
    
    movimento.re();
    delay(1000);
    garraAbaixada();
    
    movimento.fren();
    delay(2400);
    
    garraFechada();
    
    movimento.parar();
    delay(500);
    bolinhaIdentificada(); //PERGUNTA SE A BOLA FOI ENCONTRADA
    
    movimento.re();
    delay(600);
    
    movimento.girarDir90();
    
    movimento.re();
    delay(1300);

    garraAbaixada();
    
    movimento.fren();
    delay(2000);

    garraFechada();
    
    movimento.parar();
    delay(500);
    bolinhaIdentificada(); //PERGUNTA SE A BOLA FOI ENCONTRADA
    
    movimento.girarEsq45();
    
    sensorFrontal = robo.lerSensorSonarFrontal(); //TIPO SALA 1
    if (sensorFrontal < 30)
{
    tipoArea = tipoArea + 1;
}
    if (tipoArea == 1)
{
    tipoArea = tipoArea - 1;
    
    movimento.girarDir45();
    
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
    delay(500);
    
    movimento.girarDir90();

    garraAbaixada();
    
    movimento.fren();
    delay(1800);
    
    garraFechada(); 
    movimento.parar();
    delay(500);
    bolinhaIdentificada();
    
    movimento.re();
    delay(1600);
    
    movimento.girarEsq90();
    
    movimento.re(); 
    delay(1000);
    movimento.parar();
    delay(1000);
    
   tipoArea = tipoArea + 1;
    
    if (quantidadeDeBolas > 0)
   {
     resgatar();
   }
    
    procurar();  
}


    movimento.girarDir90();
   
    
    sensorFrontal = robo.lerSensorSonarFrontal(); // TIPO SALA 2
    if (sensorFrontal < 30)
{
    tipoArea = tipoArea + 2;
}
    if (tipoArea == 2)
{
    movimento.girarEsq45();

    movimento.re();
    delay(2500);
    movimento.fren();
    delay(500);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(2500);
    movimento.parar();
    delay(1000);

    movimento.fren();
    delay(400);
    
    robo.acionarServoGarra1(50); //BRAÇO
    robo.acionarServoGarra2(100); //GARRA
    
    robo.acionarMotores(-60, 60);
    delay(1250);

    garraAbaixada();
    movimento.parar();
    delay(300);
    movimento.fren();
    delay(800);

    garraFechada(); 
    
    movimento.parar();
    delay(500);
    bolinhaIdentificada(); 
    
    //movimento.re();
    //delay(600);
    
    movimento.girarEsq90();
    
    movimento.re();
    delay(1200);

    garraAbaixada();
    movimento.parar();
    delay(300);
    
    movimento.fren();
    delay(2500);

    garraFechada(); 
    
    movimento.parar();
    delay(500);
    bolinhaIdentificada(); //

    movimento.fren();
    delay(850);
    movimento.girarDir90();
    
    movimento.re();
    delay(1000);
    movimento.fren();
    delay(3000);
    movimento.re();
    delay(3500);
    movimento.parar();
    delay(1000);
    //movimento.stopp();
    alinhar();
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
   garraAbaixada();
   movimento.fren();
   delay(2400);
   
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
   garraAbaixada();
   movimento.fren();
   delay(2600);
   garraFechada();
   movimento.parar();
   delay(200);
   movimento.re();
   delay(3500);

   sensorLateralDir = robo.lerSensorSonarDir();
   if (sensorLateralDir < 40)
{
   movimento.parar();
   while(1);
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
     if (quantidadeDeBolas > 0)
  {
     resgatar();
     quantidadeDeBolas = quantidadeDeBolas - quantidadeDeBolas;
  }
   
  movimento.fren();
  delay(400);
    
  movimento.girarDir90();
    
  movimento.fren();
  delay(600);
    
  movimento.girarEsq90();
    
  movimento.re();
  delay(1200);
    
    sensorLateralDir = robo.lerSensorSonarDir();
    if (sensorLateralDir < 30 && sensorLateralDir > 25)
{
    procurar();
}
    else if (sensorLateralDir < 30 && sensorLateralDir < 25)
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
    sensorLateralDir = robo.lerSensorSonarDir();
    if (sensorLateralDir < 40)
{
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
   movimento.fren();
   delay(500);
   movimento.re();
   delay(3000);
   alinharMenor();
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
    delay(1700);  
    movimento.parar();
    delay(500);
    
    movimento.girarDir90();
    movimento.re();
    delay(1500);
    movimento.fren();
    delay(2200);

    
    movimento.parar();
    delay(500);
    
    //movimento.fren();
    //delay(600);
    
    movimento.girarDir90();
    movimento.girarDir45();
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
    robo.acionarServoGarra1(30);
    robo.acionarPassoAngDir(180, 50);

    movimento.stopp();   
}
}

















































void Sala3:: guardar()
{
  quantidadeDeBolas = quantidadeDeBolas + 1;
  robo.acionarServoGarra2(150);
  movimento.parar();
  delay(500);
}
void Sala3:: guardarComCautela()
{
  quantidadeDeBolas = quantidadeDeBolas + 1;
  robo.acionarServoGarra2(80, 150, 15); //GARRA
  movimento.parar();
  delay(1000);
}
void Sala3:: garraAbaixada()
{
  robo.acionarServoGarra1(177);
  robo.acionarServoGarra2(180);
}
void Sala3:: garraLevantada()
{
  robo.acionarServoGarra1(100); //braço
  robo.acionarServoGarra2(140);
}
void Sala3:: garraFechada()
{ 
  robo.acionarServoGarra2(80); //GARRA
  movimento.parar();
  delay(500);
  robo.acionarServoGarra1(50); //BRAÇO
}
void Sala3:: garraAbaixadaBola()
{
  robo.acionarServoGarra1(120);
  movimento.parar();
  delay(1000);
  robo.acionarServoGarra2(170);
}
void Sala3:: repeticaoBolaEncontrada()
{
  garraAbaixadaBola();
  movimento.parar();
  delay(500);
  garraFechada();
  movimento.parar();
  delay(500);
  garraAbaixadaBola();
  movimento.parar();
  delay(500);
  garraFechada();
  movimento.parar();
  delay(500);
  garraAbaixadaBola();
}
void Sala3:: abrirGarraLento()
{
  movimento.parar();
  delay(500);
  robo.acionarServoGarra2(110, 180, 15); //GARRA
  robo.acionarServoGarra1(60, 180, 15); //BRAÇO  
} 
void Sala3:: abrirGarraLento2()
{
  movimento.parar();
  delay(500);
  robo.acionarServoGarra1(60, 180, 15); //BRAÇO
  robo.acionarServoGarra2(110, 180, 15); //GARRA
}
void Sala3:: parar()
{
  movimento.parar();
  while (1);
}




void Sala3::bolinhaIdentificada()
{ 
  if (tipoArea == 1)
 {
    if (digitalRead(fimdocurso) == LOW)
 {
    if (quantidadeDeBolas == 0)
   {
    guardar();
   }
    else if (quantidadeDeBolas == 1 || quantidadeDeBolas == 2 || quantidadeDeBolas == 3)
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
    else if (quantidadeDeBolas == 1 || quantidadeDeBolas == 2 || quantidadeDeBolas == 3)
  {
    guardarComCautela();
   }
  }
  }
}
     
