// this is the start of a music player
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  // playing the "Mario" theme, https://en.wikipedia.org/wiki/Super_Mario_Bros._theme
  // piano keys (by int), could also be notes[33]
  int notes[] = {56 ,          56  ,           56  ,           0 ,
                 52  ,           56  ,           59  ,           47  ,
                 52  ,           0 ,           47  ,           0 ,
                 44  ,           0 ,           49  ,           0 ,
                 51  ,           0 ,           50  ,           49  ,
                 47  ,           56  ,           59  ,           61  ,
                 57  ,           59  ,           0 ,           56  ,
                 0 ,           52  ,           54  ,           51  ,
                 0
                };
  // note duration, in 16th notes
  int duration[] = {1 , 2 , 1 , 1 ,
                    1 , 2 , 4 , 4 ,
                    2 , 1 , 1 , 2 ,
                    2 , 1 , 1 , 1 ,
                    1 , 1 , 1 , 2 ,
                    2 , 2 , 2 , 2 ,
                    1 , 1 , 1 , 1 ,
                    1 , 1 , 1 , 1 ,
                    2
                   };
  Serial.println(sizeof(duration));
  Serial.println(sizeof(duration[0]));
  Serial.println(sizeof(duration) / sizeof(duration[0]));
  int i;
  // @  120bpm, there are 2b per second or 32x16th notes per second
  // 1/32 ~= 31ms, so
  int ms_per_16th = 4*31;  // something is messed up with the tempo, sounds better at 4x slower
  for (i = 0; i < 33; i++) {
    play_note(ms_per_16th * duration[i], get_period(notes[i]), 10);
    delay(50); // things sound better when you throw a 50ms delay in between notes.
  }

  Serial.println("\n\n");
  delay(2000);
}

int play_note(int duration_ms, int tone_period_us, int out_pin) {
  unsigned int t0;
  t0 = millis();
  if (tone_period_us > 0) {
    while ((millis() - t0) < duration_ms) {
      digitalWrite(out_pin, HIGH);
      delayMicroseconds(tone_period_us / 2);
      digitalWrite(out_pin, LOW);
      delayMicroseconds(tone_period_us / 2);
    }
  }
  else {
    // this is the case that the note is a rest
    // b/c tone_period_us is negative
    digitalWrite(out_pin, LOW);
    delay(duration_ms);
  }
  return;
}



