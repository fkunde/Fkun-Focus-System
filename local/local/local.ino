#include <AccelStepper.h>
#define motorPin1  1
#define motorPin2  3
#define motorPin3  5
#define motorPin4  4
#define MotorInterfaceType 8
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);
void setup() {
  Serial.begin(9600);
   stepper.setMaxSpeed(1000);
   stepper.setAcceleration(1000);
}

int setpos = 0;

void loop() {

  int sensorValue = analogRead(0);

  int diff = abs(setpos-sensorValue);
  if(diff>3){
  setpos = sensorValue*20;
  Serial.println(setpos);
  stepper.moveTo(setpos);
  }

  stepper.runToPosition();
}
