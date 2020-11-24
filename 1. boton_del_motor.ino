// 1. para encende el morot de agua con el pulsador 

int tempo = 0;
int  pinBomba_de_agua = 3;
bool bomba_activa = false;
int  boton = 5;

void setup() 
{
 pinMode(pinBomba_de_agua,OUTPUT);
 pinMode(boton,INPUT);
 
  }
void loop()
{
tempo = tempo + 1; //Sumar +1 al temporizador
}
void encenderBomba() {
  if (bomba_activa == false) {
    bomba_activa = true;
    digitalWrite(pinBomba_de_agua, LOW);
  } else {
    bomba_activa = false;
    digitalWrite(pinBomba_de_agua, HIGH);
  }
}
 
