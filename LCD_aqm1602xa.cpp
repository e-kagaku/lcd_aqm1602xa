#include "LCD_aqm1602xa.h"
#include "Arduino.h"
#include <Wire.h>

LCD_aqm1602xa::LCD_aqm1602xa(const int addr) {
  lcd_addr = addr;
}

void LCD_aqm1602xa::writeCommand(byte t_command) {
  Wire.beginTransmission(lcd_addr);
  Wire.write(0x00);
  Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}

int LCD_aqm1602xa::writeStr(byte cltd, byte data) {
  Wire.beginTransmission(lcd_addr);
  Wire.write(cltd);
  Wire.write(data);
  return Wire.endTransmission();
}

void LCD_aqm1602xa::initialize() {
  delay(100);
  writeCommand(0x38);  delay(20);
  writeCommand(0x39);  delay(20);
  writeCommand(0x14);  delay(20);
  writeCommand(0x73);  delay(20);
  writeCommand(0x51);  delay(20);
  writeCommand(0x6C);  delay(20);
  writeCommand(0x38);  delay(20);
  writeCommand(0x01);  delay(20);
  writeCommand(0x0C);  delay(20);
}

void LCD_aqm1602xa::printLCD(String str) {
  int n = str.length();
  for (int i = 0; i < n; i = i + 1) {
    if((str[i] & 0xFF) == 0xE3){  //Katakana
      char kana;
      i++;
      if((str[i] & 0xFF) == 0x82){  //ア～タ
        i++;
        int c = str[i] & 0xFF;
        switch(c){
          case 0xA1:  //ァ
            kana = '\xA7';
            break;
          case 0xA2:  //ア
            kana = '\xB1';
            break;
          case 0xA3:  //ィ
            kana = '\xA8';
            break;
          case 0xA4:  //イ
            kana = '\xB2';
            break;
          case 0xA5:  //ゥ
            kana = '\xA9';
            break;
          case 0xA6:  //ウ
            kana = '\xB3';
            break;
          case 0xA7:  //ェ
            kana = '\xAA';
            break;
          case 0xA8:  //エ
            kana = '\xB4';
            break;
          case 0xA9:  //ォ
            kana = '\xAB';
            break;
          case 0xAA:  //オ
            kana = '\xB5';
            break;
          case 0xAB:  //カ
            kana = '\xB6';
            break;
          case 0xAC:  //ガ
            writeStr(DATA_WRITE, 0xB6);
            kana = '\xDE';
            break;
          case 0xAD:  //キ
            kana = '\xB7';
            break;
          case 0xAE:  //ギ
            writeStr(DATA_WRITE, 0xB7);
            kana = '\xDE';
            break;
          case 0xAF:  //ク
            kana = '\xB8';
            break;
          case 0xB0:  //グ
            writeStr(DATA_WRITE, 0xB8);
            kana = '\xDE';
            break;
          case 0xB1:  //ケ
            kana = '\xB9';
            break;
          case 0xB2:  //ゲ
            writeStr(DATA_WRITE, 0xB9);
            kana = '\xDE';
            break;
          case 0xB3:  //コ
            kana = '\xBA';
            break;
          case 0xB4:  //ゴ
            writeStr(DATA_WRITE, 0xBA);
            kana = '\xDE';
            break;
          case 0xB5:  //サ
            kana = '\xBB';
            break;
          case 0xB6:  //ザ
            writeStr(DATA_WRITE, 0xBB);
            kana = '\xDE';
            break;
          case 0xB7:  //シ
            kana = '\xBC';
            break;
          case 0xB8:  //ジ
            writeStr(DATA_WRITE, 0xBC);
            kana = '\xDE';
            break;
          case 0xB9:  //ス
            kana = '\xBD';
            break;
          case 0xBA:  //ズ
            writeStr(DATA_WRITE, 0xBD);
            kana = '\xDE';
            break;
          case 0xBB:  //セ
            kana = '\xBE';
            break;
          case 0xBC:  //ゼ
            writeStr(DATA_WRITE, 0xBE);
            kana = '\xDE';
            break;
          case 0xBD:  //ソ
            kana = '\xBF';
            break;
          case 0xBE:  //ゾ
            writeStr(DATA_WRITE, 0xBF);
            kana = '\xDE';
            break;
          case 0xBF:  //タ
            kana = '\xC0';
            break;
          defaut:
            break;
        }
        writeStr(DATA_WRITE, kana);
      }else if((str[i] & 0xFF) == 0x83){  //チ～ン
        i++;
        int c = str[i] & 0xFF;
        switch(c){
          case 0x80:  //ダ
            writeStr(DATA_WRITE, 0xC0);
            kana = '\xDE';
            break;
          case 0x81:  //チ
            kana = '\xC1';
            break;
          case 0x82:  //ヂ
            writeStr(DATA_WRITE, 0xC1);
            kana = '\xDE';
            break;
          case 0x83:  //ッ
            kana = '\xAF';
            break;
          case 0x84:  //ツ
            kana = '\xC2';
            break;
          case 0x85:  //ヅ
            writeStr(DATA_WRITE, 0xC2);
            kana = '\xDE';
            break;
          case 0x86:  //テ
            kana = '\xC3';
            break;
          case 0x87:  //デ
            writeStr(DATA_WRITE, 0xC3);
            kana = '\xDE';
            break;
          case 0x88:  //ト
            kana = '\xC4';
            break;
          case 0x89:  //ド
            writeStr(DATA_WRITE, 0xC4);
            kana = '\xDE';
            break;
          case 0x8A:  //ナ
            kana = '\xC5';
            break;
          case 0x8B:  //ニ
            kana = '\xC6';
            break;
          case 0x8C:  //ヌ
            kana = '\xC7';
            break;
          case 0x8D:  //ネ
            kana = '\xC8';
            break;
          case 0x8E:  //ノ
            kana = '\xC9';
            break;
          case 0x8F:  //ハ
            kana = '\xCA';
            break;
          case 0x90:  //バ
            writeStr(DATA_WRITE, 0xCA);
            kana = '\xDE';
            break;
          case 0x91:  //パ
            writeStr(DATA_WRITE, 0xCA);
            kana = '\xDF';
            break;
          case 0x92:  //ヒ
            kana = '\xCB';
            break;
          case 0x93:  //ビ
            writeStr(DATA_WRITE, 0xCB);
            kana = '\xDE';
            break;
          case 0x94:  //ピ
            writeStr(DATA_WRITE, 0xCB);
            kana = '\xDF';
            break;
          case 0x95:  //フ
            kana = '\xCC';
            break;
          case 0x96:  //ブ
            writeStr(DATA_WRITE, 0xCC);
            kana = '\xDE';
            break;
          case 0x97:  //プ
            writeStr(DATA_WRITE, 0xCC);
            kana = '\xDF';
            break;
          case 0x98:  //ヘ
            kana = '\xCD';
            break;
          case 0x99:  //ベ
            writeStr(DATA_WRITE, 0xCD);
            kana = '\xDE';
            break;
          case 0x9A:  //ペ
            writeStr(DATA_WRITE, 0xCD);
            kana = '\xDF';
            break;
          case 0x9B:  //ホ
            kana = '\xCE';
            break;
          case 0x9C:  //ボ
            writeStr(DATA_WRITE, 0xCE);
            kana = '\xDE';
            break;
          case 0x9D:  //ポ
            writeStr(DATA_WRITE, 0xCE);
            kana = '\xDF';
            break;
          case 0x9E:  //マ
            kana = '\xCF';
            break;
          case 0x9F:  //ミ
            kana = '\xD0';
            break;
          case 0xA0:  //ム
            kana = '\xD1';
            break;
          case 0xA1:  //メ
            kana = '\xD2';
            break;
          case 0xA2:  //モ
            kana = '\xD3';
            break;
          case 0xA3:  //ャ
            kana = '\xAC';
            break;
          case 0xA4:  //ヤ
            kana = '\xD4';
            break;
          case 0xA5:  //ュ
            kana = '\xAD';
            break;
          case 0xA6:  //ユ
            kana = '\xD5';
            break;
          case 0xA7:  //ョ
            kana = '\xAE';
            break;
          case 0xA8:  //ヨ
            kana = '\xD6';
            break;
          case 0xA9:  //ラ
            kana = '\xD7';
            break;
          case 0xAA:  //リ
            kana = '\xD8';
            break;
          case 0xAB:  //ル
            kana = '\xD9';
            break;
          case 0xAC:  //レ
            kana = '\xDA';
            break;
          case 0xAD:  //ロ
            kana = '\xDB';
            break;
          case 0xAE:  //ヮ
          case 0xAF:  //ワ
            kana = '\xDC';
            break;
          case 0xB2:  //ヲ
            kana = '\xA6';
            break;
          case 0xB3:  //ン
            kana = '\xDD';
            break;
          default:
            break;
        }
        writeStr(DATA_WRITE, kana);
      }
    }else{
      writeStr(DATA_WRITE, str.charAt(i));
    }
    delay(1);
  }
}

void LCD_aqm1602xa::clearLCD() {
  writeCommand(0x01);
}

void LCD_aqm1602xa::setCursorHome() {
  writeCommand(0x02);
}

void LCD_aqm1602xa::setCursor(int line, int row) {
  line = line - 1;
  if (line < 0) {
    line = 0;
  } else if (line > 2) {
    line = 1;
  }
  if (row < 0) {
    row = 0;
  } else if (row > 15) {
    row = 15;
  }
  byte cur_pos = (row + line * 0x40) | (0x80);
  writeCommand(cur_pos);
}

void LCD_aqm1602xa::shiftCursorRight(int row = 1){
  row < 0 ? 0 : row;
  for(int i = 1 ; i <= row ; i++){
    writeCommand(0x14); 
  }
}

void LCD_aqm1602xa::shiftCursorLeft(int row = 1){
  row < 0 ? 0 : row;
  for(int i = 1 ; i <= row ; i++){
    writeCommand(0x10); 
  }
}
