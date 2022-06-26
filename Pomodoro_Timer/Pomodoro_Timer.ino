#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define Buzzer 3
#define Light 7
#define Button1 4
#define Button2 2
#define Button3 8

int ct = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

String man[] = {"5 mins   ", "25 mins  ", "1 hrs    ", "2 hrs    ", "3 hrs    "};

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Pomodoro Timer  ");

  lcd.setCursor(0, 1);
  lcd.print("Mode:1.Tan 2.Man");
  delay(2000);

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Light, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}


void loop()
{
  int y = digitalRead(Button3) ^ 1;
  int x = digitalRead(Button1) ^ 1;
  Serial.println(ct);

  if (x == 1)
  {
    delay(500);
    TanTimer();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pomodoro Timer  ");

    lcd.setCursor(0, 1);
    lcd.print("Mode:1.Tan 2.Man");
    delay(2000);
  }

  if (y == 1)
  {
    delay(1500);
    ManualTimer();
    Serial.println("abcdefg");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pomodoro Timer  ");

    lcd.setCursor(0, 1);
    lcd.print("Mode:1.Tan 2.Man");
    delay(2000);
  }
}

void ManualTimer()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set Manual Timer");

  lcd.setCursor(0, 1);
  lcd.print("Set to: ");

  //if (digitalRead(Button3) == 1)

  int n=0;
  while (digitalRead(Button3) == 1)
  {
    lcd.setCursor(8,1);
    n=n%5;
    lcd.print(man[n++]);
    delay(1500);
  }
  switch(n)
  {
    case 1: SetTim(4);
            break;
            
    case 2: SetTim(24);
            break;
            
    case 3: SetTim(59);
            break;
            
    case 4: SetTim(119);
            break;
        
    case 5: SetTim(179);
            break;

    default: break;
    }
}

void SetTim(int t)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Time left: ");
  
  for (int m = t; m >= 0; m--)
    for (int s = 59; s >= 0; s--)
    {
      Pause();

      if (digitalRead(Button2) == 0)
      {
        lcd.clear();
        lcd.print("   Exiting...   ");
        delay(1000);
        return;   //returns to main page
      }

      lcd.setCursor(0, 1);
      lcd.print(m / 10);
      lcd.print(m % 10);
      lcd.setCursor(2, 1);
      lcd.print(":");
      lcd.setCursor(3, 1);
      lcd.print(s / 10);
      lcd.print(s % 10);
      delay(950);
    }
  while (digitalRead(Button3) == 1)
    Heehaw();
  noTone(Buzzer);
  delay(1000);
 }

void Pause()
{
  if (digitalRead(Button1) == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("     Paused     ");
    delay(3000);
    while (digitalRead(Button1) == 1);
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("     Resume     ");
  }
}

void Heehaw()
{
  tone(Buzzer, 700);
  delay(500);
  tone(Buzzer, 200);
  delay(500);
}

void TanTimer()
{
  lcd.setCursor(0, 0);
  lcd.print("   Sunbathing   ");
  lcd.setCursor(0, 1);
  lcd.print("Starting...     ");

  delay(2500);

  lcd.setCursor(0, 0);
  lcd.print("Lay on your back");
  lcd.setCursor(0, 1);
  lcd.print("Time left: ");

  for (int m = 24; m >= 0; m--)
    for (int s = 59; s >= 0; s--)
    {
      Pause();

      if (digitalRead(Button2) == 0)
      {
        lcd.clear();
        lcd.print("   Exiting...   ");
        delay(1000);
        return;   //returns to main page
      }

      lcd.setCursor(11, 1);
      lcd.print(m / 10);
      lcd.print(m % 10);
      lcd.setCursor(13, 1);
      lcd.print(":");
      lcd.setCursor(14, 1);
      lcd.print(s / 10);
      lcd.print(s % 10);
      delay(950);
    }
  while (digitalRead(Button1) == 1)
    Heehaw();
  noTone(Buzzer);
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Lay on your left");
  lcd.setCursor(0, 1);
  lcd.print("Time left: ");

  for (int m = 14; m >= 0; m--)
    for (int s = 59; s >= 0; s--)
    {
      Pause();

      if (digitalRead(Button2) == 0)
      {
        lcd.clear();
        lcd.print("   Exiting...   ");
        delay(1000);
        return;   //returns to main page
      }

      lcd.setCursor(11, 1);
      lcd.print(m / 10);
      lcd.print(m % 10);
      lcd.setCursor(13, 1);
      lcd.print(":");
      lcd.setCursor(14, 1);
      lcd.print(s / 10);
      lcd.print(s % 10);
      delay(950);
    }
  while (digitalRead(Button1) == 1)
    Heehaw();
  noTone(Buzzer);
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Lay on your tum");
  lcd.setCursor(0, 1);
  lcd.print("Time left: ");

  for (int m = 14; m >= 0; m--)
    for (int s = 59; s >= 0; s--)
    {
      Pause();

      if (digitalRead(Button2) == 0)
      {
        lcd.clear();
        lcd.print("   Exiting...   ");
        delay(1000);
        return;   //returns to main page
      }

      lcd.setCursor(11, 1);
      lcd.print(m / 10);
      lcd.print(m % 10);
      lcd.setCursor(13, 1);
      lcd.print(":");
      lcd.setCursor(14, 1);
      lcd.print(s / 10);
      lcd.print(s % 10);
      delay(950);
    }
  while (digitalRead(Button1) == 1)
    Heehaw();
  noTone(Buzzer);
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Lay on your right");
  lcd.setCursor(0, 1);
  lcd.print("Time left: ");

  for (int m = 14; m >= 0; m--)
    for (int s = 59; s >= 0; s--)
    {
      Pause();

      if (digitalRead(Button2) == 0)
      {
        lcd.clear();
        lcd.print("   Exiting...   ");
        delay(1000);
        return;   //returns to main page
      }

      lcd.setCursor(11, 1);
      lcd.print(m / 10);
      lcd.print(m % 10);
      lcd.setCursor(13, 1);
      lcd.print(":");
      lcd.setCursor(14, 1);
      lcd.print(s / 10);
      lcd.print(s % 10);
      delay(950);
    }
  while (digitalRead(Button1) == 1)
    Heehaw();
  noTone(Buzzer);
  delay(1000);
}
