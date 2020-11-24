//4 variables Luminosidad
int pinLuminosidad = A2;
void setup() 
{
Serial.begin(9600);
}
void loop() 
{
int calcular4 = map(analogRead(pinLuminosidad), 0, 1023, 100, 0);
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
}
