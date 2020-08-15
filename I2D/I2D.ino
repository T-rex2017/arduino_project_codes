int VolPin[10] = {2, 3, 4};
int SigPin[10] = {6, 7, 8, 9};
int nuval;
int valu;

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
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  checkbut(0);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  checkbut(1);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  checkbut(2);
  Serial.println();
}

void checkbut(int num) {
  for (int i = 0; i < 4 ; i++) {
    Serial.print(" ");
    int bt = digitalRead(SigPin[i]);
    //Serial.print(bt);
    if (bt == 1) {
      switch (num) {
        case 0:
          switch (i) {
            case 0:
              Serial.print(1);
            case 1:
              Serial.print(2);
            case 2:
              Serial.print(3);
            case 3:
              Serial.print(4);
          }
        case 1:
          switch (i) {
            case 0:
              Serial.print(5);
            case 1:
              Serial.print(6);
            case 2:
              Serial.print(7);
            case 3:
              Serial.print(8);
          }
        case 2:
          switch (i) {
            case 0:
              Serial.print(9);
            case 1:
              Serial.print(0);
            case 2:
              Serial.print('*');
            case 3:
              Serial.print('#');
          }
      }
    }
  }
}
