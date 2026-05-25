#include <Keyboard.h>

const int upBtn = 2;
const int downBtn = 4;
const int leftBtn = 3;
const int rightBtn = 5;

const int xBtn = 6;
const int oBtn = 7;
const int triBtn = 10;
const int sqrBtn = 9;

void setup() {

  Serial.begin(9600);

  pinMode(upBtn, INPUT_PULLUP);
  pinMode(downBtn, INPUT_PULLUP);
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);

  pinMode(xBtn, INPUT_PULLUP);
  pinMode(oBtn, INPUT_PULLUP);
  pinMode(triBtn, INPUT_PULLUP);
  pinMode(sqrBtn, INPUT_PULLUP);

  Keyboard.begin();

  Serial.println("Controller Started");
}

void loop() {

  // Action buttons first priority
  bool xPressed   = digitalRead(xBtn) == LOW;
  bool oPressed   = digitalRead(oBtn) == LOW;
  bool tPressed   = digitalRead(triBtn) == LOW;
  bool sPressed   = digitalRead(sqrBtn) == LOW;

  // Agar koi action button dab raha hai
  if (xPressed || oPressed || tPressed || sPressed) {

    // Direction keys release
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);

    // X
    if (xPressed) {
      Keyboard.press('x');
      Serial.println("X");
    } else {
      Keyboard.release('x');
    }

    // O
    if (oPressed) {
      Keyboard.press('o');
      Serial.println("O");
    } else {
      Keyboard.release('o');
    }

    // TRIANGLE
    if (tPressed) {
      Keyboard.press('t');
      Serial.println("TRIANGLE");
    } else {
      Keyboard.release('t');
    }

    // SQUARE
    if (sPressed) {
      Keyboard.press('s');
      Serial.println("SQUARE");
    } else {
      Keyboard.release('s');
    }
  }

  // Agar action button nahi dab raha
  else {

    Keyboard.release('x');
    Keyboard.release('o');
    Keyboard.release('t');
    Keyboard.release('s');

    // UP
    if (digitalRead(upBtn) == LOW) {
      Keyboard.press(KEY_UP_ARROW);
      Serial.println("UP");
    } else {
      Keyboard.release(KEY_UP_ARROW);
    }

    // DOWN
    if (digitalRead(downBtn) == LOW) {
      Keyboard.press(KEY_DOWN_ARROW);
      Serial.println("DOWN");
    } else {
      Keyboard.release(KEY_DOWN_ARROW);
    }

    // LEFT
    if (digitalRead(leftBtn) == LOW) {
      Keyboard.press(KEY_LEFT_ARROW);
      Serial.println("LEFT");
    } else {
      Keyboard.release(KEY_LEFT_ARROW);
    }

    // RIGHT
    if (digitalRead(rightBtn) == LOW) {
      Keyboard.press(KEY_RIGHT_ARROW);
      Serial.println("RIGHT");
    } else {
      Keyboard.release(KEY_RIGHT_ARROW);
    }
  }

  delay(50);
}
