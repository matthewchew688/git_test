#ifndef METHODS_H
#define METHODS_H

/////////////////////////////////////////////////////////////////////////////
//                              Includes                                   //
/////////////////////////////////////////////////////////////////////////////

//// Core Libraries ////
#include <stdint.h>
#include <stdio.h>

//// User Libraries ////
#include "UserInterrupts.h"
#include "RTOS_Tasks.h"
#include "WProgram.h"

/////////////////////////////////////////////////////////////////////////////
//                              Defines                                    //
/////////////////////////////////////////////////////////////////////////////

#define NUM_POTENTS 6
#define NUM_LEDS 8
#define MAX_ANALOG 1023
#define MAX_PWM 255

/*typedef enum
{
	DRIVE=1,
	SWERVE,
	TURN_IN_PLACE,
	TANK
} Drive_Mode_t;*/

/////////////////////////////////////////////////////////////////////////////
//                              Structure Definitionss                     //
/////////////////////////////////////////////////////////////////////////////

typedef struct {
  uint16_t angle;
  uint8_t pin;
} Command_S;

enum Mode_t {
  BASE = 0,
  SHOULDER = 1,
  ELBOW = 2,
  WRIST_PITCH = 3,
  WRIST_YAW = 4,
  CLAW_TORQUE = 5
} Command_E;

Command_S Command [] =
{
  [BASE] = {.angle = 512, .pin = 0},
  [SHOULDER] = {.angle = 512, .pin = 1},
  [ELBOW] = {.angle = 512, .pin = 2},
  [WRIST_PITCH] = {.angle = 512, .pin = 3},
  [WRIST_YAW] = {.angle = 512, .pin = 4},
  [CLAW_TORQUE] = {.angle = 512, .pin = 5}
};

typedef struct {
  uint16_t PWM;
  uint8_t pin;
} Motor_S;

Motor_S Motor [] =
{
  [BASE] = {.PWM = 0, .pin = 20},
  [SHOULDER] = {.PWM = 0, .pin = 21},
  [ELBOW] = {.PWM = 0, .pin = 22},
  [WRIST_PITCH] = {.PWM = 0, .pin = 23},
  [WRIST_YAW] = {.PWM = 0, .pin = 3},
  [CLAW_TORQUE] = {.PWM = 0, .pin = 4}
};

uint8_t clockPin = 11;
uint8_t dataPin = 10;

uint8_t leds = 0;

void hello()
{
  printf("hello everyone");
}
/*
typedef struct
{
	// Fans and Temperature
	uint16_t temp[4];
	// Propulsion
	uint64_t tacho[4];
	uint16_t current[4];
	// Trajectory
	uint16_t angle[4];
	// Calculated values
	float angular_velocity[4];
	float swervo_angle[4];
} feedback_t;

typedef struct
{
	uint8_t speed;
	uint16_t angle;
} reference_t;

typedef struct
{
	uint8_t speed[4];
	uint16_t angle[4];
} command_t;

typedef union
{
	unsigned char bitfield;
	struct {
        unsigned tacho:1;
        unsigned flag1:1;
        unsigned flag2:1;
        unsigned flag3:1;
        unsigned flag4:1;
        unsigned flag5:1;
        unsigned flag6:1;
        unsigned flag7:1;
    };
} flags_t;
*/

/////////////////////////////////////////////////////////////////////////////
//                              Function Declarations                      //
/////////////////////////////////////////////////////////////////////////////

void initialize();

void joystickInput(Command_S A[]);

/*
void getTemperatures(feedback_t * feedback);

void controlFans(feedback_t * feedback);

void TAPfeedbackCapture(feedback_t * feedback);

// Handles transitions between modes and sets trajectory and propulsion commands accordingly
void ModeTransitionControlSequencer(
	reference_t * reference,
	feedback_t * feedback,
	command_t * commands
);

// Controls Rover Trajectory
void TrajectoryControlSystem(
	feedback_t * feedback,
	command_t * commands
);

// Controls Rover Propulsion
void PropulsionControlSystem(
	feedback_t * feedback,
	command_t * commands
);

// Check Fault Flags
void checkAndActionOnFaults(flags_t * flags);
*/
#endif // METHODS_H