#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <StepperDriver.h>
#define ACTIVITY_LED 13
#define STEPPER_IN1 11
#define STEPPER_IN2 10
#define STEPPER_IN3 9
#define STEPPER_IN4 8

// put function declarations (prototypes) here:

// Read https://www.freertos.org/fr-content-src/uploads/2018/07/161204_Mastering_the_FreeRTOS_Real_Time_Kernel-A_Hands-On_Tutorial_Guide.pdf
// for what a task needs to do.
void BlinkTaskPractice(void *blinkParameters);
void SerialPrintTaskPractice(void *printParams);
void StepperMotorPractice(void *stepperParams);

// Global variables:
TaskHandle_t * blinkHandle;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  StepperMotor motor1(STEPPER_IN1,STEPPER_IN2,STEPPER_IN3,STEPPER_IN4,10,CLOCKWISE);
  motor1.StartStepper();
  Serial.println(motor1.playornot);

  //BaseType_t stepperSuccess = xTaskCreate(StepperMotorPractice,"step", 256, &motor1, 1, nullptr);
  BaseType_t blinkSuccess = xTaskCreate(BlinkTaskPractice,"Blink", 256, nullptr, 2, blinkHandle);

  /*if(stepperSuccess == pdPASS) {
    String out = String("Stepper Task Created");
    Serial.println(out);
  } else {
    Serial.println("Failed to create Stepper task.");
  }*/
  if(blinkSuccess == pdPASS) {
    String out = String("Blink Task Created");
    Serial.println(out);
  } else {
    Serial.println("Failed to create Blink task.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

void BlinkTaskPractice(void *blinkParameters) {
  //Setup
  pinMode(ACTIVITY_LED, OUTPUT);
  digitalWrite(ACTIVITY_LED, 0);
  BaseType_t state = 1;

  //infinite loop
  for(;;) {
    Serial.println("Running Blink Task");
    digitalWrite(ACTIVITY_LED, state);

    state = state == 1 ? 0 : 1;
    
    // Delay => According to Arduino_FreeRTOS docs, delay calls vTaskDelay automatically.
    delay(5000);
  }

  // in the event the for loop exits:
  vTaskDelete(NULL);

}

void StepperMotorPractice(void * motor) {
  StepperMotor motor1 = *(StepperMotor *) motor;
  StartMotor(motor1);
  //Setup
  /*BaseType_t state = 0;
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);
  delay(30);

  while(true){
    if(state>7){
      state=0;
    }
    switch(state){
    case 0: 
      digitalWrite(STEPPER_IN1,0);
      digitalWrite(STEPPER_IN2,0);
      digitalWrite(STEPPER_IN3,0);
      digitalWrite(STEPPER_IN4,0);
      break;
    case 1:
      digitalWrite(STEPPER_IN1,0);
      digitalWrite(STEPPER_IN2,0);
      digitalWrite(STEPPER_IN3,0);
      digitalWrite(STEPPER_IN4,1);
      
      break;
    case 2: 
      digitalWrite(STEPPER_IN1,0);
      digitalWrite(STEPPER_IN2,0);
      digitalWrite(STEPPER_IN3,1);
      digitalWrite(STEPPER_IN4,1);
      break;
    case 3: 
      digitalWrite(STEPPER_IN1,0);
      digitalWrite(STEPPER_IN2,0);
      digitalWrite(STEPPER_IN3,1);
      digitalWrite(STEPPER_IN4,0);
      break;
    case 4: 
      digitalWrite(STEPPER_IN1,0);
      digitalWrite(STEPPER_IN2,1);
      digitalWrite(STEPPER_IN3,1);
      digitalWrite(STEPPER_IN4,0);
      break;
    case 5: 
      digitalWrite(STEPPER_IN1,0);
      digitalWrite(STEPPER_IN2,1);
      digitalWrite(STEPPER_IN3,0);
      digitalWrite(STEPPER_IN4,0);
      break;
    case 6: 
      digitalWrite(STEPPER_IN1,1);
      digitalWrite(STEPPER_IN2,1);
      digitalWrite(STEPPER_IN3,0);
      digitalWrite(STEPPER_IN4,0);
      break;
    case 7: 
      digitalWrite(STEPPER_IN1,1);
      digitalWrite(STEPPER_IN2,0);
      digitalWrite(STEPPER_IN3,0);
      digitalWrite(STEPPER_IN4,0);
      break;
    default: state = 0;
    }
    state++;
    Serial.println(state);
    delayMicroseconds(10);
  }*/



}

void SerialPrintTaskPractice(void *printParams) {
  for(;;) {
    
  }
}