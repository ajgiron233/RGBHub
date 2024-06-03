

#include "Arduino.h"

#define SEGDISP_a 4 //
#define SEGDISP_b 3 //
#define SEGDISP_c 9 //
#define SEGDISP_d 10 //
#define SEGDISP_e 6 //
#define SEGDISP_f 5 //
#define SEGDISP_g 8


void print_blank(){
  digitalWrite(SEGDISP_a, LOW);
  digitalWrite(SEGDISP_b, LOW);
  digitalWrite(SEGDISP_c, LOW);
  digitalWrite(SEGDISP_d, LOW);
  digitalWrite(SEGDISP_e, LOW);
  digitalWrite(SEGDISP_f, LOW);
  digitalWrite(SEGDISP_g, LOW);
}

void print_0(){
  digitalWrite(SEGDISP_a, HIGH);
  digitalWrite(SEGDISP_b, HIGH);
  digitalWrite(SEGDISP_c, HIGH);
  digitalWrite(SEGDISP_d, HIGH);
  digitalWrite(SEGDISP_e, HIGH);
  digitalWrite(SEGDISP_f, HIGH);
  digitalWrite(SEGDISP_g, LOW);
}

void print_1(){
  digitalWrite(SEGDISP_a, LOW);
  digitalWrite(SEGDISP_b, HIGH);
  digitalWrite(SEGDISP_c, HIGH);
  digitalWrite(SEGDISP_d, LOW);
  digitalWrite(SEGDISP_e, LOW);
  digitalWrite(SEGDISP_f, LOW);
  digitalWrite(SEGDISP_g, LOW);
}

void print_2(){
  digitalWrite(SEGDISP_a, HIGH);
  digitalWrite(SEGDISP_b, HIGH);
  digitalWrite(SEGDISP_c, LOW);
  digitalWrite(SEGDISP_d, HIGH);
  digitalWrite(SEGDISP_e, HIGH);
  digitalWrite(SEGDISP_f, LOW);
  digitalWrite(SEGDISP_g, HIGH);
}

void print_3(){
  digitalWrite(SEGDISP_a, HIGH);
  digitalWrite(SEGDISP_b, HIGH);
  digitalWrite(SEGDISP_c, HIGH);
  digitalWrite(SEGDISP_d, HIGH);
  digitalWrite(SEGDISP_e, LOW);
  digitalWrite(SEGDISP_f, LOW);
  digitalWrite(SEGDISP_g, HIGH);
}

void print_4(){
  digitalWrite(SEGDISP_a, LOW);
  digitalWrite(SEGDISP_b, HIGH);
  digitalWrite(SEGDISP_c, HIGH);
  digitalWrite(SEGDISP_d, LOW);
  digitalWrite(SEGDISP_e, LOW);
  digitalWrite(SEGDISP_f, HIGH);
  digitalWrite(SEGDISP_g, HIGH);
}

void print_5(){
  digitalWrite(SEGDISP_a, HIGH);
  digitalWrite(SEGDISP_b, LOW);
  digitalWrite(SEGDISP_c, HIGH);
  digitalWrite(SEGDISP_d, HIGH);
  digitalWrite(SEGDISP_e, LOW);
  digitalWrite(SEGDISP_f, HIGH);
  digitalWrite(SEGDISP_g, HIGH);
}