int sensor = A0;
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
//int sensor = A0; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float vout;  //temporary variable to hold sensor reading
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
lcd.begin(16,2);  
  delay(500);
}
void loop() 
{
vout=analogRead(A0);
float prehum=(vout/5);

vout=(vout*5.00)/1024.0;  
tempc=(vout-0.5)*100; // Storing value in Degree Celsius

float humconst = (0.16/0.0062);
float humi = prehum - humconst;
float pretruehumconst = 0.00216*tempc;
float pretruehum = 1.0546 - pretruehumconst;
float truehum = humi/pretruehum;
//delay(1000);  
lcd.setCursor(0,0);
lcd.print("Degree C = ");
lcd.print(tempc);
lcd.setCursor(0,1);
lcd.print("Humidity%= ");
lcd.print(truehum);
delay(1000); //Delay of 1 second for ease of viewing in serial monitor
}
