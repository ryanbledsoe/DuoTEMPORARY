int speaker = 5;   //make sure this matches the pin of your speaker

//music notes. Arduino reads pitch as frequencies in hertz. 
//The following list of variables lets us use letter names of the 
//notes instead of the frequencies.
int C = 1046;
int D = 1175;
int E = 1319;
int F = 1397;
int G = 1568;
int A = 1760;
int B = 1976;
int C1 = 2093;

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);  //sets up the speaker as an output
}

void loop() {
  // put your main code here, to run repeatedly:
    tone(speaker, A);
    delay(1000);
    tone(speaker, B);
    delay(1000);
    tone(speaker, D);
    delay(1000);
    noTone(speaker);
    delay(1000);
  }
