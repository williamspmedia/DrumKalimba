//1. (Hard Code) Map each midi note to two servo coordinates
//2. Calculate the delay time between notes and solenoid pressdown time
//3. Fire piston once both delays are finished
//4. Get ready for next note

//MIDI Servo
#include <Servo.h>
#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

//MIDI Code
//struct MySettings : public midi::DefaultSettings {
//  static const long BaudRate = 128000;
//};
//enum NoteStatus : bool {
//  NOT_PLAYING = 0,
//  PLAYING
//};
//MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings)

//Solenoid Code
int solenoid[3] = {7, 6, 5};
bool shakeState = false;
int pressTime = 300; //ms


//Timing Code
//Adjust for my inconsistent trash robot
float timeScale = 1;

void setup() {

  //Attach Solenoid
  pinMode(5, OUTPUT); //Shaker
  pinMode(6, OUTPUT); //Snare
  pinMode(7, OUTPUT); //Kick

  digitalWrite(solenoid[0], LOW); //Snare
  digitalWrite(solenoid[1], LOW); //Kick
  digitalWrite(solenoid[2], LOW); //Shaker

  //Set timescale
  timeScale = 0.997; //174bpm

  //Countin
  FirePiston(400, 1, 0, 0);
  FirePiston(400, 1, 0, 0);
  FirePiston(400, 1, 0, 0);
  FirePiston(400, 1, 0, 0);
//  FirePiston(400, 0, 1, 0);
//  FirePiston(400, 0, 1, 0);
//  FirePiston(400, 0, 1, 0);
//  FirePiston(400, 0, 1, 0);

}

void loop()
{

  //DrumBeat1();
  DrumBeat2();
//  FirePiston(1000, 1, 0, 0);
//  FirePiston(1000, 0, 1, 0);
//  FirePiston(1000, 0, 0, 1);

  //PlayTheSong();
  //PrepPistons(3000,true,false,false);
  //PrepPistons(3000,false,true,false);
  //PrepPistons(3000, false, false, true);
}
//KICK AND SNARE ARE BACKWARDS. FIX BEFORE EVER USING AGAIN
void DrumBeat1(){
  FirePiston(400, 1, 0, 0);
  FirePiston(200, 0, 1, 1);
  FirePiston(200, 0, 0, 1);
  FirePiston(200, 0, 0, 1);
  FirePiston(200, 1, 0, 1);
  FirePiston(400, 0, 1, 0);
  FirePiston(200, 1, 0, 1);
  FirePiston(200, 0, 0, 1);
  FirePiston(200, 0, 1, 1);
  FirePiston(400, 0, 0, 1);
  FirePiston(200, 1, 0, 0);
  FirePiston(400, 0, 1, 0);
}

void DrumBeat2(){
  FirePiston(400, 1, 0, 0);
  FirePiston(200, 0, 1, 0);
  FirePiston(200, 0, 0, 0);
  FirePiston(200, 0, 0, 0);
  FirePiston(200, 1, 0, 0);
  FirePiston(400, 0, 1, 0);
  FirePiston(200, 1, 0, 0);
  FirePiston(200, 0, 0, 0);
  FirePiston(200, 0, 1, 0);
  FirePiston(400, 0, 0, 0);
  FirePiston(200, 1, 0, 0);
  FirePiston(400, 0, 1, 0);
}

void FirePiston(int pause, int x, int y, int z) {

  if (x == 1) {
    digitalWrite(7, HIGH); //Kick
  }
  if (y == 1) {
    digitalWrite(6, HIGH); //Snare
  }
  if (z == 1) {
    if (shakeState == true) {
      digitalWrite(5, HIGH); //Shake
      shakeState = false;
    }
    else {
      digitalWrite(5, LOW); //Shake
      shakeState = true;
    }
  }

  delay(30); //in ms

  if (x == 1) {
    digitalWrite(7, LOW); //Kick
  }
  if (y == 1) {
    digitalWrite(6, LOW); //Snare
  }

  delay((pause*timeScale) - 30);

}

void PlayTheSong() {

  //  GoTo(63, 1000, -1);
  //
  //  GoTo(63, 200, -1); GoTo(63, 200, 0); //Count in
  //  GoTo(63, 200, -1); GoTo(63, 200, 0);
  //  GoTo(63, 200, -1); GoTo(63, 200, 0);
  //  GoTo(63, 200, -1); GoTo(63, 200, 0);
  //  GoTo(63, 200, -1); GoTo(63, 200, 0); //Count in
  //  GoTo(63, 200, -1); GoTo(63, 200, 0);
  //  GoTo(63, 200, -1); GoTo(63, 200, 0);
  //  GoTo(63, 200, -1); GoTo(63, 200, 0);

}
