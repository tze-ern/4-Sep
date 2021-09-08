#include <LiquidCrystal_I2C.h>

int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R2 = 1000;
float R1 = 0;
float buffer = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Vout:");

  lcd.setCursor(0, 1);
  lcd.print("R1:");
}

void loop() {
  raw = analogRead(analogPin);
  if (raw) {
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R1 = R2 * buffer;

    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R1: ");
    Serial.println(R1);
    delay(1000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vout:");
    lcd.setCursor(6, 0);
    lcd.print(Vout);
    lcd.setCursor(0, 1);
    lcd.print("R1:");
    lcd.setCursor(6, 1);
    lcd.print(R1);
    delay(1000);
  }
}
