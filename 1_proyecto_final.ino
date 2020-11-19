//proyecto final de las plantas de dani 
//6. librerias sensor de ultrasonido 
#include<NewPing.h>
//7. librerias temperatura 
#include "DHT.h"

//1 variables bombas 
int  pinBomba_de_agua = 3;
int  boton = 5;

//2 variables humedad 
int pinHumedad = A0;

//3 variables Detector de Agua
const int pin = 0;
int pinDetector_de_Agua = 7;

//4 variables Luminosidad
int pinLuminosidad = A6;

//5 variables Sensor de gases 
int pinGasDigital = 9;
int pinGasAnalog = A9;

//6 variables Ultrasonido 
int PinTrigger = 53;
int pinEcho = 49; 

//7 variables Temperatura 
int pinTemperatura = 11;

//6 Ultrasonido. Define altura 
NewPing ultrasonido (PinTrigger,pinEcho,200);
// 7 Temperatura Define
DHT temperatura(pinTemperatura,DHT11);

void setup() {
  //1 bombas
  pinMode(pinBomba_de_agua,OUTPUT);
  pinMode(boton,INPUT);
  //3 Detector de Agua
  pinMode(pinDetector_de_Agua, INPUT);  //definir pin como entrada
  //5 Sensor de gases
  pinMode (pinGasDigital,OUTPUT);// define ledPin una salida
  //6 Ultrasonido
  pinMode (PinTrigger,OUTPUT); //manda señal 
  pinMode (pinEcho,INPUT); // recibe la señal del trigger
  //7 Temperatura
  pinMode (pinTemperatura,INPUT);// lee informacion de la temperatura
  temperatura.begin();
  Serial.begin(9600);
  
}

void loop() 
{
//2 Humedad 
int calcular2 = map(analogRead(pinHumedad), 0, 1023, 100, 0);
//3 Sensor de Agua 
int Agua = digitalRead(pinDetector_de_Agua) ;
//4 Luminosidad 
int calcular4 = map(analogRead(pinLuminosidad), 0, 1023, 100, 0);
//5 Gases
boolean mq_estado = digitalRead(pinGasDigital);
int adc_MQ = analogRead(pinGasAnalog); //Lemos la salida analógica  del MQ
float voltaje = adc_MQ * (5.0 / 1023.0); //Convertimos la lectura en un valor de voltaje
float Rs=1000*((5-voltaje)/voltaje);  //Calculamos Rs con un RL de 1k
double alcohol=0.4091*pow(Rs/5463, -1.497); // calculamos la concentración  de alcohol con la ecuación obtenida.
int calcular5 = map(analogRead(pinGasAnalog), 500, 200, 100, 0);
//6 
int calcular6 = map(ultrasonido.ping_cm(), 0, 45, 4, 0);
int calcular7 = map(ultrasonido.ping_cm(), 0, 45, 100, 0);
//1 boron 
{
  digitalRead(boton);
  if (boton==HIGH)
  {
    digitalWrite(pinBomba_de_agua,HIGH);
    delay(5000);
    }
  else 
  {
    digitalWrite(pinBomba_de_agua,LOW);
     delay(10000);
    }
}
//2 Sensor de humedad 
//Serial.println (analogRead(pinHumedad));
Serial.print("Porcentaje Humedad: ");
Serial.print(calcular2);
Serial.println(" %");

if (analogRead(pinHumedad)>=512)
{
 Serial.println("Poca Humedad");
 Serial.println("Mucha Humedad");
  digitalWrite(pinBomba_de_agua,LOW);
  }
  else
  {
    digitalWrite(pinBomba_de_agua,HIGH);
 Serial.println("Mucha Humedad");
    }

//3 Sensor de lluvia 
//Serial.println (analogRead(pinDetector_de_Agua));
 if (digitalRead (pinDetector_de_Agua) == LOW) {
   Serial.println("Detectada Agua");
  }
  else {
    Serial.println("No Detecta Agua");
    }
     
//4 Luminosidad. 
//Serial.println (analogRead(pinLuminosidad));
Serial.print("Porcentaje Luz: ");
Serial.print(calcular4);
Serial.println(" %");
  if (analogRead(pinLuminosidad)>900)
    {
  Serial.println ("Poca Luz");
  }
  else 
    {
    Serial.println("Luz Correcta");
  }


//5 Sensor de gases
//Serial.println (analogRead(pinGasAnalog));
//Serial.println (analogRead(pinGasDigital));

  if(mq_estado) 
  {
    Serial.println("Alcohol detectado");
  }
  else 
  {
    Serial.println("Sin presencia de alcohol");
  }
  
  Serial.print("adc:");
  Serial.print(adc_MQ);
  Serial.print("    voltaje:");
  Serial.print(voltaje);
  Serial.print("    Rs:");
  Serial.print(Rs);
  Serial.print("    alcohol:");
  Serial.print(alcohol);
  Serial.println("mg/L");

  Serial.print("Porcentaje Gases: ");
  Serial.print(calcular5);
  Serial.println(" %");
  
//6 Ultrasonido Llenado de agua 
//Serial.println (analogRead(ultrasonido));
Serial.print(ultrasonido.ping_cm());// esperar 50ms entre pings (29ms como minimo)
Serial.println("cm");// obtener el valor en cm (0 = fuera de rango)
if (calcular6 == 0) 
{
  Serial.print("Nivel de Agua: Vacio / Seco");
} 
  else if (calcular6 == 1)
  {
    Serial.println("Nivle de Agua: Bajo");
  }
   else if (calcular6 == 2)
  {
    Serial.println("Nivel de Agua: Medio");
  }
   else if (calcular6 == 3)
  {
    Serial.println("Nivel de Agua: Alto");
  }
  else if (calcular6 == 4)
  {
    Serial.println("Nivel de Agua: Muy Alto");
  }

Serial.print(calcular7);
Serial.print("Porcentaje de depósito: ");
Serial.println("% ");

//7 Temperatura
//Serial.println (analogRead(pinTemperatura)); 
float h = temperatura.readHumidity();//lee la humedad usando el metodo readHumidity 
float t = temperatura.readTemperature();//lee la temperatura usando el metodo ReadTemperature
Serial.print("Humedad: ");
Serial.print(h);
Serial.print(" % ");
Serial.print("Temperatura: ");
Serial.print(t);
Serial.println(" *C");

      delay(1000); // tiempo
}

  
