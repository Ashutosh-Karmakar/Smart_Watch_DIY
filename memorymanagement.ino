/*
     display---
rst 13
12
11
10
9
vcc
4
gnd
        rotor---
clk A0
DT A1
Sw A2
vcc
gnd
        switch----
gnd
5
        led----
gnd
resiste 6
        bluetooth
vcc
gnd
tx to rx
rx to tx



*/
#include <Adafruit_GFX.h>
#include <LCD5110_Graph.h>
#include <Adafruit_PCD8544.h>
#include<Fonts/Org_01.h> 
#include <ClickEncoder.h>
#include <TimerOne.h>
int timer = 0;
int high,low;
struct tim{
  unsigned int blon:1;//0 1
  //unsigned int upButtonState:1;//0 1
  unsigned int lastUpButtonState:1;//0 1
  unsigned int backlite:1;//0 1
  unsigned int sHour :6;//0 60
  unsigned int sMin :6;//0 60
  unsigned int sSec :6;//0 60
  unsigned int sMisec :6;//0 60
  unsigned int state :1;// 0 1
  unsigned int ST :1;//0 1
  unsigned int inbl :1;//0 1
  unsigned int BLN :1;//0 1
  unsigned int wCount :10;
  unsigned int pCount :10;
  unsigned int eCount :10;
  unsigned int mCount :10;
  unsigned int page :2;//1 2
  unsigned int menuitem :4;//1 to 7
  unsigned int lastmenu :4;//1 to 7
  unsigned int up :1;//0 1
  unsigned int down :1;//0 1
  unsigned int middle :1;//0 1
  
};
struct restString {
  String calls ="0" ;
String namecall;
String numb;
String tHour="00",tMin="00",tSec="00";
String pm="0";
String date="00",month ="00",day="1";
String sendname="null";
String detail = "null";
String packagename = "null";
String isNotify = "0";
String missed ="0";
};


tim t1;
restString t2;

Adafruit_PCD8544 display = Adafruit_PCD8544( 8, 9, 10, 11, 12);
LCD5110 lcd(8,9,10,12,11);

ClickEncoder *encoder;
int16_t last, value;
extern uint8_t SmallFont[];

extern uint8_t notifications[];
extern uint8_t stopwatchs[];
extern uint8_t alarms[];
extern uint8_t backlite[];
extern uint8_t face[];
extern uint8_t res[];
extern uint8_t callings[];
extern uint8_t whatsapps[];
extern uint8_t missedcalls[];
extern uint8_t messages[];
extern uint8_t gmails[];



void setup() {
  pinMode(5,INPUT_PULLUP);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
  t1.menuitem =1;
  t1.page =1;
t1.sHour=00,t1.sMin=00,t1.sSec=00,t1.sMisec=0000;
  // put your setup code here, to run once:
  t2.tHour="00",t2.tMin="00",t2.tSec="00",t2.pm="0";
  t2.date="00",t2.month ="00",t2.day="1";
  t1.state = 0,t1.ST = 0,t1.inbl=0,t1.BLN=1;
  t1.lastmenu=1,t1.up=0,t1.down =0,t1.middle =0;
  t1.lastUpButtonState = 0,t1.blon = 0;
  Serial.begin(9600);
  Serial.println(sizeof(t1));
  Serial.begin(9600);
  
  encoder = new ClickEncoder(A1, A0, A2);
  encoder->setAccelerationEnabled(false);
  Serial.begin(9600);
  Serial.println(sizeof(t1));
  Serial.println(sizeof(t2));

  
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 
  digitalWrite(2,HIGH);
  lcd.InitLCD();
  display.begin();
  delay(200);
  display.clearDisplay();
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(0,20);
  display.setTextSize(2);
  display.print(F("WELCOME"));
  display.setCursor(16,35);
  display.print(F("ASHU"));
  digitalWrite(6,HIGH);
  display.display();
  delay(1000);
  digitalWrite(6,LOW);
  last = encoder->getValue();
  
}