int get_period(int note) {
  int Tus;
  /* Piano keys are indexed by number, 1 to 88.
      Key 1 is the highest
      Middle C is 40
     using the convention that note 0 is a rest.
     indicated with negative period
     source: https://en.wikipedia.org/wiki/Piano_key_frequencies
  */
  if (note == 0) {
    Tus = -1;
  }
  else if (note ==  1 ) {
    Tus =   36364 ;
  }
  else if (note ==  2 ) {
    Tus =   34323 ;
  }
  else if (note ==  3 ) {
    Tus =   32396 ;
  }
  else if (note ==  4 ) {
    Tus =   30578 ;
  }
  else if (note ==  5 ) {
    Tus =   28862 ;
  }
  else if (note ==  6 ) {
    Tus =   27242 ;
  }
  else if (note ==  7 ) {
    Tus =   25713 ;
  }
  else if (note ==  8 ) {
    Tus =   24270 ;
  }
  else if (note ==  9 ) {
    Tus =   22908 ;
  }
  else if (note ==  10  ) {
    Tus =   21622 ;
  }
  else if (note ==  11  ) {
    Tus =   20408 ;
  }
  else if (note ==  12  ) {
    Tus =   19263 ;
  }
  else if (note ==  13  ) {
    Tus =   18182 ;
  }
  else if (note ==  14  ) {
    Tus =   17161 ;
  }
  else if (note ==  15  ) {
    Tus =   16198 ;
  }
  else if (note ==  16  ) {
    Tus =   15289 ;
  }
  else if (note ==  17  ) {
    Tus =   14431 ;
  }
  else if (note ==  18  ) {
    Tus =   13621 ;
  }
  else if (note ==  19  ) {
    Tus =   12856 ;
  }
  else if (note ==  20  ) {
    Tus =   12135 ;
  }
  else if (note ==  21  ) {
    Tus =   11454 ;
  }
  else if (note ==  22  ) {
    Tus =   10811 ;
  }
  else if (note ==  23  ) {
    Tus =   10204 ;
  }
  else if (note ==  24  ) {
    Tus =   9631  ;
  }
  else if (note ==  25  ) {
    Tus =   9091  ;
  }
  else if (note ==  26  ) {
    Tus =   8581  ;
  }
  else if (note ==  27  ) {
    Tus =   8099  ;
  }
  else if (note ==  28  ) {
    Tus =   7645  ;
  }
  else if (note ==  29  ) {
    Tus =   7215  ;
  }
  else if (note ==  30  ) {
    Tus =   6810  ;
  }
  else if (note ==  31  ) {
    Tus =   6428  ;
  }
  else if (note ==  32  ) {
    Tus =   6067  ;
  }
  else if (note ==  33  ) {
    Tus =   5727  ;
  }
  else if (note ==  34  ) {
    Tus =   5405  ;
  }
  else if (note ==  35  ) {
    Tus =   5102  ;
  }
  else if (note ==  36  ) {
    Tus =   4816  ;
  }
  else if (note ==  37  ) {
    Tus =   4545  ;
  }
  else if (note ==  38  ) {
    Tus =   4290  ;
  }
  else if (note ==  39  ) {
    Tus =   4050  ;
  }
  else if (note ==  40  ) {
    Tus =   3822  ;
  }
  else if (note ==  41  ) {
    Tus =   3608  ;
  }
  else if (note ==  42  ) {
    Tus =   3405  ;
  }
  else if (note ==  43  ) {
    Tus =   3214  ;
  }
  else if (note ==  44  ) {
    Tus =   3034  ;
  }
  else if (note ==  45  ) {
    Tus =   2863  ;
  }
  else if (note ==  46  ) {
    Tus =   2703  ;
  }
  else if (note ==  47  ) {
    Tus =   2551  ;
  }
  else if (note ==  48  ) {
    Tus =   2408  ;
  }
  else if (note ==  49  ) {
    Tus =   2273  ;
  }
  else if (note ==  50  ) {
    Tus =   2145  ;
  }
  else if (note ==  51  ) {
    Tus =   2025  ;
  }
  else if (note ==  52  ) {
    Tus =   1911  ;
  }
  else if (note ==  53  ) {
    Tus =   1804  ;
  }
  else if (note ==  54  ) {
    Tus =   1703  ;
  }
  else if (note ==  55  ) {
    Tus =   1607  ;
  }
  else if (note ==  56  ) {
    Tus =   1517  ;
  }
  else if (note ==  57  ) {
    Tus =   1432  ;
  }
  else if (note ==  58  ) {
    Tus =   1351  ;
  }
  else if (note ==  59  ) {
    Tus =   1276  ;
  }
  else if (note ==  60  ) {
    Tus =   1204  ;
  }
  else if (note ==  61  ) {
    Tus =   1136  ;
  }
  else if (note ==  62  ) {
    Tus =   1073  ;
  }
  else if (note ==  63  ) {
    Tus =   1012  ;
  }
  else if (note ==  64  ) {
    Tus =   956 ;
  }
  else if (note ==  65  ) {
    Tus =   902 ;
  }
  else if (note ==  66  ) {
    Tus =   851 ;
  }
  else if (note ==  67  ) {
    Tus =   804 ;
  }
  else if (note ==  68  ) {
    Tus =   758 ;
  }
  else if (note ==  69  ) {
    Tus =   716 ;
  }
  else if (note ==  70  ) {
    Tus =   676 ;
  }
  else if (note ==  71  ) {
    Tus =   638 ;
  }
  else if (note ==  72  ) {
    Tus =   602 ;
  }
  else if (note ==  73  ) {
    Tus =   568 ;
  }
  else if (note ==  74  ) {
    Tus =   536 ;
  }
  else if (note ==  75  ) {
    Tus =   506 ;
  }
  else if (note ==  76  ) {
    Tus =   478 ;
  }
  else if (note ==  77  ) {
    Tus =   451 ;
  }
  else if (note ==  78  ) {
    Tus =   426 ;
  }
  else if (note ==  79  ) {
    Tus =   402 ;
  }
  else if (note ==  80  ) {
    Tus =   379 ;
  }
  else if (note ==  81  ) {
    Tus =   358 ;
  }
  else if (note ==  82  ) {
    Tus =   338 ;
  }
  else if (note ==  83  ) {
    Tus =   319 ;
  }
  else if (note ==  84  ) {
    Tus =   301 ;
  }
  else if (note ==  85  ) {
    Tus =   284 ;
  }
  else if (note ==  86  ) {
    Tus =   268 ;
  }
  else if (note ==  87  ) {
    Tus =   253 ;
  }
  else if (note ==  88  ) {
    Tus =   239 ;
  }
  return Tus;
}
