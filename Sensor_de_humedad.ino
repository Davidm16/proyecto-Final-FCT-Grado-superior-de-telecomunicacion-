// 2 Senssor de Humedad de Tierra 
int pinHumedad = A0;
int  pinBomba_de_agua = 3;
void setup() 
{
  Serial.begin(6900);
  }

void loop() 
{
int calcular2 = map(analogRead(pinHumedad), 0, 1023, 100, 0);
Serial.println (analogRead(pinHumedad));
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
  }
