// Potentiometers
const int POT1 = A0;   // A / D
const int POT2 = A1;   // W / S
const int POT3 = A2;   // U / I
const int POT4 = A3;   // O / P

void setup() {

  Serial.begin(9600);
}

void loop() {

  String output = "";

  // Read potentiometers
  int pot1 = analogRead(POT1);
  int pot2 = analogRead(POT2);
  int pot3 = analogRead(POT3);
  int pot4 = analogRead(POT4);

  // POT1 -> A / D
  if (pot1 < 300) output += "A,";
  else if (pot1 > 700) output += "D,";

  // POT2 -> W / S
  if (pot2 < 300) output += "W,";
  else if (pot2 > 700) output += "S,";

  // POT3 -> U / I
  if (pot3 < 300) output += "U,";
  else if (pot3 > 700) output += "I,";

  // POT4 -> O / P
  if (pot4 < 300) output += "O,";
  else if (pot4 > 700) output += "P,";

  // Send output
  if (output.length() > 0) {

    output.remove(output.length() - 1);
    Serial.println(output);

  } else {

    Serial.println("NONE");
  }

  delay(20);
}
