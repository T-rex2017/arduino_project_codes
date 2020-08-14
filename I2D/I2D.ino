int VolPin[3] = {2, 3, 4};
int SigPin[4] = {5, 6, 7, 8};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(VolPin[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(SigPin[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    switch (i) {
      case 0:
        digitalWrite(VolPin[i], HIGH);
        digitalWrite(VolPin[i + 1], LOW);
        digitalWrite(VolPin[i + 2], LOW);
        checkpin();
        setlow();
        break;
      case 1:
        digitalWrite(VolPin[i], HIGH);
        digitalWrite(VolPin[i + 1], LOW);
        digitalWrite(VolPin[i - 1], LOW);
        checkpin();
        setlow();
        break;
      case 2:
        digitalWrite(VolPin[i], HIGH);
        digitalWrite(VolPin[i + 1], LOW);
        digitalWrite(VolPin[i - 2], LOW);
        checkpin();
        setlow();
        break;
    }
  }
}

void checkpin() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(SigPin[i]) == HIGH){
      Serial.print(" Pin : ");
      Serial.println(SigPin[i]);
    }
  }
}

void setlow() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(VolPin[i], LOW);
  }
}