void loop() {
  
  Serial.print("blon");
  Serial.println(t1.blon);
  
  Serial.print("high");
  Serial.println(high);
  
  Serial.print("low");
  Serial.println(low);
 
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  digitalWrite(6,LOW);
  ButtonIsPressed(digitalRead(5));
//  Serial.println("backfdfdkf--------");
//  Serial.print(t1.blon);
  if(t1.backlite && t1.blon==0){
    t1.backlite = 0;
    t1.blon = 1;
  }
  if(t1.blon && t1.backlite){
    t1.blon = 0;
    t1.backlite = 0;
  }
  if(t1.blon == 1){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
//  Serial.println("CALLS");
//Serial.println(t2.calls);
//Serial.println("notify");
//Serial.println(t2.isNotify);
//Serial.print("aaaaaaaaaaaaaaaaaa--------");
//    Serial.println(t2.missed); 


  while(Serial.available()>0){
    t2.calls = Serial.readStringUntil(':');
    t2.namecall =  Serial.readStringUntil('/');
    t2.numb = Serial.readStringUntil('|');
    t2.tHour = Serial.readStringUntil('!');
    t2.tMin = Serial.readStringUntil('@');
    t2.pm = Serial.readStringUntil('$');
    t2.month = Serial.readStringUntil('%');
    t2.date = Serial.readStringUntil('^');
    t2.day = Serial.readStringUntil('&');
    t2.packagename = Serial.readStringUntil('*');
    t2.sendname = Serial.readStringUntil('(');
    t2.detail = Serial.readStringUntil(')');
    t2.isNotify=Serial.readStringUntil('_');
    t2.missed = Serial.readStringUntil('=');
    if(t2.packagename.equals("WhatsApp"))
      t1.wCount++;
    if(t2.missed.equals("1"))
      t1.pCount++;
    if(t2.packagename.equals("Message"))
      t1.mCount++;
    if(t2.packagename.equals("Gmail"))
      t1.eCount++;
    
  }

  if(t2.calls.equals("1")){
        display.clearDisplay();
        digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(6,LOW);
        if(t1.BLN==1){
          digitalWrite(4,HIGH);
        }
        else
        {
          digitalWrite(4,LOW);
        }
        delay(1000);
        lcd.clrScr();
        lcd.setFont(SmallFont);
        lcd.drawBitmap(30,16,callings,24,24);
        lcd.print("CALL FROM :",10,0);
        lcd.print(t2.namecall,0,9);
//        lcd.drawBitmap(30,16,callings,24,24);
        lcd.setFont(SmallFont);
        lcd.print(t2.numb,3,39);
        lcd.update();
  }
  else if(!t2.missed.equals("0")){
          display.clearDisplay();
          
          digitalWrite(6,HIGH);
          delay(500);
          digitalWrite(6,LOW);
          delay(500);
          
          lcd.clrScr();
          lcd.setFont(SmallFont);
          lcd.drawBitmap(30,10,missedcalls,24,24);
          lcd.print(t2.sendname,10,0);
          lcd.setFont(SmallFont);
          lcd.print(t2.detail,3,38);
          lcd.update();
          
          digitalWrite(6,HIGH);
          delay(500);
          digitalWrite(6,LOW);
          delay(500);
          
        }
  else if(t2.isNotify.equals("1")){
    
        if(t2.packagename.equals("WhatsApp")){
          display.clearDisplay();
          digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(6,LOW);
        if(t1.BLN==1){
          digitalWrite(4,HIGH);
        }
        else
        {
          digitalWrite(4,LOW);
        }
        delay(1000);
          lcd.clrScr();
          lcd.setFont(SmallFont);
          lcd.drawBitmap(30,12,whatsapps,24,24);
          lcd.print(t2.sendname,10,0);
          lcd.setFont(SmallFont);
          lcd.print(t2.detail,3,35);
          lcd.update();
          }
//        if(t2.packagename.equals("MissedCall")){
//          display.clearDisplay();
//          lcd.clrScr();
//          lcd.setFont(SmallFont);
//          lcd.drawBitmap(30,10,missedcalls,24,24);
//          lcd.print(t2.sendname,10,0);
//          lcd.setFont(SmallFont);
//          lcd.print(t2.detail,3,38);
//          lcd.update();
//        }
        if(t2.packagename.equals("Message")){
          display.clearDisplay();
          digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(6,LOW);
        if(t1.BLN==1){
          digitalWrite(4,HIGH);
        }
        else
        {
          digitalWrite(4,LOW);
        }
        delay(1000);
          lcd.clrScr();
          lcd.setFont(SmallFont);
          lcd.drawBitmap(25,5,messages,32,32);
          lcd.print(t2.sendname,0,0);
          
          lcd.setFont(SmallFont);
          lcd.print(t2.detail,3,35);
          lcd.update();
        }
        if(t2.packagename.equals("Gmail")){
          display.clearDisplay();
          digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(6,LOW);
        if(t1.BLN==1){
          digitalWrite(4,HIGH);
        }
        else
        {
          digitalWrite(4,LOW);
        }
        delay(1000);
          lcd.clrScr();
          lcd.setFont(SmallFont);
          lcd.print(t2.sendname,0,0);
          lcd.drawBitmap(30,10,gmails,24,24);
          lcd.setFont(SmallFont);
          lcd.print(t2.detail,3,34);
          lcd.update();
        }
//    Serial.println("package");
//    Serial.println(t2.packagename);
//    Serial.println("sendname");
//    Serial.println(t2.sendname);
//    Serial.println("detail");
//    Serial.println(t2.detail);
//    t2.packagename = "";
//    t2.sendname = "0";
//    t2.detail = "0";
   // delay(5000);
  }
  else{
  drawMenu();
  
  digitalWrite(2,HIGH);
  readRotaryEncoder();
   
  ClickEncoder::Button b = encoder->getButton();
   if (b != ClickEncoder::Open) {
   switch (b) {
      case ClickEncoder::Clicked:
         t1.middle=true;
        break;
    }
  }
  if(t1.up||t1.down||t1.middle){
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,LOW);
  }
 if(t1.up==1 && t1.page ==1){
    t1.up = 0;
    t1.menuitem = t1.menuitem-1;
    if(t1.menuitem ==0){
      t1.menuitem = 7;
    }
  }
  if(t1.down==1 && t1.page ==1){
    t1.down = 0;
    t1.menuitem++;
    if(t1.menuitem == 8){
      t1.menuitem = 1;
    }
  }
  if(t1.middle==1 && t1.page ==1 ){
    t1.middle = 0;
    t1.page =2;
  }
  else if(t1.middle==1 && t1.page ==2 && t1.inbl == 0){
    t1.middle = 0;
    t1.page =1;
  }
  }

 
  
}

