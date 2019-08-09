 
void setup()
{
  Serial.begin(115200);
  pinMode(D4, INPUT); // Setting D4 B Button as input
  pinMode(D3, INPUT); // Setting D3 A Button as input
}
 
void loop()
{
  if (digitalRead(D4) == LOW)
  {
    Serial.println("B Pushed");
 
  }
 
  if (digitalRead(D3) == LOW)
  {
    Serial.println("A Pushed");
 
  }
}
