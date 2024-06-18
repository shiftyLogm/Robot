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
        pin1 = pinA;
        pin2 = pinB;
        speed = 0;
    }

    void begin() {
        pinMode(pin1, OUTPUT);
        pinMode(pin2, OUTPUT);
    }

    void setSpeed(int spd) {
        speed = spd;
    }

    void Forward() {
        analogWrite(pin1, speed);
        digitalWrite(pin2, LOW);
    }

    void Backward() {
        analogWrite(pin2, speed);
        digitalWrite(pin1, LOW);
    }

    void Stop() {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
    }

    int getSpeed() {
        return speed;
    }

  private:
    uint8_t pin1;
    uint8_t pin2;
    int speed;
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