void drawClock(){
    display.clearDisplay();
    display.setCursor(0,12);
    display.setFont(&Org_01);//TomThumb
    display.setTextColor(BLACK);
    display.setTextSize(3);

    display.print(t2.tHour);
    display.setCursor(0,30);

    display.print(t2.tMin);
    display.setCursor(4,44);
    display.setTextSize(2);
    if(t2.pm.equals("0")){
      display.print(F("AM"));  
    }
    else{
      display.print(F("PM"));
    }
    display.setTextSize(1);
    display.setCursor(37,9);

    display.print(t2.date);
    display.print(F("/"));

    display.print(t2.month);
    display.setCursor(40,26);
    display.setTextSize(2);
    if(t2.day.equals("1")){
      display.print(F("SUN"));
    }
    if(t2.day.equals("2")){
      display.print(F("MON"));
    }
    if(t2.day.equals("3")){
      display.print(F("TUE"));
    }
    if(t2.day.equals("4")){
      display.print(F("WED"));
    }
    if(t2.day.equals("5")){
      display.print(F("THR"));
    }
    if(t2.day.equals("6")){
      display.print(F("FRI"));
    }
    if(t2.day.equals("7")){
      display.print(F("SAT"));
    }

    display.setTextSize(1);
    display.setCursor(40,40);
    display.setTextColor(BLACK);
    display.print("BL:");
    if(t1.BLN ==0){
    display.print(F("*"));
    }
    else if(t1.BLN ==1){
    display.print(F("+"));
    }
    display.setCursor(60,40);
    display.print("ST:");
    if(t1.ST){
      display.print(F("+"));
    }
    else{
      display.print(F("*"));
    }
    display.display();
}

