// defines variables
int distance;

void setup() {

  int trigPins[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int echoPins[10] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

  for (int i = 0; i < 10; i++) {
    pinMode(trigPins[i], OUTPUT);
  }

  for (int i = 0; i < 10; i++) {
    pinMode(echoPins[i], INPUT);
  }

  Serial.begin(9600);
}

void loop() {
  Serial.println();
  Serial.print(" us1 : ");
  Serial.print(min_distance(2, 3));
  Serial.print(" us2 : ");
  Serial.print(min_distance(4, 5));
  Serial.print(" us3 : ");
  Serial.print(min_distance(6, 7));
  Serial.print(" us4 : ");
  Serial.print(min_distance(8, 9));
  Serial.print(" us5 : ");
  Serial.print(min_distance(10, 11));
  Serial.print(" us6 : ");
  Serial.print(min_distance(12, 13));
  Serial.print(" us7 : ");
  Serial.print(min_distance(14, 15));
  Serial.print(" us8 : ");
  Serial.print(min_distance(16, 17));
  Serial.print(" us9 : ");
  Serial.print(min_distance(18, 19));
  Serial.print(" us10 : ");
  Serial.print(min_distance(20, 21));
}


int min_distance(int trig, int echo) {

  long duration;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}
