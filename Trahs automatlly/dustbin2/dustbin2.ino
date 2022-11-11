#include <Servo.h>
Servo servo;

int trigPin = 5;

int echoPin = 6;

int servoPin = 7;

long duration,
     dist,
     verage;

long aver[3];


void setup()
{


  servo.attach(servoPin);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  servo.write(0);

  delay(100);
  servo.detach();
}


void measure()
{
  digitalWrite(10, HIGH);
  digitalWrite(trigPin, LOW);

  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(15);

  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  dist = (duration / 2) / 29.1;

}

void loop()
{
  for (int i = 0; i <= 2; i++)
  { //average distance
    measure();

    aver[i] = dist;
    delay(10);

  }
  dist = (aver[0] + aver[1] + aver[2]) / 3;


  if ( dist < 150 ) {
    //Change distance as per your need
    servo.attach(servoPin);

    delay(1);
    servo.write(90);

    delay(3000);

    servo.write(0);

    delay(300);
    servo.detach();
  }
}
