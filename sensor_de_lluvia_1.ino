// 3. SENSOR DE DETECCION DE AGUA 

const int pin = 0;
int pinDetector_de_Agua = 4;
 
void setup() 
{
  pinMode(pinDetector_de_Agua, INPUT);  //definir pin como entrada
  Serial.begin(9600);
}
 
void loop()
{
  int Agua = 0;
//Serial.println (analogRead(pinDetector_de_Agua));
Agua = digitalRead(pinDetector_de_Agua );
 if (pinDetector_de_Agua == LOW) 
 {
      Serial.println("Detectada Agua");
  }
  else {
    Serial.println("No Detecta Agua");
    }    
}
