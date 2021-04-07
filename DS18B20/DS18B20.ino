#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define BUF_SIZE 3

const int oneWireBus = 2;     
OneWire sensor(oneWireBus);
DallasTemperature sensors(&sensor);
const long freqMeasurement = 1000;
unsigned long currentTtime = 0;
unsigned long takeTime = 0;
float temp_Measurement_tab[BUF_SIZE];
float temp_Measurement;
enum {MAX, MIN, AV}state;
int i = 0;

float buforMeasurements[BUF_SIZE];
float newestMeasurement = 0;

float BUF_OVER[BUF_SIZE];
float BUF_BELOW[BUF_SIZE];
float BUF_NEUTRAL[BUF_SIZE];
float swing = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{ 
    lcd.begin();
    lcd.backlight();
    Serial.begin(115200);
    sensors.begin();
}

void sensor_lcd(void){
    takeTime = millis();
   sensors.requestTemperatures(); 
   temp_Measurement = sensors.getTempCByIndex(0);
   lcd.setCursor(0, 0);    
   lcd.print("Temperatura:");
   lcd.setCursor(12, 0);   
   lcd.print(temp_Measurement);
   lcd.setCursor(17, 0); 
   lcd.print("'C");
}

float fun_Make(float tab[], int size, int state)
{
  float val_max_min = 0;

switch(state)
{
    case MAX:
            val_max_min = tab[0];
            for(int i =0; i<size; i++)
            {
                if( tab[i] > val_max_min ) { val_max_min = tab[i];}
            }
            break;
    
    case MIN:
            val_max_min = tab[0];
            for(int i =0; i<size; i++)
            {
                if( tab[i] < val_max_min ) { val_max_min = tab[i];}
            }
            break;
    case AV:
            val_max_min = tab[0];
            break;
}
return val_max_min;
}


float porowywanie_tablicy(float BUF_BELOW[], float BUF_OVER[], float BUF_NEUTRAL[], int size1, int size2, int size3)
{
    //buff below
    if( size1 > size2 && size1 > size3 )
    {
      swing =fun_Make(BUF_BELOW, sizeof(BUF_BELOW), MAX);
    }

    //buf over
     if( size2 > size1 && size2 > size3 )
     {
        swing = fun_Make(BUF_OVER, sizeof(BUF_OVER), MIN);
     }
    
     //neutral
     if( size3 > size1 && size3 > size2 )
    {
      swing = fun_Make(BUF_NEUTRAL, sizeof(BUF_NEUTRAL), AV);
    }
  return swing;
}


void loop() 
{
  
    
    takeTime = millis();
    if(takeTime % freqMeasurement == 0) 
    {

      takeTime = millis();
      sensor_lcd();
      
         temp_Measurement_tab[i] = sensors.getTempCByIndex(0);

         if(ceil(temp_Measurement_tab[i])  > newestMeasurement)
         {  
            BUF_BELOW[i] = temp_Measurement_tab[i];
         }

         if(ceil(temp_Measurement_tab[i])  < newestMeasurement)
         {
          
            BUF_OVER[i] = temp_Measurement_tab[i];
         }

        if(ceil(temp_Measurement_tab[i]) == newestMeasurement);
         {
            BUF_NEUTRAL[i] = temp_Measurement_tab[i];
         }


          if( i == BUF_SIZE)
         {
            for(int j=0; j<=BUF_SIZE; j++)
            {
                buforMeasurements[j] = 0;
            }          
         }

   
      }
  i++ ;

  if(takeTime % 10000 == 0) {
  porowywanie_tablicy(BUF_BELOW,BUF_OVER,BUF_NEUTRAL,sizeof(BUF_BELOW),sizeof(BUF_OVER), sizeof(BUF_NEUTRAL));
   lcd.setCursor(0, 1);    
   lcd.print("+/-:");
   lcd.setCursor(5, 1); 
   lcd.print(swing);

  }
      
  
  }






   
 /*   if(takeTime - currentTtime >= freqMeasurement)
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

      */
