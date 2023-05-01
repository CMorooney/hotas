#include "Joystick.h"

#define R_THRUST A1
#define L_TRIGGER 1
#define L_THRUST A0
#define R_TRIGGER 0
#define A_HAT1 14
#define A_HAT2 15
#define B_HAT1 3
#define B_HAT2 20
#define B_HAT3 4
#define B_HAT4 21
#define C_HAT1 5
#define C_HAT2 16
#define C_HAT3 2
#define C_HAT4 10

#define R_THRUST_MIN 500
#define R_THRUST_MAX 1000
#define L_THRUST_MIN 460
#define L_THRUST_MAX 1000

Joystick_ Joystick(
  0x03,
  JOYSTICK_TYPE_JOYSTICK,
  4,
  2,
  true,
  true,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false
);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A_HAT1, INPUT_PULLUP);
  pinMode(A_HAT2, INPUT_PULLUP);
  pinMode(B_HAT1, INPUT_PULLUP);
  pinMode(B_HAT2, INPUT_PULLUP);
  pinMode(B_HAT3, INPUT_PULLUP);
  pinMode(B_HAT4, INPUT_PULLUP);
  pinMode(C_HAT1, INPUT_PULLUP);
  pinMode(C_HAT2, INPUT_PULLUP);
  pinMode(C_HAT3, INPUT_PULLUP);
  pinMode(C_HAT4, INPUT_PULLUP);
  pinMode(L_TRIGGER, INPUT_PULLUP);
  pinMode(R_TRIGGER, INPUT_PULLUP);

  Joystick.setYAxisRange(R_THRUST_MIN, R_THRUST_MAX);
  Joystick.setXAxisRange(R_THRUST_MIN, L_THRUST_MAX);
  Joystick.begin();
}

void loop() {
  Joystick.setYAxis(analogRead(L_THRUST));
  Joystick.setXAxis(analogRead(R_THRUST));
  Joystick.setButton(0, !digitalRead(L_TRIGGER));
  Joystick.setButton(1, !digitalRead(R_TRIGGER));
  Joystick.setButton(2, !digitalRead(A_HAT1));
  Joystick.setButton(3, !digitalRead(A_HAT2));

  if(digitalRead(B_HAT1) == LOW) {
    Joystick.setHatSwitch(0, 0);
  } else if (digitalRead(B_HAT2) == LOW) {
    Joystick.setHatSwitch(0, 90);
  } else if (digitalRead(B_HAT3) == LOW) {
    Joystick.setHatSwitch(0, 180);
  } else if (digitalRead(B_HAT4) == LOW) {
    Joystick.setHatSwitch(0, 270);
  }

  if(digitalRead(C_HAT1) == LOW) {
    Joystick.setHatSwitch(1, 0);
  } else if(digitalRead(C_HAT2) == LOW) {
    Joystick.setHatSwitch(1, 90);
  } else if (digitalRead(C_HAT3) == LOW) {
    Joystick.setHatSwitch(1, 180);
  } else if (digitalRead(C_HAT4) == LOW) {
    Joystick.setHatSwitch(1, 270);
  }
}