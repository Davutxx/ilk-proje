#include <Servo.h>

Servo myServo;  // Servo motoru tanımla
int servoPin = 9;  // Servo motorun bağlı olduğu pin
int segmentNum = 0;  // Gelen segment numarası

void setup() {
    myServo.attach(servoPin);  // Servo motoru belirtilen pin'e bağla
    Serial.begin(9600);  // Seri iletişimi başlat
    myServo.write(0);  // Başlangıçta servo motoru 0 dereceye ayarla
}

void loop() {
    // Eğer seri porttan veri varsa oku
    if (Serial.available() > 0) {
        segmentNum = Serial.read();  // Gelen veriyi oku

        // Eğer 1 numaralı segment algılandıysa
        if (segmentNum == 1) {
            myServo.write(90);  // Servo motoru 90 dereceye döndür (saat yönünde)
            delay(1000);  // 1 saniye bekle
            myServo.write(0);  // Servo motoru 0 dereceye geri döndür
        }
    }
}
