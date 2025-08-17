#include <Servo.h>

Servo servo1; // 1 numaralı motor
Servo servo2; // 2 numaralı motor
Servo servo3; // 3 numaralı motor
Servo servo4; // 4 numaralı motor
Servo servo5; // 5 numaralı motor
Servo servo6; // 6 numaralı motor
Servo servo7; // 7 numaralı motor
Servo servo8; // 8 numaralı motor
Servo servo9; // 9 numaralı motor
Servo servo10; // 10 numaralı motor

void setup() {
  Serial.begin(9600);
  
  // Her bir servo motoru ilgili pinlere bağlayın
  servo1.attach(2);   // 1 numaralı servo motor 2. pine bağlı
  servo2.attach(3);   // 2 numaralı servo motor 3. pine bağlı
  servo3.attach(4);   // 3 numaralı servo motor 4. pine bağlı
  servo4.attach(5);   // 4 numaralı servo motor 5. pine bağlı
  servo5.attach(6);   // 5 numaralı servo motor 6. pine bağlı
  servo6.attach(7);   // 6 numaralı servo motor 7. pine bağlı
  servo7.attach(8);   // 7 numaralı servo motor 8. pine bağlı
  servo8.attach(9);   // 8 numaralı servo motor 9. pine bağlı
  servo9.attach(10);  // 9 numaralı servo motor 10. pine bağlı
  servo10.attach(11); // 10 numaralı servo motor 11. pine bağlı
}

void loop() {
  if (Serial.available() > 0) {
    int segmentNumber = Serial.read(); // Gelen numarayı oku

    // Her bir numara için servo motorun açısını belirleyin
    switch(segmentNumber) {
      case 1:
        servo1.write(90); // 1 numaralı motor 90 derece
        break;
      case 2:
        servo2.write(90); // 2 numaralı motor 90 derece
        break;
      case 3:
        servo3.write(90); // 3 numaralı motor 90 derece
        break;
      case 4:
        servo4.write(90); // 4 numaralı motor 90 derece
        break;
      case 5:
        servo5.write(90); // 5 numaralı motor 90 derece
        break;
      case 6:
        servo6.write(90); // 6 numaralı motor 90 derece
        break;
      case 7:
        servo7.write(90); // 7 numaralı motor 90 derece
        break;
      case 8:
        servo8.write(90); // 8 numaralı motor 90 derece
        break;
      case 9:
        servo9.write(90); // 9 numaralı motor 90 derece
        break;
      case 10:
        servo10.write(90); // 10 numaralı motor 90 derece
        break;
      default:
        // Hiçbir servo motor hareket ettirilmez
        break;
    }
  }
}
