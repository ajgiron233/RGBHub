#ifndef WAVE_H
#define WAVE_H

#include <FastLED.h>
#include "Arduino.h"

int POT1_PIN = A0, POT2_PIN = A1;


class Wave {
  public:
    Wave(const int NUM_LEDS, CRGB* leds);
    void setup();
    void iterate();
  private:
    int _numLeds, _pot1Pin, _pot2Pin;
    uint8_t _hue;
    CRGB* _leds;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Wave::Wave(const int NUM_LEDS, CRGB* leds){
  _hue = 0;
  _numLeds = NUM_LEDS;
  _leds = leds;
}

void Wave::setup(){
  pinMode(POT1_PIN, INPUT);
  pinMode(POT2_PIN, INPUT);
}

void Wave::iterate(){
  
  for (int i = 0; i < _numLeds; ++i){
    _leds[i] = CHSV(_hue + (i * 10), map(analogRead(POT1_PIN), 0, 1023, 0, 255), 255);
  }


  _hue += map(analogRead(POT2_PIN), 0, 1023, 0, 30);
  
  //Serial.println(analogRead(POT2_PIN));
  
}


#endif