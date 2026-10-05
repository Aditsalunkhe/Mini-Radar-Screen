#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 d(128, 64, &Wire, -1);
Servo s;
int ang = 15, step = 5;

long dist() {
  digitalWrite(9, LOW); delayMicroseconds(2);
  digitalWrite(9, HIGH); delayMicroseconds(10);
  digitalWrite(9, LOW);
  return pulseIn(10, HIGH, 30000) * 0.034 / 2;
}

void setup() {
  pinMode(9, OUTPUT); pinMode(10, INPUT);
  s.attach(6);
  d.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  s.write(ang); delay(30);
  long r = dist();
  float rad = ang * PI / 180;
  d.clearDisplay();
  d.drawCircle(64, 63, 60, WHITE);              // radar arc
  d.drawLine(64, 63, 64 + 60 * cos(rad), 63 - 60 * sin(rad), WHITE);
  if (r > 0 && r < 100) {                       // draw blip
    int p = map(r, 0, 100, 0, 60);
    d.fillCircle(64 + p * cos(rad), 63 - p * sin(rad), 3, WHITE);
  }
  d.display();
  ang += step;
  if (ang >= 165 || ang <= 15) step = -step;
}