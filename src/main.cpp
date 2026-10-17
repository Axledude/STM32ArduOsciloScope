#include <Arduino.h>
#include "lcdUtil/LCDManager.h"

LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);
int rawValue = 0;
float voltage = 0.0;

void setup() {
    analogReadResolution(12); //12 bit
    Serial.begin(115200);
    Serial.println("STM32ArduOscilo " VERSION_V1);
    lcd.begin(16, 2);
    lcd.print("STM32ArduOscilo");
    lcd.setCursor(0, 1);
    lcd.print(VERSION_V1);
    delay(2000);
    lcd.clear();
}

void loop() {
    rawValue = analogRead(A5);
    voltage = (rawValue * 5) / 4095.0;

    Serial.print("Raw: ");
    Serial.print(rawValue);

    Serial.print(" | Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    lcd.setCursor(0,0);
    lcd.print("Raw:");
    lcd.print(rawValue);
    lcd.setCursor(0,1);
    lcd.print("V:");
    lcd.print(voltage, 2);
    delay(100);
    lcd.clear();
}
