#include "DHTesp.h"
#define DHTpin D5    //D15 of ESP32 DevKit
#define SSD1306_64_48
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP8266WiFi.h>
#include "src/Adafruit_SSD1306/Adafruit_SSD1306.h"
#include "src/ESP8266HTTPClient/ESP8266HTTPClient.h"


//https://api.thingspeak.com/update?api_key=S90DGIEVLHFVT02Y&field1=0

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define CELSIUS 0
#define FARENHEIT 1

#define SHOWALL 0
#define SHOWTEMP 1
#define SHOWHUM 2
#define SHOWSOIL 3
#define SHOWMAX 3 // The maximum value of this set
char displayTypeC[] = {'A','T','H','S'};

#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


 
DHTesp dht;
int units = CELSIUS;
int displayType = SHOWALL;

int soilHumSensor = A0;
byte soilHumSensorVCC = D6;
int dht11Sensor = DHTpin;

//Max value the sensor reads
float maxSoilValue = 1024;

//Here we will store the maximum degree of humidity the sensor reads over time.
//The idea is to show values from 0% to 100%, being 100% a soil full of water.
//For thar what we should do first is to put the probe on soil full of water so it gets the desired value.

float maxSoilHum = 0;

//Timer variables used
unsigned long currentMillis;
unsigned long lastMeasureMillis;
unsigned long lastSentMillis;

unsigned int measureDelay = dht.getMinimumSamplingPeriod();
unsigned int sendDelay = 1000*60*30; //1000ms in a sec, 60secs in a minute and we send every 30 minutes.

const char* ssid = "SSID";
const char* password = "passwd";

String get1 = "http://api.thingspeak.com/update?api_key=S90DGIEVLHFVT02Y&field1=";
String field2 = "&field2=";
String field3 = "&field3=";


void sendDataHTTP(int temperature, int hum, int soil){
  HTTPClient http;
  int temp = 0;
  char tempSign = '?';
  char str[5];
  if (units == FARENHEIT){
    temp = dht.computeHeatIndex(dht.toFahrenheit(temperature), hum, true);
    tempSign = 'F';
  }else{
    temp = dht.computeHeatIndex(temperature, hum, false);
    tempSign = 'C';
  }
  Serial.println("Sending data to thingspeak.com");
  http.begin(get1+temp+field2+hum+field3+soil);
  int httpCode = http.GET();
  String payload = http.getString();
  http.end();
}

int read_humidity_sensor() {
  digitalWrite(soilHumSensorVCC, HIGH);
  delay(500);
  float sensorValueAcc = 0;
  //We take the value 100 times to get a more stable value.
  for (int i = 0; i <= 100; i++) 
  {   
    sensorValueAcc = sensorValueAcc + analogRead(soilHumSensor); 
    delay(1); 
  } 
  float value = sensorValueAcc/100.0;
  digitalWrite(soilHumSensorVCC, LOW);
  return value;
}

void serialShowSoilHum(float valueRead, float maxRead, int valueShow){
  Serial.print(valueRead);
  Serial.print(" Abs  |");
  Serial.print(maxRead);
  Serial.print(" Max  |");
  Serial.print(valueShow);
  Serial.println("%"); 
}

void serialShowTempHum(float temperature, float humidity){
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.print(dht.toFahrenheit(temperature), 1);
  Serial.print("\t\t");
  Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
  Serial.print("\t\t");
  Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
}


void adjustSoilMaxima(float soilHum){
  if (maxSoilHum <  (maxSoilValue - soilHum) ){
    maxSoilHum = maxSoilValue - soilHum;
  }
  if (maxSoilValue <  soilHum ){
    //Security comparison to deal with over 1024 measures.
    maxSoilValue = soilHum;
  }

}

void showAll(float temperature, float humidity, float soilHumidity){
  float temp = 0;
  char tempSign = '?';
  char str[5];
  if (units == FARENHEIT){
    temp = dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true);
    tempSign = 'F';
  }else{
    temp = dht.computeHeatIndex(temperature, humidity, false);
    tempSign = 'C';
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Tmp: ");
  display.print(dtostrf(temp, 4, 1, str ));
  display.println(tempSign);
  display.println();
  display.print("Hum: ");
  display.print(dtostrf(humidity, 4, 1, str ));
  display.println("%");
  display.println();
  display.print("Soil:");
  display.print(dtostrf(soilHumidity, 4, 1, str ));
  display.println("%");
  display.display();
}

