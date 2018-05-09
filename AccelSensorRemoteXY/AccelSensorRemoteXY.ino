/*
   -- AccelApp --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.3.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.1.1 or later version;
     - for iOS 1.2.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "Valhalla"
#define REMOTEXY_WIFI_PASSWORD "JoSeMaNuElMoLiNa"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,23,0,102,0,150,0,8,24,0,
  66,130,75,6,22,17,2,26,1,0,
  6,4,12,12,2,31,83,116,97,114,
  116,0,7,36,21,15,50,6,2,26,
  2,21,130,1,5,33,69,26,32,66,
  130,8,43,13,10,2,26,66,130,24,
  43,14,11,2,26,66,130,40,43,15,
  12,2,26,66,130,56,43,17,13,2,
  26,67,5,12,52,5,3,2,32,11,
  67,5,28,53,6,3,2,32,11,67,
  5,44,54,7,3,2,32,11,67,5,
  61,55,7,3,2,32,11,67,5,81,
  14,10,5,2,24,11,67,5,9,35,
  62,5,2,32,21,67,4,21,8,44,
  6,2,24,21,1,0,6,18,12,12,
  2,31,83,97,118,101,0 }; 
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  uint8_t StartButton; // =1 if button pressed, else =0 
  char playerNameField[21];  // string UTF8 end zero  
  uint8_t button_1; // =1 if button pressed, else =0 

    // output variable
  int8_t currentShotLevel; // =0..100 level position 
  int8_t shot4Level; // =0..100 level position 
  int8_t shot3Level; // =0..100 level position 
  int8_t shot2Level; // =0..100 level position 
  int8_t shot1Level; // =0..100 level position 
  char shot4Text[11];  // string UTF8 end zero 
  char shot3Text[11];  // string UTF8 end zero 
  char shot2Text[11];  // string UTF8 end zero 
  char shot1Text[11];  // string UTF8 end zero 
  char currentShotText[11];  // string UTF8 end zero 
  char lastShotsText[21];  // string UTF8 end zero 
  char playerNameText[21];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_STARTBUTTON 13


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_STARTBUTTON, OUTPUT);
  RemoteXY.shot4Level = 99;
  RemoteXY.shot3Level = 75;
  RemoteXY.shot2Level = 50;
  RemoteXY.shot1Level = 25;
  strcpy(RemoteXY.playerNameText, "Jugador");
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_STARTBUTTON, (RemoteXY.StartButton==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer


}
