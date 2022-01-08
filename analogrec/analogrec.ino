const int rec_button = 2;
const int shot_button = 4;
const int dlt_button = 7;
const int rec_led = 3;
const int shot_led = 5;
int rec[500];


void setup() {
  pinMode(rec_button, INPUT_PULLUP);
  pinMode(shot_button, INPUT_PULLUP);
  pinMode(dlt_button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(rec_button) == LOW) {
    recwave(rec);
  }
  if (digitalRead(shot_button) == LOW) {
    play(rec);
  }
  if (digitalRead(dlt_button) == LOW) {
    dlt(rec);
  }
  analogWrite(rec_led,0);
  analogWrite(shot_led,0);
}

void recwave(int rec[]) {;
  for (int i = 0; i < 500; i++) {
    rec[i] = analogRead(1);
    analogWrite(rec_led,map(rec[i],0,1023,0,255));
    delay(10);
  }
}

void play(int rec[]) {
  int i = 0;
  for (int j = 0; j < 3; j++) {
    i = 0;
    while (i < 500) {
      analogWrite(shot_led, map(rec[i], 0, 1023, 0, 255));
      i++;
      delay(10);
    }
  }
}

void dlt(int rec[]) {
  for (int i = 0; i < 500; i++) {
    rec[i] = 0;
  }
}
