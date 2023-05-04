// Joystick - Version: Latest 
#include "Joystick.h"

#define HAT1 9
#define HAT2 2
#define HAT3 4
#define HAT4 15

#define TRIGGER1 16
#define TRIGGER2 8

#define BUTTON1 7
#define BUTTON2 5
#define BUTTON3 3
#define BUTTON4 10
#define BUTTON5 14

int L_JoystickX= 424;
int H_JoystickX = 559;
int L_JoystickY = 445;
int H_JoystickY = 610;

Joystick_ Joystick(
  0x03,
  JOYSTICK_TYPE_MULTI_AXIS,
  7,
  1,
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
  false);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(HAT1, INPUT_PULLUP);
  pinMode(HAT2, INPUT_PULLUP);
  pinMode(HAT3, INPUT_PULLUP);
  pinMode(HAT4, INPUT_PULLUP);
  pinMode(TRIGGER1, INPUT_PULLUP);
  pinMode(TRIGGER2, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(BUTTON5, INPUT_PULLUP);

  Joystick.setYAxisRange(H_JoystickY, L_JoystickY);
  Joystick.setXAxisRange(H_JoystickX, L_JoystickX);
  Joystick.begin();
}

void loop() {
  Joystick.setYAxis(analogRead(A0));
  Joystick.setXAxis(analogRead(A1));
  Serial.println(analogRead(A1));
  Joystick.setButton(0, !digitalRead(BUTTON1));
  Joystick.setButton(1, !digitalRead(BUTTON2));
  Joystick.setButton(2, !digitalRead(BUTTON3));
  Joystick.setButton(3, !digitalRead(BUTTON4));
  Joystick.setButton(4, !digitalRead(BUTTON5));
  Joystick.setButton(5, !digitalRead(TRIGGER1));
  Joystick.setButton(6, !digitalRead(TRIGGER2));


  if(digitalRead(HAT1) == LOW) {
    Joystick.setHatSwitch(0, 0);
  } else if(digitalRead(HAT2) == LOW) {
    Joystick.setHatSwitch(0, 90);
  } else if(digitalRead(HAT3) == LOW) {
    Joystick.setHatSwitch(0, 180);
  } else if(digitalRead(HAT4) == LOW) {
    Joystick.setHatSwitch(0, 270);
  } else {
    Joystick.setHatSwitch(0, -1);
  }

}