void stopwatch(){
  display.clearDisplay();
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(0,17);
  display.setTextSize(2);
  if(0<=t1.sHour && t1.sHour<10)
    display.print(F("0"));
  display.print(t1.sHour);//hour
  display.print(F(":"));
  if(0<=t1.sMin && t1.sMin<10)
    display.print(F("0"));
  display.print(t1.sMin);//min
  display.print(F(":"));
  if(0<=t1.sSec && t1.sSec<10)
    display.print(F("0"));
  display.print(t1.sSec);//sec
  display.setCursor(30,25);
  display.print(F(". ."));
  display.setCursor(18,40);
  display.print(t1.sMisec);//milisec
  display.display();
  if(t1.up){
    t1.up = false;
    if(t1.state==true){
      t1.state = false;
    }
    else if(t1.state == false){
      t1.state = true;
    }
  }
  if(t1.down){
    t1.down = false;
    t1.sHour = 00;
    t1.sMin = 00;
    t1.sSec = 00;
    t1.sMisec =0000;//reset the stopwatch
  }
  if(t1.state){
    t1.sMisec++;
    t1.ST = true;
  }
  else if(t1.state == false){
    t1.ST = false;
  }
  if(t1.sMisec == 60){
    t1.sMisec =0;
    t1.sSec++;
  }
  if(t1.sSec == 60){
    t1.sSec =0;
    t1.sMin++;
  }
  if(t1.sMin == 60){
    t1.sMin =0;
    t1.sHour++;
  }
  if(t1.sHour == 24){
    t1.sHour =0;
    t1.sMin = 0;
    t1.sSec = 0;
    t1.sMisec = 0;
  }
 
  
  
}
void notification(){
  display.clearDisplay();
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(10,15);
  display.setTextSize(1);
  display.println("NOTIFICATION");
  display.println("-------------");
  display.print(F("WHATSAPP:    "));
  display.println(t1.wCount);
  display.print(F("MISSED CALL: "));
  display.println(t1.pCount);
  display.print(F("EMAIL:       "));
  display.println(t1.eCount);
  display.display();
}


void alarm(){
  display.clearDisplay();
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(0,20);
  display.setTextSize(2);
  display.print(F("coming  soon"));
  display.display();
}

void backlight(){
  static int rmenu =1;
  
  display.clearDisplay();
  t1.inbl =1;
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(0,10);
  display.setTextSize(1);
  if(t1.up){
    t1.up = false;
    rmenu--;
    if(rmenu==1){
      rmenu = 2;
    }
  }
  if(t1.down){
    t1.down = false;
    rmenu++;
    if(rmenu==3){
      rmenu =1;
    }
 }
 
 if(rmenu == 1){
  display.println(F("Do You Want To Close Backligh:"));
  display.println(F("-----------------"));
  display.setFont();
  display.setTextColor(WHITE,BLACK);
  display.println(F(">YES"));
  display.setTextColor(BLACK,WHITE);
  display.println(F(">NO"));
  display.display();
  
 }
 else if(rmenu == 2){
  display.setTextColor(BLACK);
  display.println(F("Do You Want To Close Backligh:"));
  display.println(F("-----------------"));
  display.setFont();
  display.setTextColor(BLACK,WHITE);
  display.println(F(">YES"));
  display.setTextColor(WHITE,BLACK);
  display.println(F(">NO"));
  display.display();
 }
 if(t1.middle && t1.inbl==1){
  t1.middle = false;
  t1.inbl =0;
  if(rmenu ==1){
    t1.BLN =0;
    t1.page =1;
    t1.menuitem = 6;
  }
  else if(rmenu ==2){
    t1.BLN =1;
    t1.page =1;
    t1.menuitem =6;
  }
 }

}
void watchfaces(){
  display.clearDisplay();
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(0,20);
  display.setTextSize(2);
  display.print(F("coming  soon"));
  display.display();
}
void reset(){
  
  static int rmenu =1;
  t1.inbl =1;
  display.setContrast(50);
  display.setFont(&Org_01);
  display.setCursor(0,10);
  display.setTextSize(1);
  if(t1.up){
    t1.up = false;
    rmenu--;
    if(rmenu==1){
      rmenu = 2;
    }
  }
  if(t1.down){
    t1.down = false;
    rmenu++;
    if(rmenu==3){
      rmenu =1;
    }
 }
 
 if(rmenu == 1){
  display.println(F("Do You Want To Reset Setting Of The Watch:"));
  display.println(F("-----------------"));
  display.setFont();
  display.setTextColor(WHITE,BLACK);
  display.println(F(">YES"));
  display.setTextColor(BLACK,WHITE);
  display.println(F(">NO"));
  display.display();
  ////////////////////////////////////////////////////////////////////////////////////////////////
 }
 else if(rmenu == 2){
  display.setTextColor(BLACK);
  display.println(F("Do You Want To Reset Setting Of The Watch:"));
  display.println(F("-----------------"));
  display.setFont();
  display.setTextColor(BLACK,WHITE);
  display.println(F(">YES"));
  display.setTextColor(WHITE,BLACK);
  display.println(F(">NO"));
  display.display();
 }
 if(t1.middle && t1.inbl==1){
  t1.middle = false;
  t1.inbl =0;
  if(rmenu ==1){
    t1.BLN = true;
    t1.ST = false;
    t1.state = false;
    t1.sHour=t1.sMin=t1.sSec=t1.sMisec=0;
    t1.page =1;
    t1.menuitem = 7;
  }
  else if(rmenu ==2){
    t1.page =1;
    t1.menuitem =7;
  }
 }
}


