int led = A4;
int speaker = 5;
int aluminumFoil = A5;
int sensorValue;

int C = 1046;
int D = 1175;
int E = 1319;
int F = 1397;
int G = 1568;
int A = 1760;
int B = 1976;
int C1 = 2093;

void setup() {

  pinMode(led, OUTPUT);  //The LED is an output because it does something in the world.
  pinMode(speaker, OUTPUT);
  pinMode(aluminumFoil, INPUT);
  digitalWrite(aluminumFoil, HIGH);  //initializes the sensor
  Serial.begin(9600);    //initialize serial port. 9600 is the Arduino stardard communication speed. Tells lilypad to talk to computer at the speed of 9600 bits per second.
}

void loop() {
  sensorValue = digitalRead(aluminumFoil);
  Serial.println(sensorValue);  //send sensorValue to computer
  delay(100);  //delay 1/10 of a second. This keeps the computer from crashing when you use println.
  if (sensorValue == LOW)
  {
    blinkPattern();
  }
   else
   {
    song();
  }
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
  MakeNote(F, duration);
  MakeNote(F, duration);
  MakeNote(E, duration);
  MakeNote(E, duration);
  MakeNote(D, duration);
  MakeNote(D, duration);
  MakeNote(C, duration*2);
}

void songB(int duration)
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

void blinkPattern()
{
  digitalWrite(led, HIGH);   
  delay(1000);              
  digitalWrite(led, LOW);   
  delay(1000);            
  digitalWrite(led, HIGH);  
  delay(100);             
  digitalWrite(led, LOW);    
  delay(25);    
}  
