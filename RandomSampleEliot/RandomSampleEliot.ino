#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
//#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

// WAV files converted to code by wav2sketch
#include "AudioSampleBeep.h"        
#include "AudioSampleEeeee.h"       
#include "AudioSampleRibbet.h"        
#include "AudioSampleStop.h"         
#include "AudioSampleTherewego.h"         

AudioPlayMemory    sound0;
AudioPlayMemory    sound1;  
AudioPlayMemory    sound2;  
AudioPlayMemory    sound3;
AudioPlayMemory    sound4;
//AudioPlayMemory    sound5;
AudioMixer4        mix1;    
AudioMixer4        mix2;    
AudioOutputAnalog  dac;     

// Create Audio connections between the components
//
AudioConnection c1(sound0, 0, mix1, 0);
AudioConnection c2(sound1, 0, mix1, 1);
AudioConnection c3(sound2, 0, mix1, 2);
AudioConnection c4(sound3, 0, mix1, 3);
AudioConnection c5(mix1, 0, mix2, 0);   // output of mix1 into 1st input on mix2
AudioConnection c6(sound4, 0, mix2, 1);
//AudioConnection c7(sound5, 0, mix2, 2);
AudioConnection c10(mix2, 0, dac, 0);

Bounce button0 = Bounce(22, 5);

boolean samplePlaying = false;

void setup() {
  pinMode(22, INPUT_PULLUP);
  AudioMemory(10);
//  audioShield.enable();
//  audioShield.volume(0.5);
  mix1.gain(0, 0.4);
  mix1.gain(1, 0.4);
  mix1.gain(2, 0.4);
  mix1.gain(3, 0.4);
  mix2.gain(1, 0.4);
  mix2.gain(2, 0.4);
}

void loop() {
  Serial.print(samplePlaying);
  button0.update();
  
  if (button0.fallingEdge() && !samplePlaying) {
    samplePlaying = true;
    int randNumber = random(0, 5);
    Serial.print(randNumber);
  
    if(randNumber == 0) {
      sound0.play(AudioSampleBeep);
    } else if(randNumber == 1) {
      sound1.play(AudioSampleEeeee);
    } else if(randNumber == 2) {
      sound2.play(AudioSampleRibbet);
    } else if(randNumber == 3) {
      sound3.play(AudioSampleStop);
    } else if(randNumber == 4) {
      sound4.play(AudioSampleTherewego);
    }
  }
  
  if(button0.risingEdge()) {
    samplePlaying = false;
  }
}


