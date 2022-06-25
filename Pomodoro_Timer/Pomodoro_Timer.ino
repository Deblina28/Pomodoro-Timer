#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define Buzzer 3
#define Light 7
#define Button1 2

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Pomodoro Timer");
  delay(2000);

  pinMode(Button1, INPUT_PULLUP);
  //pinMode(Button2, );
  pinMode(Light, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  for(;;)
  Heehaw();
}

boolean f=true;

void loop() 
{
  int x= digitalRead(Button1)^1;
  Serial.println(x);
  if(x==1 && f==true)
  {
    delay(500);
    TanTimer();
  }
}

void Heehaw()
{
  //analogWrite(Buzzer);
  tone(Buzzer, 700);
  delay(500);
  tone(Buzzer, 200);
  delay(500);
}

void TanTimer()
{
   lcd.setCursor(0,0);
   lcd.print("   Sunbathing   ");
   lcd.setCursor(0,1);
   lcd.print("Starting...     ");
   
   delay(2500);
   
   lcd.setCursor(0,0);
   lcd.print("Lay on your back");
   lcd.setCursor(0,1);
   lcd.print("Time left: ");
   
   for(int m=14; m>=0; m--)
   for(int s=59; s>=0; s--)
   {
    lcd.setCursor(11,1);
    lcd.print(m/10);
    lcd.print(m%10);
    lcd.setCursor(13,1);
    lcd.print(":");
    lcd.setCursor(14,1);
    lcd.print(s/10);
    lcd.print(s%10);
    delay(950);
    }

lcd.setCursor(0,0);
   lcd.print("Lay on your left");
   lcd.setCursor(0,1);
   lcd.print("Time left: ");
   
   for(int m=10; m>=0; m--)
   for(int s=59; s>=0; s--)
   {
    lcd.setCursor(11,1);
    lcd.print(m/10);
    lcd.print(m%10);
    lcd.setCursor(13,1);
    lcd.print(":");
    lcd.setCursor(14,1);
    lcd.print(s/10);
    lcd.print(s%10);
    delay(950);
   }

    
   lcd.setCursor(0,0);
   lcd.print("Lay on your front");
   lcd.setCursor(0,1);
   lcd.print("Time left: ");
   
   for(int m=10; m>=0; m--)
   for(int s=59; s>=0; s--)
   {
    lcd.setCursor(11,1);
    lcd.print(m/10);
    lcd.print(m%10);
    lcd.setCursor(13,1);
    lcd.print(":");
    lcd.setCursor(14,1);
    lcd.print(s/10);
    lcd.print(s%10);
    delay(950);
    }

lcd.setCursor(0,0);
   lcd.print("Lay on your right");
   lcd.setCursor(0,1);
   lcd.print("Time left: ");
   
   for(int m=10; m>=0; m--)
   for(int s=59; s>=0; s--)
   {
    lcd.setCursor(11,1);
    lcd.print(m/10);
    lcd.print(m%10);
    lcd.setCursor(13,1);
    lcd.print(":");
    lcd.setCursor(14,1);
    lcd.print(s/10);
    lcd.print(s%10);
    delay(950);
   }
}