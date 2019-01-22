#include <stdio.h>

const int totalTargets = 5;
int litTime = 10;
int totalTime = 180;
int changeTime = 10;
int timeUsed = 0;
int blinkTime = 3;

typedef struct {
  int blinkTime;
  int timeLimit;
  bool hit;
  int timeLeft;
  bool lit;
  int color;
} target;


target targets[totalTargets];


void setup() {
  // put your setup code here, to run once:

}

void initTargets(){
  for (int i=0; i<totalTargets; i++){
    targets[i].blinkTime = blinkTime;
    targets[i].timeLimit = litTime;
    targets[i].hit = false;
    targets[i].timeLeft = 0;
    targets[i].lit = false;
    targets[i].color = 0;
  }
}

void showStatus(){
  for (int i=0; i<totalTargets; i++){
    if (targets[i].hit){
      Serial.print("Target ");
      Serial.print(itoa(i, NULL, 10));
      Serial.println(" has been hit");
    }
    if (targets[i].lit){
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10));
      Serial.println(" is on");
    }else{
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10));
      Serial.println(" is off");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
