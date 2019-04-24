#include <stdio.h>

//Times are in seconds

enum litStatus { off, lit, blinking};

const int totalTargets = 5;
int litTime = 10;
int totalTime = 180;
int changeTime = 10;
int timeUsed = 0;
int blinkTime = 1;
const bool useDeMux = false;
int lastLitTarget = -1;
bool stillLit = false;
int targetsLeft = totalTargets;

int targetHitThreshold = 50;

typedef struct {
  int blinkTime;
  int timeLimit;
  bool hit;
  int timeLeft;
  enum  litStatus lit;
  int color;
  int pin;
} target;


//To convert times to milliseconds
int multiplier = 1000; 

//Time triggering
long previousMillis = 0;
int interval = 1000;

target targets[totalTargets];
int targetsPins[totalTargets] = {3,4,5,6,7};

void initTargets(){
  for (int i=0; i<totalTargets; i++){
    targets[i].blinkTime = blinkTime*multiplier;
    targets[i].timeLimit = litTime*multiplier;
    targets[i].hit = false;
    targets[i].timeLeft = 0;
    targets[i].lit = off;
    targets[i].color = 0;
    targets[i].pin = targetsPins[i];
    pinMode(targetsPins[i], OUTPUT);
  }
}

void showStatus(){
  Serial.println("#### TARGET STATUS ###");
  char buf[12];
  for (int i = 0; i<totalTargets; i++){
      Serial.print(itoa(i, buf, 10));
  }
  Serial.println("");
  for (int i = 0; i<totalTargets; i++){
    if (targets[i].hit){
      Serial.print("H");
    }else if (targets[i].lit == lit){
      Serial.print("H");
    }else if (targets[i].lit == blinking){
      Serial.print("B");
      digitalWrite(targets[i].pin, HIGH);
    }else if (targets[i].lit == off){
      Serial.print("O");
      digitalWrite(targets[i].pin, LOW);
    }else{
      Serial.print("?");
    }
  }
  Serial.println("");
  Serial.println("");
}

void updateTargets(int timePassed){
  stillLit = false;
  int litTarget = 0;
  for (int i = 0; i<totalTargets; i++){
    if (targets[i].timeLeft > 0){
      stillLit = true;
      lastLitTarget = i;
      litTarget = i;
      Serial.print("Target ");
      char buf[12];
      Serial.print(itoa(i,buf,10));
      Serial.print(" updated");
      Serial.println("");
      targets[i].timeLeft = targets[i].timeLeft - timePassed;
    }
  }
  Serial.println("");
  Serial.println("");
  return litTarget;
}

void updateTargetsStatus(){

}

bool isMoving(int i){
  return true;
}

int checkTarget(int i){
  if(isMoving(i)){
    hitTarget(i);
  }
}

void checkTargets(){
    for (int i = 0; i<totalTargets; i++){
      checkTarget(i);
    }
}

bool roundEnded(){
  
}

void setTarget(int i){
    lastLitTarget=i;
    targets[i].hit = false;
    targets[i].timeLeft = litTime * multiplier;
    targets[i].lit = blinking;
}

void unsetTarget(int i){
    targets[i].hit = false;
    targets[i].timeLeft = 0;
    targets[i].lit = off;
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
  for (int i = 0; i<totalTargets; i++){
    if (targets[i].timeLeft > 0){
      stillLit = true;
      lastLitTarget = i;
      Serial.print("Target ");
      char buf[12];
      Serial.print(itoa(i,buf,10));
      Serial.print(" has still ");
      Serial.print(itoa(targets[i].timeLeft,buf,10));
      Serial.println(" milliseconds left");
    }
  }
  if (!stillLit){
    //All targets are either hit or off
    do{
        newTarget = random(totalTargets);
     }while((newTarget == lastLitTarget)  || (targets[newTarget].hit));
     //We check that the new target is different from the current one (unles it is the last one) and that it is not an already hit target. 
    Serial.print("New target selected: ");
    char buf[12];
    Serial.println(itoa(newTarget,buf,10));
    unsetTarget(lastLitTarget);
    setTarget(newTarget);
    
  }
  return newTarget;
}

void saveTime(){
  
}

void saveTargets(){
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  initTargets();
  setTarget(random(totalTargets));
}

int intervalAction(long timePassed){
  int result = 0;

  return result;
}
void loop() {

  unsigned long currentMillis = millis();
  char buf[12];
  if(currentMillis - previousMillis > interval) {
    long timeCount = currentMillis - previousMillis;
    previousMillis = currentMillis;
    Serial.print("Time passed: ");
    Serial.println(itoa(timeCount,buf,10));
    int newTarget = selectTarget();
    showStatus();
    updateTargets(timeCount);
  }
}
