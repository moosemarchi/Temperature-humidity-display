#include <dht11.h>
#define DHT11PIN 4



#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);
int tempF;
 
dht11 DHT11;

byte degrees[] = {
	0b11100,
	0b10100,
	0b11100,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};


void  setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, degrees);
 
}

void loop()
{
  Serial.println();

  tempF = (DHT11.temperature*1.8)+32;

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);
  
  
  
  lcd.clear();
  lcd.setCursor(1,0);
  
  lcd.print(tempF);
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.print("Fahrenheit");


  lcd.setCursor(1,1);
  
  lcd.print(DHT11.humidity);
  
  lcd.setCursor(3,1);
  lcd.print("% Humidity");

  
  delay(500);
 
}