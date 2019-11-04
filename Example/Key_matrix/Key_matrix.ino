#include <Keypad.h> // Thư viện Keypad

const byte ROWS = 4; // 4 hàng
const byte COLS = 4; // 4 cột

// Thứ tự phím
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {PC0, PC1, PC2, PC3}; // Kết nối Arduino với 4 hàng của bàn phím
byte colPins[COLS] = {PA1, PA2, PA3, PA4}; //    Kết nối Arduino với 4 cột của bàn phím

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Khởi tạo bàn phím từ các thiết lập trên

void setup() {
  Serial.begin(9600);   // Khởi tạo giao tiếp UART 
}

void loop() {
  char key = keypad.getKey(); // Quét phím
  if (key) {
    Serial.print(key);  // Nếu có phím nhấn thì in ra màn hình
  }
}
