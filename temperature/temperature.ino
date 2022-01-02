// C++ code
//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 3

LiquidCrystal_I2C lcd(0x27, 16,2);
DHT dht(DHTPIN, DHTTYPE);

int buzzer = 11;
int lamp = 9;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ditya Ilmi R.");

  lcd.setCursor(0,1);
  lcd.print("1303191119");
  pinMode(buzzer,OUTPUT);
  pinMode(lamp,OUTPUT);

  delay(1000);
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C ");
  
  lcd.setCursor(0,1);
  lcd.print("Humi : ");
  lcd.print(h);
  delay(1000);
  
  if (t >= 34){
    tone(buzzer, 1000);
    digitalWrite(lamp, HIGH);
    delay(1000);
  }

    if (t < 34)
    {
      noTone(buzzer);
      digitalWrite(lamp, LOW);
      delay(1000);
    }
}
