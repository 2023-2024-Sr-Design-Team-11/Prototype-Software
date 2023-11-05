#include <Arduino.h>
#include <string.h>

#define CLOCKWISE 0
#define COUNTERCLOCKWISE 1

class StepperMotor { 
    // Access specifier 
public: 
    int port1;
    int port2;
    int port3;
    int port4;
    bool playornot;
    int state;
    int steptime;
    int direction;
    int nextsteptime;
    int stoptime;
    StepperMotor(int port1, int port2, int port3, int port4, int speed, int direction){
        this->port1 = port1;
        this->port2 = port2;
        this->port3 = port3;
        this->port4 = port4;
        pinMode(this->port1, OUTPUT);
        pinMode(this->port2, OUTPUT);
        pinMode(this->port3, OUTPUT);
        pinMode(this->port4, OUTPUT);
        delay(30);
        this->playornot = false;
        this->state = 0;
        this->steptime = speed;
        this->direction = direction;
    }
    void StopStepper(){
        this->playornot = false;
    }
    void Step(){
        if(this->playornot = false){
            return;
        }
        this->nextsteptime = this->nextsteptime + this->steptime;
        if(this->state<0){
            this->state = 7;
        }else if(this->state>7){
            this->state = 0;
        }
        switch(state){
            case 0: 
                digitalWrite(this->port1,0);
                digitalWrite(this->port2,0);
                digitalWrite(this->port3,0);
                digitalWrite(this->port4,0);
            break;
            case 1:
                digitalWrite(this->port1,0);
                digitalWrite(this->port2,0);
                digitalWrite(this->port3,0);
                digitalWrite(this->port4,1);
      
            break;
            case 2: 
                digitalWrite(this->port1,0);
                digitalWrite(this->port2,0);
                digitalWrite(this->port3,1);
                digitalWrite(this->port4,1);
            break;
            case 3: 
                digitalWrite(this->port1,0);
                digitalWrite(this->port2,0);
                digitalWrite(this->port3,1);
                digitalWrite(this->port4,0);
            break;
            case 4: 
                digitalWrite(this->port1,0);
                digitalWrite(this->port2,1);
                digitalWrite(this->port3,1);
                digitalWrite(this->port4,0);
            break;
            case 5: 
                digitalWrite(this->port1,0);
                digitalWrite(this->port2,1);
                digitalWrite(this->port3,0);
                digitalWrite(this->port4,0);
            break;
            case 6: 
                digitalWrite(this->port1,1);
                digitalWrite(this->port2,1);
                digitalWrite(this->port3,0);
                digitalWrite(this->port4,0);
            break;
            case 7: 
                digitalWrite(this->port1,1);
                digitalWrite(this->port2,0);
                digitalWrite(this->port3,0);
                digitalWrite(this->port4,0);
            break;
            default: state = 0;
        }
        if(this->direction = CLOCKWISE){
            state++;
        }else if(this->direction = COUNTERCLOCKWISE){
            state--;
        }
        
        //Serial.println(state);
    }
}; 

void StartMotor(StepperMotor motor){
    int currenttime = millis();
    motor.playornot = true;
    motor.nextsteptime = millis()+motor.steptime;
    while(motor.playornot){
        currenttime = millis();
        while(currenttime > motor.nextsteptime){
            motor.Step();
        }
    }

}






