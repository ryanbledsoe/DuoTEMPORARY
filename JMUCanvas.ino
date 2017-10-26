int led = A4;
int speaker = 5;
int aluminumFoil = A5;
int sensorValue;
int buttonPin1 = 5;

//notes
int C = 1046;
int D = 1175;
int E = 1319;
int Eb = 1245;
int F = 1397;
int F0 = 698;
//int F = 1480;
int G = 1568;
int A = 1760;
int Ab = 1661;
int B = 1976;
int Bb = 1865;
int Bb0 = 932;
int C1 = 2093;

void setup() {

  pinMode(led, OUTPUT);  //The LED is an output because it does something in the world.
  pinMode(speaker, OUTPUT);
  pinMode(aluminumFoil, INPUT);
  digitalWrite(aluminumFoil, HIGH);  //initializes the sensor
  Serial.begin(9600);    //initialize serial port. 9600 is the Arduino stardard communication speed. Tells lilypad to talk to computer at the speed of 9600 bits per second.
  pinMode(buttonPin1, INPUT_PULLUP);
}

void loop() {
  sensorValue = analogRead(aluminumFoil);
  Serial.println(sensorValue);  //send sensorValue to computer
  delay(100);  //delay 1/10 of a second. This keeps the computer from crashing when you use println.
  if (sensorValue>1000)
  {
    blinkPattern();
  }
  else
  {
    song(); 
  }
}

void blinkPattern()
{
  digitalWrite(led, HIGH);   
  delay(1000);              
  digitalWrite(led, LOW);   
  delay(100);            
//  digitalWrite(led, HIGH);  
//  delay(100);             
//  digitalWrite(led, LOW);    
//  delay(25);    
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
  MakeNote(Bb0, duration*2);
  MakeNote(C, duration);
  MakeNote(D, duration*3);
  MakeNote(Bb0, duration*2);
  MakeNote(Eb, duration*2);
  MakeNote(D, duration);
  MakeNote(Bb0, duration*5);
  MakeNote(Eb, duration);
  MakeNote(Eb, duration*2);
  MakeNote(D, duration);
  MakeNote(Bb0, duration*1.5);
  MakeNote(F0, duration/2);
  MakeNote(Bb0, duration);
  MakeNote(C, duration);
  MakeNote(D, duration*8);
  

}

void song()
{
  int duration = 200; // Change the number here to make the song faster or slower.
  song(duration);
}

 
