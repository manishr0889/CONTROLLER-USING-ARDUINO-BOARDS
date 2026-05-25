#include <Keyboard.h>

void setup() {

  Serial.begin(9600);
  while (!Serial);

  Keyboard.begin();
}

void loop() {

  if (Serial.available()) {

    String data = Serial.readStringUntil('\n');
    data.trim();

    if (data == "UP") Keyboard.press(KEY_UP_ARROW);
    else if (data == "DOWN") Keyboard.press(KEY_DOWN_ARROW);
    else if (data == "LEFT") Keyboard.press(KEY_LEFT_ARROW);
    else if (data == "RIGHT") Keyboard.press(KEY_RIGHT_ARROW);

    else if (data == "X") Keyboard.press('x');
    else if (data == "O") Keyboard.press('o');
    else if (data == "T") Keyboard.press('t');
    else if (data == "S") Keyboard.press('s');

    delay(50);

    Keyboard.releaseAll();
  }
}
