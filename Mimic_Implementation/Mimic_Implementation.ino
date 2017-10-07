#define NUM_POTENTS 6

// =====================================
// Potentiometer Structure
// =====================================

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

// =====================================
// Initialization and Loop
// =====================================

void setup() {
  // put your setup code here, to run once:
  for(uint8_t i = 0; i < NUM_POTENTS; i++){
  pinMode(i, INPUT_PULLUP);
  Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Command[BASE].angle = analogRead(Command[BASE].pin);
  Joystick.X(Command[BASE].angle);

  Command[SHOULDER].angle = analogRead(Command[SHOULDER].pin);
  Joystick.Y(Command[SHOULDER].angle);

  Command[ELBOW].angle = analogRead(Command[ELBOW].pin);
  Joystick.Z(Command[ELBOW].angle);

  Command[WRIST_PITCH].angle = analogRead(Command[WRIST_PITCH].pin);
  Joystick.sliderLeft(Command[WRIST_PITCH].angle);

  Command[WRIST_YAW].angle = analogRead(Command[WRIST_YAW].pin);
  Joystick.sliderRight(Command[WRIST_YAW].angle);

  Command[CLAW_TORQUE].angle = analogRead(Command[CLAW_TORQUE].pin);
  Joystick.Zrotate(Command[CLAW_TORQUE].angle);
}
