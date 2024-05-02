#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String card_ID = "";

String Name0 = "195617628"; // Nacorda, Jeo Rodel
String Name1 = "1151852319"; // Group 2
String Name2 = "243944053"; // Acupicop, Gwenn Remielle
String Name3 = "196611952"; // Amizola, Christian
String Name4 = "1917711753"; // Ayag, Khirk Johann
String Name5 = "83849653"; // Bag-ao, Christian Rey
String Name6 = "3523514952"; // Banquel, John Dave
String Name7 = "3565753"; // Canon, Ayesha Nicole
String Name8 = "211909953"; // Cunanan, Jolo
String Name9 = "22719212053"; // Felisilda, Herald
String Name10 = "16311113652"; // Jabajab, Kate
String Name11 = "1319412952"; // Jumamil, Bridget Darby
String Name12 = "2271851853"; // Mumar, Starah Jewilli
String Name13 = "21123611753"; // Pajo, Danica
String Name14 = "17915610153"; // Poquita, Nina

byte NumbCard[15], j = 0;  
byte status[15], s = 0;        

int const RedLed = 6;
int const GreenLed = 5;
int const Buzzer = 8;

String LName, FName, NName, CYear;
byte column[15], count = 2, n = 0, center;
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
  for (byte i = 0; i < mfrc522.uid.size; i++)
    card_ID += mfrc522.uid.uidByte[i];

  if (card_ID == Name0){
    card_ID = "";
    LName = "Nacorda";
    FName = "Jeo Rodel";
    NName = "Sir Jeo";
    CYear = "Instructor";
    Number = 123456;
    j = 0;
    s = 0;
  }
  else if (card_ID == Name1){
    card_ID = "";
    LName = "Group 2";
    FName = "RFID";
    NName = "Group 2";
    CYear = "BSCpE-2A";
    Number = 13;
    j = 1;
    s = 1;
  }
  else if (card_ID == Name2){
    card_ID = "";
    LName = "Acupicop";
    FName = "Gwenn Remielle";
    NName = "Gwenn";
    CYear = "BSCpE-2A";
    Number = 442694;
    j = 2;
    s = 2;
  }
  else if (card_ID == Name3){
    card_ID = "";
    LName = "Amizola";
    FName = "Christian";
    NName = "Christian";
    CYear = "BSCpE-2A";
    Number = 955357;
    j = 3;
    s = 3;
  }
  else if (card_ID == Name4){
    card_ID = "";
    LName = "Ayag";
    FName = "Khirk Johann";
    NName = "Khirk";
    CYear = "BSCpE-2A";
    Number = 676823;
    j = 4;
    s = 4;
  }
  else if (card_ID == Name5){
    card_ID = "";
    LName = "Bag-ao";
    FName = "Christian Rey";
    NName = "Rey";
    CYear = "BSCpE-2A";
    Number = 599979;
    j = 5;
    s = 5;
  }
  else if (card_ID == Name6){
    card_ID = "";
    LName = "Banquel";
    FName = "John Dave";
    NName = "Banquel";
    CYear = "BSCpE-2A";
    Number = 357690;
    j = 6;
    s = 6;
  }
  else if (card_ID == Name7){
    card_ID = "";
    LName = "Canon";
    FName = "Ayesha Nicole";
    NName = "Ayesha";
    CYear = "BSCpE-2A";
    Number = 263812;
    j = 7;
    s = 7;
  }
  else if (card_ID == Name8){
    card_ID = "";
    LName = "Cunanan";
    FName = "Joseff Mari Luis";
    NName = "Jolo";
    CYear = "BSCpE-2A";
    Number = 259013;
    j = 8;
    s = 8;
  }
  else if (card_ID == Name9){
    card_ID = "";
    LName = "Felisilda";
    FName = "Herald";
    NName = "Herald";
    CYear = "BSCpE-2A";
    Number = 144052;
    j = 9;
    s = 9;
  }
  else if (card_ID == Name10){
    card_ID = "";
    LName = "Jabajab";
    FName = "Kate";
    NName = "Kate";
    CYear = "BSCpE-2A";
    Number = 211723;
    j = 10;
    s = 10;
  }
  else if (card_ID == Name11){
    card_ID = "";
    LName = "Jumamil";
    FName = "Bridget Darby";
    NName = "Darby";
    CYear = "BSCpE-2A";
    Number = 745466;
    j = 11;
    s = 11;
  }
  else if (card_ID == Name12){
    card_ID = "";
    LName = "Mumar";
    FName = "Starah Jewilli";
    NName = "Starah";
    CYear = "BSCpE-2A";
    Number = 391952;
    j = 12;
    s = 12;
  }
  else if (card_ID == Name13){
    card_ID = "";
    LName = "Pajo";
    FName = "Danica";
    NName = "Danica";
    CYear = "BSCpE-2A";
    Number = 192203;
    j = 13;
    s = 13;
  }
  else if (card_ID == Name14){
    card_ID = "";
    LName = "Poquita";
    FName = "Nina Stephane";
    NName = "Nina";
    CYear = "BSCpE-2A";
    Number = 260893;
    j = 14;
    s = 14;
  }
  else{
    card_ID = "";
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    digitalWrite(Buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Invalid ID");
    delay(500);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Please Try Again");
    goto cont;
  }
  
  if(NumbCard[j] == 0){
    NumbCard[j] = 1;
    center = 8 - LName.length()/2;
    lcd.clear();
    lcd.setCursor(center,0);
    lcd.print(LName);
    lcd.setCursor(4,1);
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
    center = 8 - (NName.length() + 1)/2;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Good Day,");
    lcd.setCursor(center,1);
    lcd.print(NName + "!");
  }
  else if(NumbCard[j] == 1 && status[s] == 0){
    status[s] = 1;
    n++;
    center = 8 - LName.length()/2;
    lcd.clear();
    lcd.setCursor(center,0);
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
    center = 8 - (NName.length() + 1)/2;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Good Bye,");
    lcd.setCursor(center,1);
    lcd.print(NName + "!");
  }
  else if(status[s] == 1){
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    digitalWrite(Buzzer, HIGH);
    center = 8 - (LName.length() + 4)/2;
    lcd.clear();
    lcd.setCursor(center,0);
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

  if(n == 15){
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
