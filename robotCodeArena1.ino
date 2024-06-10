#include <Servo.h>

const int pinServo1 = 1;
const int pinServo2 = 2;
Servo gripperServo1;
Servo gripperServo2;
#define PINSENSOR 10
#define PINLED 11
#define ENERGYPIN 13
int ReadSensor;

void setup(){

  pinMode(PINSENSOR, INPUT);
  pinMode(PINLED, OUTPUT);
  pinMode(ENERGYPIN, OUTPUT);
  gripperServo1.attach(pinServo1);
  gripperServo2.attach(pinServo2);

}

void loop(){]

  digitalWrite(ENERGYPIN, HIGH);
  ReadSensor = digitalRead(PINSENSOR);

  if(ReadSensor == LOW){
    digitalWrite(PINLED, HIGH);
    Serial.println(PINSENSOR);
  }

  else{
    digitalWrite(PINLED, LOW);
  }

  for(int pos = 0; pos <= 180; pos++){
    gripperServo1.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    gripperServo1.write(pos);
    delay(15);
  }
}
