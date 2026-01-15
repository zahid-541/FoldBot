#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);

int Conveyor_Pin = 25;
int Mode1_LED_Pin = 33;
int Mode2_LED_Pin = 32;
int Mode3_LED_Pin = 26;

int Mode1_Btn = 5;
int Mode2_Btn = 18;
int Mode3_Btn = 19;

int Mode1_Out = 12;
int Mode2_Out = 13;
int Mode3_Out = 14;

int Finish_Flag = 27;

unsigned char Run_Flag = 0, Mode2 = 0, d = 0, dd = 0;


unsigned int Count = 0, Pre_Count = 0;

void setup() {
  Serial.begin(9600);
  //Serial2.begin(9600);

  lcd.begin(16, 4);

  pinMode(Conveyor_Pin, OUTPUT);
  pinMode(Mode1_LED_Pin, OUTPUT);
  pinMode(Mode2_LED_Pin, OUTPUT);
  pinMode(Mode3_LED_Pin, OUTPUT);

  pinMode(Mode1_Out, OUTPUT);
  pinMode(Mode2_Out, OUTPUT);
  pinMode(Mode3_Out, OUTPUT);

  pinMode(Finish_Flag, INPUT);

  digitalWrite(Conveyor_Pin, HIGH);
  digitalWrite(Mode1_LED_Pin, HIGH);
  digitalWrite(Mode2_LED_Pin, HIGH);
  digitalWrite(Mode3_LED_Pin, HIGH);

  pinMode(Mode1_Btn, INPUT);
  pinMode(Mode2_Btn, INPUT);
  pinMode(Mode3_Btn, INPUT);

  lcd.setBacklight(255);


}

void loop() {

  dd++;
  if(dd > 50)
  {
    dd = 0;
    lcd.begin(16, 4);
    //Serial.println("Allah Hooooo");
  }
  
/*
    if(!digitalRead(Mode1_LED_Pin))
    {
      digitalWrite(Mode1_LED_Pin, HIGH);
      Run_Flag = 0;
      Count++;  
    }

    if(!digitalRead(Mode2_LED_Pin))
    {
        //Mode2 = 1;
        digitalWrite(Mode2_LED_Pin, HIGH);
        Run_Flag = 0;
        Mode2 = 0;
        Count++;
        lcd.clear();
    }
*/
    if(!digitalRead(Finish_Flag))
    {
      //digitalWrite(Mode3_LED_Pin, HIGH);
      digitalWrite(Conveyor_Pin, LOW);
      Run_Flag = 0;  
      //Count++;
    }


  lcd.setCursor(0, 0);
  lcd.print("Counter: ");
  lcd.print(Count);
  lcd.print(" pcs");

  if(!digitalRead(Conveyor_Pin))
  d++;

  if(d > 160)
  {
    d = 0;
    digitalWrite(Conveyor_Pin, HIGH);
  }


  if(Run_Flag == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("Select Your Mode");

    lcd.setCursor(0, 2);
    lcd.print("Fold BOT:T-Shirt");
    lcd.setCursor(0, 3);
    lcd.print("Folding Machine ");
  }
  else // if(Run_Flag == 1 && digitalRead(Mode2_LED_Pin))
  {
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print("Processing......");
  }


  if(!digitalRead(Mode1_Btn))
  {
    lcd.setCursor(0, 1);
    lcd.print("Fold Mode Select");
    digitalWrite(Mode1_LED_Pin, LOW);
    digitalWrite(Mode1_Out, HIGH);
    delay(1000);
    digitalWrite(Mode1_Out, LOW);
     
    //Serial.print("mode1");
    Run_Flag = 1;
    delay(5000);
    digitalWrite(Mode1_LED_Pin, HIGH);
    Run_Flag = 0;
    Pre_Count = 0;
    Count++;
  }


  if(!digitalRead(Mode2_Btn))
  {
    lcd.setCursor(0, 1);
    lcd.print("Pack Mode Select");
    digitalWrite(Mode2_LED_Pin, LOW);
    digitalWrite(Mode2_Out, HIGH);
    delay(1000);
    digitalWrite(Mode2_Out, LOW);
    //Serial.print("mode2");
    Run_Flag = 1;
    Mode2++;
    delay(1000);
    digitalWrite(Mode2_LED_Pin, HIGH);
    Run_Flag = 0;
    Pre_Count++;
    if(Pre_Count > 2)
    {
      Count++;
      Pre_Count = 0;
    }
  }


  if(!digitalRead(Mode3_Btn) && Run_Flag == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("Belt Mode Select");
    digitalWrite(Mode3_LED_Pin, LOW);
    digitalWrite(Mode3_Out, HIGH);
    delay(1000);
    digitalWrite(Mode3_Out, LOW);
    //Serial.print("mode3");
    Run_Flag = 1;
    delay(5000);
    digitalWrite(Mode3_LED_Pin, HIGH);
    Run_Flag = 0;
    Pre_Count = 0;
    Count++;
  }


}