#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define ACTIVITY_LED 13

// put function declarations (prototypes) here:

// Read https://www.freertos.org/fr-content-src/uploads/2018/07/161204_Mastering_the_FreeRTOS_Real_Time_Kernel-A_Hands-On_Tutorial_Guide.pdf
// for what a task needs to do.
void BlinkTaskPractice(void *blinkParameters);
void SerialPrintTaskPractice(void *printParams);

// Global variables:
TaskHandle_t * blinkHandle;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  BaseType_t blinkSuccess = xTaskCreate(BlinkTaskPractice,"Blink", 512, nullptr, 1, blinkHandle);

  if(blinkSuccess == pdPASS) {
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
    delay(500);
  }

  // in the event the for loop exits:
  vTaskDelete(NULL);

}

//hi jake
