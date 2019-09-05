#include <SPI.h>        // Thư viện giao tiếp SPI
#include <MFRC522.h>    // Thư viện Module RC522

#define SS_PIN PC4
#define RST_PIN PA4

// Khai báo RC522
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

byte nuidPICC[4];       // Mảng chứa giá trị ID của thẻ (4 phần tử 8bit)

void setup()
{
  Serial.begin(9600);   // Khởi tạo giao tiếp Serial giữa arduino và máy tính.
  SPI.begin();          // Khởi tạo giao thức SPI
  rfid.PCD_Init();      // Khởi tạo RC522
}

void loop() {
  // Kiểm tra thẻ có hiện diện hay không và tiến hành đọc thẻ
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  // So sánh ID đọc được từ thẻ và so sánh với ID ta đã ghi lại trước đó.
  if (rfid.uid.uidByte[0] == 188 &&
      rfid.uid.uidByte[1] == 118 &&
      rfid.uid.uidByte[2] == 144 &&
      rfid.uid.uidByte[3] == 117 )
  {
    Serial.println("This is card A");   // Nếu đúng thì tiến hành in dòng chữ...
                                        // Có thẻ thay dòng này bằng lệnh muốn làm (điều khiển led, động cơ,....) 
  }

  // Tương tự cho 2 thẻ còn lại
  else if (rfid.uid.uidByte[0] == 97 &&
           rfid.uid.uidByte[1] == 77 &&
           rfid.uid.uidByte[2] == 150 &&
           rfid.uid.uidByte[3] == 117 )
  {
    Serial.println("This is card B");

  }

  else if (rfid.uid.uidByte[0] == 6 &&
           rfid.uid.uidByte[1] == 123 &&
           rfid.uid.uidByte[2] == 128 &&
           rfid.uid.uidByte[3] == 2 )
  {
    Serial.println("This is card C");

  }

  else 
  {
  Serial.println("Wrong card !");  
  }

  // Sau khi đọc thẻ xong tiến hành ngắt kết nối với thẻ.
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
