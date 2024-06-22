#define PIN_MOTOR_1A 10
#define PIN_MOTOR_1B 11
#define PIN_MOTOR_2A 5
#define PIN_MOTOR_2B 6
#define PIN_IFSENSOR_1 7
#define PIN_IFSENSOR_2 8
#define PIN_IFSENSOR_3 
#define PIN_IFSENSOR_4 

bool ReadSensor_1;
bool ReadSensor_2;
bool ReadSensor_3;
bool ReadSensor_4;

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

DCMotor Motor_1(PIN_MOTOR_1A, PIN_MOTOR_1B);
DCMotor Motor_2(PIN_MOTOR_2A, PIN_MOTOR_2B);

void turnLeft() {
  Motor_1.Stop();
  Motor_2.Forward();
}

void turnRight() {
  Motor_1.Forward();
  Motor_2.Stop();
}

void setup() {
  
  Motor_1.begin();
  Motor_2.begin();
  pinMode(PIN_IFSENSOR_1, INPUT);
  pinMode(PIN_IFSENSOR_2, INPUT);
  Motor_1.setSpeed(100);
  Motor_2.setSpeed(100);

}

void loop() {
  
  ReadSensor_1 = digitalRead(PIN_IFSENSOR_1);
  ReadSensor_2 = digitalRead(PIN_IFSENSOR_2);
  ReadSensor_3 = digitalRead(PIN_IFSENSOR_3);
  ReadSensor_4 = digitalRead(PIN_IFSENSOR_4);

  if (!ReadSensor_1 && !ReadSensor_2){
    Motor_1.Forward();
    Motor_2.Forward();
  }


}
