const int led0 = 2;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;

const int led_a = 6;
const int led_b = 7;
const int led_c = 8;

const int store = 9;
const int add = 10;
const int memoryswitch = 11;

const int in_led = 13;

int sled;

int register_a, register_b, register_c;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(led_a, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(led_c, OUTPUT);

  pinMode(in_led, OUTPUT);

  pinMode(store, INPUT_PULLUP);
  pinMode(add, INPUT_PULLUP);
  pinMode(memoryswitch, INPUT_PULLUP);

  sled = 0;
  register_a = 0;
  register_b = 0;
  register_c = 0;
}

void loop() {
  if (digitalRead(memoryswitch) == LOW) {
    if (sled % 3 == 0) {
      digitalWrite(led_a, HIGH);
      digitalWrite(led_b, LOW);
      digitalWrite(led_c, LOW);
      printled(register_a);
    } else if (sled % 3 == 1) {
      digitalWrite(led_b, HIGH);
      digitalWrite(led_c, LOW);
      digitalWrite(led_a, LOW);
      printled(register_b);
    } else {
      digitalWrite(led_c, HIGH);
      digitalWrite(led_a, LOW);
      digitalWrite(led_b, LOW);
      printled(register_c);
    }
    sled++;
    delay(400);
  }


  if (digitalRead(store) == LOW) {
    delay(400);

    digitalWrite(in_led, HIGH);
    digitalWrite(led_a, HIGH);
    digitalWrite(led_b, LOW);
    digitalWrite(led_c, LOW);
    while (digitalRead(store) == HIGH) {
      printled(mapint(analogRead(0), 0, 1023, -8, 7));
    }
    digitalWrite(in_led, LOW);
    register_a = mapint(analogRead(0), 0, 1023, -8, 7);
    delay(1000);

    digitalWrite(in_led, HIGH);
    digitalWrite(led_b, HIGH);
    digitalWrite(led_c, LOW);
    digitalWrite(led_a, LOW);
    while (digitalRead(store) == HIGH) {
      printled(mapint(analogRead(0), 0, 1023, -8, 7));
    }
    digitalWrite(in_led, LOW);
    register_b = mapint(analogRead(0), 0, 1023, -8, 7);
    delay(1000);
    digitalWrite(led_a, LOW);
    digitalWrite(led_b, LOW);
    digitalWrite(led_c, LOW);
    printled(0);
    sled = 0;
  }

  if (digitalRead(add) == LOW) {
    register_c = register_a + register_b;
  }

  delay(100);
}

int mapint(int x, int in_min, int in_max, int out_min, int out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void printled(int a) {
  switch (a) {
    case -8:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;

    case -7:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      break;

    case -6:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;

    case -5:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;

    case -4:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;

    case -3:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      break;

    case -2:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;

    case -1:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;

    case 0:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;

    case 1:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      break;

    case 2:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;

    case 3:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;

    case 4:
      digitalWrite(led0, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;

    case 5:
      digitalWrite(led0, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      break;

    case 6:
      digitalWrite(led0, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;

    case 7:
      digitalWrite(led0, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;

  }
}
