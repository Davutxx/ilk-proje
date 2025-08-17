#include <Servo.h>

// Pin tanımları
const int trigPin = 7;
const int echoPin = 6;
Servo myServo;

// Mesafe aralıkları
const int distance1 = 50;
const int distance2 = 100;
const int distance3 = 150;
const int distance4 = 250;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(9); // Servo pinini bağla
  Serial.begin(9600);
}

void loop() {
  // Mesafe ölçümü
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Mesafeyi cm olarak hesapla

  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mesafeye göre servo motor kontrolü
  if (distance <= distance1) {
    myServo.write(90); // 10 cm veya daha küçükse 90 derece
  } else if (distance <= distance2) {
    myServo.write(180); // 10-20 cm arası 180 derece
  } else if (distance <= distance3) {
    myServo.write(270); // 20-30 cm arası 270 derece
  } else if (distance <= distance4) {
    myServo.write(360); // 30-40 cm arası 360 derece
  } else {
    myServo.write(0); // 40 cm'den büyükse başlangıç pozisyonu (opsiyonel)
  }

  delay(500); // Gecikme süresi
}
