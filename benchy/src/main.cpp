#include <Arduino.h>
#define ACTIVITY_LED 13
#define STEPPER_IN1 2
#define STEPPER_IN2 3
#define STEPPER_IN3 4
#define STEPPER_IN4 5
#define STEP_EN 18

volatile int state;

void StepISR()
{
  if (state > 7)
  {
    state = 0;
  }
  switch (state)
  {
  case 0:
    digitalWrite(STEPPER_IN1, 1);
    digitalWrite(STEPPER_IN2, 0);
    digitalWrite(STEPPER_IN3, 0);
    digitalWrite(STEPPER_IN4, 1);
    break;
  case 1:
    digitalWrite(STEPPER_IN1, 0);
    digitalWrite(STEPPER_IN2, 0);
    digitalWrite(STEPPER_IN3, 0);
    digitalWrite(STEPPER_IN4, 1);

    break;
  case 2:
    digitalWrite(STEPPER_IN1, 0);
    digitalWrite(STEPPER_IN2, 0);
    digitalWrite(STEPPER_IN3, 1);
    digitalWrite(STEPPER_IN4, 1);
    break;
  case 3:
    digitalWrite(STEPPER_IN1, 0);
    digitalWrite(STEPPER_IN2, 0);
    digitalWrite(STEPPER_IN3, 1);
    digitalWrite(STEPPER_IN4, 0);
    break;
  case 4:
    digitalWrite(STEPPER_IN1, 0);
    digitalWrite(STEPPER_IN2, 1);
    digitalWrite(STEPPER_IN3, 1);
    digitalWrite(STEPPER_IN4, 0);
    break;
  case 5:
    digitalWrite(STEPPER_IN1, 0);
    digitalWrite(STEPPER_IN2, 1);
    digitalWrite(STEPPER_IN3, 0);
    digitalWrite(STEPPER_IN4, 0);
    break;
  case 6:
    digitalWrite(STEPPER_IN1, 1);
    digitalWrite(STEPPER_IN2, 1);
    digitalWrite(STEPPER_IN3, 0);
    digitalWrite(STEPPER_IN4, 0);
    break;
  case 7:
    digitalWrite(STEPPER_IN1, 1);
    digitalWrite(STEPPER_IN2, 0);
    digitalWrite(STEPPER_IN3, 0);
    digitalWrite(STEPPER_IN4, 0);
    break;
  default:
    state = 0;
  }
  state = state + 1;
}

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);



  pinMode(STEP_EN, INPUT);

  attachInterrupt(digitalPinToInterrupt(STEP_EN), StepISR, RISING);

}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("high");
  Serial.println(digitalRead(STEP_EN));
  delay(1000);
}