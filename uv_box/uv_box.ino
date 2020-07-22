int GatePin = 2;
int StartPin = 3;
int uvPin = 4;
int potPin = A0;
int bTime = 0;
int bfor = 0;
int potVal = 0;
bool isOpen = true;
bool uvState = false;
unsigned long startMillis = 0;
bool debug = true;


void setup() {
  if (debug == true)
    Serial.begin(9600);
  pinMode(GatePin, INPUT);
  pinMode(StartPin, INPUT);
  pinMode(uvPin, OUTPUT);
}

void loop() {
  if (debug == true)
    Serial.println();

  // Read Gate State
  if (digitalRead(GatePin) == HIGH) {
    isOpen = false;
    if (debug == true)
      Serial.print("Door : Closed ");
  }
  else {
    isOpen = true;
    if (debug == true)
      Serial.print("Door : Opened ");
  }

  // Read Pot Value
  potVal = analogRead(potPin);
  if (debug == true)
    Serial.print("bTime : ");

  if (potVal > 0 && potVal <= 255) {
    bTime = 15000;
    if (debug == true)
      Serial.print("15k ");
  }
  else if (potVal > 255 && potVal <= 560) {
    bTime = 30000;
    if (debug == true)
      Serial.print("30k ");
  }
  else if (potVal > 560 && potVal <= 715) {
    bTime = 45000;
    if (debug == true)
      Serial.print("45k ");
  }
  else if (potVal > 715 && potVal <= 1023) {
    bTime = 60000;
    if (debug == true)
      Serial.print("60k ");
  }

  //start baking if startbtn pressed

  if (uvState != true) {
    if (digitalRead(StartPin) == HIGH && isOpen == false) {
      startMillis = millis();
      uvState = true;
      bfor = bTime;
      digitalWrite(uvPin, HIGH);
    }
  }

  unsigned long currentMillis = millis();

  if (currentMillis - startMillis >= bfor || isOpen == true) {
    uvState = false;
    digitalWrite(uvPin, LOW);
    if (debug == true)
      Serial.print("UV : OFF ");
  }

  if (debug == true && uvState == true){
    Serial.print("UV : ON ");
    Serial.print("Time : ");
    Serial.print(currentMillis - startMillis);
  }
}