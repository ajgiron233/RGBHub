#ifndef SEVSEG_H
#define SEVSEG_H

#include "Arduino.h"
#include "sevSeg_numbers.hpp"

int oldPotVal, mode, wakeThreshold = 30;
long int timer;

class SevSeg {
  public:
    SevSeg(int potPin); 
    void setup(); // CALL IN SETUP
    void disp_num();
    void update_pot();
    void update();
    int get_pot(){
      return _potVal;
    }
    bool get_sleeping(){
      return _sleeping;
    }
    int get_timer(){
      return _timer;
    }  
    int get_mode(){
      return _mode;
    }
  private:
    int _potVal;
    int _potPin;
    bool _sleeping;
    unsigned int _timer;
    bool _timing;
    int _mode;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SevSeg::SevSeg(int potPin){
  _potPin = potPin;
  _potVal = 0;
  _sleeping = false;
  _timer = 0;
  _timing = false;
  int _mode= -1;
}
void SevSeg::setup(){
  pinMode(_potPin, INPUT_PULLUP);

  pinMode(SEGDISP_a, OUTPUT);
  pinMode(SEGDISP_b, OUTPUT);
  pinMode(SEGDISP_c, OUTPUT);
  pinMode(SEGDISP_d, OUTPUT);
  pinMode(SEGDISP_e, OUTPUT);
  pinMode(SEGDISP_f, OUTPUT);
  pinMode(SEGDISP_g, OUTPUT);

  print_blank();

  _potVal = analogRead(_potPin);
}

void SevSeg::update_pot(){
  _potVal = analogRead(_potPin);
}


void SevSeg::disp_num(){
  _mode = map(_potVal, 0, 1023, 1, 6);
  Serial.print(mode);
  switch (_mode){
    case 1:
      print_1();
      break;
    case 2:
      print_2();
      break;
    case 3:
      print_3();
      break;
    case 4:
      print_4();
      break;
    case 5:
      print_5();
      break;
  }
}

void SevSeg::update(){
  oldPotVal = _potVal;
  update_pot();
  if (_sleeping){ // Currently ASLEEP
    if ((oldPotVal - wakeThreshold < _potVal) ^ (oldPotVal + wakeThreshold > _potVal)){ // If there is activity, wake the screen up and display new number
      _sleeping = false;
    }
  } 
  if (!_sleeping){ // Currently AWAKE
    disp_num();
    if ((oldPotVal - wakeThreshold < _potVal) ^ (oldPotVal + wakeThreshold > _potVal)){ // If activity, reset sleep timer and display new number
      _timing = true;
      _timer = 0;
    }
    if (_timing){ //  Best timer system ever im actually a coding god 
      _timer += 1;
    }
    if (_timer >= 20){ // If sleep timer hits 5 sec, go to sleep and turn screen off
      _sleeping = true;
      _timing = false;
      print_blank();
    }
  }
  
  
}
#endif