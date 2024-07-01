#include <Ultrasonic.h>
#include <Servo.h>

#define PIN_MOTOR_1A 9
#define PIN_MOTOR_1B 10
#define PIN_MOTOR_2A 5
#define PIN_MOTOR_2B 6
#define PIN_RIGHTSENSOR_1 7
#define PIN_RIGHTSENSOR_2 8
#define PIN_LEFTSENSOR_1 12
#define PIN_LEFTSENSOR_2 13
#define TRIGGER 3
#define ECHO 2
#define SERVO_DEGREE 4
#define SERVO_CLAW 11

class DCMotor {
  public:
    DCMotor(uint8_t pinA, uint8_t pinB) {
        _pin1 = pinA;
        _pin2 = pinB;
        _speed = 0;
    }

    void begin() {
        pinMode(_pin1, OUTPUT);
        pinMode(_pin2, OUTPUT);
    }

    void setSpeed(int spd) {
        _speed = spd;
    }

    void forward() {
        analogWrite(_pin1, _speed);
        digitalWrite(_pin2, LOW);
    }

    void backward() {
        analogWrite(_pin2, _speed);
        digitalWrite(_pin1, LOW);
    }

    void stop() {
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, LOW);
    }

    int getSpeed() {
        return _speed;
    }

  private:
    uint8_t _pin1;
    uint8_t _pin2;
    int _speed;
};

DCMotor motor_1(PIN_MOTOR_1A, PIN_MOTOR_1B);
DCMotor motor_2(PIN_MOTOR_2A, PIN_MOTOR_2B);  
Ultrasonic ultSensor(TRIGGER, ECHO);

bool rightSensor_1;
bool rightSensor_2;
bool leftSensor_1;
bool leftSensor_2;
bool hasBiff;
bool hasObj;
int ultSensor_Distance;
int realDistance;
int backMillis;
unsigned long previousMillis = 0;
const unsigned long interval = 500;
const unsigned long turnDelay = 1000;

void setup(){
  motor_1.begin();
  motor_2.begin();
  pinMode(PIN_RIGHTSENSOR_1, INPUT);
  pinMode(PIN_RIGHTSENSOR_2, INPUT);
  pinMode(PIN_LEFTSENSOR_1, INPUT);
  pinMode(PIN_LEFTSENSOR_2, INPUT);
  motor_1.setSpeed(60);
  motor_2.setSpeed(60);
  motor_1.forward();
  motor_2.forward();
  hasBiff = false;
  hasObj = false;
  Serial.begin(9600);
}

void loop(){
  unsigned long currentMillis = millis();
  
  while(true){
    ultSensor_Distance = ultSensor.read(CM);
    rightSensor_1 = digitalRead(PIN_RIGHTSENSOR_1);
    rightSensor_2 = digitalRead(PIN_RIGHTSENSOR_2);
    leftSensor_1 = digitalRead(PIN_LEFTSENSOR_1);
    leftSensor_2 = digitalRead(PIN_LEFTSENSOR_2);

    if(ultSensor_Distance <= 15 && (!rightSensor_2 || !leftSensor_2)){
      if((rightSensor_2 || leftSensor_2) && !hasBiff){
        hasBiff = true;
        backMillis = currentMillis;
      }
      hasObj = true;
      motor_1.forward();
      motor_2.forward();
      motor_1.setSpeed(60);
      motor_2.setSpeed(60);
      Serial.println("asd");
    }
    if((ultSensor_Distance <= 15 && (rightSensor_2 && leftSensor_2)) && !hasBiff){
      motor_1.stop();
      motor_2.stop();
      break;
    }
    if((rightSensor_2 && leftSensor_2) && hasBiff){
        while((backMillis + 150) > 0){
          motor_1.backward();
          motor_2.backward();
          backMillis -= 1;
        }
        hasBiff = false;
      }
    

    if(hasObj){
      return;
    }
    if(rightSensor_2 || leftSensor_2){
      motor_1.stop();
      motor_2.stop();
      delay(500);
    }
    if(!rightSensor_2 && leftSensor_2){
      motor_2.stop();
      motor_1.forward();
      motor_1.setSpeed(60);
      delay(200);
    }
    else if(rightSensor_2 && !leftSensor_2){
      motor_1.stop();
      motor_2.forward();
      motor_2.setSpeed(60);
      delay(200);
    }
    else{
      if(!rightSensor_1 && leftSensor_1){
        motor_1.forward();
        motor_2.forward();
        motor_1.setSpeed(50);
        motor_2.setSpeed(0);
      }
      else if(rightSensor_1 && !leftSensor_1){
        motor_1.forward();
        motor_2.forward();
        motor_2.setSpeed(50);
        motor_1.setSpeed(0);
      }
      else if(!rightSensor_1 && !leftSensor_1){
        motor_1.forward();
        motor_2.forward();
        motor_2.setSpeed(50);
        motor_1.setSpeed(50);
      }
    }
  }
}

