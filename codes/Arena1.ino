#define PIN_MOTOR1A 5
#define PIN_MOTOR1B 6
#define PIN_MOTOR2A 10
#define PIN_MOTOR2B 11
#define PIN_IFSENSOR1 7
#define PIN_IFSENSOR2 8

bool ReadSensor1;
bool ReadSensor2;

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

    void Forward() {
        analogWrite(_pin1, _speed);
        digitalWrite(_pin2, LOW);
    }

    void Backward() {
        analogWrite(_pin2, _speed);
        digitalWrite(_pin1, LOW);
    }

    void Stop() {
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

DCMotor motor1(PIN_MOTOR1A, PIN_MOTOR1B);
DCMotor motor2(PIN_MOTOR2A, PIN_MOTOR2B);

void setup() {
  
  motor1.begin();
  motor2.begin();
  pinMode(PIN_IFSENSOR1, INPUT);
  pinMode(PIN_IFSENSOR2, INPUT);
  motor1.setSpeed(80);
  motor2.setSpeed(80);

}

void loop() {
  
  ReadSensor1 = digitalRead(PIN_IFSENSOR1) == HIGH ? true : false;
  ReadSensor2 = digitalRead(PIN_IFSENSOR2) == HIGH ? true : false;

  ReadSensor1 ? motor1.Stop() : motor1.Forward();
  ReadSensor2 ? motor2.Stop() : motor2.Forward();

}
