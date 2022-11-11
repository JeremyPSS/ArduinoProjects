/*
 * Proyecto de Hemisemestre - Cubo de basura inteligente
 * Semester: Quinto
 * Author: Jeremy Josue Prieto Conza
 * Date: 20/07/2022
 * Version: 3.0
*/

//#include "ServoTimer2.h" //this library use timer2 from ArduinoUno
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial SerialEsp(2, 3); // RX, TX
//ServoTimer2 servo1;
Servo servo1;

//1º Sensor
int trigPin = 5, echoPin = 6;
long duration,dist,verage;
long aver[3];
//2º Sensor
int trigPin1 = 3, echoPin1 = 9;
long duration1,dist1,verage1;
long aver1[3];
//Servo
int servoPin = 7;
//logic
bool isfull = false, sended=false;
char data;

void setup()
{
  servo1.attach(servoPin);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //pinMode(trigPin1, OUTPUT);
  //pinMode(echoPin1, INPUT)
  
  servo1.write(90); //close the dustbin
  delay(100);
  servo1.detach();//desconnect pin

  Serial.begin(9600);
  SerialEsp.begin(9600);
 
}

void loop()
{

  for (int i = 0; i <= 2; i++)
  { //average distance
    measure();
    //measure1();
    aver[i] = dist;
    //aver1[i] = dist1;
    delay(10);
  }
  
  dist = (aver[0] + aver[1] + aver[2]) / 3;
  //dist1 = (aver1[0] + aver1[1] + aver1[2]) / 3;

  /* Send the data just once time
   * Send the data again just after clear and is full again
  */
  /*
  if( dist1 < 5) 
  {
    isfull = true;
    if(sended != true)
    {
      bool resul = sendDataToEsp("lleno");
      sended = resul; //true
    }
  }else{
    if(isfull==true)
    {
      isfull = false;
      sended = false;
    }
  }
  */
  
  if ( dist < 70 ) { //150
    //Change distance as per your need  
    servo1.attach(servoPin); //reconnect pin
    delay(1);
    servo1.write(25); //open
    delay(3000);
    servo1.write(90);  //close
    delay(300);
    servo1.detach();
    sendDataToEsp();
    
  }

  

}



void measure()
{
  //digitalWrite(10, HIGH); //I dont understand why this line
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration / 2) / 29.1;
}

/*
void measure2()
{
  digitalWrite(10, HIGH); //I dont understand why this line
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  dist1 = (duration1 / 2) / 29.1;
}
*/


//Send information through serial to ESP8266
void sendDataToEsp(){
  /*
  if(type.equals("abierto")){
    //coding for send a register at the DB when is open the dustbin
    String value = "1";
    SerialEsp.println(value);
    //Serial.println("contar <- resquest to esp");
      
  }else{
    //coding for send a notification when the dustbin is full
  
  }
  */
  String value = "1";
  SerialEsp.println(value);
  Serial.println(value);
}




  
