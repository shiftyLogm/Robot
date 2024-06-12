#include <Servo.h> // Biblioteca para manuseio do Motor Servo
#include <Ultrasonic.h> // Biblioteca para manuseio do Sensor Ultrassônico
#include <L298N.h> // Biblioteca para manuseio da Ponte H

// Definições dos pinos que serão usados
#define PIN_SERVO1
#define PIN_SERVO2
#define PIN_IFSENSOR1
#define PIN_IFSENSOR2
#define PIN_LED
#define ENERGY_PIN 
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

Servo gripper_Servo1;
Servo gripper_Servo2;
int Read_IFSensor1;
int Read_IFSensor2;
int UltSensor_Distance; // Variável que receberá a atual distância em centímetros do objeto detectado pelo Sensor Utrassônico

L298N motor1(ENA, IN1, IN2);
L298N motor2(ENB, IN3, IN4);
Ultrasonic SensorUltra(TRIGGER, ECHO); // Definindo os pinos de entrada de Trigger e Echo do Ultrassônico

bool ReadSensor1;
bool ReadSensor2;

void setup(){

  pinMode(PIN_IFSENSOR1, INPUT); // Definindo pino do sensor como input
  pinMode(PIN_IFSENSOR2, INPUT);
  pinMode(ENERGY_PIN, OUTPUT); // Definindo a entrada do pino de energia
  pinMode(7, OUTPUT);
  
  gripper_Servo1.attach(PIN_IFSERVO1); // Atribuindo energia ao pino do servo
  gripper_Servo2.attach(PIN_IFSERVO2);

  // Definindo velocidade do Motor
  motor1.setSpeed(150);
  motor2.setSpeed(150);

  
  
  Dc_Motor1.run(FORWARD); // Definindo a direção para frente (Isso também liga o motor)
  Dc_Motor2.run(FORWARD);
  
}

void loop(){

  UltSensor_Distance = SensorUltra.read(CM); // Passará a distância em centímetros do objecto detectado pelo Sensor
  digitalWrite(ENERGY_PIN, HIGH); // Atribuindo energia ao pino
  Read_IFSensor1 = digitalRead(PIN_IFSENSOR1); // Variável que armazena o atual valor do sensor IF em loop
  Read_IFSensor2 = digitalRead(PIN_IFSENSOR2);

  digitalWrite(7, HIGH);
  ReadSensor1 = digitalRead(PIN_IFSENSOR1) == HIGH ? true : false;
  ReadSensor2 = digitalRead(PIN_IFSENSOR2) == HIGH ? true : false;
  
  ReadSensor1 ? motor1.forward() : motor1.stop();
  ReadSensor2 ? motor2.forward() : motor2.stop(); 

  // Possível lógica

}
