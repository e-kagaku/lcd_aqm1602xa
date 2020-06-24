#ifndef LCD_AQM1602XA_H_INCLUDE_20200616232121
#define LCD_AQM1602XA_H_INCLUDE_20200616232121
#include "Arduino.h"
#define DATA_WRITE 0x40

class LCD_aqm1602xa {
  public:
    LCD_aqm1602xa(const int addr);
    void initialize();
    void printLCD(String str);
    void printLCD(int num);
    void printLCD(float num);
    void printLCD(long num);
    void clearLCD();
    void setCursorHome();
    void setCursor(int line, int row);
    void shiftCursorLeft(int row = 1);
    void shiftCursorRight(int row = 1);

  private:
    void writeCommand(byte t_command);
    int writeStr(byte cltd, byte data);
    int lcd_addr;
};

#endif
