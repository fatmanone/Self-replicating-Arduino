


String inputString;
void util_setup() {
  inputString.reserve(200);
}

void(* resetFunc) (void) = 0; //declare reset function @ address 0

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      Serial.print("CMD: ");
      Serial.println(inputString);
      if (inputString == "prg\n") {
        Serial.println("onProgram();");
        onProgram();
      }
      inputString = "";
    }
  }
}
