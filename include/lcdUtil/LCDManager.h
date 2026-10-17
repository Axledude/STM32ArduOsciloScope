#ifndef STM32ARDUOSCILISCOPE_LCDMANAGER_H
#define STM32ARDUOSCILISCOPE_LCDMANAGER_H
#include "Version.h"
#include <Arduino.h>
#include "LiquidCrystal.h"
// #include "LiquidCrystal_I2C.h"

class LCDManager : public LiquidCrystal {
public:
    // 4Bit hd447800 Setup
    LCDManager(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : LiquidCrystal(rs, enable, d4, d5, d6, d7) {}
    virtual void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS) {
        LiquidCrystal::begin(cols, rows, charsize);
    }
    void init() {
        begin(16, 2);
        print("STM32ArduOscilo");
        setCursor(0, 1);
        print(VERSION_START);
        delay(500);
        clear();
        delay(2000);
    }
    // I2C hd44780 Setup
};
#endif //STM32ARDUOSCILISCOPE_LCDMANAGER_H