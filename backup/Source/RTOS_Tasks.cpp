#include "RTOS_Tasks.h"
#include "FreeRTOS_ARM.h"
#include "Methods.h"
//#include "WProgram.h"

/////////////////////////////////////////////////////////////////////////////
//                             Definitions                                 //
/////////////////////////////////////////////////////////////////////////////

 Command_S A [] =
    {
      [BASE] = {.angle = 512, .pin = 0, .PWM = 0, .mPin = 20},
      [SHOULDER] = {.angle = 512, .pin = 1, .PWM = 0, .mPin = 21},
      [ELBOW] = {.angle = 512, .pin = 2, .PWM = 0, .mPin = 22},
      [WRIST_PITCH] = {.angle = 512, .pin = 3, .PWM = 0, .mPin = 23},
      [WRIST_YAW] = {.angle = 512, .pin = 4, .PWM = 0, .mPin = 3},
      [CLAW_TORQUE] = {.angle = 512, .pin = 5, .PWM = 0, .mPin = 4}
    };

void vJoystickInput(void *pvParameters)
{
    initialize();

    const TickType_t xDelay = DELAY_MS(100);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    //task 1
    while(1)
    {
        vTaskDelayUntil(&xLastWakeTime, xDelay);
        joystickInput(A);
    }
}

void vHeartBeatTask(void *pvParameters)
{

    // Hardware Configuration
    pinMode(13, OUTPUT);

    // Constants
    const TickType_t xDelay = DELAY_MS(500);
    const uint8_t Seq_1[4] = {1, 2, 1, 3};

    // Variables
    TickType_t xLastWakeTime = xTaskGetTickCount();
    uint8_t state = 0;

    // Task Loop
    while (1)
    {
        //Absolute Delay
        vTaskDelayUntil(&xLastWakeTime, xDelay);

        //HeartBeat State Machine
        switch(Seq_1[state])
        {
            case 1:
                digitalWrite(13, HIGH);
                state++;
                break;
            case 2:
                digitalWrite(13, LOW);
                state++;
                break;
            default:
                state = 0;
                digitalWrite(13, LOW);
                break;
        }
    }
}

//Collects and sends Serial Data
void vSerialController(void *pvParameters)
{
    // Variables
    const TickType_t xDelay = DELAY_MS(100);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    // Task Loop
    while (1)
    {
        //Absolute Delay
        vTaskDelayUntil(&xLastWakeTime, xDelay);

        //Collect Incomminbg Serial and assign to the set variables
        Serial.CollectIncomming();

        //Send out changed set values over seial
        Serial.SerialSendAll();
    }
}

//Controls the Teensy's LED in a sequence