// Pinos dos Motores
#define pinMot1A 5
#define pinMot1B 6
#define pinMot2A 9
#define pinMot2B 10


void setup(){

  // Definindo pinos dos motores como OUTPUT
  pinMode(pinMot1A, OUTPUT); 
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);

}

void loop(){

  // Colocando valor específico de energia para os motores
  analogWrite(pinMot1A, 80);
  analogWrite(pinMot2A, 80);
  
}
