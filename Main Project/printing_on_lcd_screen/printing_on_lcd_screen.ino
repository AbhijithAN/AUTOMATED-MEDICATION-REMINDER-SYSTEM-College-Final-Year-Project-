#include <LiquidCrystal.h>

String mednam = "";
String CompNo = "";
String Dosage = "";
String ConsumpTime = "";

// Define LCD pin connections
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    Serial.begin(9600);

    // Initialize the LCD with 16 columns and 2 rows
    lcd.begin(16, 2);
}

void loop()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter medicine name.");

    while (!Serial.available())
    {
    }
    delay(20000);
    mednam = Serial.readString();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter compartment number.");

    while (Serial.available() == 4)
    {
    }
    delay(5000);
    CompNo = Serial.readString();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter dosage number.");

    while (Serial.available() == 0)
    {
    }
    delay(5000);
    Dosage = Serial.readString();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter consumption time.");

    while (Serial.available() == 0)
    {
    }
    delay(10000);
    ConsumpTime = Serial.readString();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MEDICINE: " + mednam);

    lcd.setCursor(0, 1);
    lcd.print("COMP: " + CompNo);

    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DOSAGE: " + Dosage);

    lcd.setCursor(0, 1);
    lcd.print("TIME: " + ConsumpTime);

    delay(2000);

    lcd.clear();
    lcd.print("Thanks You...");
    Serial.println("");
    while (Serial.available() == 0)
    {
    }
}
