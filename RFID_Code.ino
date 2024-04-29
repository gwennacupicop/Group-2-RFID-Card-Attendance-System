#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte card_ID[4];
byte Name0[4] = {0xC3, 0x3D, 0x4C, 0x1C}; // Nacorda, Jeo Rodel
byte Name1[4] = {0x73, 0xB9, 0x17, 0x13}; // Group 2
byte Name2[4] = {0x00, 0x00, 0x00, 0x01}; // Acupicop, Gwenn Remielle
byte Name3[4] = {0x00, 0x00, 0x00, 0x02}; // Amizola, Christian
byte Name4[4] = {0x00, 0x00, 0x00, 0x03}; // Ayag, Khirk Johann
byte Name5[4] = {0x00, 0x00, 0x00, 0x04}; // Bag-ao, Christian Rey
byte Name6[4] = {0x00, 0x00, 0x00, 0x05}; // Banquel, John Dave
byte Name7[4] = {0x00, 0x00, 0x00, 0x06}; // Canon, Ayesha Nicole
byte Name8[4] = {0x00, 0x00, 0x00, 0x07}; // Cunanan, Jolo
byte Name9[4] = {0x00, 0x00, 0x00, 0x08}; // Felisilda, Herald
byte Name10[4] = {0x00, 0x00, 0x00, 0x09}; // Jabajab, Kate
byte Name11[4] = {0x00, 0x00, 0x00, 0x10}; // Jumamil, Bridget Darby
byte Name12[4] = {0x00, 0x00, 0x00, 0x11}; // Mumar, Starah Jewilli
byte Name13[4] = {0x00, 0x00, 0x00, 0x12}; // Pajo, Danica
byte Name14[4] = {0x00, 0x00, 0x00, 0x13}; // Poquita, Nina

int NumbCard[14], j = 0;  
int status[14], s = 0;        

int const RedLed = 6;
int const GreenLed = 5;
int const Buzzer = 8;

String LName, FName, CYear;
int column[14], count = 2, n = 0;
long Number;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.println("CLEARSHEET");
  Serial.println("LABEL,Last Name,First Name,ID Number,Course & Year,Date,Time In,Time Out");

  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  
  digitalWrite(GreenLed, HIGH);
  
  lcd.setCursor(2, 0);
  lcd.print("Scan ID Card");
  delay(200);
}
   
