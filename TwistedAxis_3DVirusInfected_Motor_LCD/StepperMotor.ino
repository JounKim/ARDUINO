/////////// XYZ 정의 ////////////
#define X_STEP_PIN 54 
#define X_DIR_PIN 55 
#define X_ENABLE_PIN 38 
#define X_MIN_PIN 3 
#define X_MAX_PIN 2 

#define Y_STEP_PIN 60 
#define Y_DIR_PIN 61 
#define Y_ENABLE_PIN 56 
#define Y_MIN_PIN 14 
#define Y_MAX_PIN 15 

#define Z_STEP_PIN 46 
#define Z_DIR_PIN 48 
#define Z_ENABLE_PIN 62 
#define Z_MIN_PIN 18 
#define Z_MAX_PIN 19 

//////////// LCD 정의 ////////////////////
#include <LiquidCrystal.h>

LiquidCrystal lcd(16, 17, 23, 25, 27, 29);

//#define LCD_PINS_RS 16 //[RAMPS14-SMART-ADAPTER]  
//#define LCD_PINS_ENABLE 17 //[RAMPS14-SMART-ADAPTER]  
//#define LCD_PINS_D4 23 //[RAMPS14-SMART-ADAPTER]  
//#define LCD_PINS_D5 25 //[RAMPS14-SMART-ADAPTER]  
//#define LCD_PINS_D6 27 //[RAMPS14-SMART-ADAPTER]  
//#define LCD_PINS_D7 29 //[RAMPS14-SMART-ADAPTER]  

//////////// Stepper Motor 속도 ///////////
int DelayTimeX = 3;
int DelayTimeY = 3;
int DelayTimeZ = 3;

//////////////////////////////////////////

void setup() {

  
  pinMode(X_STEP_PIN , OUTPUT);
  pinMode(X_DIR_PIN , OUTPUT); 
  pinMode(X_ENABLE_PIN , OUTPUT); 

  pinMode(Y_STEP_PIN , OUTPUT);
  pinMode(Y_DIR_PIN , OUTPUT); 
  pinMode(Y_ENABLE_PIN , OUTPUT); 
  
  pinMode(Z_STEP_PIN , OUTPUT); 
  pinMode(Z_DIR_PIN , OUTPUT);
  pinMode(Z_ENABLE_PIN , OUTPUT); 
 
  
  digitalWrite(X_ENABLE_PIN , LOW);
  digitalWrite(Y_ENABLE_PIN , LOW);
  digitalWrite(Z_ENABLE_PIN , LOW);

  ///////////////// LCD ////////////////

  // 16개의 셀과 2줄을 사용하도록 설정합니다.
  lcd.begin(20,4);
  // LCD를 초기화 합니다.
  lcd.clear();

  //////////////////////////////////////
}
  
void loop () { 

  
  digitalWrite(X_DIR_PIN , HIGH);
  digitalWrite(Y_DIR_PIN , HIGH);
  digitalWrite(Z_DIR_PIN , HIGH);
  
  
  digitalWrite(X_STEP_PIN , HIGH); 
  delay(DelayTimeX);
  digitalWrite(X_STEP_PIN , LOW);

  digitalWrite(Y_STEP_PIN , HIGH);
  delay(DelayTimeY);
  digitalWrite(Y_STEP_PIN , LOW); 

  digitalWrite(Z_STEP_PIN , HIGH);
  delay(DelayTimeZ);
  digitalWrite(Z_STEP_PIN , LOW);

  ////////////////// LCD //////////////////

  // 5초 단위로 2초 2초 1초 나눠서 credit을 보여준다
  if(millis() % 5000 < 2000){
    lcd.setCursor(0,0);
    lcd.print("    ");
  
    lcd.setCursor(0,1);
    lcd.print("    TWISTED AXIS");
  
    lcd.setCursor(0,2);
    lcd.print("  K.M.H K.J.Y S.H.S");
  
    lcd.setCursor(0,3);
    lcd.print("    ");
  }
  if(millis()% 5000 >2000 && millis() % 5000 < 4000){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    ");
  
    lcd.setCursor(0,1);
    lcd.print("    3D VIRUS");
  
    lcd.setCursor(0,2);
    lcd.print("     INFECTED!!");
  
    lcd.setCursor(0,3);
    lcd.print("    ");
  }

  if(millis() %5000 > 4000 && millis()% 5000 < 5000){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    ");
  
    lcd.setCursor(0,1);
    lcd.print("    ");
  
    lcd.setCursor(0,2);
    lcd.print(" (YOU DUCKED UP!!!)");
  
    lcd.setCursor(0,3);
    lcd.print("    ");
  }
  

}
