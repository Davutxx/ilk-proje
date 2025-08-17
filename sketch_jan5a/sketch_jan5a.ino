#include <Servo.h>

Servo omuzServo;  // Omuz için servo
Servo dirsekServo; // Dirsek için servo
Servo bilekServo;  // Bilek için servo

int omuzAci, dirsekAci, bilekAci;

void setup() {
  Serial.begin(9600);

  omuzServo.attach(7);   // Omuz servosu, pin 
  dirsekServo.attach(6); // Dirsek servosu, pin 
  bilekServo.attach(5);  // Bilek servosu, pin 
}

void loop() {
  if (Serial.available() > 0) {
    String veri = Serial.readStringUntil('\n');  // Seri veriyi oku
    int ayrac1 = veri.indexOf(',');
    int ayrac2 = veri.lastIndexOf(',');

    // Veriyi ayrıştır
    omuzAci = veri.substring(0, ayrac1).toInt();
    dirsekAci = veri.substring(ayrac1 + 1, ayrac2).toInt();
    bilekAci = veri.substring(ayrac2 + 1).toInt();

    // Servo açılarını -180 ile 180 arasında normalleştir
    omuzServo.write(map(normalizeAci(omuzAci), -180, 180, 0, 180));
    dirsekServo.write(map(normalizeAci(dirsekAci), -180, 180, 0, 180));
    bilekServo.write(map(normalizeAci(bilekAci), -180, 180, 0, 180));

    // Debug için yazdır
    Serial.print("Omuz: "); Serial.print(omuzAci);
    Serial.print(", Dirsek: "); Serial.print(dirsekAci);
    Serial.print(", Bilek: "); Serial.println(bilekAci);
  }
}

int normalizeAci(int angle) {
  // Açıyı -180 ile 180 arasında normalize et
  while (angle > 180) {
    angle -= 360;
  }
  while (angle < -180) {
    angle += 360;
  }
  return angle;
}
