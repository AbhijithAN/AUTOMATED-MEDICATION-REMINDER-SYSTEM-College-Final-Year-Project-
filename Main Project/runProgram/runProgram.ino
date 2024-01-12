#include <Wire.h>
#include <RTClib.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address
#define LCD_ADDRESS 0x27

// Set the LCD dimensions
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Initialize the LCD object
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

RTC_DS3231 rtc;

#include <EEPROM.h>
bool result = false;

void setup() {
  lcd.init();
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight();

  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  if (rtc.lostPower()) {
    Serial.println("RTC lost power! Setting the time...");
    // Uncomment the following line to set the initial time
     rtc.adjust(DateTime(F(_DATE), F(TIME_)));
  }
}

void loop()
{
while (Serial.available() == 0) 
{
 result = compare(); //result will be true if time matches and will be false if time does not match 
if(result ==true)
{
  //compartment rotation code
  result=false;
  }
  } 
    Serial.println("Enter medicine name.");  
    while (!Serial.available()) {}
    delay(20000);   
    mednam = Serial.readString(); //Reading the Input string from Serial port.
     
    Serial.println("Enter compartment number.");  
    while (Serial.available() == 4) {} 
    delay(5000); 
    CompNo = Serial.readString();  
    Serial.println("Enter dosage number.");  
    while (Serial.available() == 0) {}  
    delay(5000);
    Dosage = Serial.readString();  
    Serial.println("enter consumption time.");  
    while (Serial.available() == 0) {}
    delay(10000) ; 
    ConsumpTime = Serial.readString();  
    Serial.println("-------------------------"); //Showing the details  
    Serial.println("MEDICINE NAME:" + mednam);  
    Serial.println("COMPARTMENT NUMBER NO:" + CompNo);  
    Serial.println("DOSAGE:" + Dosage);  
    Serial.println("CONSUMPTION TIME:" + ConsumpTime);  
    Serial.println("Thanks You...");  
    Serial.println("");   
//call this to store time in ee prom as a four digit number
storetime(ConsumpTime);

//read time
byte val = readtime(); // val gets a four digit number  // print val in lcd

// compare eeprom value with rtc calue of time
result = compare(); //result will be true if time matches and will be false if time does not match 
if(result ==true)
{
  //compartment rotation code
  result=false;
  }
 
 }

void storetime(ConsumpTime) {
int addr = 0;
EEPROM.write(addr, ConsumpTime.toInt());
}


byte readtime() {
  int addr = 0;
  byte val = EEPROM.read(addr);
  return val
}


bool compare()
{
  byte t = readtime();
  
  DateTime now = rtc.now();
  String hr = now.hour();
  String mn =now.minute();
  hr=hr+mn;
  val=hr.toInt();

  if (val == t){ return true;}
  else{return false;}
  }
