/////////////////////////////////////////////////////////////////////////////
//                              Includes                                   //
/////////////////////////////////////////////////////////////////////////////

//// Core Libraries ////
#include "WProgram.h"
#include "FreeRTOS_ARM.h"
#include <stdbool.h>
#include <stdio.h>

//// User Libraries ////
#include "Methods.h"
#include "RTOS_Tasks.h"
#include "UserInterrupts.h"

/////////////////////////////////////////////////////////////////////////////
//                              Defines                                    //
/////////////////////////////////////////////////////////////////////////////

#define DELAY_MS(ms) (ms / portTICK_PERIOD_MS)
#define STACK(s) configMINIMAL_STACK_SIZE + s
#define PRIORITY(p) tskIDLE_PRIORITY + p
#define ARR_SIZEOF(x)   (sizeof((x)) / sizeof((x[0])))
#define BAUDRATE 9600

<<<<<<< HEAD
typedef enum
{
    PRIORITY_CRITICAL   = PRIORITY(0),
    PRIORITY_HIGH       = PRIORITY(1),
    PRIORITY_MEDIUM     = PRIORITY(2),
    PRIORITY_LOW        = PRIORITY(3)
} RTOS_Task_Priorities;

=======
>>>>>>> 24d9547eed1608b417dd40e83088be3136747e37
/////////////////////////////////////////////////////////////////////////////
//                              RTOS Handels                               //
/////////////////////////////////////////////////////////////////////////////

TaskHandle_t Heart;
TaskHandle_t Serial_Task;
<<<<<<< HEAD
TaskHandle_t JoystickInput;
=======
TaskHandle_t Joystick_task;
>>>>>>> 24d9547eed1608b417dd40e83088be3136747e37

/////////////////////////////////////////////////////////////////////////////
//                              Startup                                    //
/////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
extern "C" 
int main(void)
=======
extern "C" int main(void)
>>>>>>> 24d9547eed1608b417dd40e83088be3136747e37
{

    // Initializing USB Serial Communication
    Serial.begin(BAUDRATE);
<<<<<<< HEAD
    //while(!Serial) {digitalWrite(13, LOW);}
=======
    while(!Serial) {}
>>>>>>> 24d9547eed1608b417dd40e83088be3136747e37
    Serial.println("Teensy is Alive!");

    // Initializing UART Serial Communication
    Serial1.begin(BAUDRATE);
<<<<<<< HEAD
    //while(!Serial1) {}
    Serial2.begin(BAUDRATE);
    //while(!Serial2) {}


=======
    while(!Serial1) {}
    Serial2.begin(BAUDRATE);
    while(!Serial2) {}
>>>>>>> 24d9547eed1608b417dd40e83088be3136747e37

/////////////////////////////////////////////////////////////////////////////
//                              RTOS Task Initalization                    //
/////////////////////////////////////////////////////////////////////////////

//// Heart Beat Task ////
    xTaskCreate(
        vHeartBeatTask, //Function that implements the task
        "Heart",        //Test name for the task
        STACK(128),     //Stack size in words, no bytes
        NULL,           //Parameter passes into the task
        PRIORITY(0),    //Priority at which the task is created
        &Heart          //Used to pass out the created task's handel
    );

//// SerialController Task ////
     xTaskCreate(
         vSerialController,   //Function that implements the task
         "Serial",      //Test name for the task
         STACK(128),    //Stack size in words, not bytes
         NULL,          //Parameter that is passed into the task
         PRIORITY(1),   //Priority at which the task is created
         &Serial_Task   //Used to pass out the created task's handel
     );

<<<<<<< HEAD
     xTaskCreate(
     	vJoystickInput,
     	"joystickInput",
     	STACK(128),
     	NULL,
     	PRIORITY(1),
     	&JoystickInput
     );
=======
     xTaskCreat(
     	vJoystickInput,
     	"JoystickInput",
     	STACK(128),
     	Command,
     	PRIORITY(0),
     	&Joystick_task
     	);
>>>>>>> 24d9547eed1608b417dd40e83088be3136747e37
    // Start FreeRTOS
    vTaskStartScheduler();

    // should never return
    while(1);
}