
  
//sensor keys as labelled on the lilypad
//input pins
int key[8] = {6, 9, 10, 11, A2, A3, A4, A5};  //the pins on the lilypad
int speaker = 5;      //name of the speaker pin
int touchValue;      //will store sensor readings
// musical notes. This array holds the C scale without creating a new variable for each pitch
int pitch[8] = {587, 659, 740, 784, 880, 988, 1109, 1175};



void setup() {
  //set all keys to be inputs
  pinMode(key[0], INPUT);
  pinMode(key[1], INPUT);
  pinMode(key[2], INPUT);
  pinMode(key[3], INPUT);
  pinMode(key[4], INPUT);
  pinMode(key[5], INPUT);
  pinMode(key[6], INPUT);
  pinMode(key[7], INPUT);
  pinMode(speaker, OUTPUT);  //set speaker to be an output
  Serial.begin(9600); //initialize the communication
}

void loop() {
  checkPianoKey(0);
  checkPianoKey(1);
  checkPianoKey(2);
  checkPianoKey(3);
  checkPianoKey(4);
  checkPianoKey(5);
  checkPianoKey(6);
  checkPianoKey(7); //passes in the pitch and key together as an index
  delay(10);
}

void checkPianoKey(int index)
{
  touchValue = readCapacitivePin(key[index]);  //read the touch sensor value
  Serial.print(index);
  Serial.print(": ");
  Serial.println(touchValue); //send touchValue to the computer
  //delay(20); //delay for 2/1000 of a second (you can play faster notes)
  if (touchValue > 1)  //if the key is pressed
  {
    tone(speaker, pitch[index]);  //play the note C. The 0 refers to the first position in the array named pitch above.
    delay(100);  //wait for 1/10th of a second
  }
  else  //if the key is not pressed
  {
    noTone(speaker);  //stop playing the note
  }
}
