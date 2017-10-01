int soilHumSensor = A0;
byte soilHumSensorVCC = D6;


void setup() {
  // put your setup code here, to run once:
  pinMode(soilHumSensor, INPUT);
  pinMode(soilHumSensorVCC, OUTPUT);
  digitalWrite(soilHumSensorVCC, LOW);
  
  delay(1000);
  Serial.begin(115200);


}


int read_humidity_sensor() {
  digitalWrite(soilHumSensorVCC, HIGH);
  delay(500);
  int value = analogRead(soilHumSensor);
  digitalWrite(soilHumSensorVCC, LOW);
  return 1023 - value;
}


void loop() {
  Serial.print("Humidity Level (0-1023): ");
  Serial.println(read_humidity_sensor()); 
  delay(10000);
}
