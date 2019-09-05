#include <SPI.h>
#include <SD.h>
// Tham khảo thêm các hàm chức năng ở 
// https://www.arduino.cc/en/Reference/SD

File myFile;
void setup() {
  // Thiết lập giao tiếp Serial
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Serial.print("Khởi tạo SD card...");

  if (!SD.begin(PC4)) {
    Serial.println("Khởi tạo thất bại !");
    while (1);
  }
  Serial.println("Khởi tại thành công !");

  // Mở file, chỉ mở được 1 file trong 1 thời điểm, nếu không có file để mở thì
  // sẽ tạo ra file tương ứng
  // Ở đây file mở tên là 'test.txt', nếu file không tồn tại thì tạo file 'test.txt'

  myFile = SD.open("test.txt", FILE_WRITE);

  // Nếu mở file thành công
  if (myFile) {
    myFile.println("Chao mung den voi");
    myFile.println("Cau lac bo Dien Tu !!!");

    // Sau khi ghi xong tiến hành đóng file lại
    myFile.close();
    Serial.println("Đã ghi xong.");
  } else {
    // Nếu gặp lỗi khi mở file thì in ra màn hình
    Serial.println("Lỗi khi mở file");
  }

  // Đọc file ///////////////////////////////////////////////

  // Mở file để đọc
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("Đang mở file...");
    Serial.println("****** Nội dung file ******");
    // Đọc toàn bộ chữ trong file
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    Serial.println("****** Kết thúc file ******");
    // Đóng file lại sau khi đọc
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("Lỗi khi mở file.");
  }
}

void loop() {
}
