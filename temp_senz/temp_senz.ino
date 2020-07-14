// input & output pins
int uv_trig = 2;
int uv_echo = 3;
int temp_btn = 4;
int green_led = 5;
int red_led = 6;

unsigned long currentmillis = 0;
unsigned long previousmillis = 0;
unsigned long wakemillis = 0;
unsigned long checkstartmillis = 0;

int distance = 0;
int duration = 0;
int checkdelay = 20000;
int sleepdelay = 30000;


bool sleeping = true;
bool checking = false;
bool waking = false;
bool presence = false;



void setup() {
  pinMode(uv_trig, OUTPUT);
  pinMode(uv_echo, INPUT);
  pinMode(temp_btn, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

void loop() {
  digitalWrite(uv_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(uv_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(uv_trig, LOW);
  duration = pulseIn(uv_echo, HIGH);
  distance = duration * 0.034 / 2;

  if (sleeping == true) {
    digitalWrite(temp_btn, HIGH);
    delayMicroseconds(2);
    digitalWrite(temp_btn, LOW);
    wakemillis = millis();
    sleeping = false;
    delayMicroseconds(500);
  }

  if (distance < 100 && distance > 10 && checking != true) {
    digitalWrite(red_led, HIGH);
  }
  else {
    digitalWrite(red_led, LOW);
  }

  if (distance < 10 && checking != true) {
    digitalWrite(green_led, HIGH);
    digitalWrite(temp_btn, HIGH);
    delayMicroseconds(2);
    digitalWrite(temp_btn, LOW);
    checking = true;
    checkstartmillis = millis();
  }
  else {
    digitalWrite(green_led, LOW);
    digitalWrite(temp_btn, LOW);
  }

  currentmillis = millis();

  if (currentmillis - checkstartmillis >= checkdelay) {
    checking = false;
  }

  if (checking != true && currentmillis - wakemillis >= sleepdelay ) {
    sleeping = true;
  }

}
