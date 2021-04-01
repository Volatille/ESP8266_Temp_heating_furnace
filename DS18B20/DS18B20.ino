#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>


const int oneWireBus = 2;     
OneWire sensor(oneWireBus);
DallasTemperature sensors(&sensor);
const long freqMeasurement = 10000;
unsigned long currentTtime = 0;
unsigned long takeTime = 0;
float temp_Measurement;
float buforMeasurements[100];


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{ 
    lcd.begin();
    lcd.backlight();
    Serial.begin(115200);
    sensors.begin();
}

void loop() 
{

   takeTime = millis();
   sensors.requestTemperatures(); 
   temp_Measurement = sensors.getTempCByIndex(0);

   lcd.setCursor(0, 0);    
   lcd.print("Temperatura:");
   lcd.setCursor(12, 0);   
   lcd.print(temp_Measurement);
   lcd.setCursor(17, 0); 
   lcd.print("'C");

   
    if(takeTime - currentTtime >= freqMeasurement)
    {
      temp_Measurement = sensors.getTempCByIndex(0);
  
        for(int i=0; i<=100; i++)
        {
          buforMeasurements[i] = temp_Measurement;
          if( (i-1) <= 100)
          {
              for(int j=0; j<=100; j++)
              {
                buforMeasurements[i] = 0;
              }
          }
        }


      }
}
