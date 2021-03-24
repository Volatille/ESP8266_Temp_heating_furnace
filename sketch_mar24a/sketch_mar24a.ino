#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>



#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

#include <Wire.h>

char* ssid ="ANTENA 5G 200% MOCY TEST";
char* password = "JAROSLAWpolskezbaw";
LiquidCrystal_I2C lcd(0x27, 16, 2);


char MEA[]="Temperatura: 00'C";
char TIME[] = "SPADEK W 00min";
char DECREASE[] = "O 00'C";
char ALARM[] = "NALEŻY PODŁOŻYĆ !";
void setup() 
{
Serial.begin(115200);
//Use predefined PINS consts
Wire.begin(D2, D1);
lcd.begin();
lcd.home();

lcd.setCursor(0,0);
lcd.print(MEA);

lcd.setCursor(0,1);
lcd.print(TIME);

lcd.setCursor(0,2);
lcd.print(DECREASE);



}

void loop() 
{ 
  // do nothing here 
}
