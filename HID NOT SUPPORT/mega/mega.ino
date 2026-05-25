const int UP_BTN = 2;
const int DOWN_BTN = 3;
const int LEFT_BTN = 5;
const int RIGHT_BTN = 4;

const int A_BTN = 9;   
const int S_BTN = 8;   
const int Z_BTN = 6;   
const int X_BTN = 7;   

// New buttons
const int U_BTN = 10;
const int I_BTN = 11;
const int O_BTN = 12;
const int P_BTN = 13;

void setup() {

  Serial.begin(9600);

  pinMode(UP_BTN, INPUT_PULLUP);
  pinMode(DOWN_BTN, INPUT_PULLUP);
  pinMode(LEFT_BTN, INPUT_PULLUP);
  pinMode(RIGHT_BTN, INPUT_PULLUP);

  pinMode(A_BTN, INPUT_PULLUP);
  pinMode(S_BTN, INPUT_PULLUP);
  pinMode(Z_BTN, INPUT_PULLUP);
  pinMode(X_BTN, INPUT_PULLUP);

  // New buttons setup
  pinMode(U_BTN, INPUT_PULLUP);
  pinMode(I_BTN, INPUT_PULLUP);
  pinMode(O_BTN, INPUT_PULLUP);
  pinMode(P_BTN, INPUT_PULLUP);
}

void loop() {

  String output = "";

  if (!digitalRead(UP_BTN)) output += "UP,";
  if (!digitalRead(DOWN_BTN)) output += "DOWN,";
  if (!digitalRead(LEFT_BTN)) output += "LEFT,";
  if (!digitalRead(RIGHT_BTN)) output += "RIGHT,";

  if (!digitalRead(A_BTN)) output += "A,";
  if (!digitalRead(S_BTN)) output += "S,";
  if (!digitalRead(Z_BTN)) output += "Z,";
  if (!digitalRead(X_BTN)) output += "X,";

  // New buttons read
  if (!digitalRead(U_BTN)) output += "U,";
  if (!digitalRead(I_BTN)) output += "I,";
  if (!digitalRead(O_BTN)) output += "O,";
  if (!digitalRead(P_BTN)) output += "P,";

  if (output.length() > 0) {

    output.remove(output.length() - 1);

    Serial.println(output);
  }
  else {
    Serial.println("NONE");
  }

  delay(20);
}
