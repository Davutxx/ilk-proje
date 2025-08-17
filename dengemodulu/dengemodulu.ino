#include <Servo.h>         
#include <PID_v1.h>        

const int servoPin = 9;    
const int triggerPin = 7;  
const int echoPin = 6;     

float Kp = 2.5;            
float Ki = 0;              
float Kd = 1.1;            

double Setpoint, Input, Output, ServoOutput;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);

  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT);     

  Input = readPosition();
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-80, 80); 
}

void loop() {
  Setpoint = 15; 
  Input = readPosition();  

  myPID.Compute(); 
  ServoOutput = 102 + Output; 
  myServo.write(ServoOutput);
}

float readPosition() {
  delay(40); 

  long duration, cm;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = duration / (29 * 2); 

  if (cm > 30) {
    cm = 30; 
  }

  Serial.println(cm);
  return cm;
}
