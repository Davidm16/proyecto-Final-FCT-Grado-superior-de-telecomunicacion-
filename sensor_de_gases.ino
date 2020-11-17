//5 variables Sensor de gases 
int pinGasDigital = 9;
int pinGasAnalog = A9;

void setup()
{
  pinMode (pinGasDigital,OUTPUT);// define ledPin una salida
  Serial.begin(9600);
}
void loop() {
boolean mq_estado = digitalRead(pinGasDigital);
int adc_MQ = analogRead(pinGasAnalog); //Lemos la salida analógica  del MQ
float voltaje = adc_MQ * (5.0 / 1023.0); //Convertimos la lectura en un valor de voltaje
float Rs=1000*((5-voltaje)/voltaje);  //Calculamos Rs con un RL de 1k
double alcohol=0.4091*pow(Rs/5463, -1.497); // calculamos la concentración  de alcohol con la ecuación obtenida.
int calcular5 = map(analogRead(pinGasAnalog), 500, 200, 100, 0);

//Serial.println (analogRead(pinGasAnalog));
//Serial.println (analogRead(pinGasDigital));

  if(mq_estado) 
  {
    Serial.println("Alcohol detectado");
  }
  else //si la salida del sensor es 0
  {
    Serial.println("Sin presencia de alcohol");
  }
  {
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
}
}
