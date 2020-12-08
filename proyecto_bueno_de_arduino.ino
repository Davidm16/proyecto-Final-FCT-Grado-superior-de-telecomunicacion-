//proyecto final de las plantas de dani 
//6. librerias sensor de ultrasonido 
#include<NewPing.h>
//7. librerias temperatura 
#include "DHT.h"

//0 Temporizador y bomba 
int tempo = 0;
int  pinBomba_de_agua = 3;
bool bomba_activa = false;
bool estadoBomba = false;

//1 variables boton  
int  boton = 2;

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
  attachInterrupt(digitalPinToInterrupt(boton), encenderBomba, CHANGE);
}

void loop() 
{
//0 Temporizador
tempo = tempo + 1; //Sumar +1 al temporizador
//2 Humedad 
int calcular2 = map(analogRead(pinHumedad), 0, 1023, 100, 0);
//3 Sensor de Agua 
int Agua = digitalRead(pinDetector_de_Agua) ;
//4 Luminosidad 
int calcular4 = map(analogRead(pinLuminosidad), 0, 1023, 100, 0);
//5 Gases
int calcular5 = map(analogRead(pinGasAnalog), 0, 1023, 0, 100);
//6 
int calcular7 = map(ultrasonido.ping_cm(), 1, 35, 100, 0);
//2 Sensor de humedad 
if (bomba_activa == false) {
if (analogRead(pinHumedad)>=512)
{
  digitalWrite(pinBomba_de_agua,LOW);
  }
  else
  {
    digitalWrite(pinBomba_de_agua,HIGH);
    }
}
//7 Temperatura
float h = temperatura.readHumidity();//lee la humedad usando el metodo readHumidity 
float t = temperatura.readTemperature();//lee la temperatura usando el metodo ReadTemperature

// python 
  if (tempo > 200) { 
    //0. Bonba de agua 
    Serial.print(digitalRead(pinBomba_de_agua));
    Serial.print(",");
    // 2.Humedad de tierra 
    Serial.print(calcular2);
    Serial.print(",");
    // 3. Detector de agua  
    Serial.print(digitalRead(pinDetector_de_Agua));
    Serial.print(",");
    // 4. Luminosidad
    Serial.print(calcular4);
    Serial.print(","); 
    // 5. gases
    Serial.print(calcular5);
    Serial.print(",");
    // 6. Nivel de agua ULTRASONIDO
    Serial.print(calcular7);
    Serial.print(",");
    // 7. Temperatura
    Serial.print(t, 1);
    Serial.print(",");
    Serial.print(h, 1);
    Serial.print(",");
     // Phyton 
    Serial.print("\r\n");
    tempo = 0;
}
    delay(10); //tiempo
}

//1boton
void encenderBomba() {
  if (bomba_activa == false) {
    bomba_activa = true;
    digitalWrite(pinBomba_de_agua, LOW);
  } else {
    bomba_activa = false;
    digitalWrite(pinBomba_de_agua, HIGH);
  }
} 
  
