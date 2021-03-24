### *"Enjoy the little things because one day you will look back and realize that they were big things"* ~ Robert Brault.


__Project of measurement temperature of the heating furnace__


##Table of contents
* General info
* Design assumptions
* Technologies
* Componens
* Development
* License


## __General info__

 The project is to monitor the temperature in the furnace. It is aimed at people who like comfort. In 2011, we can read the statistics of the Central Statistical Office*, about 96.8% in rural areas are single-family buildings. In cities, it is 79.4%. In the next document* we see that 28.8% and 36.6% of people consumed coal and wood for burning in the furnace. This project is aimed at people who want to monitor the temperature of the furnace

1* *https://stat.gov.pl/cps/rde/xbcr/gus/L_zamieszk_budynki_nsp_2011.pdf*               
2* *https://stat.gov.pl/obszary-tematyczne/srodowisko-energia/energia/zuzycie-energii-w-gospodarstwa-domowych-w-2018-roku,2,4.html*


## Design assumptions 
Sotware Assumptaions:
    * learn i2c serial communication bus.
    * Measurements performed once a minute
    * Update Measurements after performed
    * Alarm display
    * __Temperature drop range over time__

Hardware Assumptions:
Processor: Esp8266 + wifi module.
* V2 version.
* USB CP2102
* Voltage 3.3V/5V
* min. 50Mhz
* min. 7 GPIO
* Wi-Fi: IEEE 802.11 b/g/n: - 2,4Ghz
* 1 x I2Cs
* min. 1MB Flash.
    
LCD screen: 20x4
* Power supply +3.3..+5V
* Led blacklight Y/G max. 150mA@+25°C
* Hight Contrast
* Operating temperature range 0~+50°C
* Low power with blue-white optic / max. 45mA@+25°C
    
 Converter to LCD screen
*   Must handle I2c 

Cable (transmision medium)
*   Length: minimum 7m.
*   Category: CAT 5e
*   Structure:  __twisted pair__ (important)

Ethernet over twisted pair- must the be used, to goal ensuring data transmission over the transmission medium#

## Technologies 
Language: C
IDE: Arduino IDE 
   
   
## Componens
*   [ESP8266 NodeMCU (ESP-12E Wifi) v2](https://pdf1.alldatasheet.com/datasheet-pdf/view/1179099/ETC2/ESP12E.html")
*   [Sensor DS18B20 Dallas](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf")
*   [LCD 2004 4x20 HD44780](https://www.lcd-module.com/fileadmin/eng/pdf/doma/dip204-4e.pdf")
*   [Converter I2C LCM1602](https://opencircuit.shop/resources/file/da88acc1702a90667728fcf4ac9c75c455475706466/I2C-LCD-interface.pdf")
*   [Ethernet Patchcord UTP 5e 7,5m](http://dlink-me.com/pdf/NCB-5EUBLUR1-1.pdf")
*   [Cable MicroUSB 1,8m](https://cdn.centralpoint.nl/objects/pdf/d/dc4/1350363769_1_usb-kabels-roline-usb-20-cable-micro-a-micro-b-m-m-18m-11028753.pdf")


## Development
- [ ]  In the future, a request will be added to an independent smartphone application. 
- [ ]  Change the display to a larger one (OLED). Adding new measurement functionalities.


## License
BeerWare. If you everywhere meet me, you must buy my a beer :)
but now:
Copyright by Bajkos Michał. All rights reserved.
