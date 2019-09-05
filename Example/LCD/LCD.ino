//Thêm thư viện LiquitCrystal - nó có sẵn vì vậy bạn không cần cài thêm gì cả
#include <LiquidCrystal.h>

#define D7 PB0
#define D6 PB1
#define D5 PB2
#define D4 PE7
#define RS PE10
#define RW PE9
#define E  PE8  

//Khởi tạo với các chân
LiquidCrystal lcd(RS, RW, E, D4, D5, D6, D7);

void setup() {
  //Thông báo đây là LCD 1602
  lcd.begin(16, 2);
  //In ra màn hình lcd dòng chữ Toi yeu Arduino
  lcd.print("Toi yeu jkjkjjj");
}

void loop() {
  // đặt con trỏ vào cột 0, dòng 1
  // Lưu ý: dòng 1 là dòng thứ 2, lòng 0 là dòng thứ 1. Nôm na, nó đếm từ 0 từ không phải từ 1
  lcd.setCursor(0, 1);
  // In ra dong chu
  lcd.print("   Arduino.VN");
}
