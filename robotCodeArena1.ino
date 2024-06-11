#include <Servo.h> // Biblioteca para manuseio do Motor Servo
#include <AFMotor.h> // Biblioteca para manuseio do Shield Motor
#include <Ultrasonic.h> // Biblioteca para manuseio do Sensor Ultrassônico

// Definições dos pinos que serão usados
#define PINSERVO1
#define PINSERVO2
#define PIN_IFSENSOR1
#define PIN_IFSENSOR2
#define PINLED
#define ENERGYPIN 
#define TRIGGER
#define ECHO

Servo gripperServo1;
Servo gripperServo2;
int Read_IFSensor1;
int Read_IFSensor2;
int UltSensor_Distance; // Variável que receberá a atual distância em centímetros do objeto detectado pelo Sensor Utrassônico

AF_DCMotor Dc_Motor1(1); // Definindo pino de entrada para o motor, no caso M1
AF_DCMotor Dc_Motor2(4);
Ultrasonic SensorUltra(TRIGGER, ECHO); // Definindo os pinos de entrada de Trigger e Echo do Ultrassônico

void setup(){

  pinMode(PIN_IFSENSOR1, INPUT); // Definindo pino do sensor como input
  pinMode(PIN_IFSENSOR2, INPUT);
  pinMode(ENERGYPIN, OUTPUT); // Definindo a entrada do pino de energia
  
  gripperServo1.attach(PIN_IFSERVO1); // Atribuindo energia ao pino do servo
  gripperServo2.attach(PIN_IFSERVO2);

  Dc_Motor1.setSpeed(200); // Definindo velocidade do Motor
  Dc_Motor2.setSpeed(200); 
  Dc_Motor1.run(FORWARD); // Definindo a direção para frente (Isso também liga o motor)
  Dc_Motor2.run(FORWARD);
  
}

void loop(){

  UltSensor_Distance = SensorUltra.read(CM); // Passará a distância em centímetros do objecto detectado pelo Sensor
  digitalWrite(ENERGYPIN, HIGH); // Atribuindo energia ao pino
  Read_IFSensor1 = digitalRead(PIN_IFSENSOR1); // Variável que armazena o atual valor do sensor IF em loop
  Read_IFSensor2 = digitalRead(PIN_IFSENSOR2);

  if(Read_IFSensor1 == HIGH && Read_IFSensor2 == HIGH){
    delay(500);
    Dc_Motor1.run(BACKWARD);
    Dc_Motor2.run(BACKWARD);
  }

  else{
    // Método para caso seja falso
  }

  Dc_Motor1.setSpeed(200); // Definindo velocidade do Motor
  Dc_Motor2.setSpeed(200); 
  Dc_Motor1.run(FORWARD); // Definindo a direção para a frente
  Dc_Motor2.run(FORWARD);
  Dc_Motor1.run(BACKWARD); // Definindo a direção para trás
  Dc_Motor2.run(BACKWARD); // motor.run(RELEASE) => Desliga o motor    

  // Possível lógica

}
