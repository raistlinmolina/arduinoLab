int waterSensor = A0;
byte waterSensorVCC = D6;


void setup() {
  // put your setup code here, to run once:
  pinMode(waterSensor, INPUT);
  pinMode(waterSensorVCC, OUTPUT);
  digitalWrite(waterSensorVCC, LOW);
  
  delay(1000);
  Serial.begin(115200);


}


int read_humidity_sensor() {
  digitalWrite(waterSensorVCC, HIGH);
  delay(500);
  int value = analogRead(waterSensor);
  digitalWrite(waterSensorVCC, LOW);
  return value;
}


void loop() {
  Serial.print("Water height (0-1023): ");
  Serial.println(read_humidity_sensor()); 
  delay(10000);
}
