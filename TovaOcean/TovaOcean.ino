int speaker = 5;   //speaker is attached to pin 5
int button1 = 6;   //Octi
int button2 = 9;    //rubi
int button3 = A5;     //dolphi
int button1Value;  //sets up the sensor variable for the pointer finger
int button2Value;   //sets up the sensor variable for the middle finger
int button3Value;     //sets up the sensor variable for the ring finger
int led = 13;

//notes
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
  pinMode(button1, INPUT);  
  pinMode(button2, INPUT);  
  pinMode(button3, INPUT);      
  digitalWrite(button1, HIGH); //initializes the sensor
  digitalWrite(button2, HIGH);  //initializes the sensor
  digitalWrite(button3, HIGH);    //initializes the sensor
}

void MakeNote(int NoteNumber, int duration)
{
  // "stacatto" note, on for 1/2 of duration, off for 1/2 of duration
  tone(speaker, NoteNumber);
  delay(duration/2);
  noTone(speaker);
  delay(duration/2);
}

void songA(int duration)
{
  MakeNote(C, duration);
  MakeNote(C, duration);
  MakeNote(G, duration);
  MakeNote(G, duration);
  MakeNote(A, duration);
  MakeNote(A, duration);
  MakeNote(G, duration*2);
}

void songB(int duration)
{
  MakeNote(F, duration);
  MakeNote(F, duration);
  MakeNote(E, duration);
  MakeNote(E, duration);
  MakeNote(D, duration);
  MakeNote(D, duration);
  MakeNote(C, duration*2);
}

void songC(int duration)
{
  MakeNote(G, duration);
  MakeNote(G, duration);
  MakeNote(F, duration);
  MakeNote(F, duration);
  MakeNote(E, duration);
  MakeNote(E, duration);
  MakeNote(D, duration*2);
}

void song()
{
  int duration = 500; // controls tempo of song
  songA(duration);
  songB(duration);
  songB(duration);
  songA(duration);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1Value = digitalRead(button1);  //reads information from the sensor
  button2Value = digitalRead(button2);    //reads information from the sensor
  button3Value = digitalRead(button3);        //reads information from the sensor
  int duration = 500; //controls tempo of song
  
  if (button1Value==LOW)
  {
    digitalWrite(led, HIGH);
    songA(duration);
  }
  else if (button2Value==LOW)
  {
    digitalWrite(led, HIGH);
    songB(duration);
  }
  else if (button3Value==LOW)
  {
    digitalWrite(led, HIGH);
    songC(duration);
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(speaker);
  }
}


