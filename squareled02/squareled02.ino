const int upleft_led = 3;
const int upright_led = 5;
const int downleft_led = 6;
const int downright_led = 9;
int val[4];
int i;

void setup() {
  Serial.begin(9600);
  Serial.write(0);
  i = 0;
  for (int i = 0; i < 4; i++) {
    val[i] = 30;
  }
}

void loop() {
  if (Serial.available()) {
    val[i] = Serial.read();
    if (i > 4 || val[i] == '\0') {
      i = 0;
    }
    else {
      i++;
    }
  }
  analogWrite(upleft_led, val[0]);
  analogWrite(upright_led, val[1]);
  analogWrite(downleft_led, val[2]);
  analogWrite(downright_led, val[3]);
}
