#include <LiquidCrystal.h>

#define D7 PC9
#define D6 PC8
#define D5 PC7
#define D4 PC6
#define RS PB0
#define RW PA15
#define E  PB1

//Khởi tạo với các chân
LiquidCrystal lcd(RS, RW, E, D4, D5, D6, D7);
int i = 0;

void setup()
{
  //********************************************************
  *(uint32_t*)(0x40021018) |= 0x05;       //Enable clock   *
  *(uint32_t*)(0x40010004) |= 0x04000000; //Remap pin      *
  //********************************************************
  
  //Khai báo đây là LCD 1602
  lcd.begin(20, 4);
  //In ra màn hình lcd dòng chữ Toi yeu Arduino
  lcd.print("Toi yeu Arduino");
}

void loop()
{
  // đặt con trỏ vào cột 10, dòng 1
  lcd.setCursor(10, 1);
  lcd.print(i);
  i++;
  delay(200);
}
