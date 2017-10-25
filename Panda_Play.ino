// Play with the code in this sketch! Go to line 44 to change the notes that are played. Go to line 500 to play with the tempo/speed.  

int speaker = 5;   //speaker is attached to pin 5
int aluminumFoil = 6;   //aluminum foil is attached to pin 6
int sensorValue;   

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
  pinMode(aluminumFoil, INPUT);   //sets up the pointer finger as an input
  digitalWrite(aluminumFoil, HIGH);  //initializes the sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = digitalRead(aluminumFoil);  //reads information from the sensor
  if (sensorValue==LOW)
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

void MakeRest(int duration)
{
  noTone(speaker);
  delay(duration);
}

void song(int duration)
{
  MakeNote(E, duration); //Change the letter to change the note that plays.
  MakeNote(D, duration);
  MakeNote(C, duration); //Change the letter to change the note that plays.
  MakeNote(F, duration);
  //noTone(duration);
  MakeRest(duration);
  MakeNote(G, duration);
  MakeNote(C, duration);
}

void song()
{
  int duration = 350; // Change the number here to make the song faster or slower.
  song(duration);

}
  
