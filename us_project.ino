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
  Serial.print(" us01 : ");
  Serial.print(min_distance(2, 3));
  Serial.print(" us02 : ");
  Serial.print(min_distance(4, 5));
  Serial.print(" us03 : ");
  Serial.print(min_distance(6, 7));
  Serial.print(" us04 : ");
  Serial.print(min_distance(8, 9));
  Serial.print(" us05 : ");
  Serial.print(min_distance(10, 11));
  Serial.print(" us06 : ");
  Serial.print(min_distance(12, 13));
  Serial.print(" us07 : ");
  Serial.print(min_distance(14, 15));
  Serial.print(" us08 : ");
  Serial.print(min_distance(16, 17));
  Serial.print(" us09 : ");
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

  distance = constrain(distance, 0, 40);

  return distance;
}
