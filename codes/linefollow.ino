#define PIN_MOTOR_1A 13
#define PIN_MOTOR_1B 12
#define PIN_MOTOR_2A 11
#define PIN_MOTOR_2B 10
#define PIN_RIGHTSENSOR 9
#define PIN_LEFTSENSOR 8

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

bool rightSensor;
bool leftSensor;

void setup() {

  motor_1.begin();
  motor_2.begin();
  pinMode(PIN_RIGHTSENSOR, INPUT);
  pinMode(PIN_LEFTSENSOR, INPUT);

}

void loop() {

  motor_1.setSpeed(60);
  motor_2.setSpeed(60);

  rightSensor = digitalRead(PIN_RIGHTSENSOR);
  leftSensor = digitalRead(PIN_LEFTSENSOR);

  if (!leftSensor && !rightSensor) {
    motor_1.forward();
    motor_2.forward();
  }
  else {
    if (rightSensor) {
      motor_1.stop();
      motor_2.forward();
    }

    if (leftSensor) {
      motor_1.forward();
      motor_2.stop();
    }
  }
}