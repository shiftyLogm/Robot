#include <Servo.h>

#define PIN_MOTOR_1A 9
#define PIN_MOTOR_1B 10
#define PIN_MOTOR_2A 5
#define PIN_MOTOR_2B 6
#define PIN_RIGHTSENSOR_1 7
#define PIN_RIGHTSENSOR_2 8
#define PIN_LEFTSENSOR_1 12
#define PIN_LEFTSENSOR_2 13

bool rightSensor_1;
bool rightSensor_2;
bool leftSensor_1;
bool leftSensor_2;

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
}

void loop(){

  unsigned long currentMillis = millis();

  rightSensor_1 = digitalRead(PIN_RIGHTSENSOR_1);
  rightSensor_2 = digitalRead(PIN_RIGHTSENSOR_2);
  leftSensor_1 = digitalRead(PIN_LEFTSENSOR_1);
  leftSensor_2 = digitalRead(PIN_LEFTSENSOR_2);

  if(rightSensor_2 || leftSensor_2){
    motor_1.stop();
    motor_2.stop();
    delay(800);
    if(!rightSensor_2 && leftSensor_2){
      motor_1.forward();
      motor_1.setSpeed(60);
      motor_2.stop();
      unsigned long turnStartTime = currentMillis;
      
      while (leftSensor_2 && currentMillis - turnStartTime < turnDelay) {
        currentMillis = millis();
      }
    }
    else if(rightSensor_2 && !leftSensor_2){
      motor_1.stop();
      motor_2.forward();
      motor_2.setSpeed(60);
      unsigned long turnStartTime = currentMillis;
      
      while (rightSensor_2 && currentMillis - turnStartTime < turnDelay) {
        currentMillis = millis();
      }
    }
    else if(rightSensor_2 && leftSensor_2){
      motor_1.forward();
      motor_2.forward();
      motor_1.setSpeed(60);
      motor_2.setSpeed(60);
      delay(200);
    }
  }
  else{
    motor_1.setSpeed(60);
    motor_2.setSpeed(60);
    
    if(!rightSensor_1){
      motor_1.forward();
    }
    else{
      motor_1.stop();
    }
    if(!leftSensor_1){
      motor_2.forward();
    }
    else{
      motor_2.stop();
    }

    if(leftSensor_1 && rightSensor_1){
      motor_1.forward();
      motor_2.forward();
    }
  }
}
