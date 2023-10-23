#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

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
  
  
  BaseType_t stepperSuccess = xTaskCreate(StepperMotorPractice,"step", 512, nullptr, 2, nullptr);
  BaseType_t blinkSuccess = xTaskCreate(BlinkTaskPractice,"Blink", 512, nullptr, 1, blinkHandle);

  if(stepperSuccess == pdPASS) {
    String out = String("Hello, Blink: ");
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
    digitalWrite(ACTIVITY_LED, state);

    state = state == 1 ? 0 : 1;
    
    // Delay => According to Arduino_FreeRTOS docs, delay calls vTaskDelay automatically.
    delay(5000);
  }

  // in the event the for loop exits:
  vTaskDelete(NULL);

}

void StepperMotorPractice(void *stepperParams) {
  //Setup
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);
  BaseType_t state = 0;

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
    delay(10);
  }



}

void SerialPrintTaskPractice(void *printParams) {
  for(;;) {
    
  }
}