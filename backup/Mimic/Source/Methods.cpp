#include "Methods.h"
#include "usb_joystick.h"

/////////////////////////////////////////////////////////////////////////////
//                              Function Definitions                       //
/////////////////////////////////////////////////////////////////////////////
void initialize()
{
   for(uint8_t i = 14; i < 14+NUM_POTENTS; i++){
    pinMode(i, INPUT_PULLUP);
    }
   for(uint8_t i = 20; i < 24; i++){
    pinMode(i, OUTPUT);
    }
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
}

void joystickInput(Command_S A[])
{
    uint8_t leds = 0;
    shiftOut(dataPin, clockPin, MSBFIRST, leds);

    A[BASE].angle = analogRead(A[BASE].pin);
      A[WRIST_PITCH].PWM = MAX_PWM * A[BASE].angle / MAX_ANALOG;
      analogWrite(A[WRIST_PITCH].mPin, A[WRIST_PITCH].PWM);
      for(int8_t i = 7; i >= 0; i--)
      {
        if(A[BASE].angle > (1005/7)*i+3)
        {
          bitSet(leds, i);
          shiftOut(dataPin, clockPin, MSBFIRST, leds);
        }
        else
        {
          bitClear(leds, i);
          shiftOut(dataPin, clockPin, MSBFIRST, leds);
        }
      }
    //Joystick.X(A[BASE].angle);

    //A[SHOULDER].angle = analogRead(A[SHOULDER].pin);
    //Joystick.Y(A[SHOULDER].angle);

    //A[ELBOW].angle = analogRead(A[ELBOW].pin);
    //Joystick.Z(A[ELBOW].angle);

    //A[WRIST_PITCH].angle = analogRead(A[WRIST_PITCH].pin);
    //Joystick.sliderLeft(A[WRIST_PITCH].angle);

    //A[WRIST_YAW].angle = analogRead(A[WRIST_YAW].pin);
    //Joystick.sliderRight(A[WRIST_YAW].angle);

    //A[CLAW_TORQUE].angle = analogRead(A[CLAW_TORQUE].pin);
    //Joystick.Zrotate(A[CLAW_TORQUE].angle);
}

/*void getTemperatures(feedback_t * feedback)
{

  //Put code here

}

void controlFans(feedback_t * feedback)
{

  //Put code here

}

void TAPfeedbackCapture(feedback_t * feedback)
{

  //Put code here

}

// Handles transitions between modes and sets trajectory and propulsion commands accordingly
void ModeTransitionControlSequencer(
  reference_t * reference,
  feedback_t * feedback,
  command_t * commands
)
{

  //Put code here

}

// Controls Rover Trajectory
void TrajectoryControlSystem(
  feedback_t * feedback,
  command_t * commands
)
{

  //Put code here

}

// Controls Rover Propulsion
void PropulsionControlSystem(
  feedback_t * feedback,
  command_t * commands
)
{

  //Put code here

}

// Check Fault Flags
void checkAndActionOnFaults(flags_t * flags)
{

  //Put code here

}*/










