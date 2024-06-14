#include <L298NX2.h>

// Pinos dos Motores
#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9
#define ENA 10
#define ENB 11

// Objeto para manuseio dos 2 motores na Ponte H
L298NX2 Dc_Motors(ENA, IN1, IN2, ENB, IN3, IN4);

void setup() {

  Dc_Motors.setSpeedA(80); // Motor 1 recebendo velocidade específica
  Dc_Motors.setSpeedB(200); // Motor 2 recebendo velocidade específica

}

void loop() {

  Dc_Motors.forward(); // Define a direção frente para os motores seguirem

}