#include <stdio.h>

//Times in seconds
const int totalTargets = 5;
int litTime = 10;
int totalTime = 180;
int changeTime = 10;
int timeUsed = 0;
int blinkTime = 1;
const bool useDeMux = false;
int lastLitTarget = 0;
bool stillLit = false;
int multiplier = 1000; //To convert to milliseconds
int interval = 1000; // Interval
int targetsLeft = totalTargets;


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

int targetsPins[totalTargets] = {3,4,5,6,7};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  initTargets();
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
  Serial.println("#### TARGET STATUS ###");
  
  for (int i=0; i<totalTargets; i++){
      Serial.print(itoa(i, NULL, 10));
  }
  
  for (int i=0; i<totalTargets; i++){
    if (targets[i].hit){
      Serial.print("H");
    }else if (targets[i].lit == lit){
      Serial.print("H");
    }else if (targets[i].lit == blinking){
      Serial.print("B");
    }else if (targets[i].lit == off){
      Serial.print("O");
    }else{
      Serial.print("?");
    }
  }
}

void updateTargets(){
  
}

void updateTargetsStatus(){

}

void setTarget(int i){
    targets[i].hit = false;
    targets[i].timeLeft = changeTime * multiplier;
    targets[i].lit = blinking;
}

void hitTarget(int i){
    targets[i].hit = true;
    targets[i].timeLeft = 0;
    targets[i].lit = lit;
    targetsLeft--;
}

int selectTarget(){
  stillLit = false;
  int newTarget = lastLitTarget;
  for (int i = 0; i++; i<totalTargets){
    if (targets[i].timeLeft > 0){
      stillLit = true;
      lastLitTarget = i;
      Serial.print("Target ");
      Serial.print(itoa(i,NULL,10);
      Serial.print(" has still ");
      Serial.print(itoa(targets[i].timeLeft);
      Serial.println(" milliseconds left");
    }
  }
  if (!stillLit){
    //All targets are either hit or off
    do{
        newTarget = random(totalTargets);
     }while(((newTarget != lastTarget) || (targetsLeft == 1))  && (!target[newTarget].hit))
     //We check that the new target is different from the current one (unles it is the last one) and that it is not an already hit target. 
    Serial.print("New target selected: ");
    Serial.println(itoa(newTarget,NULL,10));
    setTarget(newTarget);
    updateTargets();
    showStatus();
  }
  return newTarget;
}




void loop() {
  // put your main code here, to run repeatedly:

}
