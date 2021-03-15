//Made by VR
  #include<Servo.h>

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

const int IN1 = 12;
const int IN2 = 13;
const int IN3 = 21;
const int IN4 = 22;
int pirSensor = 26;
const int trigPin = 28;
const int echoPin = 29;
const int trigPin1 = 30;
const int echoPin1 = 31;
int soundSensor1 = 24;
int soundSensor = 25;

long duration;
int distance;
int safetyDistance;
long duration1;
int distance1;
int safetyDistance1;
String voice;

int pos = 0; 
int smokeA0 = A1;
int sensorThres = 500;
void setup() {
 
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
   servo2.write(170);
   servo3.write(0);
   servo4.write(180);
   servo5.write(0);
   servo6.write(0);
   servo7.write(90);
   servo8.write(90);
   servo9.write(90);
   servo10.write(90);
   
   pinMode (IN1, OUTPUT);
   pinMode (IN2, OUTPUT);
   pinMode (IN3, OUTPUT);
   pinMode (IN4, OUTPUT);
   pinMode(pirSensor, INPUT);
   pinMode(smokeA0, INPUT);
   pinMode (soundSensor, INPUT);
   pinMode (soundSensor1, INPUT);
   pinMode(trigPin, OUTPUT); 
   pinMode(echoPin, INPUT); 
   pinMode(trigPin1, OUTPUT); 
   pinMode(echoPin1, INPUT); 
   
   Serial.begin(9600);
   
}

void loop() {
  

  while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
 if (voice =="FORWARD"){
 
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
else{
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);

// Calculating the distance
distance1= duration1*0.034/2;

safetyDistance1 = distance1;
if (safetyDistance1 <= 5){
 digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
else{
 digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
}


}
delay(2000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
    }
    
    if (voice =="BACK"){
      
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
    }
    
    if (voice =="LEFT"){
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
    }
    
    if (voice =="RIGHT"){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
    }
    
    if (voice =="STOP"){
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
   servo1.write(10);
   servo2.write(160);
   servo3.write(0);
   servo4.write(180);
   servo5.write(0);
   servo6.write(0);
   servo7.write(90);
   servo8.write(90);
   servo9.write(0);
   servo10.write(0);
    }
     if (voice =="EXPLAIN"){
     servo7.write(100);
     servo1.write(50);
     servo5.write(30);
     delay(2000);
     servo7.write(90);
     servo1.write(0);
     servo5.write(0);
     delay(2000);
    }
    if (voice =="HIFI"){
   servo1.write(90);
  delay(2000);
  servo5.write(70);
   delay(2000);
  servo5.write(70);
   delay(2000);
  servo1.write(10);
   delay(2000);
    }
     if (voice =="CLEAN"){
 for (pos = 30; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo7.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 130; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo7.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
    if (voice =="HANDSHAKE"){
     servo7.write(90);
     servo8.write(30);
     delay(2000);
     servo1.write(60);
     servo5.write(70);
     delay(2000);
     servo5.write(30);
     
     delay(2000);
     servo1.write(10);
     servo5.write(0);
     delay(2000);
    }
     if (voice =="HANDSUP"){
     servo1.write(180);
     servo2.write(0);
    }

    if (voice == "HANDSDOWN"){
      servo1.write(10);
      servo2.write(160);
    }
    if (voice == "GRAB"){
      servo9.write(90);
      servo10.write(90);
    }
    if (voice == "TYR"){
      servo7.write(175);
     
    }
    if (voice == "TYL"){
     servo7.write(0);
     
    }
    
    if (voice == "TYU"){
      servo8.write(30);
     
    }
    if (voice == "TYD"){
     servo8.write(135);
     
    }
    if (voice == "ELBOWUP"){
             
    servo5.write(50);
    servo6.write(50);
    }
    if (voice == "ELBOWDOWN"){
             
    servo5.write(0);
    servo6.write(0);
    }


   voice="";
  }
    }
  
   
    
