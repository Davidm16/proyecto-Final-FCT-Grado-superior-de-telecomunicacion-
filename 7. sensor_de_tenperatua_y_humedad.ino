//7 Sensor de  Temperatura 
#include "DHT.h"

int pinTemperatura = 11;

DHT temperatura(pinTemperatura,DHT11);

void setup() 
{
  pinMode (pinTemperatura,INPUT);
  temperatura.begin();
  Serial.begin(9600);
}

void loop() {
 
float h = temperatura.readHumidity();//lee la humedad usando el metodo readHumidity 
float t = temperatura.readTemperature();//lee la temperatura usando el metodo ReadTemperature
if (isnan(h) || isnan(t))
return;
{
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");
  }
       
}
