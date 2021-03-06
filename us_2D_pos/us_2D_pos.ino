
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

  int us01 = min_distance(2, 3);
  int us02 = min_distance(4, 5);
  int us03 = min_distance(7, 6);
  int us04 = min_distance(9, 8);
  int us05 = min_distance(11, 10);
  int us06 = min_distance(34, 36);
  int us07 = min_distance(32, 30);
  int us08 = min_distance(26, 28);
  int us09 = min_distance(35, 37);
  int us10 = min_distance(22, 24);

  int usX[6] = {us01, us02, us03, us04, us05};
  int usY[6] = {us06, us07, us08, us09, us10};

  int xMin = usX[0];
  int yMin = usY[0];

  Serial.println();

  for (int i = 0; i < 5; i++) {
    if (usX[i] < xMin){
      xMin = usX[i];
    } 
  }

  Serial.print(" X : ");
  Serial.print(xMin);

  for (int i = 0; i < 5; i++) {
    if (usY[i] < yMin){
      yMin = usY[i];
    } 
  }

  Serial.print(" Y : ");
  Serial.print(yMin);
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
