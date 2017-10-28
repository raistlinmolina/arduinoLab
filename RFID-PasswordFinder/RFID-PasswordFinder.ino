/*
 * Copy the RFID card data into variables and then 
 * scan the second empty card to copy all the date
 * ----------------------------------------------------------------------------
 * Example sketch/program which will try the most used default keys listed in 
 * https://code.google.com/p/mfcuk/wiki/MifareClassicDefaultKeys to dump the
 * block 0 of a MIFARE RFID card using a RFID-RC522 reader.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Wemos      Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      D1 R2      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D4         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D8         D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D7         D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D6         D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D5         D13        ICSP-3           15
 * 
 *
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         5           // Configurable, see typical pin layout above
#define SS_PIN          53          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

byte buffer[18];
byte block;
byte waarde[64][16];
MFRC522::StatusCode status;
    
MFRC522::MIFARE_Key key;

// Number of known default keys (hard-coded)
// NOTE: Synchronize the NR_KNOWN_KEYS define with the defaultKeys[] array
#define NR_KNOWN_KEYS   9
// Known keys, see: https://code.google.com/p/mfcuk/wiki/MifareClassicDefaultKeys
byte knownKeys[NR_KNOWN_KEYS][MFRC522::MF_KEY_SIZE] =  {
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, // FF FF FF FF FF FF = factory default
    {0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5}, // A0 A1 A2 A3 A4 A5
    {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5}, // B0 B1 B2 B3 B4 B5
    {0x4d, 0x3a, 0x99, 0xc3, 0x51, 0xdd}, // 4D 3A 99 C3 51 DD
    {0x1a, 0x98, 0x2c, 0x7e, 0x45, 0x9a}, // 1A 98 2C 7E 45 9A
    {0xd3, 0xf7, 0xd3, 0xf7, 0xd3, 0xf7}, // D3 F7 D3 F7 D3 F7
    {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff}, // AA BB CC DD EE FF
    {0x00, 0x00, 0x00, 0x00, 0x00, 0xff}, // 00 00 00 00 00 01
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // 00 00 00 00 00 00
};

unsigned long long byteArray2ULong(byte* d){
  return byteArray2ULong(d, MFRC522::MF_KEY_SIZE);
}

unsigned long long byteArray2ULong(byte* d, int keySize){
  unsigned long long adc_value = 0;
  int multiplier = 8 * (keySize);
  int index = 0;
  while (multiplier > 0){
    multiplier -= 8;
    adc_value  +=  (unsigned long long)d[index] << multiplier;
    index++;
  }
  return adc_value;
}

void addToKey(byte* d, byte toAdd){
  addToKey(d, toAdd, MFRC522::MF_KEY_SIZE);
}


 
void addToKey(byte* d, byte toAdd, int keySize){
  
  bool add = true;
  int index = keySize-1;
  byte temp = 0;
  byte carry = toAdd;
  while (add && index>=0){
    temp = d[index];
    d[index] += carry;
    if ( temp > d[index]){
      carry = 0x01;
    }else{
      add = false;
    }
    index--;
  }
}


char choice;
/*
 * Initialize.
 */
void setup() {
    Serial.begin(9600);         // Initialize serial communications with the PC
    while (!Serial);            // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();                // Init SPI bus
    mfrc522.PCD_Init();         // Init MFRC522 card
    Serial.println(F("Try the most used default keys to print block 0 to 63 of a MIFARE PICC."));
    Serial.println("1.Read card \n2.Write to card \n3.Copy the data.");

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }
}



 //Via seriele monitor de bytes uitlezen in hexadecimaal
 
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
//Via seriele monitor de bytes uitlezen in ASCI

void dump_byte_array1(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.write(buffer[i]);
  }
}

/*
 * Try using the PICC (the tag/card) with the given key to access block 0 to 63.
 * On success, it will show the key details, and dump the block data on Serial.
 *
 * @return true when the given key worked, false otherwise.
 */
 
boolean try_key(MFRC522::MIFARE_Key *key)
{
    boolean result = false;
    
    for(byte block = 0; block < 64; block++){
      
    // Serial.println(F("Authenticating using key A..."));
    dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }

    // Read block
    byte byteCount = sizeof(buffer);
    status = mfrc522.MIFARE_Read(block, buffer, &byteCount);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
    }
    else {
        // Successful read
        result = true;
        Serial.print(F("Success with key:"));
        dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
        Serial.println();
        
        // Dump block data
        Serial.print(F("Block ")); Serial.print(block); Serial.print(F(":"));
        dump_byte_array1(buffer, 16); //omzetten van hex naar ASCI
        Serial.println();
        
        for (int p = 0; p < 16; p++) //De 16 bits uit de block uitlezen
        {
          waarde [block][p] = buffer[p];
          Serial.print(waarde[block][p]);
          Serial.print(" ");
        }
        
        }
    }
    Serial.println();
    
    Serial.println("1.Read card \n2.Write to card \n3.Copy the data.");

    mfrc522.PICC_HaltA();       // Halt PICC
    mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
    return result;
    
    start();
}

void readCard(){ //Read card
  Serial.println("Insert card...");
  // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)
    Serial.print(F("Card UID:"));
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();
    Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
    
    // Try the known default keys
    MFRC522::MIFARE_Key key;
    bool exito = false;
    while (!exito){
    //for (byte k = 0; k < NR_KNOWN_KEYS; k++) {
        // Copy the known key into the MIFARE_Key structure
        for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
            key.keyByte[i] = knownKeys[8][i];
        }
        // Try the key
        if (try_key(&key)) {
            // Found and reported on the key and block,
            // no need to try other keys for this PICC
            exito = true;
            //break;
        }
        addToKey(knownKeys[8],0x01);
    }
}

void printLongLong(unsigned long long toPrint){
    unsigned long highPart= toPrint / 100000;
    //TODO: fill lowPart with 0s to the left cause if not you lose one decimal position when printing.
    unsigned long lowPart = toPrint % 100000;
    Serial.print(highPart);
    //Serial.print(" ");
    if (lowPart <10000) Serial.print("0");
    Serial.println(lowPart);
}


void start(){
  choice = Serial.read();
  
  if(choice == '1')
  {
    Serial.println("Read the card");
    readCard();
  }
//  byte[] keyToTest = byteArray2ULong(knownKeys[8]);
//  for (byte k = 0; k < NR_KNOWN_KEYS; k++) {
//    unsigned long long valueKey = byteArray2ULong(knownKeys[k]);
//    printLongLong(valueKey);
//    
//    addToKey(knownKeys[k],0x01);
//    valueKey = byteArray2ULong(knownKeys[k]);
//    printLongLong(valueKey);
//    Serial.println("");
//  }
}
/*
 * Main loop.
 */
void loop() {
  start();
}






