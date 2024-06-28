#include <Servo.h>

#define PIN_MOTOR_1A 11
#define PIN_MOTOR_1B 10
#define PIN_MOTOR_2A 6
#define PIN_MOTOR_2B 5
// #define PIN_RIGHTSENSOR_1 7
#define PIN_RIGHTSENSOR_2 8
// #define PIN_LEFTSENSOR_1 12
#define PIN_LEFTSENSOR_2 13

// bool rightSensor_1;
bool rightSensor_2;
// bool leftSensor_1;
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

Servo servo_1;
DCMotor motor_1(PIN_MOTOR_1A, PIN_MOTOR_1B);
DCMotor motor_2(PIN_MOTOR_2A, PIN_MOTOR_2B);  

void setup(){

  motor_1.begin();
  motor_2.begin();
  // pinMode(PIN_RIGHTSENSOR_1, INPUT);
  pinMode(PIN_RIGHTSENSOR_2, INPUT);
  // pinMode(PIN_LEFTSENSOR_1, INPUT);
  pinMode(PIN_LEFTSENSOR_2, INPUT);
  servo_1.attach(2);

}

void loop(){

  // rightSensor_1 = digitalRead(PIN_RIGHTSENSOR_1);
  rightSensor_2 = digitalRead(PIN_RIGHTSENSOR_2);
  // leftSensor_1 = digitalRead(PIN_LEFTSENSOR_1);
  leftSensor_2 = digitalRead(PIN_LEFTSENSOR_2);
  Serial.println(rightSensor_2);
  servo_1.write(0);
  delay(2000);
  servo_1.write(70);
  delay(2000);
}
