int VolPin[3] = {2, 3, 4};
int SigPin[4] = {5, 6, 7, 8};
int nuval;

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
        checkpin(i);
        setlow();
        break;
      case 1:
        digitalWrite(VolPin[i], HIGH);
        digitalWrite(VolPin[i + 1], LOW);
        digitalWrite(VolPin[i - 1], LOW);
        checkpin(i);
        setlow();
        break;
      case 2:
        digitalWrite(VolPin[i], HIGH);
        digitalWrite(VolPin[i + 1], LOW);
        digitalWrite(VolPin[i - 2], LOW);
        checkpin(i);
        setlow();
        break;
    }
  }
}

void checkpin(int nuval) {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(SigPin[i]) == HIGH) {
      Serial.print(" Pin : ");
      switch (nuval) {
        case 0:
          switch (i) {
            case 0:
              Serial.println(0);
            case 2:
              Serial.println(1);
            case 3:
              Serial.println(2);
            case 4:
              Serial.println(3);
          }
        case 1:
          switch (i) {
            case 0:
              Serial.println(4);
            case 2:
              Serial.println(5);
            case 3:
              Serial.println(6);
            case 4:
              Serial.println(7);
          }
        case 2:
          switch (i) {
            case 0:
              Serial.println(8);
            case 2:
              Serial.println(9);
            case 3:
              Serial.println('*');
            case 4:
              Serial.println('#');
          }
      }
    }
  }
}

void setlow() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(VolPin[i], LOW);
  }
}
