#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
String readString;
const int IN1 = 12;
const int IN2 = 13;
const int IN3 = 21;
const int IN4 = 22;

void setup() {
   Serial.begin(9600);
   servo1.attach(2);
   servo2.attach(3);
   servo3.attach(4);
   servo4.attach(5);
   servo5.attach(6);
   servo6.attach(7);
   servo7.attach(8);
   servo8.attach(9);
   servo9.attach(10);
   servo10.attach(11);
    servo1.write(10);
   servo2.write(160);
   servo3.write(0);
   servo4.write(180);
   servo5.write(0);
   servo6.write(0);
   servo7.write(180);
   servo8.write(90);
   servo9.write(0);
   servo10.write(0);
   pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
 
}

void loop() {
 while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);

    /*To run the motor, call run(direction) where direction is FORWARD, BACKWARD or RELEASE.*/
    if (readString =="FORWARD"){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
    }
    
    if (readString =="BACK"){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
    }
    
    if (readString =="LEFT"){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
    }
    
    if (readString =="RIGHT"){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
    }
    
    if (readString =="STOP"){
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
   servo1.write(0);
   servo2.write(160);
   servo3.write(0);
   servo4.write(180);
   servo5.write(0);
   servo6.write(0);
   servo7.write(180);
   servo8.write(0);
   servo9.write(0);
   servo10.write(0);
    }
     if (readString =="NAME"){
     servo8.write(0);
     delay(15);
     servo8.write(90);
     delay(15);
    }
     if (readString =="HANDSUP"){
     servo1.write(180);
     servo2.write(0);
    }

    if (readString == "HANDSDOWN"){
      servo1.write(10);
      servo2.write(160);
    }

    if (readString == "TYR"){
      servo7.write(175);
     
    }
    if (readString == "TYL"){
     servo7.write(0);
     
    }
    
    if (readString == "TYU"){
      servo8.write(175);
     
    }
    if (readString == "TYD"){
     servo8.write(0);
     
    }
    if (readString == "ELBOW"){
             
    servo5.write(50);
    servo6.write(50);
    }

    readString="";
  }
}
