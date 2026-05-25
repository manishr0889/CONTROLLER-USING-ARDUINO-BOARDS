#include <Keyboard.h>

const int upBtn = 5;   //r5
const int downBtn = 4;  //l4
const int leftBtn = 2;  //u2
const int rightBtn = 3;  //d3

const int xBtn = 7;
const int oBtn = 6;
const int triBtn = 8;
const int sqrBtn = 9;

void setup() {

  Serial.begin(9600);

  while (!Serial);

  pinMode(upBtn, INPUT_PULLUP);
  pinMode(downBtn, INPUT_PULLUP);
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);

  pinMode(xBtn, INPUT_PULLUP);
  pinMode(oBtn, INPUT_PULLUP);
  pinMode(triBtn, INPUT_PULLUP);
  pinMode(sqrBtn, INPUT_PULLUP);

  Keyboard.begin();

  Serial.println("GAME CONTROLLER READY");
}

void loop() {

  // ===== ACTION BUTTONS =====

  if (digitalRead(xBtn) == LOW) {

    Keyboard.press('x');
    Serial.println("X");

  } else {

    Keyboard.release('x');
  }

  if (digitalRead(oBtn) == LOW) {

    Keyboard.press('o');
    Serial.println("O");

  } else {

    Keyboard.release('o');
  }

  if (digitalRead(triBtn) == LOW) {

    Keyboard.press('t');
    Serial.println("TRIANGLE");

  } else {

    Keyboard.release('t');
  }

  if (digitalRead(sqrBtn) == LOW) {

    Keyboard.press('s');
    Serial.println("SQUARE");

  } else {

    Keyboard.release('s');
  }

  // ===== DIRECTION BUTTONS =====

  if (digitalRead(upBtn) == LOW) {

    Keyboard.press(KEY_UP_ARROW);
    Serial.println("UP");

  } else {

    Keyboard.release(KEY_UP_ARROW);
  }

  if (digitalRead(downBtn) == LOW) {

    Keyboard.press(KEY_DOWN_ARROW);
    Serial.println("DOWN");

  } else {

    Keyboard.release(KEY_DOWN_ARROW);
  }

  if (digitalRead(leftBtn) == LOW) {

    Keyboard.press(KEY_LEFT_ARROW);
    Serial.println("LEFT");

  } else {

    Keyboard.release(KEY_LEFT_ARROW);
  }

  if (digitalRead(rightBtn) == LOW) {

    Keyboard.press(KEY_RIGHT_ARROW);
    Serial.println("RIGHT");

  } else {

    Keyboard.release(KEY_RIGHT_ARROW);
  }

  delay(30);
}