void loop() {
  if (!mfrc522.PICC_IsNewCardPresent())
    return;
  if (!mfrc522.PICC_ReadCardSerial())
    return;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    card_ID[i] = mfrc522.uid.uidByte[i];
    if (card_ID[i] == Name0[i]){
      LName = "Nacorda";
      FName = "Jeo Rodel";
      CYear = "Instructor";
      Number = 123456;
      j = 0;
      s = 0;
    }
    else if (card_ID[i] == Name1[i]){
      LName = "Group 2";
      FName = "RFID";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 1;
      s = 1;
    }
    else if (card_ID[i] == Name2[i]){
      LName = "Acupicop";
      FName = "Gwenn Remielle";
      CYear = "BSCpE-2A";
      Number = 442694;
      j = 2;
      s = 2;
    }
    else if (card_ID[i] == Name3[i]){
      LName = "Amizola";
      FName = "Christian";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 3;
      s = 3;
    }
    else if (card_ID[i] == Name4[i]){
      LName = "Ayag";
      FName = "Khirk Johann";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 4;
      s = 4;
    }
    else if (card_ID[i] == Name5[i]){
      LName = "Bag-ao";
      FName = "Christian Rey";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 5;
      s = 5;
    }
    else if (card_ID[i] == Name6[i]){
      LName = "Banquel";
      FName = "John Dave";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 6;
      s = 6;
    }
    else if (card_ID[i] == Name7[i]){
      LName = "Canon";
      FName = "Ayesha Nicole";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 7;
      s = 7;
    }
    else if (card_ID[i] == Name8[i]){
      LName = "Cunanan";
      FName = "Joseff Mari Luis";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 8;
      s = 8;
    }
    else if (card_ID[i] == Name9[i]){
      LName = "Felisilda";
      FName = "Herald";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 9;
      s = 9;
    }
    else if (card_ID[i] == Name10[i]){
      LName = "Jabajab";
      FName = "Kate";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 10;
      s = 10;
    }
    else if (card_ID[i] == Name11[i]){
      LName = "Jumamil";
      FName = "Bridget Darby";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 11;
      s = 11;
    }
    else if (card_ID[i] == Name12[i]){
      LName = "Mumar";
      FName = "Starah Jewilli";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 12;
      s = 12;
    }
    else if (card_ID[i] == Name13[i]){
      LName = "Pajo";
      FName = "Danica";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 13;
      s = 13;
    }
    else if (card_ID[i] == Name14[i]){
      LName = "Poquita";
      FName = "Nina Stephane";
      CYear = "BSCpE-2A";
      Number = 111111;
      j = 14;
      s = 14;
    }
    else{
      digitalWrite(GreenLed, LOW);
      digitalWrite(RedLed, HIGH);
      digitalWrite(Buzzer, HIGH);
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Invalid ID");
      delay(500);
      digitalWrite(Buzzer, LOW);
      goto cont;
    }
  }
  if(NumbCard[j] == 0){
    NumbCard[j] = 1;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print(LName);
    lcd.setCursor(3,1);
    lcd.print("Signed In");
    Serial.print("DATA," + LName + ",");
    Serial.print(FName + ",");
    Serial.print(Number);
    Serial.print(",");
    Serial.print(CYear + ",");
    Serial.print("DATE,");
    Serial.println("TIME,");
    column[j] = count;
    count++;
    for (byte i = 0; i < 2; i++){
      digitalWrite(Buzzer,HIGH);
      delay(250);
      digitalWrite(Buzzer,LOW);
      digitalWrite(GreenLed,LOW);
      delay(250);
      digitalWrite(GreenLed,HIGH);
    }
    delay(1000);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Good Day!");
  }
  else if(NumbCard[j] == 1 && status[s] == 0){
    status[s] = 1;
    n++;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print(LName);
    lcd.setCursor(3,1);
    lcd.print("Signed Out");
    Serial.println("CELL,SET,G" + String(column[j]) + ",TIME");
    for (byte i = 0; i < 2; i++){
      digitalWrite(Buzzer,HIGH);
      delay(250);
      digitalWrite(Buzzer,LOW);
      digitalWrite(GreenLed,LOW);
      delay(250);
      digitalWrite(GreenLed,HIGH);
    }
    delay(1000);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Good Bye!");
  }
  else if(status[s] == 1){
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    digitalWrite(Buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print(LName + " Was");
    lcd.setCursor(0,1);
    lcd.print("Done Signing In");
    delay(750);
    digitalWrite(Buzzer, LOW);
  }

  cont:
  delay(2500);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Scan ID Card");
  digitalWrite(GreenLed,HIGH);
  digitalWrite(RedLed,LOW);

  if(n==2){ // 2 pa kay duha pay cards namo
    Serial.print("SAVEWORKBOOKAS,BSCpE-2A - Attendance Sheet - ");
    Serial.println(__DATE__);
    Serial.println("FORCEEXCELQUIT");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("All is Present.");
    for (byte i = 0; i < 5; i++){
      digitalWrite(Buzzer,HIGH);
      delay(200);
      digitalWrite(Buzzer,LOW);
      digitalWrite(GreenLed,LOW);
      digitalWrite(RedLed,HIGH);
      delay(200);
      digitalWrite(GreenLed,HIGH);
      digitalWrite(RedLed,LOW);
   }
    digitalWrite(GreenLed,LOW);
    lcd.setCursor(0,1);
    lcd.print("Document Saved!");
    while(1){
      for(byte i = 0; i < 2; i++){
        delay(1000);
        lcd.setCursor(0,0);
        lcd.print("All is Present.");
        lcd.setCursor(0,1);
        lcd.print("Document Saved!");
        digitalWrite(GreenLed,HIGH);
        digitalWrite(RedLed,HIGH);
        delay(1000);
        lcd.clear();
        digitalWrite(GreenLed,LOW);
        digitalWrite(RedLed,LOW);
      }
      for(byte i = 0; i < 2; i++){
        delay(1000);
        lcd.setCursor(1,0);
        lcd.print("Please Eject.");
        lcd.setCursor(2,1);
        lcd.print("Thank you!");
        digitalWrite(GreenLed,HIGH);
        digitalWrite(RedLed,HIGH);
        delay(1000);
        lcd.clear();
        digitalWrite(GreenLed,LOW);
        digitalWrite(RedLed,LOW);
      }
    }
  }
}
