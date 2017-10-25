int speaker = 5;   //speaker is attached to pin 5
int button1 = 6;   //triangle pumpkin
int button2 = 9;    //round eyed pumpkin
int button3 = 10;     //square eyes, round mouth
int button4 = 11;   //square eye, jagged teeth
int button1Value;  //sets up the sensor variable for the pointer finger
int button2Value;   //sets up the sensor variable for the middle finger
int button3Value;     //sets up the sensor variable for the ring finger
int button4Value;
int led = 13;

//notes

int A = 1760;
int B = 1976;
int C = 2093;
int D = 2349;
int E = 2637;
int F = 2793;
int G = 3135;

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);  //sets up the speaker as an output
  pinMode(button1, INPUT);  
  pinMode(button2, INPUT);  
  pinMode(button3, INPUT);    
  pinMode(button4, INPUT);  
  digitalWrite(button1, HIGH); //initializes the sensor
  digitalWrite(button2, HIGH);  //initializes the sensor
  digitalWrite(button3, HIGH);    //initializes the sensor
  digitalWrite(button4, HIGH);
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
  MakeNote(A, duration);
  MakeNote(A, duration);
  MakeNote(C, duration*2);
  MakeNote(A, duration);
  MakeNote(A, duration);
  MakeNote(C, duration*2);
}

void songB(int duration)
{
  MakeNote(A, duration);
  MakeNote(C, duration);
  MakeNote(E, duration);
  MakeNote(C, duration);
  MakeNote(A, duration);
  MakeNote(C, duration);
  MakeNote(A, duration*2);
}

void songC(int duration)
{
  MakeNote(A, duration);
  MakeNote(B, duration);
  MakeNote(C, duration);
  MakeNote(D, duration);
  MakeNote(E, duration);
  MakeNote(C, duration);
  MakeNote(A, duration*2);
}

void songD(int duration)
{
  MakeNote(A, duration);
  MakeNote(A, duration);
  MakeNote(E, duration);
  MakeNote(C, duration);
  MakeNote(A, duration);
  MakeNote(C, duration);
  MakeNote(A, duration*2);
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
  button4Value = digitalRead(button4);
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
  else if (button4Value==LOW)
  {
    digitalWrite(led, HIGH);
    songD(duration);
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(speaker);
  }
}


