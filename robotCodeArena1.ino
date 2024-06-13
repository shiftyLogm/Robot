#include <Servo.h> // Biblioteca para manuseio do Motor Servo
#include <Ultrasonic.h> // Biblioteca para manuseio do Sensor Ultrassônico
#include <L298N.h> // Biblioteca para manuseio da Ponte H

// Definições dos pinos que serão usados
#define PIN_SERVO1
#define PIN_SERVO2
#define PIN_IFSENSOR1
#define PIN_IFSENSOR2
#define PIN_LED
#define ENERGY_PIN 7
#define TRIGGER
#define ECHO
#define IN1 A1
#define IN2 A2
#define ENA A0
#define IN3 A3
#define IN4 A4
#define ENB A5
#define PIN_IFSENSOR1 12
#define PIN_IFSENSOR2 13

// Variáveis Servos
Servo gripper_Servo1;
Servo gripper_Servo2;

// Variável que receberá a atual distância em centímetros do objeto detectado pelo Sensor Utrassônico
int UltSensor_Distance; 

// Variáveis recebendo os Motores DC na Ponte H
L298N motor1(ENA, IN1, IN2);
L298N motor2(ENB, IN3, IN4);

// Definindo os pinos de entrada de Trigger e Echo do Ultrassônico
Ultrasonic SensorUltra(TRIGGER, ECHO); 

// Valores booleanos para armazenar o valor dos Sensores Infravermelhos
bool ReadSensor1;
bool ReadSensor2;

void setup(){

  // Definindo pinos dos sensores como input
  pinMode(PIN_IFSENSOR1, INPUT);
  pinMode(PIN_IFSENSOR2, INPUT);
  
  // Definindo a entrada do pino de energia
  pinMode(ENERGYPIN, OUTPUT);

  // Atribuindo energia aos pinos dos servos
  gripper_Servo1.attach(PIN_IFSERVO1); 
  gripper_Servo2.attach(PIN_IFSERVO2);

  // Definindo velocidade dos Motores
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  
}

void loop(){

  UltSensor_Distance = SensorUltra.read(CM); // Passará a distância em centímetros do objecto detectado pelo Sensor
  
  digitalWrite(ENERGY_PIN, HIGH); // Atribuindo energia ao pino

  // Ternário Condicional que armazena os atuais valores dos sensores IF em loop, caso HIGH armazena true, caso contrário armazena falso
  ReadSensor1 = digitalRead(PIN_IFSENSOR1) == HIGH ? true : false;
  ReadSensor2 = digitalRead(PIN_IFSENSOR2) == HIGH ? true : false;

  // Ternário Condicional que executa uma direção para os motores, caso o valor booelano seja true ele anda, caso contrário ele para
  ReadSensor1 ? motor1.forward() : motor1.stop();
  ReadSensor2 ? motor2.forward() : motor2.stop(); 

  // Possível lógica

}
