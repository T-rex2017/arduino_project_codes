// INPUTS
int sensorPin = 2;
int flotPin = 3;
int potPin = A0;

// OUTPUTS
int relayPin = 5;
int readyPin = 6; 

int potVal;
int spillTime;
int trigTime;

bool isRunning = false;
bool sensorDetected;
bool noFluid;
bool isReady = false;

unsigned long readDelay = 1000;
unsigned long sqartMillis;
unsigned long sensorCounter;
unsigned long squartCounter;

void setup() {
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(readyPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(flotPin, INPUT_PULLUP);

  //digitalWrite(readyPin, HIGH);
  //digitalWrite(relayPin, LOW);
}

void loop() {
  pot();
  
  if (digitalRead(flotPin) == LOW) {
    noFluid = true;
  }
  else if(digitalRead(flotPin) == HIGH){
    noFluid = false;
  }

  if (sensorDetected != true && digitalRead(sensorPin) == HIGH) {
    sensorDetected = true;
    sensorCounter = millis();
  }
  else if (digitalRead(sensorPin) == LOW) {
    sensorDetected = false;
  }

  unsigned long currentMillis = millis();

  if (isRunning != true && noFluid != true && sensorDetected == true && currentMillis - sensorCounter >= readDelay) {
    trigTime = spillTime;
    squartCounter = millis();
    digitalWrite(relayPin, HIGH);
    isRunning = true;
    isReady = false;
  }

  if (isRunning == true) {
    if (currentMillis - squartCounter >= trigTime || sensorDetected == false || noFluid == true) {
      digitalWrite(relayPin, LOW);
      isReady = true;
      if(sensorDetected == false){
        isRunning = false;
      }
    }
  }

  if (isReady == true && noFluid != true) {
    digitalWrite(readyPin, HIGH);
  }
  else {
    digitalWrite(readyPin, LOW);
  }
} // loop


void pot() {
  potVal = analogRead(potPin);

  if (potVal >= 0 && potVal <= 93) {
    spillTime = 500;
  }
  else if (potVal >= 93 && potVal <= 186) {
    spillTime = 600;
  }
  else if (potVal >= 186 && potVal <= 279) {
    spillTime = 700;
  }
  else if (potVal >= 279 && potVal <= 372) {
    spillTime = 800;
  }
  else if (potVal >= 372 && potVal <= 465) {
    spillTime = 900;
  }
  else if (potVal >= 465 && potVal <= 558) {
    spillTime = 1000;
  }
  else if (potVal >= 588 && potVal <= 651) {
    spillTime = 1100;
  }
  else if (potVal >= 651 && potVal <= 744) {
    spillTime = 1200;
  }
  else if (potVal >= 744 && potVal <= 837) {
    spillTime = 1300;
  }
  else if (potVal >= 837 && potVal <= 930) {
    spillTime = 1400;
  }
  else if (potVal >= 930 && potVal <= 1023) {
    spillTime = 1500;
  }
}
