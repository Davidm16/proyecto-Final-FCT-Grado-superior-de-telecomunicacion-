// 1. para encende el morot de agua con el pulsador 

int  pinBomba_de_agua = 3;
int  boton = 5;

void setup() 
{
 pinMode(pinBomba_de_agua,OUTPUT);
 pinMode(boton,INPUT);
  }
void loop() 
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
