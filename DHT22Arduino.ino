#include<LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 10
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
    lcd.begin(16,2);
    Serial.begin(9600);
    Serial.println("DHT22 test");
    dht.begin();
}
void loop()
{
      delay(2000);
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      delay(1000);
      Serial.print("Humidity: \t");
      Serial.print(h);
      Serial.print("%\n");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Humidity");
      lcd.print(h);
      Serial.print("Tempreature :\t");
      Serial.print(t);
      Serial.print("*C \n");
      lcd.setCursor(0,1);
      lcd.print("Temp : ");
      lcd.print(t);
}