#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
 
int RECV_PIN = D4; //an IR detector connected to D4
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}
 
void loop() {
  if (irrecv.decode(&results)) {
    serialPrintUint64(results.value, HEX);
    Serial.println("---");
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}


