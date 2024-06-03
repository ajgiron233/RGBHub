/* 
[--------------RGB Hub MAIN----------------]
[           Author:  AJ Giron              ]
[         Last updated:  6/1/2023         ]
[------------------------------------------]
*/

#include <FastLED.h>
#include "sevSeg.hpp"
#include "wave.hpp"
#include "sort.hpp"

#define NUM_LEDS 150
#define LED_PIN 2
#define POT1_PIN A1
#define POT2_PIN A0

CRGB leds[NUM_LEDS];
SevSeg SevenSeg(A2);
Wave wave(150, leds);

int h, b, newh, newb, buffer = 10;
bool switched = false;
/*
// Sorting setup
int selRGBRead, currPos = 0;
bool doneSorting = false;
int startArr[NUM_LEDS];
int* pLEDArr = startArr;
*/

//  [~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DEBUG INFO AND PRINTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]
struct {
  bool sevenSegDebug = true;
} debugList;

void debug_prints(){
  if (debugList.sevenSegDebug){
    Serial.print("PotVal: ");  Serial.print(SevenSeg.get_pot()); Serial.print(", PotVal2: ");  Serial.print(analogRead(POT1_PIN)); Serial.print(", PotVal3: ");  Serial.print(analogRead(POT2_PIN)); Serial.print(" | Sleeping: ");  Serial.print(SevenSeg.get_sleeping()); Serial.print("  | Timer: ");  Serial.print(SevenSeg.get_timer());Serial.print("  | Mode: ");  Serial.println(SevenSeg.get_mode());
  }
}


//  [~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SETUP AND LOOP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]
void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  Serial.begin(9600);
  SevenSeg.setup();
  wave.setup();

}

void loop() {
  
  SevenSeg.update();

  switch (SevenSeg.get_mode()){
    case 1:
      wave.iterate();
      break;
    case 2:
    /*
      EVERY_N_MILLISECONDS(map(analogRead(POT1_PIN), 0, 1023, 10, 2000)){
        if (doneSorting){
          Serial.println("------------FINISHED SORT--------------");
          pLEDArr = arr_randomize(NUM_LEDS);
          currPos = 0;
          doneSorting = false;
        } else {
          pLEDArr = arr_sorter_step(pLEDArr, NUM_LEDS, currPos, doneSorting, leds); 
        }
      }
      */
      newh = map(analogRead(POT1_PIN), 0, 1023, 0, 255);
      newb = map(analogRead(POT2_PIN), 0, 1023, 0, 255);
      if (newh > h+buffer || newh < h-buffer || newb > b+buffer || newb < b-buffer){
        h = newh;
        b = newb;
        for (int i = 0; i < NUM_LEDS; i++){
          leds[i] = CHSV(h, 255, b);
        }
      }
      break;
    case 3:
      
      break;
    case 4:
      
      break;
    case 5:
      
      break;
  }
  

  debug_prints();

  FastLED.show();

  delay(5);
}
