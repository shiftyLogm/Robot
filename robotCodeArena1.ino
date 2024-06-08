#include <Servo.h>

const int pinServo1 = 1;
const int pinServo2 = 2;
Servo gripperServo1;
Servo gripperServo2;

void setup(){

  gripperServo1.attach(pinServo1);
  gripperServo2.attach(pinServo2);

}

void loop(){

  for(int pos = 0; pos <= 180; pos++){
    gripperServo1.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    gripperServo1.write(pos);
    delay(15);
  }
}
