#include <stdio.h>

const int totalTargets = 5;
int litTime = 10;
int totalTime = 180;
int changeTime = 10;
int timeUsed = 0;
int blinkTime = 3;

enum litStatus { off, lit, blinking};

typedef struct {
  int blinkTime;
  int timeLimit;
  bool hit;
  int timeLeft;
  enum  litStatus lit;
  int color;
  int pin;
} target;




target targets[totalTargets];

int targetsPins[totalTargets] = {0,0,0,0,0};


void setup() {
  // put your setup code here, to run once:

}

void initTargets(){
  for (int i=0; i<totalTargets; i++){
    targets[i].blinkTime = blinkTime;
    targets[i].timeLimit = litTime;
    targets[i].hit = false;
    targets[i].timeLeft = 0;
    targets[i].lit = off;
    targets[i].color = 0;
    targets[i].pin = targetsPins[i];
  }
}

void showStatus(){
  for (int i=0; i<totalTargets; i++){
    if (targets[i].hit){
      Serial.print("Target ");
      Serial.print(itoa(i, NULL, 10));
      Serial.println(" has been hit");
    }
    if (targets[i].lit == lit){
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10));
      Serial.println(" is on");
    }else if (targets[i].lit == off){
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10));
      Serial.println(" is off");
    }else if (targets[i].lit == blinking){
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10));
      Serial.println(" is off");
    }else{
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10));
      Serial.println(" has an invalid status.");
    }
  }
}

void updateTargets(){
  
}

void updateTargetsStatus(){

}


void loop() {
  // put your main code here, to run repeatedly:

}
