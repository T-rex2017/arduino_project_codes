// defines variables
int distance;

void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  pinMode(4, OUTPUT);
  pinMode(5, INPUT);

  pinMode(6, OUTPUT);
  pinMode(7, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, INPUT);

  pinMode(12, OUTPUT);
  pinMode(13, INPUT);

  pinMode(14, OUTPUT);
  pinMode(15, INPUT);

  pinMode(16, OUTPUT);
  pinMode(17, INPUT);

  pinMode(18, OUTPUT);
  pinMode(19, INPUT);

  pinMode(20, OUTPUT);
  pinMode(21, INPUT);

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
  Serial.print(" us1 : ");
  Serial.print(min_distance(12, 13));
  Serial.print(" us1 : ");
  Serial.print(min_distance(14, 15));
  Serial.print(" us1 : ");
  Serial.print(min_distance(16, 17));
  Serial.print(" us1 : ");
  Serial.print(min_distance(18, 19));
  Serial.print(" us1 : ");
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