void showTemp(float temperature, float humidity){
  float temp = 0;
  char tempSign = '?';
  char str[5];
  if (units == FARENHEIT){
    temp = dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true);
    tempSign = 'F';
  }else{
    temp = dht.computeHeatIndex(temperature, humidity, false);
    tempSign = 'C';
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temp:");
  display.setTextSize(2);
  display.setCursor(0,25);
  display.print(dtostrf(temp, 4, 1, str ));
  display.println(tempSign);
  display.display();
}

void showHum(float humidity){
  char str[5];

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Hum:");
  display.setTextSize(2);
  display.setCursor(0,25);
  display.print(dtostrf(humidity, 4, 1, str ));
  display.println("%");
  display.display();
}

void showSoil(float soilHumidity){
  char str[5];

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Soil:");
  display.setTextSize(2);
  display.setCursor(0,25);
  display.print(dtostrf(soilHumidity, 4, 1, str ));
  display.println("%");
  display.display();
}

void showDataDisplay(float temperature, float humidity, float soilHumidity){
  switch (displayType) {
    case SHOWALL:
      showAll(temperature, humidity, soilHumidity);
      break;
    case SHOWTEMP:
      showTemp(temperature, humidity);
      break;
    case SHOWHUM:
      showHum(humidity);
      break;
    case SHOWSOIL:
      showSoil(soilHumidity);
      break;
    default:
      showAll(temperature, humidity, soilHumidity);
      break;  
  }
}

int checkButtons(){
  int result = 0;
  // 0 none, 1 A, 2 B, 3 Both
  if (digitalRead(D3) == LOW){
    result = result + 1;
    Serial.println("A pressed");
  }
  if (digitalRead(D4) == LOW){
    result = result + 2;
    Serial.println("B pressed");
  }
  return result;
}

void changeUnits(int value){
  if (value == 1 || value == 3){
    if (units == CELSIUS){
      units = FARENHEIT;
      Serial.println("Temp set to Farenheit");
      displayChangeEvent('F');
    }else{
      units = CELSIUS;
      Serial.println("Temp set to Celsius");
      displayChangeEvent('C');
    }
  }
}

void changeDisplay(int value){
  if (value == 2 || value == 3){
    displayType++;
    if (displayType > SHOWMAX) displayType = SHOWALL;
    Serial.print("Display Type Changed to ");
    Serial.println(displayType);
    displayChangeEvent(displayTypeC[displayType]);
  }
}

void displayChangeEvent(char char2Show){
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,10);
  display.println(char2Show);
  display.display();
  delay(500);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(soilHumSensor, INPUT);
  pinMode(soilHumSensorVCC, OUTPUT);
  digitalWrite(soilHumSensorVCC, LOW);
  
  dht.setup(DHTpin, DHTesp::DHT11);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  
  delay(1000);
  // Clear the buffer.
  display.clearDisplay();

  
  Serial.begin(115200);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("OK!");
  display.setCursor(0,30);
  display.println("Moli.");
  
  display.display();
  currentMillis = millis();
  lastMeasureMillis = currentMillis;
  lastSentMillis = currentMillis - sendDelay + 30000; //We wait 30 secs to send data so the sensor gets some stable measure
  int count=0;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
    count ++;
    if (count > 15) break;
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
  }else{
     Serial.println("Could not connect!!!");
  }
}

void loop() {
  currentMillis = millis();
  if ((currentMillis - lastMeasureMillis) >= measureDelay){
    lastMeasureMillis = currentMillis;
    float soilHum = read_humidity_sensor();
    adjustSoilMaxima(soilHum);
    int valueToShow = ((maxSoilValue - soilHum) / maxSoilHum)*100;
    serialShowSoilHum(soilHum, maxSoilHum, valueToShow);
  
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();
    serialShowTempHum(temperature, humidity);
    showDataDisplay(temperature, humidity, valueToShow);
    if ((currentMillis - lastSentMillis) >= sendDelay){
      lastSentMillis = currentMillis;
      sendDataHTTP(temperature, humidity, valueToShow);
    }
  }
  int buttons = checkButtons();
  changeUnits(buttons);
  changeDisplay(buttons);
}
