#include "robo_hardware2.h"
#include "Sala3.h"

void Sala3::executar() 
{
  robo.desligarTodosLeds();
  movimento.fren();
  delay(1000);
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
    movimento.girandoEsq();
    delay(1400);
    movimento.re();
    delay(1000);
    movimento.fren();
    delay(1800);
    movimento.girando();
    delay(800);
    movimento.re();
    delay(1500);
    
    movimento.fren();
    delay(2000);
    movimento.girandoEsq();
    delay(800);
    
    sensorFrontal = robo.lerSensorSonarFrontal(); //TIPO SALA 1
    if (sensorFrontal < 30)
{
    tipoArea = tipoArea + 1;
}
    if (tipoArea == 1)
{
    movimento.girando();
    delay(500);
    movimento.re();
    delay(2500);
    movimento.fren();
    delay(600);
    movimento.girandoEsq();
    delay(1400);
    movimento.re();
    delay(2500);
    movimento.parar();
    delay(1000);
    
    movimento.fren();
    delay(500);
    movimento.girando();
    delay(850);
    movimento.fren();
    delay(2500);
    movimento.re();
    delay(2400);
    movimento.girandoEsq();
    delay(1500);
    movimento.re();
    delay(1000);
    movimento.parar();
    delay(1000);
    procurar();  
}


    movimento.girando();
    delay(1000);
    
    
    sensorFrontal = robo.lerSensorSonarFrontal(); // TIPO SALA 2
    if (sensorFrontal < 30)
{
    tipoArea = tipoArea + 2;
}
    if (tipoArea == 2)
{
    movimento.girandoEsq();
    delay(800);
    movimento.re();
    delay(2500);
    movimento.fren();
    delay(600);
    movimento.girandoEsq();
    delay(1400);
    movimento.re();
    delay(2500);
    movimento.parar();
    delay(1000);

    movimento.fren();
    delay(3200);
    movimento.girando();
    delay(1000);
    movimento.re();
    delay(1200);
    movimento.fren();
    delay(3000);
    movimento.re();
    delay(3500);
    movimento.parar();
    delay(1000);
    alinhar();
}

   if (tipoArea == 0)
{
    movimento.girandoEsq();
    delay(700);
    movimento.re();
    delay(2500);
    movimento.fren();
    delay(600);
    movimento.girandoEsq();
    delay(1400);
    movimento.re();
    delay(2500);
    movimento.parar();
    delay(1000);

    movimento.fren();
    delay(500);
    movimento.girando();
    delay(850);
    movimento.fren();
    delay(2500);
    movimento.re();
    delay(2400);
    movimento.girandoEsq();
    delay(1500);
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
   if (tipoArea == 1 || tipoArea == 2)
{
   movimento.fren();
   delay(3000);
   movimento.re();
   delay(3500);
   alinhar();
}
   else if (tipoArea == 0)
{
   movimento.fren();
   delay(2000);
   movimento.re();
   delay(2500);
   alinhar();
}
}


// --> ALINHAR


void Sala3:: alinhar()
{
  if (tipoArea == 1)
{
    movimento.fren();
    delay(400);
    movimento.girando();
    delay(850);
    movimento.fren();
    delay(800);
    movimento.girandoEsq();
    delay(1300);
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
    movimento.girandoEsq();
    delay(1000);
    movimento.re();
    delay(2000);
    movimento.parar();
    while(1);
}
    sensorLateralDir = robo.lerSensorSonarDir();
    if (sensorLateralDir < 40)
{
    contadorAuxiliar = contadorAuxiliar + 1;
}
    movimento.fren();
    delay(400);
    movimento.girando();
    delay(1000);
    movimento.fren();
    delay(500);
    movimento.girandoEsq();
    delay(1500);
    movimento.re();
    delay(1000);
    procurar();
}
  else if (tipoArea == 0)
{
  
}
}


// --> PROCURAR MENOR


void Sala3:: procurarMenor()
{
   if (tipoArea == 1 || tipoArea == 2)
{
   movimento.fren();
   delay(2500);
   movimento.re();
   delay(3300);
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
    movimento.girando();
    delay(850);
    movimento.fren();
    delay(600);
    movimento.girandoEsq();
    delay(1300);
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
  movimento.girandoEsq();
  delay(1400);
  movimento.fren();
  delay(600);
  movimento.girando();
  delay(1000);
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
   alinharInverso();
}
}




















































void Sala3:: garraAbaixada()
{
  robo.acionarServoGarra1(180);
  robo.acionarServoGarra2(180);
}
void Sala3:: garraLevantada()
{
  robo.acionarServoGarra1(100);
  robo.acionarServoGarra2(140);
}
void Sala3:: garraFechada()
{
  robo.acionarServoGarra2(110);
  movimento.parar();
  delay(400);
  robo.acionarServoGarra1(90);
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
  if (digitalRead(fimdocurso) == LOW || digitalRead(fimdocurso2) == LOW)
  {
    robo.acionarMotores(0, 0);//resgatar(); 
    while(1);
  }
}
