#include <SoftwareSerial.h>

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int Mode1_In = A3;
int Mode2_In = A1;
int Mode3_In = A2;

int Free1 = A0;
int Free2 = A4;
int Free3 = A5;
int Free4 = 10;
int Free5 = 11;
int Free6 = 12;
int Free7 = 13;


int Finish_Flag = 9;


SoftwareSerial mySerial(2, 3);


#define Servo1_1st_Pos 160
#define Servo1_2nd_Pos 160-120

#define Servo2_1st_Pos 160
#define Servo2_2nd_Pos 160-130

#define Servo3_1st_Pos 0
#define Servo3_2nd_Pos 110

#define Servo4_1st_Pos 160
#define Servo4_2nd_Pos 160-120

#define Servo5_1st_Pos 150
#define Servo5_2nd_Pos 150-130
#define Servo5_3nd_Pos 150-50


unsigned char mode = 0;

unsigned char second_mode_flag = 0;



void setup() {
  Serial.begin(9600);

  mySerial.begin(9600);

  pinMode(Mode1_In, INPUT);
  pinMode(Mode2_In, INPUT);
  pinMode(Mode3_In, INPUT);

  pinMode(Finish_Flag, OUTPUT);

  pinMode(Free1, OUTPUT);
  pinMode(Free2, OUTPUT);
  pinMode(Free3, OUTPUT);
  pinMode(Free4, OUTPUT);
  pinMode(Free5, OUTPUT);
  pinMode(Free6, OUTPUT);
  pinMode(Free7, OUTPUT);

  servo1.attach(4);
  servo1.write(Servo1_1st_Pos);

  servo2.attach(5);
  servo2.write(Servo2_1st_Pos);
  
  servo3.attach(6);
  servo3.write(Servo3_1st_Pos);

  servo4.attach(7);
  servo4.write(Servo4_1st_Pos);

  servo5.attach(8);
  servo5.write(Servo5_1st_Pos);

}

void loop() {

  //if(mode == 1)
  if(!digitalRead(Mode1_In))
  {
    delay(500);
    servo1.write(Servo1_2nd_Pos);
    delay(1000);
    servo1.write(Servo1_1st_Pos);
    //delay(200);

    servo2.write(Servo2_2nd_Pos);
    delay(1000);
    servo2.write(Servo2_1st_Pos);
    //delay(200);

    servo3.write(Servo3_2nd_Pos);
    delay(1000);
    servo3.write(Servo3_1st_Pos);
    delay(200);

    servo4.write(Servo4_2nd_Pos);
    delay(1000);
    servo4.write(Servo4_1st_Pos);
    delay(500);

    mode = 0;


  }

  if((!digitalRead(Mode2_In)) && second_mode_flag == 0)
  {
    delay(1000);
    servo5.write(Servo5_3nd_Pos);
    second_mode_flag = 1;
    mode = 0;
    //mySerial.print("mode21OK");
    delay(1000);
  }


  if((!digitalRead(Mode2_In)) && second_mode_flag == 1)
  {
    servo5.write(Servo5_1st_Pos);
    delay(300);
    
    servo1.write(Servo1_2nd_Pos);
    delay(1000);
    servo1.write(Servo1_1st_Pos);
    //delay(200);

    servo2.write(Servo2_2nd_Pos);
    delay(1000);
    servo2.write(Servo2_1st_Pos);
    //delay(200);

    servo3.write(Servo3_2nd_Pos);
    delay(1000);
    servo3.write(Servo3_1st_Pos);
    delay(200);

    servo4.write(Servo4_2nd_Pos);
    delay(1000);
    servo4.write(Servo4_1st_Pos);
    delay(500);


    servo5.write(Servo5_3nd_Pos);
    second_mode_flag = 2;
    mode = 0;
  }

  if((!digitalRead(Mode2_In)) && second_mode_flag == 2)
  {
    
    mode = 0;
    delay(500);
    servo5.write(Servo5_1st_Pos);
    delay(1000);
    second_mode_flag = 0;
  }

  
  if(!digitalRead(Mode3_In))
  {
    delay(500);
    servo1.write(Servo1_2nd_Pos);
    delay(1000);
    servo1.write(Servo1_1st_Pos);
    //delay(200);

    servo2.write(Servo2_2nd_Pos);
    delay(1000);
    servo2.write(Servo2_1st_Pos);
    //delay(200);

    servo3.write(Servo3_2nd_Pos);
    delay(1000);
    servo3.write(Servo3_1st_Pos);
    delay(200);

    servo4.write(Servo4_2nd_Pos);
    delay(1000);
    servo4.write(Servo4_1st_Pos);
    delay(500);

    servo5.write(Servo5_2nd_Pos);
    delay(1000);
    servo5.write(Servo5_1st_Pos);
    delay(1000);

    digitalWrite(Finish_Flag, HIGH);
    delay(1000);
    digitalWrite(Finish_Flag, LOW);


    mode = 0;
  }  
  

}