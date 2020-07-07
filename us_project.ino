
void setup() {

  int trigPins[10] = {2, 4, 7, 9, 11, 34, 32, 26, 35, 22};
  int echoPins[10] = {3, 5, 6, 8, 10, 36, 30, 28, 37, 24};

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
  Serial.print(min_distance(7, 6));
  Serial.print(" us04 : ");
  Serial.print(min_distance(9, 8));
  Serial.print(" us05 : ");
  Serial.print(min_distance(11, 10));
  Serial.print(" us06 : ");
  Serial.print(min_distance(34, 36));
  Serial.print(" us07 : ");
  Serial.print(min_distance(32, 30));
  Serial.print(" us08 : ");
  Serial.print(min_distance(26, 28));
  Serial.print(" us09 : ");
  Serial.print(min_distance(35, 37));
  Serial.print(" us10 : ");
  Serial.print(min_distance(22, 24));
}


int min_distance(int trig, int echo) {

  long duration;
  int distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  //distance = max(distance, 40);

  return distance;
}
