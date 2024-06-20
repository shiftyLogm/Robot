#define PIN_MOTOR1A 5
#define PIN_MOTOR1B 6
#define PIN_MOTOR2A 10
#define PIN_MOTOR2B 11
#define PIN_IFSENSOR1 7
#define PIN_IFSENSOR2 8
#define PIN_IFSENSOR3 12
#define PIN_IFSENSOR4 13

bool direita1;
bool direita2;
bool esquerda1;
bool esquerda2;

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

DCMotor motor1(PIN_MOTOR1A, PIN_MOTOR1B);
DCMotor motor2(PIN_MOTOR2A, PIN_MOTOR2B);

void setup() {
  
  motor1.begin();
  motor2.begin();
  pinMode(PIN_IFSENSOR1, INPUT);
  pinMode(PIN_IFSENSOR2, INPUT);
  pinMode(PIN_IFSENSOR3, INPUT);
  pinMode(PIN_IFSENSOR4, INPUT);
  motor1.setSpeed(80);
  motor2.setSpeed(80);
  Serial.begin(9600);

}

void loop() {
  
  direita1 = digitalRead(PIN_IFSENSOR1);
  direita2 = digitalRead(PIN_IFSENSOR2);
  esquerda1 = digitalRead(PIN_IFSENSOR3);
  esquerda2 = digitalRead(PIN_IFSENSOR4);

  if(direita1){
    turnRight();
  }
  
  else if(esquerda1){
    turnLeft();
  }
  
  if(!direita1 && !direita2 || !esquerda1 && !esquerda2){
    straight();
  }
} 

void turnRight(){
  motor1.setSpeed(80);
  motor2.stop();
}
void turnLeft(){
  motor1.stop();
  motor2.setSpeed(80);
}
void straight(){
  motor1.setSpeed(80);
  motor2.setSpeed(80);
}