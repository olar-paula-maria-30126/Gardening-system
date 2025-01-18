
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
String str;
int oldmos=-1;
LiquidCrystal_I2C lcd(0x27,16,2);  
void setup()
{
   Serial.begin(9600); 
   pinMode(3,INPUT); 
   pinMode(13,OUTPUT); 
 lcd.init();    // LCD initialization
     lcd.backlight();
}
void loop()
{
 int  soil_mos;
 
 soil_mos=1023-analogRead(0);//Obtaining data from the sensor on pin A0
 soil_mos=map(soil_mos, 0, 1023, 0, 100); //Conversion of analog data to digital
 if (oldmos!=soil_mos) {
 
// Display on the LCD screen
     lcd.setCursor(0,0);
     lcd.print("Umiditatea=");
     lcd.print(soil_mos);
     lcd.print("%");
     delay(4000); // a short pause to read the value of the humidity
     if (soil_mos < 35) {
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("The plants need");
           lcd.setCursor(0, 1);
           lcd.print("water now!");
           delay(10000); // a short pause to allow the user to read the alert message 
           lcd.clear();
    }else{
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("The plants have enough");
           lcd.setCursor(0, 1);
           lcd.print(" water :)!");
           delay(5000); // a short pause to allow the user to read the alert message
           lcd.clear();
    }
 }
}
  

