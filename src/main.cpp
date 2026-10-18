#include <Arduino.h>
#include <thread>
#include "lcdUtil/LCDManager.h"

LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);
int rawValue;
float readVoltage;

void setup() {
    analogReadResolution(10); //10 bit

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
    readVoltage = (rawValue * 5) / 1023.0;

    Serial.println("A5 Pin:");
    Serial.print("Raw: ");
    Serial.print(rawValue);
    Serial.print(" | Voltage: ");
    Serial.print(readVoltage);
    Serial.println(" V");
    Serial.clearWriteError();

    lcd.setCursor(0,0);
    lcd.print("Raw:");
    lcd.print(rawValue);
    lcd.setCursor(0,1);
    lcd.print("V:");
    lcd.print(readVoltage, 2);
    delay(100);
    lcd.clear();
}