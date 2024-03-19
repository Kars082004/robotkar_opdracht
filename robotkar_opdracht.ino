#include <NewPing.h>
  
int directionPinRight = 12;
int pwmPinRight = 3;



//uncomment if using channel B, and remove above definitions
int directionPinLeft = 13;
int pwmPinLeft = 11;


//ping variabelen
int trigPin = 9;
int echoPin = 8;
int distance;
int duration;


// controls
int speed = 80;
int straight[5] = {1, 1, 0, 1, 1};
int left[5] = {0,0,1,1,1};
int right[5] = {1,1,1,0,0};
int both[5] = {0,0,0,0,0};
int nothing[5] = {1,1,1,1,1};
// check
bool boolLeft = false;
bool boolRight = false;


//boolean to switch direction
bool directionState = true;

// lineSensore

int lineSensor1 = 4;
int lineSensor2 = 5;
int lineSensor3 = 6;
int lineSensor4 = 7;
int lineSensor5 = 10;

// milli
long int startTime = 0;
long int longInt = 0;

// timers 
  bool turn = true;


void setup() {
  //define pins
  pinMode(directionPinRight, OUTPUT);
  pinMode(directionPinLeft, OUTPUT);
  pinMode(pwmPinRight, OUTPUT);
  pinMode(pwmPinLeft, OUTPUT);
  pinMode(lineSensor1, INPUT);
  pinMode(lineSensor2, INPUT);
  pinMode(lineSensor3, INPUT);
  pinMode(lineSensor4, INPUT);
  pinMode(lineSensor5, INPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
}

void ping(){
   digitalWrite (trigPin, HIGH);
   delay(50);
   digitalWrite (trigPin, LOW);
   duration = pulseIn(echoPin,HIGH);
   distance = (duration/2)/29.1;
   if(distance >= 50){

   }
   delay(200);
   Serial.print(distance);
   Serial.println(" cm");

}

void releaseBreak() {
  //release breaks
  changeSpeed(65);
}

void setBreak() {
  //sets breaks
  changeSpeed(0);
}

void directionFront() {
  directionState = true;
}

void directionBack() {
  directionState = false;
}

void changeSpeed(int speed) {
  analogWrite(pwmPinRight, speed);
  analogWrite(pwmPinLeft, speed);
}

void driveStraight() {
  changeSpeed(65);
  directionFront();
  digitalWrite(directionPinRight, LOW);
  digitalWrite(directionPinLeft, HIGH);
}

void driveLeft() {
  changeSpeed(65);
  directionFront();
  digitalWrite(directionPinRight, LOW);
  digitalWrite(directionPinLeft, LOW);
}

void driveRight() {
  changeSpeed(65);
  directionFront();
  digitalWrite(directionPinRight, HIGH);
  digitalWrite(directionPinLeft, HIGH);
}

void smallRight(int speed) {
  analogWrite(pwmPinRight, speed / 2);
  analogWrite(pwmPinLeft, speed);

}


void smallLeft(int speed) {
  analogWrite(pwmPinRight, speed);
  analogWrite(pwmPinLeft, speed / 2);

}

void loop() {
  if((millis() > 2000) ) {
    int lineS1 = digitalRead(lineSensor1);
    int lineS2 = digitalRead(lineSensor2);
    int lineS3 = digitalRead(lineSensor3);
    int lineS4 = digitalRead(lineSensor4);
    int lineS5 = digitalRead(lineSensor5);
    int line[5] = {lineS1, lineS2, lineS3, lineS4, lineS5};
    //set work duty for the motor
    // if(turn == true) {
    //   releaseBreak();
    //   driveRight();      
    // } else {
    //   changeSpeed(0);
    //   setBreak();
    // }
   
   Serial.println();
    if(memcmp(line, straight, sizeof(line)) == 0) {
      releaseBreak();
      driveStraight();
      boolLeft = false;
    }
    if (memcmp(line, left, sizeof(line)) == 0){
      boolLeft = true;
    }
    if(memcmp(line, nothing, sizeof(line)) == 0){
      if(left) {
        driveLeft();
      }
      releaseBreak();
      // changeSpeed(0);
      // setBreak();
    }
    if (memcmp(line, right, sizeof(line)) == 0){

    longInt = millis();
    if (lineS3 == 0 && lineS4 == 1) {
      startTime = longInt;
      turn = false;
    
    //write a low state to the direction pin (13)
    }
    }
  }
  
  
}