void drawMenu(){
  if(t1.page==1){
    switch(t1.menuitem){
      case 1:
      drawClock();
      break;
      case 2:
      lcd.clrScr();
      lcd.drawBitmap(25,0,stopwatchs,32,32);
      lcd.setFont(SmallFont);
      lcd.print("STOPWATCH",13,35);
      lcd.update();
      break;
      
      case 3:
      lcd.clrScr();
      lcd.drawBitmap(25,0,notifications,32,32);
      lcd.setFont(SmallFont);
      lcd.print("NOTIFICATION",7,35);
      lcd.update();
      break;
      
      //case 4:menuitem++;
      //break;
      
      case 4:
      lcd.clrScr();
      lcd.drawBitmap(25,0,alarms,32,32);
      lcd.setFont(SmallFont);
      lcd.print("ALARM",26,35);
      lcd.update();
      break;
      
      case 5:
      lcd.clrScr();
      lcd.drawBitmap(25,0,backlite,32,32);
      lcd.setFont(SmallFont);
      lcd.print("BACKLIGHT",17,35);
      lcd.update();
      break;
      
      case 6:
      lcd.clrScr();
      lcd.drawBitmap(25,0,face,32,32);
      lcd.setFont(SmallFont);
      lcd.print("WATCHFACES",14,35);
      lcd.update();
      break;
      
      case 7:
      lcd.clrScr();
      lcd.drawBitmap(25,0,res,32,32);
      lcd.setFont(SmallFont);
      lcd.print("RESET",27,35);
      lcd.update();
      break;
      
    }//END OF PAGE ONE SWITCH
  }//END OF PAGE 1
  else if(t1.page ==2){
    switch(t1.menuitem){
      case 2:
      t1.lastmenu = t1.menuitem;
      stopwatch();
      t1.menuitem = t1.lastmenu;
      break;
      
      case 3:
      t1.lastmenu = t1.menuitem;
      notification();
      t1.menuitem = t1.lastmenu;
      break;
      
      case 4:
      t1.lastmenu = t1.menuitem;
      alarm();
      t1.menuitem = t1.lastmenu;
      break;
      
      case 5:
      t1.lastmenu = t1.menuitem;
      backlight();
      t1.menuitem = t1.lastmenu;
      break;
      
      case 6:
      t1.lastmenu = t1.menuitem;
      watchfaces();
      t1.menuitem = t1.lastmenu;
      break;
      
      case 7:
      t1.lastmenu = t1.menuitem;
      reset();
      t1.menuitem = t1.lastmenu;
      break;
      
    }//END OF PAGE 2 SWITCH
  }//END OF PAGE 2
}//END OF DRAWmENU

void timerIsr() {
  encoder->service();
}
void readRotaryEncoder()
{
  value += encoder->getValue();
  
  if (value/2 > last) {
    last = value/2;
    t1.down = 1;
    low = t1.down;
    delay(150);
  }else   if (value/2 < last) {
    last = value/2;
    t1.up = 1;
    high = t1.up;
    delay(150);
  }
  
//  Serial.println("up");
//  Serial.println(t1.up);
//  
//  Serial.println("down");
//  Serial.println(t1.down);
  //delay(2000);
}


void ButtonIsPressed(int upButtonState){
  if(upButtonState != t1.lastUpButtonState){
    if(upButtonState == 0){
      t1.backlite = 1;
    }
    delay(50);
  }
  t1.lastUpButtonState = upButtonState;
}
