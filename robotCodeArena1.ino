#include <Servo.h>
#include <AFMotor.h>

#define PINSERVO1 1;
#define PINSERVO2 2;
#define PINSENSOR 10
#define PINLED 11
#define ENERGYPIN 13

Servo gripperServo1;
Servo gripperServo2;
int ReadSensor;

AF_DCMotor motor(1); // Definindo pino de entrada para o motor, no caso M1
AF_DCMotor motor2(4);

void setup(){

  pinMode(PINSENSOR, INPUT); // Definindo pino do sensor como input
  pinMode(ENERGYPIN, OUTPUT); // Definindo a entrda do pino de energia
  
  gripperServo1.attach(PINSERVO1); // Atribuindo energia ao pino do servo
  gripperServo2.attach(PINSERVO2);

  motor.setSpeed(200); // Definindo velocidade do Motor
  motor2.setSpeed(200); 
  motor.run(FORWARD); // Definindo a direção para frente (Isso também liga o motor)
  motor2.run(FORWARD);
  
}

void loop(){]

  digitalWrite(ENERGYPIN, HIGH); // Atribuindo energia ao pino
  ReadSensor = digitalRead(PINSENSOR); // Variável que armazena o atual valor do sensor IF em loop

  if(ReadSensor == LOW){
    // Condição para caso o sensor detecte "LOW"
  }

  else{
    // Método para caso seja falso
  }

  motor.setSpeed(200); // Definindo velocidade do Motor
  motor2.setSpeed(200); 
  motor.run(FORWARD); // Definindo a direção para a frente
  motor2.run(FORWARD);
  motor.run(BACKWARD); // Definindo a direção para trás
  motor2.run(BACKWARD); // motor.run(RELEASE) => Desliga o motor    
}
