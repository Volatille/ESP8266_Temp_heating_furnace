#include <OneWire.h>
#include <DallasTemperature.h>

const int oneWireBus = 2;     
OneWire sensor(oneWireBus);
DallasTemperature sensors(&sensor);

void setup() 
{
  Serial.begin(115200);
  sensors.begin();
}

void loop() 
{
   
  sensors.requestTemperatures(); 
  float temp_Measurement = sensors.getTempCByIndex(0);
  
  Serial.print(temp_Measurement);
  Serial.println("C");
 
  delay(2000);

}
