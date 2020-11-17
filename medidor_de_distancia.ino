// 6 Sensor de ultrasonodo de sistancia 

#include<NewPing.h>

const int PinTrigger = 49;
const int pinEcho = 53; 

NewPing ultrasonido (PinTrigger,pinEcho,200);

void setup() {
  Serial.begin(9600);
  pinMode(PinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
}

void loop() {
  
int calcular6 = map(ultrasonido.ping_cm(), 0, 45, 4, 0);
int calcular7 = map(ultrasonido.ping_cm(), 0, 45, 100, 0);

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
Serial.println("% ");
}
