#define BUTTON 2
#define BUZZER 8

#define MAX_SCORE_SIZE 256

#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951

int melody1[] = {
  NOTE_B6, 0, NOTE_AS6, NOTE_B6, NOTE_AS6,
  NOTE_GS5, 0, NOTE_FS5, 0,
  NOTE_AS6, 0, NOTE_GS6, NOTE_A6, NOTE_GS6,
  0
};

int melody1NoteDurations[] = {
  16, 16, 24, 24, 24,
  16, 16, 16, 16,
  16, 16, 32, 32, 10,
  4
};

const int melody1Length = sizeof(melody1) / sizeof(int);
const int melody1Bpm = 130;

class Player {
private:
  int *score;
  int *noteDurations;
  int noteTimeMs[MAX_SCORE_SIZE];  // TODO: きちんとメモリ確保する
  int length;
  int nowNote = 0;
  unsigned long elapse = 0;
  unsigned long startTime;
  bool playing = false;

public:
  Player(int *score, int *noteDurations, int length, int bpm);
  void startPlay();
  void play();
};

Player::Player(int *score, int *noteDurations, int length, int bpm)
  : score(score), noteDurations(noteDurations), length(length) {
  double bps = (double)bpm / 60.0;

  for (int i = 0; i <= length; i++) {
    noteTimeMs[i] = (int)(4.0 / (bps * (double)noteDurations[i - 1]) * 1000.0);
  }
}

void Player::startPlay() {
  if (playing) return;
  nowNote = 0;
  playing = true;
  elapse = 0;
  startTime = millis();
}

void Player::play() {
  if (!playing) return;
  if (millis() - startTime > elapse) {
    score[nowNote] == 0 ? noTone(BUZZER) : tone(BUZZER, score[nowNote]);  // NOTE: tone(BUZZER, 0); だとなんかノイズが乗る
    nowNote++;
    elapse += noteTimeMs[nowNote];
  }
  if (length < nowNote) {
    noTone(BUZZER);
    playing = false;
  }
}

Player player(melody1, melody1NoteDurations, melody1Length, melody1Bpm);

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    player.startPlay();
  }
  player.play();
}
