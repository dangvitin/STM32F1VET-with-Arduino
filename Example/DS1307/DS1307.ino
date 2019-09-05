#include "Wire.h"     // Thư viện I2C
#include "uRTCLib.h"  //Thư viện module thời gian thực

uRTCLib rtc(0x68);  // Địa chỉ I2C của Module thời gian thực

void setup() {
	Serial.begin(9600); // Khởi tạo giao tiếp Serial
	Wire.begin();       // Khởi tạo giao tiếp I2C

  // Cài đặt thời gian theo thứ tự (giây, phút, giờ, thứ, ngày, tháng, năm)
  // Lưu ý cài đặt thứ, chủ nhật sẽ là số 1, thứ bảy là số 7
	
	rtc.set(0, 54, 18, 5, 2, 5, 19);  // hàm này sẽ thiết lập thời gian
  
  // Thời gian chỉ nên thiết lập 1 lần
  // nếu không thì mỗi lần reset thời gian cũng sẽ bị đặt lại 
}

void loop() {
	rtc.refresh();    //  Lấy dữ liệu từ module
  
  Serial.print("Thứ:"); 
  Serial.print(rtc.dayOfWeek()); // thứ, hàm rtc.dayOfWeek() sẽ trả về "thứ"

  // Tương tự các hàm bên dưới sẽ trả về thời gian, ngày, tháng,...
  Serial.print(" Ngày: ");
  Serial.print(rtc.day());  // Ngày
	Serial.print('/');
	Serial.print(rtc.month());  // Tháng
	Serial.print('/');
	Serial.print(rtc.year()); // Năm

	Serial.print(' ');

	Serial.print(rtc.hour()); // Giờ
	Serial.print(':');
	Serial.print(rtc.minute()); // Phút
	Serial.print(':');
	Serial.print(rtc.second()); // Giây

	Serial.println();

	delay(1000);
}
