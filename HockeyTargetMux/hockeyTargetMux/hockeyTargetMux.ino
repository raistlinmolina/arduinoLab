#include <stdio.h>

/*
 * Already hit and service pins:
 * D3,D4,D5,D6
 * Blinking target pins
 * D0,D1,D2
 * Tilt sensor pin
 * D7
 * 
*/

//Times are in seconds

enum class litStatus { off, lit, blinking};

//Number of targets
const int totalTargets = 5;
//
int litTime = 10;
//Total time of the round in seconds
int totalTime = 180;
//Change time after "changeTime" seconds
int changeTime = 10;
//Time used so far
int timeUsed = 0;
//Blink interval
int blinkTime = 1;
//Using de/multiplexors
const bool useDeMux = false;
//Last target that was lit
int lastLitTarget = -1;
//Is still lit?
bool stillLit = false;
//Targets left unhit
int targetsLeft = totalTargets;

//LED that indicates target was hit
int tiltLedPin = 12;

//Tilt sensor pin
int tiltPin = 2;
int tiltStatus = LOW;

//Sensisitivity sensor threshold
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
int targetsPins[totalTargets] = {6,7,8,9,10};

int getBit(int value, int pos){
  return (value & ( 1 << pos )) >> pos
}

void decode(int value, int pins[], int size){
   for (int i=0, i<size, i++){
    pins [i] = getBit(value, i);
   }
}
 
void initTargets(){
  for (int i=0; i<totalTargets; i++){
    targets[i].blinkTime = blinkTime*multiplier;
    targets[i].timeLimit = litTime*multiplier;
    targets[i].hit = false;
    targets[i].timeLeft = 0;
    targets[i].lit = litStatus::off;
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
    }else if (targets[i].lit == litStatus::lit){
      Serial.print("H");
    }else if (targets[i].lit == litStatus::blinking){
      Serial.print("B");
      digitalWrite(targets[i].pin, HIGH);
    }else if (targets[i].lit == litStatus::off){
      Serial.print("O");
      digitalWrite(targets[i].pin, LOW);
    }else{
      Serial.print("?");
    }
  }
  Serial.println("");
  Serial.println("");
}

int updateTargets(int timePassed){
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
    targets[i].lit = litStatus::blinking;
}

void unsetTarget(int i){
    targets[i].hit = false;
    targets[i].timeLeft = 0;
    targets[i].lit = litStatus::off;
}

void hitTarget(int i){
    targets[i].hit = true;
    targets[i].timeLeft = 0;
    targets[i].lit = litStatus::lit;
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

void targetHit(){
  Serial.println("###################################################");
  Serial.println("Target has been hit");
  Serial.println("###################################################");
  digitalWrite(tiltLedPin, HIGH);
  delay(1000);
  digitalWrite(tiltLedPin, LOW);
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  initTargets();
  attachInterrupt(digitalPinToInterrupt(tiltPin), targetHit, CHANGE);
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


}
